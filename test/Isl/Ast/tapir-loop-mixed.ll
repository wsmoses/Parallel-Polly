; RUN: opt %loadPolly -basicaa -polly-ast -analyze < %s | FileCheck %s
;
; Four-layer loop mixing regular loops and tapir loops of the form:
;
; cilk_for(int i=0; i<512; i++) {
;     for(int j=0; j<512; j++) {
;         cilk_for(int k=0; k<512; k++) {
;             for(int l=0; l<512; l++) {
;                 B[i + j + k + l] = A[i + j + k + l] * 2;
;             }
;         }
;     }
; }
;
; CHECK: for (int c0 = 0; c0 <= 511; c0 += 1)
; CHECK-NEXT:   for (int c1 = 0; c1 <= 511; c1 += 1)
; CHECK-NEXT:     for (int c2 = 0; c2 <= 511; c2 += 1)
; CHECK-NEXT:       for (int c3 = 0; c3 <= 511; c3 += 1)
; CHECK-NEXT:         Stmt_for_body18(c0, c1, c2, c3);

; ModuleID = 'test.ll'
source_filename = "test.c"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1

; Function Attrs: nounwind uwtable
define i32 @main() local_unnamed_addr #0 {
entry:
  %A = alloca [4096 x i32], align 16
  %B = alloca [4096 x i32], align 16
  br label %entry.split

entry.split:                                      ; preds = %entry
  %syncreg = tail call token @llvm.syncregion.start()
  %0 = bitcast [4096 x i32]* %A to i8*
  call void @llvm.lifetime.start.p0i8(i64 16384, i8* nonnull %0) #3
  %1 = bitcast [4096 x i32]* %B to i8*
  call void @llvm.lifetime.start.p0i8(i64 16384, i8* nonnull %1) #3
  br label %pfor.detach

pfor.cond.cleanup:                                ; preds = %pfor.inc33
  sync within %syncreg, label %pfor.end.continue

pfor.end.continue:                                ; preds = %pfor.cond.cleanup
  %arrayidx36 = getelementptr inbounds [4096 x i32], [4096 x i32]* %B, i64 0, i64 0
  %2 = load i32, i32* %arrayidx36, align 16, !tbaa !2
  %call = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i64 0, i64 0), i32 %2)
  call void @llvm.lifetime.end.p0i8(i64 16384, i8* nonnull %1) #3
  call void @llvm.lifetime.end.p0i8(i64 16384, i8* nonnull %0) #3
  ret i32 0

pfor.detach:                                      ; preds = %pfor.inc33, %entry.split
  %indvars.iv73 = phi i64 [ 0, %entry.split ], [ %indvars.iv.next74, %pfor.inc33 ]
  detach within %syncreg, label %pfor.body, label %pfor.inc33

pfor.body:                                        ; preds = %pfor.detach
  %syncreg2 = tail call token @llvm.syncregion.start()
  br label %for.body

for.cond.cleanup:                                 ; preds = %pfor.end.continue9
  reattach within %syncreg, label %pfor.inc33

for.body:                                         ; preds = %pfor.end.continue9, %pfor.body
  %indvars.iv69 = phi i64 [ 0, %pfor.body ], [ %indvars.iv.next70, %pfor.end.continue9 ]
  %3 = add nuw nsw i64 %indvars.iv69, %indvars.iv73
  br label %pfor.detach10

pfor.cond.cleanup8:                               ; preds = %pfor.inc
  sync within %syncreg2, label %pfor.end.continue9

pfor.end.continue9:                               ; preds = %pfor.cond.cleanup8
  %indvars.iv.next70 = add nuw nsw i64 %indvars.iv69, 1
  %exitcond72 = icmp eq i64 %indvars.iv.next70, 512
  br i1 %exitcond72, label %for.cond.cleanup, label %for.body, !llvm.loop !6

pfor.detach10:                                    ; preds = %pfor.inc, %for.body
  %indvars.iv65 = phi i64 [ 0, %for.body ], [ %indvars.iv.next66, %pfor.inc ]
  detach within %syncreg2, label %pfor.body14, label %pfor.inc

pfor.body14:                                      ; preds = %pfor.detach10
  %4 = add nuw nsw i64 %3, %indvars.iv65
  br label %for.body18

for.cond.cleanup17:                               ; preds = %for.body18
  reattach within %syncreg2, label %pfor.inc

for.body18:                                       ; preds = %for.body18, %pfor.body14
  %indvars.iv = phi i64 [ 0, %pfor.body14 ], [ %indvars.iv.next, %for.body18 ]
  %5 = add nuw nsw i64 %4, %indvars.iv
  %arrayidx = getelementptr inbounds [4096 x i32], [4096 x i32]* %A, i64 0, i64 %5
  %6 = load i32, i32* %arrayidx, align 4, !tbaa !2
  %mul22 = shl nsw i32 %6, 1
  %arrayidx27 = getelementptr inbounds [4096 x i32], [4096 x i32]* %B, i64 0, i64 %5
  store i32 %mul22, i32* %arrayidx27, align 4, !tbaa !2
  %indvars.iv.next = add nuw nsw i64 %indvars.iv, 1
  %exitcond = icmp eq i64 %indvars.iv.next, 512
  br i1 %exitcond, label %for.cond.cleanup17, label %for.body18, !llvm.loop !10

pfor.inc:                                         ; preds = %for.cond.cleanup17, %pfor.detach10
  %indvars.iv.next66 = add nuw nsw i64 %indvars.iv65, 1
  %exitcond68 = icmp eq i64 %indvars.iv.next66, 512
  br i1 %exitcond68, label %pfor.cond.cleanup8, label %pfor.detach10, !llvm.loop !11

pfor.inc33:                                       ; preds = %for.cond.cleanup, %pfor.detach
  %indvars.iv.next74 = add nuw nsw i64 %indvars.iv73, 1
  %exitcond75 = icmp eq i64 %indvars.iv.next74, 512
  br i1 %exitcond75, label %pfor.cond.cleanup, label %pfor.detach, !llvm.loop !13
}

; Function Attrs: argmemonly nounwind
declare void @llvm.lifetime.start.p0i8(i64, i8* nocapture) #1

; Function Attrs: argmemonly nounwind
declare token @llvm.syncregion.start() #1

; Function Attrs: argmemonly nounwind
declare void @llvm.lifetime.end.p0i8(i64, i8* nocapture) #1

; Function Attrs: nounwind
declare i32 @printf(i8* nocapture readonly, ...) local_unnamed_addr #2

attributes #0 = { nounwind uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { argmemonly nounwind }
attributes #2 = { nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 5.0.0 (https://github.com/wsmoses/Cilk-Clang.git 2637f015d66418964aa0225534c004dd71a174b8) (git@github.com:wsmoses/Parallel-IR.git 1f09ac94609f7bd432bd139897056ef96f339812)"}
!2 = !{!3, !3, i64 0}
!3 = !{!"int", !4, i64 0}
!4 = !{!"omnipotent char", !5, i64 0}
!5 = !{!"Simple C/C++ TBAA"}
!6 = distinct !{!6, !7, !8, !9}
!7 = !{!"llvm.loop.vectorize.width", i32 1}
!8 = !{!"llvm.loop.interleave.count", i32 1}
!9 = !{!"llvm.loop.unroll.disable"}
!10 = distinct !{!10, !7, !8, !9}
!11 = distinct !{!11, !7, !8, !9, !12}
!12 = !{!"tapir.loop.spawn.strategy", i32 1}
!13 = distinct !{!13, !7, !8, !9, !12}
