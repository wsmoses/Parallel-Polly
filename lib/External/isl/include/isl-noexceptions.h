/// These are automatically generated C++ bindings for isl.
///
///
/// isl is a library for computing with integer sets and maps described by
/// Presburger formula. On top of this, isl provides various tools for
/// Polyhedral compilation ranging from dependence analysis over scheduling
/// to AST generation.
///
///
/// WARNING: Even though these bindings have been throughly tested and the
///          design has been reviewed by various members of the isl community,
///          we do not yet provide any stability guarantees for this interface.
///          We do not expect any larger changes to the interface, but want to
///          reserve the freedom to improve the bindings based on insights that
///          only become visible after shipping these bindings with isl itself.

#ifndef ISL_CPP_NOEXCEPTIONS
#define ISL_CPP_NOEXCEPTIONS

#include <isl/aff.h>
#include <isl/ast_build.h>
#include <isl/flow.h>
#include <isl/id.h>
#include <isl/ilp.h>
#include <isl/map.h>
#include <isl/schedule.h>
#include <isl/schedule_node.h>
#include <isl/set.h>
#include <isl/union_map.h>
#include <isl/union_set.h>
#include <isl/val.h>

#include <functional>
#include <string>

namespace isl {

inline namespace noexceptions {

// forward declarations
class aff;
class ast_build;
class ast_expr;
class ast_node;
class basic_map;
class basic_set;
class id;
class local_space;
class map;
class multi_aff;
class multi_pw_aff;
class multi_union_pw_aff;
class multi_val;
class point;
class pw_aff;
class pw_multi_aff;
class schedule;
class schedule_constraints;
class schedule_node;
class set;
class space;
class union_access_info;
class union_flow;
class union_map;
class union_pw_aff;
class union_pw_multi_aff;
class union_set;
class val;

#define ISLPP_STRINGIZE_(X) #X
#define ISLPP_STRINGIZE(X) ISLPP_STRINGIZE_(X)

#define ISLPP_ASSERT(test, message)                          \
  do {                                                       \
    if (test)                                                \
      break;                                                 \
    fputs("Assertion \"" #test "\" failed at " __FILE__      \
          ":" ISLPP_STRINGIZE(__LINE__) "\n  " message "\n", \
          stderr);                                           \
  } while (0)

class boolean {
private:
  friend boolean manage(isl_bool val);

  isl_bool val;

public:
  boolean()
      : val(isl_bool_error) {}
  /* implicit */ boolean(bool val)
      : val(val ? isl_bool_true : isl_bool_false) {}

  bool is_error() const { return val == isl_bool_error; }
  bool is_false_or_error() const { return val != isl_bool_true; }
  bool is_true_or_error() const { return val != isl_bool_false; }
  bool is_no_error() const { return val != isl_bool_error; }
  bool is_false_no_error() const { return val == isl_bool_false; }
  bool is_true_no_error() const { return val == isl_bool_true; }

  explicit operator bool() const {
    ISLPP_ASSERT(is_no_error(), "IMPLEMENTATION ERROR: Unhandled error state");
    return is_true_no_error();
  }

  boolean operator!() const {
    if (is_error())
      return boolean();
    return !is_true_no_error();
  }
};

inline boolean manage(isl_bool val) {
  return boolean(val);
}

class ctx {
  isl_ctx *ptr;

public:
  ctx(isl_ctx *ctx)
      : ptr(ctx) {}
  isl_ctx *release() {
    auto tmp = ptr;
    ptr = nullptr;
    return tmp;
  }
  isl_ctx *get() {
    return ptr;
  }
};

enum class stat {
  ok = isl_stat_ok,
  error = isl_stat_error,
};

enum class dim {
  cst = isl_dim_cst,
  param = isl_dim_param,
  in = isl_dim_in,
  out = isl_dim_out,
  set = isl_dim_set,
  div = isl_dim_div,
  all = isl_dim_all
};

// declarations for isl::aff
inline aff manage(__isl_take isl_aff *ptr);

inline aff give(__isl_take isl_aff *ptr);

class aff {
  friend inline aff manage(__isl_take isl_aff *ptr);

  isl_aff *ptr = nullptr;

  inline explicit aff(__isl_take isl_aff *ptr);

public:
  inline /* implicit */ aff();
  inline /* implicit */ aff(const aff &obj);
  inline /* implicit */ aff(std::nullptr_t);
  inline explicit aff(local_space ls);
  inline explicit aff(local_space ls, val val);
  inline explicit aff(ctx ctx, const std::string &str);
  inline aff &operator=(aff obj);
  inline ~aff();
  inline __isl_give isl_aff *copy() const &;
  inline __isl_give isl_aff *copy() && = delete;
  inline __isl_keep isl_aff *get() const;
  inline __isl_give isl_aff *release();
  inline __isl_keep isl_aff *keep() const;
  inline __isl_give isl_aff *take();
  inline explicit operator bool() const;
  inline ctx get_ctx() const;
  inline bool is_null() const;
  inline std::string to_str() const;
  inline aff add(aff aff2) const;
  inline val get_constant() const;
  inline boolean is_cst() const;
  inline aff pullback(multi_aff ma) const;
};

// declarations for isl::ast_build
inline ast_build manage(__isl_take isl_ast_build *ptr);

inline ast_build give(__isl_take isl_ast_build *ptr);

class ast_build {
  friend inline ast_build manage(__isl_take isl_ast_build *ptr);

  isl_ast_build *ptr = nullptr;

  inline explicit ast_build(__isl_take isl_ast_build *ptr);

public:
  inline /* implicit */ ast_build();
  inline /* implicit */ ast_build(const ast_build &obj);
  inline /* implicit */ ast_build(std::nullptr_t);
  inline explicit ast_build(ctx ctx);
  inline ast_build &operator=(ast_build obj);
  inline ~ast_build();
  inline __isl_give isl_ast_build *copy() const &;
  inline __isl_give isl_ast_build *copy() && = delete;
  inline __isl_keep isl_ast_build *get() const;
  inline __isl_give isl_ast_build *release();
  inline __isl_keep isl_ast_build *keep() const;
  inline __isl_give isl_ast_build *take();
  inline explicit operator bool() const;
  inline ctx get_ctx() const;
  inline bool is_null() const;
  inline ast_expr access_from(pw_multi_aff pma) const;
  inline ast_expr access_from(multi_pw_aff mpa) const;
  inline ast_expr call_from(pw_multi_aff pma) const;
  inline ast_expr call_from(multi_pw_aff mpa) const;
  inline ast_expr expr_from(set set) const;
  inline ast_expr expr_from(pw_aff pa) const;
  static inline ast_build from_context(set set);
  inline ast_node node_from_schedule_map(union_map schedule) const;
};

// declarations for isl::ast_expr
inline ast_expr manage(__isl_take isl_ast_expr *ptr);

inline ast_expr give(__isl_take isl_ast_expr *ptr);

class ast_expr {
  friend inline ast_expr manage(__isl_take isl_ast_expr *ptr);

  isl_ast_expr *ptr = nullptr;

  inline explicit ast_expr(__isl_take isl_ast_expr *ptr);

public:
  inline /* implicit */ ast_expr();
  inline /* implicit */ ast_expr(const ast_expr &obj);
  inline /* implicit */ ast_expr(std::nullptr_t);
  inline ast_expr &operator=(ast_expr obj);
  inline ~ast_expr();
  inline __isl_give isl_ast_expr *copy() const &;
  inline __isl_give isl_ast_expr *copy() && = delete;
  inline __isl_keep isl_ast_expr *get() const;
  inline __isl_give isl_ast_expr *release();
  inline __isl_keep isl_ast_expr *keep() const;
  inline __isl_give isl_ast_expr *take();
  inline explicit operator bool() const;
  inline ctx get_ctx() const;
  inline bool is_null() const;
  inline std::string to_str() const;
  inline std::string to_C_str() const;
};

// declarations for isl::ast_node
inline ast_node manage(__isl_take isl_ast_node *ptr);

inline ast_node give(__isl_take isl_ast_node *ptr);

class ast_node {
  friend inline ast_node manage(__isl_take isl_ast_node *ptr);

  isl_ast_node *ptr = nullptr;

  inline explicit ast_node(__isl_take isl_ast_node *ptr);

public:
  inline /* implicit */ ast_node();
  inline /* implicit */ ast_node(const ast_node &obj);
  inline /* implicit */ ast_node(std::nullptr_t);
  inline ast_node &operator=(ast_node obj);
  inline ~ast_node();
  inline __isl_give isl_ast_node *copy() const &;
  inline __isl_give isl_ast_node *copy() && = delete;
  inline __isl_keep isl_ast_node *get() const;
  inline __isl_give isl_ast_node *release();
  inline __isl_keep isl_ast_node *keep() const;
  inline __isl_give isl_ast_node *take();
  inline explicit operator bool() const;
  inline ctx get_ctx() const;
  inline bool is_null() const;
  inline std::string to_str() const;
  inline std::string to_C_str() const;
};

// declarations for isl::basic_map
inline basic_map manage(__isl_take isl_basic_map *ptr);

inline basic_map give(__isl_take isl_basic_map *ptr);

class basic_map {
  friend inline basic_map manage(__isl_take isl_basic_map *ptr);

  isl_basic_map *ptr = nullptr;

  inline explicit basic_map(__isl_take isl_basic_map *ptr);

public:
  inline /* implicit */ basic_map();
  inline /* implicit */ basic_map(const basic_map &obj);
  inline /* implicit */ basic_map(std::nullptr_t);
  inline explicit basic_map(ctx ctx, const std::string &str);
  inline basic_map &operator=(basic_map obj);
  inline ~basic_map();
  inline __isl_give isl_basic_map *copy() const &;
  inline __isl_give isl_basic_map *copy() && = delete;
  inline __isl_keep isl_basic_map *get() const;
  inline __isl_give isl_basic_map *release();
  inline __isl_keep isl_basic_map *keep() const;
  inline __isl_give isl_basic_map *take();
  inline explicit operator bool() const;
  inline ctx get_ctx() const;
  inline bool is_null() const;
  inline std::string to_str() const;
  inline basic_map affine_hull() const;
  inline basic_map apply_domain(basic_map bmap2) const;
  inline basic_map apply_range(basic_map bmap2) const;
  inline basic_set deltas() const;
  inline basic_map detect_equalities() const;
  inline basic_map fix_si(enum dim type, unsigned int pos, int value) const;
  inline basic_map flatten() const;
  inline basic_map flatten_domain() const;
  inline basic_map flatten_range() const;
  inline basic_map gist(basic_map context) const;
  inline basic_map intersect(basic_map bmap2) const;
  inline basic_map intersect_domain(basic_set bset) const;
  inline basic_map intersect_range(basic_set bset) const;
  inline boolean is_empty() const;
  inline boolean is_equal(const basic_map &bmap2) const;
  inline boolean is_subset(const basic_map &bmap2) const;
  inline map lexmax() const;
  inline map lexmin() const;
  inline val plain_get_val_if_fixed(enum dim type, unsigned int pos) const;
  inline basic_map project_out(enum dim type, unsigned int first, unsigned int n) const;
  inline basic_map reverse() const;
  inline basic_map sample() const;
  inline map unite(basic_map bmap2) const;
  static inline basic_map universe(space dim);
};

// declarations for isl::basic_set
inline basic_set manage(__isl_take isl_basic_set *ptr);

inline basic_set give(__isl_take isl_basic_set *ptr);

class basic_set {
  friend inline basic_set manage(__isl_take isl_basic_set *ptr);

  isl_basic_set *ptr = nullptr;

  inline explicit basic_set(__isl_take isl_basic_set *ptr);

public:
  inline /* implicit */ basic_set();
  inline /* implicit */ basic_set(const basic_set &obj);
  inline /* implicit */ basic_set(std::nullptr_t);
  inline explicit basic_set(ctx ctx, const std::string &str);
  inline /* implicit */ basic_set(point pnt);
  inline basic_set &operator=(basic_set obj);
  inline ~basic_set();
  inline __isl_give isl_basic_set *copy() const &;
  inline __isl_give isl_basic_set *copy() && = delete;
  inline __isl_keep isl_basic_set *get() const;
  inline __isl_give isl_basic_set *release();
  inline __isl_keep isl_basic_set *keep() const;
  inline __isl_give isl_basic_set *take();
  inline explicit operator bool() const;
  inline ctx get_ctx() const;
  inline bool is_null() const;
  inline std::string to_str() const;
  inline basic_set affine_hull() const;
  inline basic_set apply(basic_map bmap) const;
  inline basic_set detect_equalities() const;
  inline basic_set flatten() const;
  inline basic_set gist(basic_set context) const;
  inline basic_set intersect(basic_set bset2) const;
  inline basic_set intersect_params(basic_set bset2) const;
  inline boolean is_bounded() const;
  inline boolean is_empty() const;
  inline boolean is_equal(const basic_set &bset2) const;
  inline boolean is_subset(const basic_set &bset2) const;
  inline boolean is_wrapping() const;
  inline set lexmax() const;
  inline set lexmin() const;
  inline basic_set project_out(enum dim type, unsigned int first, unsigned int n) const;
  inline basic_set sample() const;
  inline point sample_point() const;
  inline set unite(basic_set bset2) const;
};

// declarations for isl::id
inline id manage(__isl_take isl_id *ptr);

inline id give(__isl_take isl_id *ptr);

class id {
  friend inline id manage(__isl_take isl_id *ptr);

  isl_id *ptr = nullptr;

  inline explicit id(__isl_take isl_id *ptr);

public:
  inline /* implicit */ id();
  inline /* implicit */ id(const id &obj);
  inline /* implicit */ id(std::nullptr_t);
  inline id &operator=(id obj);
  inline ~id();
  inline __isl_give isl_id *copy() const &;
  inline __isl_give isl_id *copy() && = delete;
  inline __isl_keep isl_id *get() const;
  inline __isl_give isl_id *release();
  inline __isl_keep isl_id *keep() const;
  inline __isl_give isl_id *take();
  inline explicit operator bool() const;
  inline ctx get_ctx() const;
  inline bool is_null() const;
  inline std::string to_str() const;
};

// declarations for isl::local_space
inline local_space manage(__isl_take isl_local_space *ptr);

inline local_space give(__isl_take isl_local_space *ptr);

class local_space {
  friend inline local_space manage(__isl_take isl_local_space *ptr);

  isl_local_space *ptr = nullptr;

  inline explicit local_space(__isl_take isl_local_space *ptr);

public:
  inline /* implicit */ local_space();
  inline /* implicit */ local_space(const local_space &obj);
  inline /* implicit */ local_space(std::nullptr_t);
  inline explicit local_space(space dim);
  inline local_space &operator=(local_space obj);
  inline ~local_space();
  inline __isl_give isl_local_space *copy() const &;
  inline __isl_give isl_local_space *copy() && = delete;
  inline __isl_keep isl_local_space *get() const;
  inline __isl_give isl_local_space *release();
  inline __isl_keep isl_local_space *keep() const;
  inline __isl_give isl_local_space *take();
  inline explicit operator bool() const;
  inline ctx get_ctx() const;
  inline bool is_null() const;
};

// declarations for isl::map
inline map manage(__isl_take isl_map *ptr);

inline map give(__isl_take isl_map *ptr);

class map {
  friend inline map manage(__isl_take isl_map *ptr);

  isl_map *ptr = nullptr;

  inline explicit map(__isl_take isl_map *ptr);

public:
  inline /* implicit */ map();
  inline /* implicit */ map(const map &obj);
  inline /* implicit */ map(std::nullptr_t);
  inline explicit map(ctx ctx, const std::string &str);
  inline /* implicit */ map(basic_map bmap);
  inline map &operator=(map obj);
  inline ~map();
  inline __isl_give isl_map *copy() const &;
  inline __isl_give isl_map *copy() && = delete;
  inline __isl_keep isl_map *get() const;
  inline __isl_give isl_map *release();
  inline __isl_keep isl_map *keep() const;
  inline __isl_give isl_map *take();
  inline explicit operator bool() const;
  inline ctx get_ctx() const;
  inline bool is_null() const;
  inline std::string to_str() const;
  inline basic_map affine_hull() const;
  inline map apply_domain(map map2) const;
  inline map apply_range(map map2) const;
  inline map coalesce() const;
  inline map complement() const;
  inline set deltas() const;
  inline map detect_equalities() const;
  inline unsigned int dim(enum dim type) const;
  inline pw_aff dim_max(int pos) const;
  inline pw_aff dim_min(int pos) const;
  inline map flatten() const;
  inline map flatten_domain() const;
  inline map flatten_range() const;
  inline stat foreach_basic_map(std::function<stat(basic_map)> &&fn) const;
  static inline map from_range(set set);
  inline map gist(map context) const;
  inline map gist_domain(set context) const;
  inline map intersect(map map2) const;
  inline map intersect_domain(set set) const;
  inline map intersect_params(set params) const;
  inline map intersect_range(set set) const;
  inline boolean is_bijective() const;
  inline boolean is_disjoint(const map &map2) const;
  inline boolean is_empty() const;
  inline boolean is_equal(const map &map2) const;
  inline boolean is_injective() const;
  inline boolean is_single_valued() const;
  inline boolean is_strict_subset(const map &map2) const;
  inline boolean is_subset(const map &map2) const;
  inline map lexmax() const;
  inline map lexmin() const;
  inline basic_map polyhedral_hull() const;
  inline map project_out(enum dim type, unsigned int first, unsigned int n) const;
  inline map reverse() const;
  inline basic_map sample() const;
  inline map subtract(map map2) const;
  inline map unite(map map2) const;
  inline basic_map unshifted_simple_hull() const;
};

// declarations for isl::multi_aff
inline multi_aff manage(__isl_take isl_multi_aff *ptr);

inline multi_aff give(__isl_take isl_multi_aff *ptr);

class multi_aff {
  friend inline multi_aff manage(__isl_take isl_multi_aff *ptr);

  isl_multi_aff *ptr = nullptr;

  inline explicit multi_aff(__isl_take isl_multi_aff *ptr);

public:
  inline /* implicit */ multi_aff();
  inline /* implicit */ multi_aff(const multi_aff &obj);
  inline /* implicit */ multi_aff(std::nullptr_t);
  inline /* implicit */ multi_aff(aff aff);
  inline explicit multi_aff(ctx ctx, const std::string &str);
  inline multi_aff &operator=(multi_aff obj);
  inline ~multi_aff();
  inline __isl_give isl_multi_aff *copy() const &;
  inline __isl_give isl_multi_aff *copy() && = delete;
  inline __isl_keep isl_multi_aff *get() const;
  inline __isl_give isl_multi_aff *release();
  inline __isl_keep isl_multi_aff *keep() const;
  inline __isl_give isl_multi_aff *take();
  inline explicit operator bool() const;
  inline ctx get_ctx() const;
  inline bool is_null() const;
  inline std::string to_str() const;
  inline multi_aff add(multi_aff multi2) const;
  inline multi_aff flat_range_product(multi_aff multi2) const;
  inline aff get_aff(int pos) const;
  inline multi_aff product(multi_aff multi2) const;
  inline multi_aff pullback(multi_aff ma2) const;
  inline multi_aff range_product(multi_aff multi2) const;
};

// declarations for isl::multi_pw_aff
inline multi_pw_aff manage(__isl_take isl_multi_pw_aff *ptr);

inline multi_pw_aff give(__isl_take isl_multi_pw_aff *ptr);

class multi_pw_aff {
  friend inline multi_pw_aff manage(__isl_take isl_multi_pw_aff *ptr);

  isl_multi_pw_aff *ptr = nullptr;

  inline explicit multi_pw_aff(__isl_take isl_multi_pw_aff *ptr);

public:
  inline /* implicit */ multi_pw_aff();
  inline /* implicit */ multi_pw_aff(const multi_pw_aff &obj);
  inline /* implicit */ multi_pw_aff(std::nullptr_t);
  inline /* implicit */ multi_pw_aff(multi_aff ma);
  inline /* implicit */ multi_pw_aff(pw_aff pa);
  inline /* implicit */ multi_pw_aff(pw_multi_aff pma);
  inline explicit multi_pw_aff(ctx ctx, const std::string &str);
  inline multi_pw_aff &operator=(multi_pw_aff obj);
  inline ~multi_pw_aff();
  inline __isl_give isl_multi_pw_aff *copy() const &;
  inline __isl_give isl_multi_pw_aff *copy() && = delete;
  inline __isl_keep isl_multi_pw_aff *get() const;
  inline __isl_give isl_multi_pw_aff *release();
  inline __isl_keep isl_multi_pw_aff *keep() const;
  inline __isl_give isl_multi_pw_aff *take();
  inline explicit operator bool() const;
  inline ctx get_ctx() const;
  inline bool is_null() const;
  inline std::string to_str() const;
  inline multi_pw_aff add(multi_pw_aff multi2) const;
  inline multi_pw_aff flat_range_product(multi_pw_aff multi2) const;
  inline pw_aff get_pw_aff(int pos) const;
  inline multi_pw_aff product(multi_pw_aff multi2) const;
  inline multi_pw_aff pullback(multi_aff ma) const;
  inline multi_pw_aff pullback(pw_multi_aff pma) const;
  inline multi_pw_aff pullback(multi_pw_aff mpa2) const;
  inline multi_pw_aff range_product(multi_pw_aff multi2) const;
};

// declarations for isl::multi_union_pw_aff
inline multi_union_pw_aff manage(__isl_take isl_multi_union_pw_aff *ptr);

inline multi_union_pw_aff give(__isl_take isl_multi_union_pw_aff *ptr);

class multi_union_pw_aff {
  friend inline multi_union_pw_aff manage(__isl_take isl_multi_union_pw_aff *ptr);

  isl_multi_union_pw_aff *ptr = nullptr;

  inline explicit multi_union_pw_aff(__isl_take isl_multi_union_pw_aff *ptr);

public:
  inline /* implicit */ multi_union_pw_aff();
  inline /* implicit */ multi_union_pw_aff(const multi_union_pw_aff &obj);
  inline /* implicit */ multi_union_pw_aff(std::nullptr_t);
  inline /* implicit */ multi_union_pw_aff(union_pw_aff upa);
  inline /* implicit */ multi_union_pw_aff(multi_pw_aff mpa);
  inline explicit multi_union_pw_aff(union_pw_multi_aff upma);
  inline explicit multi_union_pw_aff(ctx ctx, const std::string &str);
  inline multi_union_pw_aff &operator=(multi_union_pw_aff obj);
  inline ~multi_union_pw_aff();
  inline __isl_give isl_multi_union_pw_aff *copy() const &;
  inline __isl_give isl_multi_union_pw_aff *copy() && = delete;
  inline __isl_keep isl_multi_union_pw_aff *get() const;
  inline __isl_give isl_multi_union_pw_aff *release();
  inline __isl_keep isl_multi_union_pw_aff *keep() const;
  inline __isl_give isl_multi_union_pw_aff *take();
  inline explicit operator bool() const;
  inline ctx get_ctx() const;
  inline bool is_null() const;
  inline std::string to_str() const;
  inline multi_union_pw_aff add(multi_union_pw_aff multi2) const;
  inline multi_union_pw_aff flat_range_product(multi_union_pw_aff multi2) const;
  inline union_pw_aff get_union_pw_aff(int pos) const;
  inline multi_union_pw_aff pullback(union_pw_multi_aff upma) const;
  inline multi_union_pw_aff range_product(multi_union_pw_aff multi2) const;
  inline multi_union_pw_aff union_add(multi_union_pw_aff mupa2) const;
};

// declarations for isl::multi_val
inline multi_val manage(__isl_take isl_multi_val *ptr);

inline multi_val give(__isl_take isl_multi_val *ptr);

class multi_val {
  friend inline multi_val manage(__isl_take isl_multi_val *ptr);

  isl_multi_val *ptr = nullptr;

  inline explicit multi_val(__isl_take isl_multi_val *ptr);

public:
  inline /* implicit */ multi_val();
  inline /* implicit */ multi_val(const multi_val &obj);
  inline /* implicit */ multi_val(std::nullptr_t);
  inline multi_val &operator=(multi_val obj);
  inline ~multi_val();
  inline __isl_give isl_multi_val *copy() const &;
  inline __isl_give isl_multi_val *copy() && = delete;
  inline __isl_keep isl_multi_val *get() const;
  inline __isl_give isl_multi_val *release();
  inline __isl_keep isl_multi_val *keep() const;
  inline __isl_give isl_multi_val *take();
  inline explicit operator bool() const;
  inline ctx get_ctx() const;
  inline bool is_null() const;
  inline std::string to_str() const;
  inline multi_val add(multi_val multi2) const;
  inline multi_val flat_range_product(multi_val multi2) const;
  inline val get_val(int pos) const;
  inline multi_val product(multi_val multi2) const;
  inline multi_val range_product(multi_val multi2) const;
};

// declarations for isl::point
inline point manage(__isl_take isl_point *ptr);

inline point give(__isl_take isl_point *ptr);

class point {
  friend inline point manage(__isl_take isl_point *ptr);

  isl_point *ptr = nullptr;

  inline explicit point(__isl_take isl_point *ptr);

public:
  inline /* implicit */ point();
  inline /* implicit */ point(const point &obj);
  inline /* implicit */ point(std::nullptr_t);
  inline explicit point(space dim);
  inline point &operator=(point obj);
  inline ~point();
  inline __isl_give isl_point *copy() const &;
  inline __isl_give isl_point *copy() && = delete;
  inline __isl_keep isl_point *get() const;
  inline __isl_give isl_point *release();
  inline __isl_keep isl_point *keep() const;
  inline __isl_give isl_point *take();
  inline explicit operator bool() const;
  inline ctx get_ctx() const;
  inline bool is_null() const;
  inline std::string to_str() const;
};

// declarations for isl::pw_aff
inline pw_aff manage(__isl_take isl_pw_aff *ptr);

inline pw_aff give(__isl_take isl_pw_aff *ptr);

class pw_aff {
  friend inline pw_aff manage(__isl_take isl_pw_aff *ptr);

  isl_pw_aff *ptr = nullptr;

  inline explicit pw_aff(__isl_take isl_pw_aff *ptr);

public:
  inline /* implicit */ pw_aff();
  inline /* implicit */ pw_aff(const pw_aff &obj);
  inline /* implicit */ pw_aff(std::nullptr_t);
  inline /* implicit */ pw_aff(aff aff);
  inline explicit pw_aff(local_space ls);
  inline explicit pw_aff(set domain, val v);
  inline explicit pw_aff(ctx ctx, const std::string &str);
  inline pw_aff &operator=(pw_aff obj);
  inline ~pw_aff();
  inline __isl_give isl_pw_aff *copy() const &;
  inline __isl_give isl_pw_aff *copy() && = delete;
  inline __isl_keep isl_pw_aff *get() const;
  inline __isl_give isl_pw_aff *release();
  inline __isl_keep isl_pw_aff *keep() const;
  inline __isl_give isl_pw_aff *take();
  inline explicit operator bool() const;
  inline ctx get_ctx() const;
  inline bool is_null() const;
  inline std::string to_str() const;
  inline pw_aff add(pw_aff pwaff2) const;
  inline stat foreach_piece(std::function<stat(set, aff)> &&fn) const;
  inline space get_space() const;
  inline boolean is_cst() const;
  inline pw_aff mul(pw_aff pwaff2) const;
  inline pw_aff neg() const;
  inline pw_aff pullback(multi_aff ma) const;
  inline pw_aff pullback(pw_multi_aff pma) const;
  inline pw_aff pullback(multi_pw_aff mpa) const;
  inline pw_aff sub(pw_aff pwaff2) const;
  inline pw_aff union_add(pw_aff pwaff2) const;
};

// declarations for isl::pw_multi_aff
inline pw_multi_aff manage(__isl_take isl_pw_multi_aff *ptr);

inline pw_multi_aff give(__isl_take isl_pw_multi_aff *ptr);

class pw_multi_aff {
  friend inline pw_multi_aff manage(__isl_take isl_pw_multi_aff *ptr);

  isl_pw_multi_aff *ptr = nullptr;

  inline explicit pw_multi_aff(__isl_take isl_pw_multi_aff *ptr);

public:
  inline /* implicit */ pw_multi_aff();
  inline /* implicit */ pw_multi_aff(const pw_multi_aff &obj);
  inline /* implicit */ pw_multi_aff(std::nullptr_t);
  inline explicit pw_multi_aff(ctx ctx, const std::string &str);
  inline /* implicit */ pw_multi_aff(multi_aff ma);
  inline /* implicit */ pw_multi_aff(pw_aff pa);
  inline pw_multi_aff &operator=(pw_multi_aff obj);
  inline ~pw_multi_aff();
  inline __isl_give isl_pw_multi_aff *copy() const &;
  inline __isl_give isl_pw_multi_aff *copy() && = delete;
  inline __isl_keep isl_pw_multi_aff *get() const;
  inline __isl_give isl_pw_multi_aff *release();
  inline __isl_keep isl_pw_multi_aff *keep() const;
  inline __isl_give isl_pw_multi_aff *take();
  inline explicit operator bool() const;
  inline ctx get_ctx() const;
  inline bool is_null() const;
  inline std::string to_str() const;
  inline pw_multi_aff add(pw_multi_aff pma2) const;
  inline pw_multi_aff flat_range_product(pw_multi_aff pma2) const;
  inline pw_multi_aff product(pw_multi_aff pma2) const;
  inline pw_multi_aff pullback(multi_aff ma) const;
  inline pw_multi_aff pullback(pw_multi_aff pma2) const;
  inline pw_multi_aff range_product(pw_multi_aff pma2) const;
  inline pw_multi_aff union_add(pw_multi_aff pma2) const;
};

// declarations for isl::schedule
inline schedule manage(__isl_take isl_schedule *ptr);

inline schedule give(__isl_take isl_schedule *ptr);

class schedule {
  friend inline schedule manage(__isl_take isl_schedule *ptr);

  isl_schedule *ptr = nullptr;

  inline explicit schedule(__isl_take isl_schedule *ptr);

public:
  inline /* implicit */ schedule();
  inline /* implicit */ schedule(const schedule &obj);
  inline /* implicit */ schedule(std::nullptr_t);
  inline explicit schedule(ctx ctx, const std::string &str);
  inline schedule &operator=(schedule obj);
  inline ~schedule();
  inline __isl_give isl_schedule *copy() const &;
  inline __isl_give isl_schedule *copy() && = delete;
  inline __isl_keep isl_schedule *get() const;
  inline __isl_give isl_schedule *release();
  inline __isl_keep isl_schedule *keep() const;
  inline __isl_give isl_schedule *take();
  inline explicit operator bool() const;
  inline ctx get_ctx() const;
  inline bool is_null() const;
  inline std::string to_str() const;
  inline union_map get_map() const;
  inline schedule_node get_root() const;
  inline schedule pullback(union_pw_multi_aff upma) const;
};

// declarations for isl::schedule_constraints
inline schedule_constraints manage(__isl_take isl_schedule_constraints *ptr);

inline schedule_constraints give(__isl_take isl_schedule_constraints *ptr);

class schedule_constraints {
  friend inline schedule_constraints manage(__isl_take isl_schedule_constraints *ptr);

  isl_schedule_constraints *ptr = nullptr;

  inline explicit schedule_constraints(__isl_take isl_schedule_constraints *ptr);

public:
  inline /* implicit */ schedule_constraints();
  inline /* implicit */ schedule_constraints(const schedule_constraints &obj);
  inline /* implicit */ schedule_constraints(std::nullptr_t);
  inline explicit schedule_constraints(ctx ctx, const std::string &str);
  inline schedule_constraints &operator=(schedule_constraints obj);
  inline ~schedule_constraints();
  inline __isl_give isl_schedule_constraints *copy() const &;
  inline __isl_give isl_schedule_constraints *copy() && = delete;
  inline __isl_keep isl_schedule_constraints *get() const;
  inline __isl_give isl_schedule_constraints *release();
  inline __isl_keep isl_schedule_constraints *keep() const;
  inline __isl_give isl_schedule_constraints *take();
  inline explicit operator bool() const;
  inline ctx get_ctx() const;
  inline bool is_null() const;
  inline std::string to_str() const;
  inline union_map get_coincidence() const;
  inline union_map get_conditional_validity() const;
  inline union_map get_conditional_validity_condition() const;
  inline set get_context() const;
  inline union_set get_domain() const;
  inline union_map get_proximity() const;
  inline union_map get_validity() const;
};

// declarations for isl::schedule_node
inline schedule_node manage(__isl_take isl_schedule_node *ptr);

inline schedule_node give(__isl_take isl_schedule_node *ptr);

class schedule_node {
  friend inline schedule_node manage(__isl_take isl_schedule_node *ptr);

  isl_schedule_node *ptr = nullptr;

  inline explicit schedule_node(__isl_take isl_schedule_node *ptr);

public:
  inline /* implicit */ schedule_node();
  inline /* implicit */ schedule_node(const schedule_node &obj);
  inline /* implicit */ schedule_node(std::nullptr_t);
  inline schedule_node &operator=(schedule_node obj);
  inline ~schedule_node();
  inline __isl_give isl_schedule_node *copy() const &;
  inline __isl_give isl_schedule_node *copy() && = delete;
  inline __isl_keep isl_schedule_node *get() const;
  inline __isl_give isl_schedule_node *release();
  inline __isl_keep isl_schedule_node *keep() const;
  inline __isl_give isl_schedule_node *take();
  inline explicit operator bool() const;
  inline ctx get_ctx() const;
  inline bool is_null() const;
  inline std::string to_str() const;
  inline boolean band_member_get_coincident(int pos) const;
  inline schedule_node band_member_set_coincident(int pos, int coincident) const;
  inline schedule_node child(int pos) const;
  inline multi_union_pw_aff get_prefix_schedule_multi_union_pw_aff() const;
  inline union_map get_prefix_schedule_union_map() const;
  inline union_pw_multi_aff get_prefix_schedule_union_pw_multi_aff() const;
  inline schedule get_schedule() const;
  inline schedule_node parent() const;
};

// declarations for isl::set
inline set manage(__isl_take isl_set *ptr);

inline set give(__isl_take isl_set *ptr);

class set {
  friend inline set manage(__isl_take isl_set *ptr);

  isl_set *ptr = nullptr;

  inline explicit set(__isl_take isl_set *ptr);

public:
  inline /* implicit */ set();
  inline /* implicit */ set(const set &obj);
  inline /* implicit */ set(std::nullptr_t);
  inline explicit set(union_set uset);
  inline explicit set(ctx ctx, const std::string &str);
  inline /* implicit */ set(basic_set bset);
  inline /* implicit */ set(point pnt);
  inline set &operator=(set obj);
  inline ~set();
  inline __isl_give isl_set *copy() const &;
  inline __isl_give isl_set *copy() && = delete;
  inline __isl_keep isl_set *get() const;
  inline __isl_give isl_set *release();
  inline __isl_keep isl_set *keep() const;
  inline __isl_give isl_set *take();
  inline explicit operator bool() const;
  inline ctx get_ctx() const;
  inline bool is_null() const;
  inline std::string to_str() const;
  inline set add_dims(enum dim type, unsigned int n) const;
  inline basic_set affine_hull() const;
  inline set apply(map map) const;
  inline set coalesce() const;
  inline set complement() const;
  inline set detect_equalities() const;
  inline unsigned int dim(enum dim type) const;
  inline pw_aff dim_max(int pos) const;
  inline pw_aff dim_min(int pos) const;
  inline set flatten() const;
  inline stat foreach_basic_set(std::function<stat(basic_set)> &&fn) const;
  inline set gist(set context) const;
  inline map identity() const;
  inline set intersect(set set2) const;
  inline set intersect_params(set params) const;
  inline boolean is_bounded() const;
  inline boolean is_disjoint(const set &set2) const;
  inline boolean is_empty() const;
  inline boolean is_equal(const set &set2) const;
  inline boolean is_strict_subset(const set &set2) const;
  inline boolean is_subset(const set &set2) const;
  inline boolean is_wrapping() const;
  inline set lexmax() const;
  inline set lexmin() const;
  inline val max_val(const aff &obj) const;
  inline val min_val(const aff &obj) const;
  inline basic_set polyhedral_hull() const;
  inline set project_out(enum dim type, unsigned int first, unsigned int n) const;
  inline basic_set sample() const;
  inline point sample_point() const;
  inline set subtract(set set2) const;
  inline set unite(set set2) const;
  static inline set universe(space dim);
  inline basic_set unshifted_simple_hull() const;
};

// declarations for isl::space
inline space manage(__isl_take isl_space *ptr);

inline space give(__isl_take isl_space *ptr);

class space {
  friend inline space manage(__isl_take isl_space *ptr);

  isl_space *ptr = nullptr;

  inline explicit space(__isl_take isl_space *ptr);

public:
  inline /* implicit */ space();
  inline /* implicit */ space(const space &obj);
  inline /* implicit */ space(std::nullptr_t);
  inline explicit space(ctx ctx, unsigned int nparam, unsigned int n_in, unsigned int n_out);
  inline explicit space(ctx ctx, unsigned int nparam, unsigned int dim);
  inline space &operator=(space obj);
  inline ~space();
  inline __isl_give isl_space *copy() const &;
  inline __isl_give isl_space *copy() && = delete;
  inline __isl_keep isl_space *get() const;
  inline __isl_give isl_space *release();
  inline __isl_keep isl_space *keep() const;
  inline __isl_give isl_space *take();
  inline explicit operator bool() const;
  inline ctx get_ctx() const;
  inline bool is_null() const;
  inline std::string to_str() const;
  inline space domain() const;
  inline boolean is_equal(const space &space2) const;
  inline space params() const;
  inline space set_from_params() const;
};

// declarations for isl::union_access_info
inline union_access_info manage(__isl_take isl_union_access_info *ptr);

inline union_access_info give(__isl_take isl_union_access_info *ptr);

class union_access_info {
  friend inline union_access_info manage(__isl_take isl_union_access_info *ptr);

  isl_union_access_info *ptr = nullptr;

  inline explicit union_access_info(__isl_take isl_union_access_info *ptr);

public:
  inline /* implicit */ union_access_info();
  inline /* implicit */ union_access_info(const union_access_info &obj);
  inline /* implicit */ union_access_info(std::nullptr_t);
  inline explicit union_access_info(union_map sink);
  inline union_access_info &operator=(union_access_info obj);
  inline ~union_access_info();
  inline __isl_give isl_union_access_info *copy() const &;
  inline __isl_give isl_union_access_info *copy() && = delete;
  inline __isl_keep isl_union_access_info *get() const;
  inline __isl_give isl_union_access_info *release();
  inline __isl_keep isl_union_access_info *keep() const;
  inline __isl_give isl_union_access_info *take();
  inline explicit operator bool() const;
  inline ctx get_ctx() const;
  inline bool is_null() const;
  inline std::string to_str() const;
  inline union_flow compute_flow() const;
  inline union_access_info set_may_source(union_map may_source) const;
  inline union_access_info set_must_source(union_map must_source) const;
  inline union_access_info set_schedule(schedule schedule) const;
  inline union_access_info set_schedule_map(union_map schedule_map) const;
};

// declarations for isl::union_flow
inline union_flow manage(__isl_take isl_union_flow *ptr);

inline union_flow give(__isl_take isl_union_flow *ptr);

class union_flow {
  friend inline union_flow manage(__isl_take isl_union_flow *ptr);

  isl_union_flow *ptr = nullptr;

  inline explicit union_flow(__isl_take isl_union_flow *ptr);

public:
  inline /* implicit */ union_flow();
  inline /* implicit */ union_flow(const union_flow &obj);
  inline /* implicit */ union_flow(std::nullptr_t);
  inline union_flow &operator=(union_flow obj);
  inline ~union_flow();
  inline __isl_give isl_union_flow *copy() const &;
  inline __isl_give isl_union_flow *copy() && = delete;
  inline __isl_keep isl_union_flow *get() const;
  inline __isl_give isl_union_flow *release();
  inline __isl_keep isl_union_flow *keep() const;
  inline __isl_give isl_union_flow *take();
  inline explicit operator bool() const;
  inline ctx get_ctx() const;
  inline bool is_null() const;
  inline std::string to_str() const;
  inline union_map get_full_may_dependence() const;
  inline union_map get_full_must_dependence() const;
  inline union_map get_may_dependence() const;
  inline union_map get_may_no_source() const;
  inline union_map get_must_dependence() const;
  inline union_map get_must_no_source() const;
};

// declarations for isl::union_map
inline union_map manage(__isl_take isl_union_map *ptr);

inline union_map give(__isl_take isl_union_map *ptr);

class union_map {
  friend inline union_map manage(__isl_take isl_union_map *ptr);

  isl_union_map *ptr = nullptr;

  inline explicit union_map(__isl_take isl_union_map *ptr);

public:
  inline /* implicit */ union_map();
  inline /* implicit */ union_map(const union_map &obj);
  inline /* implicit */ union_map(std::nullptr_t);
  inline explicit union_map(union_pw_aff upa);
  inline /* implicit */ union_map(basic_map bmap);
  inline /* implicit */ union_map(map map);
  inline explicit union_map(ctx ctx, const std::string &str);
  inline union_map &operator=(union_map obj);
  inline ~union_map();
  inline __isl_give isl_union_map *copy() const &;
  inline __isl_give isl_union_map *copy() && = delete;
  inline __isl_keep isl_union_map *get() const;
  inline __isl_give isl_union_map *release();
  inline __isl_keep isl_union_map *keep() const;
  inline __isl_give isl_union_map *take();
  inline explicit operator bool() const;
  inline ctx get_ctx() const;
  inline bool is_null() const;
  inline std::string to_str() const;
  inline union_map add_map(map map) const;
  inline union_map affine_hull() const;
  inline union_map apply_domain(union_map umap2) const;
  inline union_map apply_range(union_map umap2) const;
  inline union_map coalesce() const;
  inline union_map compute_divs() const;
  inline union_set deltas() const;
  inline union_map detect_equalities() const;
  inline union_set domain() const;
  inline union_map domain_factor_domain() const;
  inline union_map domain_factor_range() const;
  inline union_map domain_map() const;
  inline union_pw_multi_aff domain_map_union_pw_multi_aff() const;
  inline union_map domain_product(union_map umap2) const;
  static inline union_map empty(space dim);
  inline union_map factor_domain() const;
  inline union_map factor_range() const;
  inline union_map fixed_power(val exp) const;
  inline union_map flat_range_product(union_map umap2) const;
  inline stat foreach_map(std::function<stat(map)> &&fn) const;
  static inline union_map from(union_pw_multi_aff upma);
  static inline union_map from(multi_union_pw_aff mupa);
  static inline union_map from_domain_and_range(union_set domain, union_set range);
  inline space get_space() const;
  inline union_map gist(union_map context) const;
  inline union_map gist_domain(union_set uset) const;
  inline union_map gist_params(set set) const;
  inline union_map gist_range(union_set uset) const;
  inline union_map intersect(union_map umap2) const;
  inline union_map intersect_domain(union_set uset) const;
  inline union_map intersect_params(set set) const;
  inline union_map intersect_range(union_set uset) const;
  inline boolean is_bijective() const;
  inline boolean is_empty() const;
  inline boolean is_equal(const union_map &umap2) const;
  inline boolean is_injective() const;
  inline boolean is_single_valued() const;
  inline boolean is_strict_subset(const union_map &umap2) const;
  inline boolean is_subset(const union_map &umap2) const;
  inline union_map lexmax() const;
  inline union_map lexmin() const;
  inline union_map polyhedral_hull() const;
  inline union_map product(union_map umap2) const;
  inline union_set range() const;
  inline union_map range_factor_domain() const;
  inline union_map range_factor_range() const;
  inline union_map range_map() const;
  inline union_map range_product(union_map umap2) const;
  inline union_map reverse() const;
  inline union_map subtract(union_map umap2) const;
  inline union_map subtract_domain(union_set dom) const;
  inline union_map subtract_range(union_set dom) const;
  inline union_map unite(union_map umap2) const;
  inline union_set wrap() const;
  inline union_map zip() const;
};

// declarations for isl::union_pw_aff
inline union_pw_aff manage(__isl_take isl_union_pw_aff *ptr);

inline union_pw_aff give(__isl_take isl_union_pw_aff *ptr);

class union_pw_aff {
  friend inline union_pw_aff manage(__isl_take isl_union_pw_aff *ptr);

  isl_union_pw_aff *ptr = nullptr;

  inline explicit union_pw_aff(__isl_take isl_union_pw_aff *ptr);

public:
  inline /* implicit */ union_pw_aff();
  inline /* implicit */ union_pw_aff(const union_pw_aff &obj);
  inline /* implicit */ union_pw_aff(std::nullptr_t);
  inline /* implicit */ union_pw_aff(pw_aff pa);
  inline explicit union_pw_aff(union_set domain, val v);
  inline explicit union_pw_aff(ctx ctx, const std::string &str);
  inline union_pw_aff &operator=(union_pw_aff obj);
  inline ~union_pw_aff();
  inline __isl_give isl_union_pw_aff *copy() const &;
  inline __isl_give isl_union_pw_aff *copy() && = delete;
  inline __isl_keep isl_union_pw_aff *get() const;
  inline __isl_give isl_union_pw_aff *release();
  inline __isl_keep isl_union_pw_aff *keep() const;
  inline __isl_give isl_union_pw_aff *take();
  inline explicit operator bool() const;
  inline ctx get_ctx() const;
  inline bool is_null() const;
  inline std::string to_str() const;
  inline union_pw_aff add(union_pw_aff upa2) const;
  static inline union_pw_aff empty(space space);
  inline stat foreach_pw_aff(std::function<stat(pw_aff)> &&fn) const;
  inline space get_space() const;
  inline union_pw_aff pullback(union_pw_multi_aff upma) const;
  inline union_pw_aff sub(union_pw_aff upa2) const;
  inline union_pw_aff union_add(union_pw_aff upa2) const;
};

// declarations for isl::union_pw_multi_aff
inline union_pw_multi_aff manage(__isl_take isl_union_pw_multi_aff *ptr);

inline union_pw_multi_aff give(__isl_take isl_union_pw_multi_aff *ptr);

class union_pw_multi_aff {
  friend inline union_pw_multi_aff manage(__isl_take isl_union_pw_multi_aff *ptr);

  isl_union_pw_multi_aff *ptr = nullptr;

  inline explicit union_pw_multi_aff(__isl_take isl_union_pw_multi_aff *ptr);

public:
  inline /* implicit */ union_pw_multi_aff();
  inline /* implicit */ union_pw_multi_aff(const union_pw_multi_aff &obj);
  inline /* implicit */ union_pw_multi_aff(std::nullptr_t);
  inline /* implicit */ union_pw_multi_aff(pw_multi_aff pma);
  inline explicit union_pw_multi_aff(union_set uset);
  inline explicit union_pw_multi_aff(union_map umap);
  inline explicit union_pw_multi_aff(ctx ctx, const std::string &str);
  inline /* implicit */ union_pw_multi_aff(union_pw_aff upa);
  inline union_pw_multi_aff &operator=(union_pw_multi_aff obj);
  inline ~union_pw_multi_aff();
  inline __isl_give isl_union_pw_multi_aff *copy() const &;
  inline __isl_give isl_union_pw_multi_aff *copy() && = delete;
  inline __isl_keep isl_union_pw_multi_aff *get() const;
  inline __isl_give isl_union_pw_multi_aff *release();
  inline __isl_keep isl_union_pw_multi_aff *keep() const;
  inline __isl_give isl_union_pw_multi_aff *take();
  inline explicit operator bool() const;
  inline ctx get_ctx() const;
  inline bool is_null() const;
  inline std::string to_str() const;
  inline union_pw_multi_aff add(union_pw_multi_aff upma2) const;
  inline union_pw_multi_aff flat_range_product(union_pw_multi_aff upma2) const;
  inline union_pw_multi_aff pullback(union_pw_multi_aff upma2) const;
  inline union_pw_multi_aff union_add(union_pw_multi_aff upma2) const;
};

// declarations for isl::union_set
inline union_set manage(__isl_take isl_union_set *ptr);

inline union_set give(__isl_take isl_union_set *ptr);

class union_set {
  friend inline union_set manage(__isl_take isl_union_set *ptr);

  isl_union_set *ptr = nullptr;

  inline explicit union_set(__isl_take isl_union_set *ptr);

public:
  inline /* implicit */ union_set();
  inline /* implicit */ union_set(const union_set &obj);
  inline /* implicit */ union_set(std::nullptr_t);
  inline /* implicit */ union_set(basic_set bset);
  inline /* implicit */ union_set(set set);
  inline /* implicit */ union_set(point pnt);
  inline explicit union_set(ctx ctx, const std::string &str);
  inline union_set &operator=(union_set obj);
  inline ~union_set();
  inline __isl_give isl_union_set *copy() const &;
  inline __isl_give isl_union_set *copy() && = delete;
  inline __isl_keep isl_union_set *get() const;
  inline __isl_give isl_union_set *release();
  inline __isl_keep isl_union_set *keep() const;
  inline __isl_give isl_union_set *take();
  inline explicit operator bool() const;
  inline ctx get_ctx() const;
  inline bool is_null() const;
  inline std::string to_str() const;
  inline union_set affine_hull() const;
  inline union_set apply(union_map umap) const;
  inline union_set coalesce() const;
  inline union_set compute_divs() const;
  inline union_set detect_equalities() const;
  inline stat foreach_point(std::function<stat(point)> &&fn) const;
  inline stat foreach_set(std::function<stat(set)> &&fn) const;
  inline union_set gist(union_set context) const;
  inline union_set gist_params(set set) const;
  inline union_map identity() const;
  inline union_set intersect(union_set uset2) const;
  inline union_set intersect_params(set set) const;
  inline boolean is_empty() const;
  inline boolean is_equal(const union_set &uset2) const;
  inline boolean is_strict_subset(const union_set &uset2) const;
  inline boolean is_subset(const union_set &uset2) const;
  inline union_set lexmax() const;
  inline union_set lexmin() const;
  inline union_set polyhedral_hull() const;
  inline point sample_point() const;
  inline union_set subtract(union_set uset2) const;
  inline union_set unite(union_set uset2) const;
  inline union_map unwrap() const;
};

// declarations for isl::val
inline val manage(__isl_take isl_val *ptr);

inline val give(__isl_take isl_val *ptr);

class val {
  friend inline val manage(__isl_take isl_val *ptr);

  isl_val *ptr = nullptr;

  inline explicit val(__isl_take isl_val *ptr);

public:
  inline /* implicit */ val();
  inline /* implicit */ val(const val &obj);
  inline /* implicit */ val(std::nullptr_t);
  inline explicit val(ctx ctx, long i);
  inline explicit val(ctx ctx, const std::string &str);
  inline val &operator=(val obj);
  inline ~val();
  inline __isl_give isl_val *copy() const &;
  inline __isl_give isl_val *copy() && = delete;
  inline __isl_keep isl_val *get() const;
  inline __isl_give isl_val *release();
  inline __isl_keep isl_val *keep() const;
  inline __isl_give isl_val *take();
  inline explicit operator bool() const;
  inline ctx get_ctx() const;
  inline bool is_null() const;
  inline std::string to_str() const;
  inline val two_exp() const;
  inline val abs() const;
  inline boolean abs_eq(const val &v2) const;
  inline val add(val v2) const;
  inline val add_ui(unsigned long v2) const;
  inline val ceil() const;
  inline int cmp_si(long i) const;
  inline val div(val v2) const;
  inline boolean eq(const val &v2) const;
  inline val floor() const;
  inline val gcd(val v2) const;
  inline boolean ge(const val &v2) const;
  inline boolean gt(const val &v2) const;
  static inline val infty(ctx ctx);
  inline val inv() const;
  inline boolean is_divisible_by(const val &v2) const;
  inline boolean is_infty() const;
  inline boolean is_int() const;
  inline boolean is_nan() const;
  inline boolean is_neg() const;
  inline boolean is_neginfty() const;
  inline boolean is_negone() const;
  inline boolean is_nonneg() const;
  inline boolean is_nonpos() const;
  inline boolean is_one() const;
  inline boolean is_pos() const;
  inline boolean is_rat() const;
  inline boolean is_zero() const;
  inline boolean le(const val &v2) const;
  inline boolean lt(const val &v2) const;
  inline val max(val v2) const;
  inline val min(val v2) const;
  inline val mod(val v2) const;
  inline val mul(val v2) const;
  static inline val nan(ctx ctx);
  inline boolean ne(const val &v2) const;
  inline val neg() const;
  static inline val neginfty(ctx ctx);
  static inline val negone(ctx ctx);
  static inline val one(ctx ctx);
  inline int sgn() const;
  inline val sub(val v2) const;
  inline val sub_ui(unsigned long v2) const;
  inline val trunc() const;
  static inline val zero(ctx ctx);
};

// implementations for isl::aff
aff manage(__isl_take isl_aff *ptr) {
  return aff(ptr);
}

aff give(__isl_take isl_aff *ptr) {
  return manage(ptr);
}

aff::aff()
    : ptr(nullptr) {}

aff::aff(const aff &obj)
    : ptr(obj.copy()) {}

aff::aff(std::nullptr_t)
    : ptr(nullptr) {}

aff::aff(__isl_take isl_aff *ptr)
    : ptr(ptr) {}

aff::aff(local_space ls) {
  auto res = isl_aff_zero_on_domain(ls.release());
  ptr = res;
}

aff::aff(local_space ls, val val) {
  auto res = isl_aff_val_on_domain(ls.release(), val.release());
  ptr = res;
}

aff::aff(ctx ctx, const std::string &str) {
  auto res = isl_aff_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}

aff &aff::operator=(aff obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

aff::~aff() {
  if (ptr)
    isl_aff_free(ptr);
}

__isl_give isl_aff *aff::copy() const & {
  return isl_aff_copy(ptr);
}

__isl_keep isl_aff *aff::get() const {
  return ptr;
}

__isl_give isl_aff *aff::release() {
  isl_aff *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_aff *aff::keep() const {
  return get();
}

__isl_give isl_aff *aff::take() {
  return release();
}

aff::operator bool() const {
  return !is_null();
}

ctx aff::get_ctx() const {
  return ctx(isl_aff_get_ctx(ptr));
}

bool aff::is_null() const {
  return ptr == nullptr;
}

std::string aff::to_str() const {
  char *Tmp = isl_aff_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
                                     const aff &Obj) {
  OS << Obj.to_str();
  return OS;
}

aff aff::add(aff aff2) const {
  auto res = isl_aff_add(copy(), aff2.release());
  return manage(res);
}

val aff::get_constant() const {
  auto res = isl_aff_get_constant_val(get());
  return manage(res);
}

boolean aff::is_cst() const {
  auto res = isl_aff_is_cst(get());
  return res;
}

aff aff::pullback(multi_aff ma) const {
  auto res = isl_aff_pullback_multi_aff(copy(), ma.release());
  return manage(res);
}

// implementations for isl::ast_build
ast_build manage(__isl_take isl_ast_build *ptr) {
  return ast_build(ptr);
}

ast_build give(__isl_take isl_ast_build *ptr) {
  return manage(ptr);
}

ast_build::ast_build()
    : ptr(nullptr) {}

ast_build::ast_build(const ast_build &obj)
    : ptr(obj.copy()) {}

ast_build::ast_build(std::nullptr_t)
    : ptr(nullptr) {}

ast_build::ast_build(__isl_take isl_ast_build *ptr)
    : ptr(ptr) {}

ast_build::ast_build(ctx ctx) {
  auto res = isl_ast_build_alloc(ctx.release());
  ptr = res;
}

ast_build &ast_build::operator=(ast_build obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

ast_build::~ast_build() {
  if (ptr)
    isl_ast_build_free(ptr);
}

__isl_give isl_ast_build *ast_build::copy() const & {
  return isl_ast_build_copy(ptr);
}

__isl_keep isl_ast_build *ast_build::get() const {
  return ptr;
}

__isl_give isl_ast_build *ast_build::release() {
  isl_ast_build *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_ast_build *ast_build::keep() const {
  return get();
}

__isl_give isl_ast_build *ast_build::take() {
  return release();
}

ast_build::operator bool() const {
  return !is_null();
}

ctx ast_build::get_ctx() const {
  return ctx(isl_ast_build_get_ctx(ptr));
}

bool ast_build::is_null() const {
  return ptr == nullptr;
}

ast_expr ast_build::access_from(pw_multi_aff pma) const {
  auto res = isl_ast_build_access_from_pw_multi_aff(get(), pma.release());
  return manage(res);
}

ast_expr ast_build::access_from(multi_pw_aff mpa) const {
  auto res = isl_ast_build_access_from_multi_pw_aff(get(), mpa.release());
  return manage(res);
}

ast_expr ast_build::call_from(pw_multi_aff pma) const {
  auto res = isl_ast_build_call_from_pw_multi_aff(get(), pma.release());
  return manage(res);
}

ast_expr ast_build::call_from(multi_pw_aff mpa) const {
  auto res = isl_ast_build_call_from_multi_pw_aff(get(), mpa.release());
  return manage(res);
}

ast_expr ast_build::expr_from(set set) const {
  auto res = isl_ast_build_expr_from_set(get(), set.release());
  return manage(res);
}

ast_expr ast_build::expr_from(pw_aff pa) const {
  auto res = isl_ast_build_expr_from_pw_aff(get(), pa.release());
  return manage(res);
}

ast_build ast_build::from_context(set set) {
  auto res = isl_ast_build_from_context(set.release());
  return manage(res);
}

ast_node ast_build::node_from_schedule_map(union_map schedule) const {
  auto res = isl_ast_build_node_from_schedule_map(get(), schedule.release());
  return manage(res);
}

// implementations for isl::ast_expr
ast_expr manage(__isl_take isl_ast_expr *ptr) {
  return ast_expr(ptr);
}

ast_expr give(__isl_take isl_ast_expr *ptr) {
  return manage(ptr);
}

ast_expr::ast_expr()
    : ptr(nullptr) {}

ast_expr::ast_expr(const ast_expr &obj)
    : ptr(obj.copy()) {}

ast_expr::ast_expr(std::nullptr_t)
    : ptr(nullptr) {}

ast_expr::ast_expr(__isl_take isl_ast_expr *ptr)
    : ptr(ptr) {}

ast_expr &ast_expr::operator=(ast_expr obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

ast_expr::~ast_expr() {
  if (ptr)
    isl_ast_expr_free(ptr);
}

__isl_give isl_ast_expr *ast_expr::copy() const & {
  return isl_ast_expr_copy(ptr);
}

__isl_keep isl_ast_expr *ast_expr::get() const {
  return ptr;
}

__isl_give isl_ast_expr *ast_expr::release() {
  isl_ast_expr *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_ast_expr *ast_expr::keep() const {
  return get();
}

__isl_give isl_ast_expr *ast_expr::take() {
  return release();
}

ast_expr::operator bool() const {
  return !is_null();
}

ctx ast_expr::get_ctx() const {
  return ctx(isl_ast_expr_get_ctx(ptr));
}

bool ast_expr::is_null() const {
  return ptr == nullptr;
}

std::string ast_expr::to_str() const {
  char *Tmp = isl_ast_expr_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
                                     const ast_expr &Obj) {
  OS << Obj.to_str();
  return OS;
}

std::string ast_expr::to_C_str() const {
  auto res = isl_ast_expr_to_C_str(get());
  std::string tmp(res);
  free(res);
  return tmp;
}

// implementations for isl::ast_node
ast_node manage(__isl_take isl_ast_node *ptr) {
  return ast_node(ptr);
}

ast_node give(__isl_take isl_ast_node *ptr) {
  return manage(ptr);
}

ast_node::ast_node()
    : ptr(nullptr) {}

ast_node::ast_node(const ast_node &obj)
    : ptr(obj.copy()) {}

ast_node::ast_node(std::nullptr_t)
    : ptr(nullptr) {}

ast_node::ast_node(__isl_take isl_ast_node *ptr)
    : ptr(ptr) {}

ast_node &ast_node::operator=(ast_node obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

ast_node::~ast_node() {
  if (ptr)
    isl_ast_node_free(ptr);
}

__isl_give isl_ast_node *ast_node::copy() const & {
  return isl_ast_node_copy(ptr);
}

__isl_keep isl_ast_node *ast_node::get() const {
  return ptr;
}

__isl_give isl_ast_node *ast_node::release() {
  isl_ast_node *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_ast_node *ast_node::keep() const {
  return get();
}

__isl_give isl_ast_node *ast_node::take() {
  return release();
}

ast_node::operator bool() const {
  return !is_null();
}

ctx ast_node::get_ctx() const {
  return ctx(isl_ast_node_get_ctx(ptr));
}

bool ast_node::is_null() const {
  return ptr == nullptr;
}

std::string ast_node::to_str() const {
  char *Tmp = isl_ast_node_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
                                     const ast_node &Obj) {
  OS << Obj.to_str();
  return OS;
}

std::string ast_node::to_C_str() const {
  auto res = isl_ast_node_to_C_str(get());
  std::string tmp(res);
  free(res);
  return tmp;
}

// implementations for isl::basic_map
basic_map manage(__isl_take isl_basic_map *ptr) {
  return basic_map(ptr);
}

basic_map give(__isl_take isl_basic_map *ptr) {
  return manage(ptr);
}

basic_map::basic_map()
    : ptr(nullptr) {}

basic_map::basic_map(const basic_map &obj)
    : ptr(obj.copy()) {}

basic_map::basic_map(std::nullptr_t)
    : ptr(nullptr) {}

basic_map::basic_map(__isl_take isl_basic_map *ptr)
    : ptr(ptr) {}

basic_map::basic_map(ctx ctx, const std::string &str) {
  auto res = isl_basic_map_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}

basic_map &basic_map::operator=(basic_map obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

basic_map::~basic_map() {
  if (ptr)
    isl_basic_map_free(ptr);
}

__isl_give isl_basic_map *basic_map::copy() const & {
  return isl_basic_map_copy(ptr);
}

__isl_keep isl_basic_map *basic_map::get() const {
  return ptr;
}

__isl_give isl_basic_map *basic_map::release() {
  isl_basic_map *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_basic_map *basic_map::keep() const {
  return get();
}

__isl_give isl_basic_map *basic_map::take() {
  return release();
}

basic_map::operator bool() const {
  return !is_null();
}

ctx basic_map::get_ctx() const {
  return ctx(isl_basic_map_get_ctx(ptr));
}

bool basic_map::is_null() const {
  return ptr == nullptr;
}

std::string basic_map::to_str() const {
  char *Tmp = isl_basic_map_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
                                     const basic_map &Obj) {
  OS << Obj.to_str();
  return OS;
}

basic_map basic_map::affine_hull() const {
  auto res = isl_basic_map_affine_hull(copy());
  return manage(res);
}

basic_map basic_map::apply_domain(basic_map bmap2) const {
  auto res = isl_basic_map_apply_domain(copy(), bmap2.release());
  return manage(res);
}

basic_map basic_map::apply_range(basic_map bmap2) const {
  auto res = isl_basic_map_apply_range(copy(), bmap2.release());
  return manage(res);
}

basic_set basic_map::deltas() const {
  auto res = isl_basic_map_deltas(copy());
  return manage(res);
}

basic_map basic_map::detect_equalities() const {
  auto res = isl_basic_map_detect_equalities(copy());
  return manage(res);
}

basic_map basic_map::fix_si(enum dim type, unsigned int pos, int value) const {
  auto res = isl_basic_map_fix_si(copy(), static_cast<enum isl_dim_type>(type), pos, value);
  return manage(res);
}

basic_map basic_map::flatten() const {
  auto res = isl_basic_map_flatten(copy());
  return manage(res);
}

basic_map basic_map::flatten_domain() const {
  auto res = isl_basic_map_flatten_domain(copy());
  return manage(res);
}

basic_map basic_map::flatten_range() const {
  auto res = isl_basic_map_flatten_range(copy());
  return manage(res);
}

basic_map basic_map::gist(basic_map context) const {
  auto res = isl_basic_map_gist(copy(), context.release());
  return manage(res);
}

basic_map basic_map::intersect(basic_map bmap2) const {
  auto res = isl_basic_map_intersect(copy(), bmap2.release());
  return manage(res);
}

basic_map basic_map::intersect_domain(basic_set bset) const {
  auto res = isl_basic_map_intersect_domain(copy(), bset.release());
  return manage(res);
}

basic_map basic_map::intersect_range(basic_set bset) const {
  auto res = isl_basic_map_intersect_range(copy(), bset.release());
  return manage(res);
}

boolean basic_map::is_empty() const {
  auto res = isl_basic_map_is_empty(get());
  return res;
}

boolean basic_map::is_equal(const basic_map &bmap2) const {
  auto res = isl_basic_map_is_equal(get(), bmap2.get());
  return res;
}

boolean basic_map::is_subset(const basic_map &bmap2) const {
  auto res = isl_basic_map_is_subset(get(), bmap2.get());
  return res;
}

map basic_map::lexmax() const {
  auto res = isl_basic_map_lexmax(copy());
  return manage(res);
}

map basic_map::lexmin() const {
  auto res = isl_basic_map_lexmin(copy());
  return manage(res);
}

val basic_map::plain_get_val_if_fixed(enum dim type, unsigned int pos) const {
  auto res = isl_basic_map_plain_get_val_if_fixed(get(), static_cast<enum isl_dim_type>(type), pos);
  return manage(res);
}

basic_map basic_map::project_out(enum dim type, unsigned int first, unsigned int n) const {
  auto res = isl_basic_map_project_out(copy(), static_cast<enum isl_dim_type>(type), first, n);
  return manage(res);
}

basic_map basic_map::reverse() const {
  auto res = isl_basic_map_reverse(copy());
  return manage(res);
}

basic_map basic_map::sample() const {
  auto res = isl_basic_map_sample(copy());
  return manage(res);
}

map basic_map::unite(basic_map bmap2) const {
  auto res = isl_basic_map_union(copy(), bmap2.release());
  return manage(res);
}

basic_map basic_map::universe(space dim) {
  auto res = isl_basic_map_universe(dim.release());
  return manage(res);
}

// implementations for isl::basic_set
basic_set manage(__isl_take isl_basic_set *ptr) {
  return basic_set(ptr);
}

basic_set give(__isl_take isl_basic_set *ptr) {
  return manage(ptr);
}

basic_set::basic_set()
    : ptr(nullptr) {}

basic_set::basic_set(const basic_set &obj)
    : ptr(obj.copy()) {}

basic_set::basic_set(std::nullptr_t)
    : ptr(nullptr) {}

basic_set::basic_set(__isl_take isl_basic_set *ptr)
    : ptr(ptr) {}

basic_set::basic_set(ctx ctx, const std::string &str) {
  auto res = isl_basic_set_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}

basic_set::basic_set(point pnt) {
  auto res = isl_basic_set_from_point(pnt.release());
  ptr = res;
}

basic_set &basic_set::operator=(basic_set obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

basic_set::~basic_set() {
  if (ptr)
    isl_basic_set_free(ptr);
}

__isl_give isl_basic_set *basic_set::copy() const & {
  return isl_basic_set_copy(ptr);
}

__isl_keep isl_basic_set *basic_set::get() const {
  return ptr;
}

__isl_give isl_basic_set *basic_set::release() {
  isl_basic_set *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_basic_set *basic_set::keep() const {
  return get();
}

__isl_give isl_basic_set *basic_set::take() {
  return release();
}

basic_set::operator bool() const {
  return !is_null();
}

ctx basic_set::get_ctx() const {
  return ctx(isl_basic_set_get_ctx(ptr));
}

bool basic_set::is_null() const {
  return ptr == nullptr;
}

std::string basic_set::to_str() const {
  char *Tmp = isl_basic_set_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
                                     const basic_set &Obj) {
  OS << Obj.to_str();
  return OS;
}

basic_set basic_set::affine_hull() const {
  auto res = isl_basic_set_affine_hull(copy());
  return manage(res);
}

basic_set basic_set::apply(basic_map bmap) const {
  auto res = isl_basic_set_apply(copy(), bmap.release());
  return manage(res);
}

basic_set basic_set::detect_equalities() const {
  auto res = isl_basic_set_detect_equalities(copy());
  return manage(res);
}

basic_set basic_set::flatten() const {
  auto res = isl_basic_set_flatten(copy());
  return manage(res);
}

basic_set basic_set::gist(basic_set context) const {
  auto res = isl_basic_set_gist(copy(), context.release());
  return manage(res);
}

basic_set basic_set::intersect(basic_set bset2) const {
  auto res = isl_basic_set_intersect(copy(), bset2.release());
  return manage(res);
}

basic_set basic_set::intersect_params(basic_set bset2) const {
  auto res = isl_basic_set_intersect_params(copy(), bset2.release());
  return manage(res);
}

boolean basic_set::is_bounded() const {
  auto res = isl_basic_set_is_bounded(get());
  return res;
}

boolean basic_set::is_empty() const {
  auto res = isl_basic_set_is_empty(get());
  return res;
}

boolean basic_set::is_equal(const basic_set &bset2) const {
  auto res = isl_basic_set_is_equal(get(), bset2.get());
  return res;
}

boolean basic_set::is_subset(const basic_set &bset2) const {
  auto res = isl_basic_set_is_subset(get(), bset2.get());
  return res;
}

boolean basic_set::is_wrapping() const {
  auto res = isl_basic_set_is_wrapping(get());
  return res;
}

set basic_set::lexmax() const {
  auto res = isl_basic_set_lexmax(copy());
  return manage(res);
}

set basic_set::lexmin() const {
  auto res = isl_basic_set_lexmin(copy());
  return manage(res);
}

basic_set basic_set::project_out(enum dim type, unsigned int first, unsigned int n) const {
  auto res = isl_basic_set_project_out(copy(), static_cast<enum isl_dim_type>(type), first, n);
  return manage(res);
}

basic_set basic_set::sample() const {
  auto res = isl_basic_set_sample(copy());
  return manage(res);
}

point basic_set::sample_point() const {
  auto res = isl_basic_set_sample_point(copy());
  return manage(res);
}

set basic_set::unite(basic_set bset2) const {
  auto res = isl_basic_set_union(copy(), bset2.release());
  return manage(res);
}

// implementations for isl::id
id manage(__isl_take isl_id *ptr) {
  return id(ptr);
}

id give(__isl_take isl_id *ptr) {
  return manage(ptr);
}

id::id()
    : ptr(nullptr) {}

id::id(const id &obj)
    : ptr(obj.copy()) {}

id::id(std::nullptr_t)
    : ptr(nullptr) {}

id::id(__isl_take isl_id *ptr)
    : ptr(ptr) {}

id &id::operator=(id obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

id::~id() {
  if (ptr)
    isl_id_free(ptr);
}

__isl_give isl_id *id::copy() const & {
  return isl_id_copy(ptr);
}

__isl_keep isl_id *id::get() const {
  return ptr;
}

__isl_give isl_id *id::release() {
  isl_id *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_id *id::keep() const {
  return get();
}

__isl_give isl_id *id::take() {
  return release();
}

id::operator bool() const {
  return !is_null();
}

ctx id::get_ctx() const {
  return ctx(isl_id_get_ctx(ptr));
}

bool id::is_null() const {
  return ptr == nullptr;
}

std::string id::to_str() const {
  char *Tmp = isl_id_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
                                     const id &Obj) {
  OS << Obj.to_str();
  return OS;
}

// implementations for isl::local_space
local_space manage(__isl_take isl_local_space *ptr) {
  return local_space(ptr);
}

local_space give(__isl_take isl_local_space *ptr) {
  return manage(ptr);
}

local_space::local_space()
    : ptr(nullptr) {}

local_space::local_space(const local_space &obj)
    : ptr(obj.copy()) {}

local_space::local_space(std::nullptr_t)
    : ptr(nullptr) {}

local_space::local_space(__isl_take isl_local_space *ptr)
    : ptr(ptr) {}

local_space::local_space(space dim) {
  auto res = isl_local_space_from_space(dim.release());
  ptr = res;
}

local_space &local_space::operator=(local_space obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

local_space::~local_space() {
  if (ptr)
    isl_local_space_free(ptr);
}

__isl_give isl_local_space *local_space::copy() const & {
  return isl_local_space_copy(ptr);
}

__isl_keep isl_local_space *local_space::get() const {
  return ptr;
}

__isl_give isl_local_space *local_space::release() {
  isl_local_space *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_local_space *local_space::keep() const {
  return get();
}

__isl_give isl_local_space *local_space::take() {
  return release();
}

local_space::operator bool() const {
  return !is_null();
}

ctx local_space::get_ctx() const {
  return ctx(isl_local_space_get_ctx(ptr));
}

bool local_space::is_null() const {
  return ptr == nullptr;
}

// implementations for isl::map
map manage(__isl_take isl_map *ptr) {
  return map(ptr);
}

map give(__isl_take isl_map *ptr) {
  return manage(ptr);
}

map::map()
    : ptr(nullptr) {}

map::map(const map &obj)
    : ptr(obj.copy()) {}

map::map(std::nullptr_t)
    : ptr(nullptr) {}

map::map(__isl_take isl_map *ptr)
    : ptr(ptr) {}

map::map(ctx ctx, const std::string &str) {
  auto res = isl_map_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}

map::map(basic_map bmap) {
  auto res = isl_map_from_basic_map(bmap.release());
  ptr = res;
}

map &map::operator=(map obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

map::~map() {
  if (ptr)
    isl_map_free(ptr);
}

__isl_give isl_map *map::copy() const & {
  return isl_map_copy(ptr);
}

__isl_keep isl_map *map::get() const {
  return ptr;
}

__isl_give isl_map *map::release() {
  isl_map *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_map *map::keep() const {
  return get();
}

__isl_give isl_map *map::take() {
  return release();
}

map::operator bool() const {
  return !is_null();
}

ctx map::get_ctx() const {
  return ctx(isl_map_get_ctx(ptr));
}

bool map::is_null() const {
  return ptr == nullptr;
}

std::string map::to_str() const {
  char *Tmp = isl_map_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
                                     const map &Obj) {
  OS << Obj.to_str();
  return OS;
}

basic_map map::affine_hull() const {
  auto res = isl_map_affine_hull(copy());
  return manage(res);
}

map map::apply_domain(map map2) const {
  auto res = isl_map_apply_domain(copy(), map2.release());
  return manage(res);
}

map map::apply_range(map map2) const {
  auto res = isl_map_apply_range(copy(), map2.release());
  return manage(res);
}

map map::coalesce() const {
  auto res = isl_map_coalesce(copy());
  return manage(res);
}

map map::complement() const {
  auto res = isl_map_complement(copy());
  return manage(res);
}

set map::deltas() const {
  auto res = isl_map_deltas(copy());
  return manage(res);
}

map map::detect_equalities() const {
  auto res = isl_map_detect_equalities(copy());
  return manage(res);
}

unsigned int map::dim(enum dim type) const {
  auto res = isl_map_dim(get(), static_cast<enum isl_dim_type>(type));
  return res;
}

pw_aff map::dim_max(int pos) const {
  auto res = isl_map_dim_max(copy(), pos);
  return manage(res);
}

pw_aff map::dim_min(int pos) const {
  auto res = isl_map_dim_min(copy(), pos);
  return manage(res);
}

map map::flatten() const {
  auto res = isl_map_flatten(copy());
  return manage(res);
}

map map::flatten_domain() const {
  auto res = isl_map_flatten_domain(copy());
  return manage(res);
}

map map::flatten_range() const {
  auto res = isl_map_flatten_range(copy());
  return manage(res);
}

stat map::foreach_basic_map(std::function<stat(basic_map)> &&fn) const {
  auto fn_lambda = [](isl_basic_map *arg_0, void *arg_1) -> isl_stat {
    auto *func = (std::function<stat(basic_map)> *)arg_1;
    stat ret = (*func)(isl::manage(arg_0));
    return isl_stat(ret);
  };
  auto res = isl_map_foreach_basic_map(get(), fn_lambda, &fn);
  return stat(res);
}

map map::from_range(set set) {
  auto res = isl_map_from_range(set.release());
  return manage(res);
}

map map::gist(map context) const {
  auto res = isl_map_gist(copy(), context.release());
  return manage(res);
}

map map::gist_domain(set context) const {
  auto res = isl_map_gist_domain(copy(), context.release());
  return manage(res);
}

map map::intersect(map map2) const {
  auto res = isl_map_intersect(copy(), map2.release());
  return manage(res);
}

map map::intersect_domain(set set) const {
  auto res = isl_map_intersect_domain(copy(), set.release());
  return manage(res);
}

map map::intersect_params(set params) const {
  auto res = isl_map_intersect_params(copy(), params.release());
  return manage(res);
}

map map::intersect_range(set set) const {
  auto res = isl_map_intersect_range(copy(), set.release());
  return manage(res);
}

boolean map::is_bijective() const {
  auto res = isl_map_is_bijective(get());
  return res;
}

boolean map::is_disjoint(const map &map2) const {
  auto res = isl_map_is_disjoint(get(), map2.get());
  return res;
}

boolean map::is_empty() const {
  auto res = isl_map_is_empty(get());
  return res;
}

boolean map::is_equal(const map &map2) const {
  auto res = isl_map_is_equal(get(), map2.get());
  return res;
}

boolean map::is_injective() const {
  auto res = isl_map_is_injective(get());
  return res;
}

boolean map::is_single_valued() const {
  auto res = isl_map_is_single_valued(get());
  return res;
}

boolean map::is_strict_subset(const map &map2) const {
  auto res = isl_map_is_strict_subset(get(), map2.get());
  return res;
}

boolean map::is_subset(const map &map2) const {
  auto res = isl_map_is_subset(get(), map2.get());
  return res;
}

map map::lexmax() const {
  auto res = isl_map_lexmax(copy());
  return manage(res);
}

map map::lexmin() const {
  auto res = isl_map_lexmin(copy());
  return manage(res);
}

basic_map map::polyhedral_hull() const {
  auto res = isl_map_polyhedral_hull(copy());
  return manage(res);
}

map map::project_out(enum dim type, unsigned int first, unsigned int n) const {
  auto res = isl_map_project_out(copy(), static_cast<enum isl_dim_type>(type), first, n);
  return manage(res);
}

map map::reverse() const {
  auto res = isl_map_reverse(copy());
  return manage(res);
}

basic_map map::sample() const {
  auto res = isl_map_sample(copy());
  return manage(res);
}

map map::subtract(map map2) const {
  auto res = isl_map_subtract(copy(), map2.release());
  return manage(res);
}

map map::unite(map map2) const {
  auto res = isl_map_union(copy(), map2.release());
  return manage(res);
}

basic_map map::unshifted_simple_hull() const {
  auto res = isl_map_unshifted_simple_hull(copy());
  return manage(res);
}

// implementations for isl::multi_aff
multi_aff manage(__isl_take isl_multi_aff *ptr) {
  return multi_aff(ptr);
}

multi_aff give(__isl_take isl_multi_aff *ptr) {
  return manage(ptr);
}

multi_aff::multi_aff()
    : ptr(nullptr) {}

multi_aff::multi_aff(const multi_aff &obj)
    : ptr(obj.copy()) {}

multi_aff::multi_aff(std::nullptr_t)
    : ptr(nullptr) {}

multi_aff::multi_aff(__isl_take isl_multi_aff *ptr)
    : ptr(ptr) {}

multi_aff::multi_aff(aff aff) {
  auto res = isl_multi_aff_from_aff(aff.release());
  ptr = res;
}

multi_aff::multi_aff(ctx ctx, const std::string &str) {
  auto res = isl_multi_aff_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}

multi_aff &multi_aff::operator=(multi_aff obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

multi_aff::~multi_aff() {
  if (ptr)
    isl_multi_aff_free(ptr);
}

__isl_give isl_multi_aff *multi_aff::copy() const & {
  return isl_multi_aff_copy(ptr);
}

__isl_keep isl_multi_aff *multi_aff::get() const {
  return ptr;
}

__isl_give isl_multi_aff *multi_aff::release() {
  isl_multi_aff *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_multi_aff *multi_aff::keep() const {
  return get();
}

__isl_give isl_multi_aff *multi_aff::take() {
  return release();
}

multi_aff::operator bool() const {
  return !is_null();
}

ctx multi_aff::get_ctx() const {
  return ctx(isl_multi_aff_get_ctx(ptr));
}

bool multi_aff::is_null() const {
  return ptr == nullptr;
}

std::string multi_aff::to_str() const {
  char *Tmp = isl_multi_aff_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
                                     const multi_aff &Obj) {
  OS << Obj.to_str();
  return OS;
}

multi_aff multi_aff::add(multi_aff multi2) const {
  auto res = isl_multi_aff_add(copy(), multi2.release());
  return manage(res);
}

multi_aff multi_aff::flat_range_product(multi_aff multi2) const {
  auto res = isl_multi_aff_flat_range_product(copy(), multi2.release());
  return manage(res);
}

aff multi_aff::get_aff(int pos) const {
  auto res = isl_multi_aff_get_aff(get(), pos);
  return manage(res);
}

multi_aff multi_aff::product(multi_aff multi2) const {
  auto res = isl_multi_aff_product(copy(), multi2.release());
  return manage(res);
}

multi_aff multi_aff::pullback(multi_aff ma2) const {
  auto res = isl_multi_aff_pullback_multi_aff(copy(), ma2.release());
  return manage(res);
}

multi_aff multi_aff::range_product(multi_aff multi2) const {
  auto res = isl_multi_aff_range_product(copy(), multi2.release());
  return manage(res);
}

// implementations for isl::multi_pw_aff
multi_pw_aff manage(__isl_take isl_multi_pw_aff *ptr) {
  return multi_pw_aff(ptr);
}

multi_pw_aff give(__isl_take isl_multi_pw_aff *ptr) {
  return manage(ptr);
}

multi_pw_aff::multi_pw_aff()
    : ptr(nullptr) {}

multi_pw_aff::multi_pw_aff(const multi_pw_aff &obj)
    : ptr(obj.copy()) {}

multi_pw_aff::multi_pw_aff(std::nullptr_t)
    : ptr(nullptr) {}

multi_pw_aff::multi_pw_aff(__isl_take isl_multi_pw_aff *ptr)
    : ptr(ptr) {}

multi_pw_aff::multi_pw_aff(multi_aff ma) {
  auto res = isl_multi_pw_aff_from_multi_aff(ma.release());
  ptr = res;
}

multi_pw_aff::multi_pw_aff(pw_aff pa) {
  auto res = isl_multi_pw_aff_from_pw_aff(pa.release());
  ptr = res;
}

multi_pw_aff::multi_pw_aff(pw_multi_aff pma) {
  auto res = isl_multi_pw_aff_from_pw_multi_aff(pma.release());
  ptr = res;
}

multi_pw_aff::multi_pw_aff(ctx ctx, const std::string &str) {
  auto res = isl_multi_pw_aff_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}

multi_pw_aff &multi_pw_aff::operator=(multi_pw_aff obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

multi_pw_aff::~multi_pw_aff() {
  if (ptr)
    isl_multi_pw_aff_free(ptr);
}

__isl_give isl_multi_pw_aff *multi_pw_aff::copy() const & {
  return isl_multi_pw_aff_copy(ptr);
}

__isl_keep isl_multi_pw_aff *multi_pw_aff::get() const {
  return ptr;
}

__isl_give isl_multi_pw_aff *multi_pw_aff::release() {
  isl_multi_pw_aff *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_multi_pw_aff *multi_pw_aff::keep() const {
  return get();
}

__isl_give isl_multi_pw_aff *multi_pw_aff::take() {
  return release();
}

multi_pw_aff::operator bool() const {
  return !is_null();
}

ctx multi_pw_aff::get_ctx() const {
  return ctx(isl_multi_pw_aff_get_ctx(ptr));
}

bool multi_pw_aff::is_null() const {
  return ptr == nullptr;
}

std::string multi_pw_aff::to_str() const {
  char *Tmp = isl_multi_pw_aff_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
                                     const multi_pw_aff &Obj) {
  OS << Obj.to_str();
  return OS;
}

multi_pw_aff multi_pw_aff::add(multi_pw_aff multi2) const {
  auto res = isl_multi_pw_aff_add(copy(), multi2.release());
  return manage(res);
}

multi_pw_aff multi_pw_aff::flat_range_product(multi_pw_aff multi2) const {
  auto res = isl_multi_pw_aff_flat_range_product(copy(), multi2.release());
  return manage(res);
}

pw_aff multi_pw_aff::get_pw_aff(int pos) const {
  auto res = isl_multi_pw_aff_get_pw_aff(get(), pos);
  return manage(res);
}

multi_pw_aff multi_pw_aff::product(multi_pw_aff multi2) const {
  auto res = isl_multi_pw_aff_product(copy(), multi2.release());
  return manage(res);
}

multi_pw_aff multi_pw_aff::pullback(multi_aff ma) const {
  auto res = isl_multi_pw_aff_pullback_multi_aff(copy(), ma.release());
  return manage(res);
}

multi_pw_aff multi_pw_aff::pullback(pw_multi_aff pma) const {
  auto res = isl_multi_pw_aff_pullback_pw_multi_aff(copy(), pma.release());
  return manage(res);
}

multi_pw_aff multi_pw_aff::pullback(multi_pw_aff mpa2) const {
  auto res = isl_multi_pw_aff_pullback_multi_pw_aff(copy(), mpa2.release());
  return manage(res);
}

multi_pw_aff multi_pw_aff::range_product(multi_pw_aff multi2) const {
  auto res = isl_multi_pw_aff_range_product(copy(), multi2.release());
  return manage(res);
}

// implementations for isl::multi_union_pw_aff
multi_union_pw_aff manage(__isl_take isl_multi_union_pw_aff *ptr) {
  return multi_union_pw_aff(ptr);
}

multi_union_pw_aff give(__isl_take isl_multi_union_pw_aff *ptr) {
  return manage(ptr);
}

multi_union_pw_aff::multi_union_pw_aff()
    : ptr(nullptr) {}

multi_union_pw_aff::multi_union_pw_aff(const multi_union_pw_aff &obj)
    : ptr(obj.copy()) {}

multi_union_pw_aff::multi_union_pw_aff(std::nullptr_t)
    : ptr(nullptr) {}

multi_union_pw_aff::multi_union_pw_aff(__isl_take isl_multi_union_pw_aff *ptr)
    : ptr(ptr) {}

multi_union_pw_aff::multi_union_pw_aff(union_pw_aff upa) {
  auto res = isl_multi_union_pw_aff_from_union_pw_aff(upa.release());
  ptr = res;
}

multi_union_pw_aff::multi_union_pw_aff(multi_pw_aff mpa) {
  auto res = isl_multi_union_pw_aff_from_multi_pw_aff(mpa.release());
  ptr = res;
}

multi_union_pw_aff::multi_union_pw_aff(union_pw_multi_aff upma) {
  auto res = isl_multi_union_pw_aff_from_union_pw_multi_aff(upma.release());
  ptr = res;
}

multi_union_pw_aff::multi_union_pw_aff(ctx ctx, const std::string &str) {
  auto res = isl_multi_union_pw_aff_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}

multi_union_pw_aff &multi_union_pw_aff::operator=(multi_union_pw_aff obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

multi_union_pw_aff::~multi_union_pw_aff() {
  if (ptr)
    isl_multi_union_pw_aff_free(ptr);
}

__isl_give isl_multi_union_pw_aff *multi_union_pw_aff::copy() const & {
  return isl_multi_union_pw_aff_copy(ptr);
}

__isl_keep isl_multi_union_pw_aff *multi_union_pw_aff::get() const {
  return ptr;
}

__isl_give isl_multi_union_pw_aff *multi_union_pw_aff::release() {
  isl_multi_union_pw_aff *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_multi_union_pw_aff *multi_union_pw_aff::keep() const {
  return get();
}

__isl_give isl_multi_union_pw_aff *multi_union_pw_aff::take() {
  return release();
}

multi_union_pw_aff::operator bool() const {
  return !is_null();
}

ctx multi_union_pw_aff::get_ctx() const {
  return ctx(isl_multi_union_pw_aff_get_ctx(ptr));
}

bool multi_union_pw_aff::is_null() const {
  return ptr == nullptr;
}

std::string multi_union_pw_aff::to_str() const {
  char *Tmp = isl_multi_union_pw_aff_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
                                     const multi_union_pw_aff &Obj) {
  OS << Obj.to_str();
  return OS;
}

multi_union_pw_aff multi_union_pw_aff::add(multi_union_pw_aff multi2) const {
  auto res = isl_multi_union_pw_aff_add(copy(), multi2.release());
  return manage(res);
}

multi_union_pw_aff multi_union_pw_aff::flat_range_product(multi_union_pw_aff multi2) const {
  auto res = isl_multi_union_pw_aff_flat_range_product(copy(), multi2.release());
  return manage(res);
}

union_pw_aff multi_union_pw_aff::get_union_pw_aff(int pos) const {
  auto res = isl_multi_union_pw_aff_get_union_pw_aff(get(), pos);
  return manage(res);
}

multi_union_pw_aff multi_union_pw_aff::pullback(union_pw_multi_aff upma) const {
  auto res = isl_multi_union_pw_aff_pullback_union_pw_multi_aff(copy(), upma.release());
  return manage(res);
}

multi_union_pw_aff multi_union_pw_aff::range_product(multi_union_pw_aff multi2) const {
  auto res = isl_multi_union_pw_aff_range_product(copy(), multi2.release());
  return manage(res);
}

multi_union_pw_aff multi_union_pw_aff::union_add(multi_union_pw_aff mupa2) const {
  auto res = isl_multi_union_pw_aff_union_add(copy(), mupa2.release());
  return manage(res);
}

// implementations for isl::multi_val
multi_val manage(__isl_take isl_multi_val *ptr) {
  return multi_val(ptr);
}

multi_val give(__isl_take isl_multi_val *ptr) {
  return manage(ptr);
}

multi_val::multi_val()
    : ptr(nullptr) {}

multi_val::multi_val(const multi_val &obj)
    : ptr(obj.copy()) {}

multi_val::multi_val(std::nullptr_t)
    : ptr(nullptr) {}

multi_val::multi_val(__isl_take isl_multi_val *ptr)
    : ptr(ptr) {}

multi_val &multi_val::operator=(multi_val obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

multi_val::~multi_val() {
  if (ptr)
    isl_multi_val_free(ptr);
}

__isl_give isl_multi_val *multi_val::copy() const & {
  return isl_multi_val_copy(ptr);
}

__isl_keep isl_multi_val *multi_val::get() const {
  return ptr;
}

__isl_give isl_multi_val *multi_val::release() {
  isl_multi_val *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_multi_val *multi_val::keep() const {
  return get();
}

__isl_give isl_multi_val *multi_val::take() {
  return release();
}

multi_val::operator bool() const {
  return !is_null();
}

ctx multi_val::get_ctx() const {
  return ctx(isl_multi_val_get_ctx(ptr));
}

bool multi_val::is_null() const {
  return ptr == nullptr;
}

std::string multi_val::to_str() const {
  char *Tmp = isl_multi_val_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
                                     const multi_val &Obj) {
  OS << Obj.to_str();
  return OS;
}

multi_val multi_val::add(multi_val multi2) const {
  auto res = isl_multi_val_add(copy(), multi2.release());
  return manage(res);
}

multi_val multi_val::flat_range_product(multi_val multi2) const {
  auto res = isl_multi_val_flat_range_product(copy(), multi2.release());
  return manage(res);
}

val multi_val::get_val(int pos) const {
  auto res = isl_multi_val_get_val(get(), pos);
  return manage(res);
}

multi_val multi_val::product(multi_val multi2) const {
  auto res = isl_multi_val_product(copy(), multi2.release());
  return manage(res);
}

multi_val multi_val::range_product(multi_val multi2) const {
  auto res = isl_multi_val_range_product(copy(), multi2.release());
  return manage(res);
}

// implementations for isl::point
point manage(__isl_take isl_point *ptr) {
  return point(ptr);
}

point give(__isl_take isl_point *ptr) {
  return manage(ptr);
}

point::point()
    : ptr(nullptr) {}

point::point(const point &obj)
    : ptr(obj.copy()) {}

point::point(std::nullptr_t)
    : ptr(nullptr) {}

point::point(__isl_take isl_point *ptr)
    : ptr(ptr) {}

point::point(space dim) {
  auto res = isl_point_zero(dim.release());
  ptr = res;
}

point &point::operator=(point obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

point::~point() {
  if (ptr)
    isl_point_free(ptr);
}

__isl_give isl_point *point::copy() const & {
  return isl_point_copy(ptr);
}

__isl_keep isl_point *point::get() const {
  return ptr;
}

__isl_give isl_point *point::release() {
  isl_point *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_point *point::keep() const {
  return get();
}

__isl_give isl_point *point::take() {
  return release();
}

point::operator bool() const {
  return !is_null();
}

ctx point::get_ctx() const {
  return ctx(isl_point_get_ctx(ptr));
}

bool point::is_null() const {
  return ptr == nullptr;
}

std::string point::to_str() const {
  char *Tmp = isl_point_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
                                     const point &Obj) {
  OS << Obj.to_str();
  return OS;
}

// implementations for isl::pw_aff
pw_aff manage(__isl_take isl_pw_aff *ptr) {
  return pw_aff(ptr);
}

pw_aff give(__isl_take isl_pw_aff *ptr) {
  return manage(ptr);
}

pw_aff::pw_aff()
    : ptr(nullptr) {}

pw_aff::pw_aff(const pw_aff &obj)
    : ptr(obj.copy()) {}

pw_aff::pw_aff(std::nullptr_t)
    : ptr(nullptr) {}

pw_aff::pw_aff(__isl_take isl_pw_aff *ptr)
    : ptr(ptr) {}

pw_aff::pw_aff(aff aff) {
  auto res = isl_pw_aff_from_aff(aff.release());
  ptr = res;
}

pw_aff::pw_aff(local_space ls) {
  auto res = isl_pw_aff_zero_on_domain(ls.release());
  ptr = res;
}

pw_aff::pw_aff(set domain, val v) {
  auto res = isl_pw_aff_val_on_domain(domain.release(), v.release());
  ptr = res;
}

pw_aff::pw_aff(ctx ctx, const std::string &str) {
  auto res = isl_pw_aff_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}

pw_aff &pw_aff::operator=(pw_aff obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

pw_aff::~pw_aff() {
  if (ptr)
    isl_pw_aff_free(ptr);
}

__isl_give isl_pw_aff *pw_aff::copy() const & {
  return isl_pw_aff_copy(ptr);
}

__isl_keep isl_pw_aff *pw_aff::get() const {
  return ptr;
}

__isl_give isl_pw_aff *pw_aff::release() {
  isl_pw_aff *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_pw_aff *pw_aff::keep() const {
  return get();
}

__isl_give isl_pw_aff *pw_aff::take() {
  return release();
}

pw_aff::operator bool() const {
  return !is_null();
}

ctx pw_aff::get_ctx() const {
  return ctx(isl_pw_aff_get_ctx(ptr));
}

bool pw_aff::is_null() const {
  return ptr == nullptr;
}

std::string pw_aff::to_str() const {
  char *Tmp = isl_pw_aff_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
                                     const pw_aff &Obj) {
  OS << Obj.to_str();
  return OS;
}

pw_aff pw_aff::add(pw_aff pwaff2) const {
  auto res = isl_pw_aff_add(copy(), pwaff2.release());
  return manage(res);
}

stat pw_aff::foreach_piece(std::function<stat(set, aff)> &&fn) const {
  auto fn_lambda = [](isl_set *arg_0, isl_aff *arg_1, void *arg_2) -> isl_stat {
    auto *func = (std::function<stat(set, aff)> *)arg_2;
    stat ret = (*func)(isl::manage(arg_0), isl::manage(arg_1));
    return isl_stat(ret);
  };
  auto res = isl_pw_aff_foreach_piece(get(), fn_lambda, &fn);
  return stat(res);
}

space pw_aff::get_space() const {
  auto res = isl_pw_aff_get_space(get());
  return manage(res);
}

boolean pw_aff::is_cst() const {
  auto res = isl_pw_aff_is_cst(get());
  return res;
}

pw_aff pw_aff::mul(pw_aff pwaff2) const {
  auto res = isl_pw_aff_mul(copy(), pwaff2.release());
  return manage(res);
}

pw_aff pw_aff::neg() const {
  auto res = isl_pw_aff_neg(copy());
  return manage(res);
}

pw_aff pw_aff::pullback(multi_aff ma) const {
  auto res = isl_pw_aff_pullback_multi_aff(copy(), ma.release());
  return manage(res);
}

pw_aff pw_aff::pullback(pw_multi_aff pma) const {
  auto res = isl_pw_aff_pullback_pw_multi_aff(copy(), pma.release());
  return manage(res);
}

pw_aff pw_aff::pullback(multi_pw_aff mpa) const {
  auto res = isl_pw_aff_pullback_multi_pw_aff(copy(), mpa.release());
  return manage(res);
}

pw_aff pw_aff::sub(pw_aff pwaff2) const {
  auto res = isl_pw_aff_sub(copy(), pwaff2.release());
  return manage(res);
}

pw_aff pw_aff::union_add(pw_aff pwaff2) const {
  auto res = isl_pw_aff_union_add(copy(), pwaff2.release());
  return manage(res);
}

// implementations for isl::pw_multi_aff
pw_multi_aff manage(__isl_take isl_pw_multi_aff *ptr) {
  return pw_multi_aff(ptr);
}

pw_multi_aff give(__isl_take isl_pw_multi_aff *ptr) {
  return manage(ptr);
}

pw_multi_aff::pw_multi_aff()
    : ptr(nullptr) {}

pw_multi_aff::pw_multi_aff(const pw_multi_aff &obj)
    : ptr(obj.copy()) {}

pw_multi_aff::pw_multi_aff(std::nullptr_t)
    : ptr(nullptr) {}

pw_multi_aff::pw_multi_aff(__isl_take isl_pw_multi_aff *ptr)
    : ptr(ptr) {}

pw_multi_aff::pw_multi_aff(ctx ctx, const std::string &str) {
  auto res = isl_pw_multi_aff_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}

pw_multi_aff::pw_multi_aff(multi_aff ma) {
  auto res = isl_pw_multi_aff_from_multi_aff(ma.release());
  ptr = res;
}

pw_multi_aff::pw_multi_aff(pw_aff pa) {
  auto res = isl_pw_multi_aff_from_pw_aff(pa.release());
  ptr = res;
}

pw_multi_aff &pw_multi_aff::operator=(pw_multi_aff obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

pw_multi_aff::~pw_multi_aff() {
  if (ptr)
    isl_pw_multi_aff_free(ptr);
}

__isl_give isl_pw_multi_aff *pw_multi_aff::copy() const & {
  return isl_pw_multi_aff_copy(ptr);
}

__isl_keep isl_pw_multi_aff *pw_multi_aff::get() const {
  return ptr;
}

__isl_give isl_pw_multi_aff *pw_multi_aff::release() {
  isl_pw_multi_aff *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_pw_multi_aff *pw_multi_aff::keep() const {
  return get();
}

__isl_give isl_pw_multi_aff *pw_multi_aff::take() {
  return release();
}

pw_multi_aff::operator bool() const {
  return !is_null();
}

ctx pw_multi_aff::get_ctx() const {
  return ctx(isl_pw_multi_aff_get_ctx(ptr));
}

bool pw_multi_aff::is_null() const {
  return ptr == nullptr;
}

std::string pw_multi_aff::to_str() const {
  char *Tmp = isl_pw_multi_aff_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
                                     const pw_multi_aff &Obj) {
  OS << Obj.to_str();
  return OS;
}

pw_multi_aff pw_multi_aff::add(pw_multi_aff pma2) const {
  auto res = isl_pw_multi_aff_add(copy(), pma2.release());
  return manage(res);
}

pw_multi_aff pw_multi_aff::flat_range_product(pw_multi_aff pma2) const {
  auto res = isl_pw_multi_aff_flat_range_product(copy(), pma2.release());
  return manage(res);
}

pw_multi_aff pw_multi_aff::product(pw_multi_aff pma2) const {
  auto res = isl_pw_multi_aff_product(copy(), pma2.release());
  return manage(res);
}

pw_multi_aff pw_multi_aff::pullback(multi_aff ma) const {
  auto res = isl_pw_multi_aff_pullback_multi_aff(copy(), ma.release());
  return manage(res);
}

pw_multi_aff pw_multi_aff::pullback(pw_multi_aff pma2) const {
  auto res = isl_pw_multi_aff_pullback_pw_multi_aff(copy(), pma2.release());
  return manage(res);
}

pw_multi_aff pw_multi_aff::range_product(pw_multi_aff pma2) const {
  auto res = isl_pw_multi_aff_range_product(copy(), pma2.release());
  return manage(res);
}

pw_multi_aff pw_multi_aff::union_add(pw_multi_aff pma2) const {
  auto res = isl_pw_multi_aff_union_add(copy(), pma2.release());
  return manage(res);
}

// implementations for isl::schedule
schedule manage(__isl_take isl_schedule *ptr) {
  return schedule(ptr);
}

schedule give(__isl_take isl_schedule *ptr) {
  return manage(ptr);
}

schedule::schedule()
    : ptr(nullptr) {}

schedule::schedule(const schedule &obj)
    : ptr(obj.copy()) {}

schedule::schedule(std::nullptr_t)
    : ptr(nullptr) {}

schedule::schedule(__isl_take isl_schedule *ptr)
    : ptr(ptr) {}

schedule::schedule(ctx ctx, const std::string &str) {
  auto res = isl_schedule_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}

schedule &schedule::operator=(schedule obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

schedule::~schedule() {
  if (ptr)
    isl_schedule_free(ptr);
}

__isl_give isl_schedule *schedule::copy() const & {
  return isl_schedule_copy(ptr);
}

__isl_keep isl_schedule *schedule::get() const {
  return ptr;
}

__isl_give isl_schedule *schedule::release() {
  isl_schedule *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_schedule *schedule::keep() const {
  return get();
}

__isl_give isl_schedule *schedule::take() {
  return release();
}

schedule::operator bool() const {
  return !is_null();
}

ctx schedule::get_ctx() const {
  return ctx(isl_schedule_get_ctx(ptr));
}

bool schedule::is_null() const {
  return ptr == nullptr;
}

std::string schedule::to_str() const {
  char *Tmp = isl_schedule_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
                                     const schedule &Obj) {
  OS << Obj.to_str();
  return OS;
}

union_map schedule::get_map() const {
  auto res = isl_schedule_get_map(get());
  return manage(res);
}

schedule_node schedule::get_root() const {
  auto res = isl_schedule_get_root(get());
  return manage(res);
}

schedule schedule::pullback(union_pw_multi_aff upma) const {
  auto res = isl_schedule_pullback_union_pw_multi_aff(copy(), upma.release());
  return manage(res);
}

// implementations for isl::schedule_constraints
schedule_constraints manage(__isl_take isl_schedule_constraints *ptr) {
  return schedule_constraints(ptr);
}

schedule_constraints give(__isl_take isl_schedule_constraints *ptr) {
  return manage(ptr);
}

schedule_constraints::schedule_constraints()
    : ptr(nullptr) {}

schedule_constraints::schedule_constraints(const schedule_constraints &obj)
    : ptr(obj.copy()) {}

schedule_constraints::schedule_constraints(std::nullptr_t)
    : ptr(nullptr) {}

schedule_constraints::schedule_constraints(__isl_take isl_schedule_constraints *ptr)
    : ptr(ptr) {}

schedule_constraints::schedule_constraints(ctx ctx, const std::string &str) {
  auto res = isl_schedule_constraints_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}

schedule_constraints &schedule_constraints::operator=(schedule_constraints obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

schedule_constraints::~schedule_constraints() {
  if (ptr)
    isl_schedule_constraints_free(ptr);
}

__isl_give isl_schedule_constraints *schedule_constraints::copy() const & {
  return isl_schedule_constraints_copy(ptr);
}

__isl_keep isl_schedule_constraints *schedule_constraints::get() const {
  return ptr;
}

__isl_give isl_schedule_constraints *schedule_constraints::release() {
  isl_schedule_constraints *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_schedule_constraints *schedule_constraints::keep() const {
  return get();
}

__isl_give isl_schedule_constraints *schedule_constraints::take() {
  return release();
}

schedule_constraints::operator bool() const {
  return !is_null();
}

ctx schedule_constraints::get_ctx() const {
  return ctx(isl_schedule_constraints_get_ctx(ptr));
}

bool schedule_constraints::is_null() const {
  return ptr == nullptr;
}

std::string schedule_constraints::to_str() const {
  char *Tmp = isl_schedule_constraints_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
                                     const schedule_constraints &Obj) {
  OS << Obj.to_str();
  return OS;
}

union_map schedule_constraints::get_coincidence() const {
  auto res = isl_schedule_constraints_get_coincidence(get());
  return manage(res);
}

union_map schedule_constraints::get_conditional_validity() const {
  auto res = isl_schedule_constraints_get_conditional_validity(get());
  return manage(res);
}

union_map schedule_constraints::get_conditional_validity_condition() const {
  auto res = isl_schedule_constraints_get_conditional_validity_condition(get());
  return manage(res);
}

set schedule_constraints::get_context() const {
  auto res = isl_schedule_constraints_get_context(get());
  return manage(res);
}

union_set schedule_constraints::get_domain() const {
  auto res = isl_schedule_constraints_get_domain(get());
  return manage(res);
}

union_map schedule_constraints::get_proximity() const {
  auto res = isl_schedule_constraints_get_proximity(get());
  return manage(res);
}

union_map schedule_constraints::get_validity() const {
  auto res = isl_schedule_constraints_get_validity(get());
  return manage(res);
}

// implementations for isl::schedule_node
schedule_node manage(__isl_take isl_schedule_node *ptr) {
  return schedule_node(ptr);
}

schedule_node give(__isl_take isl_schedule_node *ptr) {
  return manage(ptr);
}

schedule_node::schedule_node()
    : ptr(nullptr) {}

schedule_node::schedule_node(const schedule_node &obj)
    : ptr(obj.copy()) {}

schedule_node::schedule_node(std::nullptr_t)
    : ptr(nullptr) {}

schedule_node::schedule_node(__isl_take isl_schedule_node *ptr)
    : ptr(ptr) {}

schedule_node &schedule_node::operator=(schedule_node obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

schedule_node::~schedule_node() {
  if (ptr)
    isl_schedule_node_free(ptr);
}

__isl_give isl_schedule_node *schedule_node::copy() const & {
  return isl_schedule_node_copy(ptr);
}

__isl_keep isl_schedule_node *schedule_node::get() const {
  return ptr;
}

__isl_give isl_schedule_node *schedule_node::release() {
  isl_schedule_node *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_schedule_node *schedule_node::keep() const {
  return get();
}

__isl_give isl_schedule_node *schedule_node::take() {
  return release();
}

schedule_node::operator bool() const {
  return !is_null();
}

ctx schedule_node::get_ctx() const {
  return ctx(isl_schedule_node_get_ctx(ptr));
}

bool schedule_node::is_null() const {
  return ptr == nullptr;
}

std::string schedule_node::to_str() const {
  char *Tmp = isl_schedule_node_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
                                     const schedule_node &Obj) {
  OS << Obj.to_str();
  return OS;
}

boolean schedule_node::band_member_get_coincident(int pos) const {
  auto res = isl_schedule_node_band_member_get_coincident(get(), pos);
  return res;
}

schedule_node schedule_node::band_member_set_coincident(int pos, int coincident) const {
  auto res = isl_schedule_node_band_member_set_coincident(copy(), pos, coincident);
  return manage(res);
}

schedule_node schedule_node::child(int pos) const {
  auto res = isl_schedule_node_child(copy(), pos);
  return manage(res);
}

multi_union_pw_aff schedule_node::get_prefix_schedule_multi_union_pw_aff() const {
  auto res = isl_schedule_node_get_prefix_schedule_multi_union_pw_aff(get());
  return manage(res);
}

union_map schedule_node::get_prefix_schedule_union_map() const {
  auto res = isl_schedule_node_get_prefix_schedule_union_map(get());
  return manage(res);
}

union_pw_multi_aff schedule_node::get_prefix_schedule_union_pw_multi_aff() const {
  auto res = isl_schedule_node_get_prefix_schedule_union_pw_multi_aff(get());
  return manage(res);
}

schedule schedule_node::get_schedule() const {
  auto res = isl_schedule_node_get_schedule(get());
  return manage(res);
}

schedule_node schedule_node::parent() const {
  auto res = isl_schedule_node_parent(copy());
  return manage(res);
}

// implementations for isl::set
set manage(__isl_take isl_set *ptr) {
  return set(ptr);
}

set give(__isl_take isl_set *ptr) {
  return manage(ptr);
}

set::set()
    : ptr(nullptr) {}

set::set(const set &obj)
    : ptr(obj.copy()) {}

set::set(std::nullptr_t)
    : ptr(nullptr) {}

set::set(__isl_take isl_set *ptr)
    : ptr(ptr) {}

set::set(union_set uset) {
  auto res = isl_set_from_union_set(uset.release());
  ptr = res;
}

set::set(ctx ctx, const std::string &str) {
  auto res = isl_set_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}

set::set(basic_set bset) {
  auto res = isl_set_from_basic_set(bset.release());
  ptr = res;
}

set::set(point pnt) {
  auto res = isl_set_from_point(pnt.release());
  ptr = res;
}

set &set::operator=(set obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

set::~set() {
  if (ptr)
    isl_set_free(ptr);
}

__isl_give isl_set *set::copy() const & {
  return isl_set_copy(ptr);
}

__isl_keep isl_set *set::get() const {
  return ptr;
}

__isl_give isl_set *set::release() {
  isl_set *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_set *set::keep() const {
  return get();
}

__isl_give isl_set *set::take() {
  return release();
}

set::operator bool() const {
  return !is_null();
}

ctx set::get_ctx() const {
  return ctx(isl_set_get_ctx(ptr));
}

bool set::is_null() const {
  return ptr == nullptr;
}

std::string set::to_str() const {
  char *Tmp = isl_set_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
                                     const set &Obj) {
  OS << Obj.to_str();
  return OS;
}

set set::add_dims(enum dim type, unsigned int n) const {
  auto res = isl_set_add_dims(copy(), static_cast<enum isl_dim_type>(type), n);
  return manage(res);
}

basic_set set::affine_hull() const {
  auto res = isl_set_affine_hull(copy());
  return manage(res);
}

set set::apply(map map) const {
  auto res = isl_set_apply(copy(), map.release());
  return manage(res);
}

set set::coalesce() const {
  auto res = isl_set_coalesce(copy());
  return manage(res);
}

set set::complement() const {
  auto res = isl_set_complement(copy());
  return manage(res);
}

set set::detect_equalities() const {
  auto res = isl_set_detect_equalities(copy());
  return manage(res);
}

unsigned int set::dim(enum dim type) const {
  auto res = isl_set_dim(get(), static_cast<enum isl_dim_type>(type));
  return res;
}

pw_aff set::dim_max(int pos) const {
  auto res = isl_set_dim_max(copy(), pos);
  return manage(res);
}

pw_aff set::dim_min(int pos) const {
  auto res = isl_set_dim_min(copy(), pos);
  return manage(res);
}

set set::flatten() const {
  auto res = isl_set_flatten(copy());
  return manage(res);
}

stat set::foreach_basic_set(std::function<stat(basic_set)> &&fn) const {
  auto fn_lambda = [](isl_basic_set *arg_0, void *arg_1) -> isl_stat {
    auto *func = (std::function<stat(basic_set)> *)arg_1;
    stat ret = (*func)(isl::manage(arg_0));
    return isl_stat(ret);
  };
  auto res = isl_set_foreach_basic_set(get(), fn_lambda, &fn);
  return stat(res);
}

set set::gist(set context) const {
  auto res = isl_set_gist(copy(), context.release());
  return manage(res);
}

map set::identity() const {
  auto res = isl_set_identity(copy());
  return manage(res);
}

set set::intersect(set set2) const {
  auto res = isl_set_intersect(copy(), set2.release());
  return manage(res);
}

set set::intersect_params(set params) const {
  auto res = isl_set_intersect_params(copy(), params.release());
  return manage(res);
}

boolean set::is_bounded() const {
  auto res = isl_set_is_bounded(get());
  return res;
}

boolean set::is_disjoint(const set &set2) const {
  auto res = isl_set_is_disjoint(get(), set2.get());
  return res;
}

boolean set::is_empty() const {
  auto res = isl_set_is_empty(get());
  return res;
}

boolean set::is_equal(const set &set2) const {
  auto res = isl_set_is_equal(get(), set2.get());
  return res;
}

boolean set::is_strict_subset(const set &set2) const {
  auto res = isl_set_is_strict_subset(get(), set2.get());
  return res;
}

boolean set::is_subset(const set &set2) const {
  auto res = isl_set_is_subset(get(), set2.get());
  return res;
}

boolean set::is_wrapping() const {
  auto res = isl_set_is_wrapping(get());
  return res;
}

set set::lexmax() const {
  auto res = isl_set_lexmax(copy());
  return manage(res);
}

set set::lexmin() const {
  auto res = isl_set_lexmin(copy());
  return manage(res);
}

val set::max_val(const aff &obj) const {
  auto res = isl_set_max_val(get(), obj.get());
  return manage(res);
}

val set::min_val(const aff &obj) const {
  auto res = isl_set_min_val(get(), obj.get());
  return manage(res);
}

basic_set set::polyhedral_hull() const {
  auto res = isl_set_polyhedral_hull(copy());
  return manage(res);
}

set set::project_out(enum dim type, unsigned int first, unsigned int n) const {
  auto res = isl_set_project_out(copy(), static_cast<enum isl_dim_type>(type), first, n);
  return manage(res);
}

basic_set set::sample() const {
  auto res = isl_set_sample(copy());
  return manage(res);
}

point set::sample_point() const {
  auto res = isl_set_sample_point(copy());
  return manage(res);
}

set set::subtract(set set2) const {
  auto res = isl_set_subtract(copy(), set2.release());
  return manage(res);
}

set set::unite(set set2) const {
  auto res = isl_set_union(copy(), set2.release());
  return manage(res);
}

set set::universe(space dim) {
  auto res = isl_set_universe(dim.release());
  return manage(res);
}

basic_set set::unshifted_simple_hull() const {
  auto res = isl_set_unshifted_simple_hull(copy());
  return manage(res);
}

// implementations for isl::space
space manage(__isl_take isl_space *ptr) {
  return space(ptr);
}

space give(__isl_take isl_space *ptr) {
  return manage(ptr);
}

space::space()
    : ptr(nullptr) {}

space::space(const space &obj)
    : ptr(obj.copy()) {}

space::space(std::nullptr_t)
    : ptr(nullptr) {}

space::space(__isl_take isl_space *ptr)
    : ptr(ptr) {}

space::space(ctx ctx, unsigned int nparam, unsigned int n_in, unsigned int n_out) {
  auto res = isl_space_alloc(ctx.release(), nparam, n_in, n_out);
  ptr = res;
}

space::space(ctx ctx, unsigned int nparam, unsigned int dim) {
  auto res = isl_space_set_alloc(ctx.release(), nparam, dim);
  ptr = res;
}

space &space::operator=(space obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

space::~space() {
  if (ptr)
    isl_space_free(ptr);
}

__isl_give isl_space *space::copy() const & {
  return isl_space_copy(ptr);
}

__isl_keep isl_space *space::get() const {
  return ptr;
}

__isl_give isl_space *space::release() {
  isl_space *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_space *space::keep() const {
  return get();
}

__isl_give isl_space *space::take() {
  return release();
}

space::operator bool() const {
  return !is_null();
}

ctx space::get_ctx() const {
  return ctx(isl_space_get_ctx(ptr));
}

bool space::is_null() const {
  return ptr == nullptr;
}

std::string space::to_str() const {
  char *Tmp = isl_space_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
                                     const space &Obj) {
  OS << Obj.to_str();
  return OS;
}

space space::domain() const {
  auto res = isl_space_domain(copy());
  return manage(res);
}

boolean space::is_equal(const space &space2) const {
  auto res = isl_space_is_equal(get(), space2.get());
  return res;
}

space space::params() const {
  auto res = isl_space_params(copy());
  return manage(res);
}

space space::set_from_params() const {
  auto res = isl_space_set_from_params(copy());
  return manage(res);
}

// implementations for isl::union_access_info
union_access_info manage(__isl_take isl_union_access_info *ptr) {
  return union_access_info(ptr);
}

union_access_info give(__isl_take isl_union_access_info *ptr) {
  return manage(ptr);
}

union_access_info::union_access_info()
    : ptr(nullptr) {}

union_access_info::union_access_info(const union_access_info &obj)
    : ptr(obj.copy()) {}

union_access_info::union_access_info(std::nullptr_t)
    : ptr(nullptr) {}

union_access_info::union_access_info(__isl_take isl_union_access_info *ptr)
    : ptr(ptr) {}

union_access_info::union_access_info(union_map sink) {
  auto res = isl_union_access_info_from_sink(sink.release());
  ptr = res;
}

union_access_info &union_access_info::operator=(union_access_info obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

union_access_info::~union_access_info() {
  if (ptr)
    isl_union_access_info_free(ptr);
}

__isl_give isl_union_access_info *union_access_info::copy() const & {
  return isl_union_access_info_copy(ptr);
}

__isl_keep isl_union_access_info *union_access_info::get() const {
  return ptr;
}

__isl_give isl_union_access_info *union_access_info::release() {
  isl_union_access_info *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_union_access_info *union_access_info::keep() const {
  return get();
}

__isl_give isl_union_access_info *union_access_info::take() {
  return release();
}

union_access_info::operator bool() const {
  return !is_null();
}

ctx union_access_info::get_ctx() const {
  return ctx(isl_union_access_info_get_ctx(ptr));
}

bool union_access_info::is_null() const {
  return ptr == nullptr;
}

std::string union_access_info::to_str() const {
  char *Tmp = isl_union_access_info_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
                                     const union_access_info &Obj) {
  OS << Obj.to_str();
  return OS;
}

union_flow union_access_info::compute_flow() const {
  auto res = isl_union_access_info_compute_flow(copy());
  return manage(res);
}

union_access_info union_access_info::set_may_source(union_map may_source) const {
  auto res = isl_union_access_info_set_may_source(copy(), may_source.release());
  return manage(res);
}

union_access_info union_access_info::set_must_source(union_map must_source) const {
  auto res = isl_union_access_info_set_must_source(copy(), must_source.release());
  return manage(res);
}

union_access_info union_access_info::set_schedule(schedule schedule) const {
  auto res = isl_union_access_info_set_schedule(copy(), schedule.release());
  return manage(res);
}

union_access_info union_access_info::set_schedule_map(union_map schedule_map) const {
  auto res = isl_union_access_info_set_schedule_map(copy(), schedule_map.release());
  return manage(res);
}

// implementations for isl::union_flow
union_flow manage(__isl_take isl_union_flow *ptr) {
  return union_flow(ptr);
}

union_flow give(__isl_take isl_union_flow *ptr) {
  return manage(ptr);
}

union_flow::union_flow()
    : ptr(nullptr) {}

union_flow::union_flow(const union_flow &obj)
    : ptr(obj.copy()) {}

union_flow::union_flow(std::nullptr_t)
    : ptr(nullptr) {}

union_flow::union_flow(__isl_take isl_union_flow *ptr)
    : ptr(ptr) {}

union_flow &union_flow::operator=(union_flow obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

union_flow::~union_flow() {
  if (ptr)
    isl_union_flow_free(ptr);
}

__isl_give isl_union_flow *union_flow::copy() const & {
  return isl_union_flow_copy(ptr);
}

__isl_keep isl_union_flow *union_flow::get() const {
  return ptr;
}

__isl_give isl_union_flow *union_flow::release() {
  isl_union_flow *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_union_flow *union_flow::keep() const {
  return get();
}

__isl_give isl_union_flow *union_flow::take() {
  return release();
}

union_flow::operator bool() const {
  return !is_null();
}

ctx union_flow::get_ctx() const {
  return ctx(isl_union_flow_get_ctx(ptr));
}

bool union_flow::is_null() const {
  return ptr == nullptr;
}

std::string union_flow::to_str() const {
  char *Tmp = isl_union_flow_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
                                     const union_flow &Obj) {
  OS << Obj.to_str();
  return OS;
}

union_map union_flow::get_full_may_dependence() const {
  auto res = isl_union_flow_get_full_may_dependence(get());
  return manage(res);
}

union_map union_flow::get_full_must_dependence() const {
  auto res = isl_union_flow_get_full_must_dependence(get());
  return manage(res);
}

union_map union_flow::get_may_dependence() const {
  auto res = isl_union_flow_get_may_dependence(get());
  return manage(res);
}

union_map union_flow::get_may_no_source() const {
  auto res = isl_union_flow_get_may_no_source(get());
  return manage(res);
}

union_map union_flow::get_must_dependence() const {
  auto res = isl_union_flow_get_must_dependence(get());
  return manage(res);
}

union_map union_flow::get_must_no_source() const {
  auto res = isl_union_flow_get_must_no_source(get());
  return manage(res);
}

// implementations for isl::union_map
union_map manage(__isl_take isl_union_map *ptr) {
  return union_map(ptr);
}

union_map give(__isl_take isl_union_map *ptr) {
  return manage(ptr);
}

union_map::union_map()
    : ptr(nullptr) {}

union_map::union_map(const union_map &obj)
    : ptr(obj.copy()) {}

union_map::union_map(std::nullptr_t)
    : ptr(nullptr) {}

union_map::union_map(__isl_take isl_union_map *ptr)
    : ptr(ptr) {}

union_map::union_map(union_pw_aff upa) {
  auto res = isl_union_map_from_union_pw_aff(upa.release());
  ptr = res;
}

union_map::union_map(basic_map bmap) {
  auto res = isl_union_map_from_basic_map(bmap.release());
  ptr = res;
}

union_map::union_map(map map) {
  auto res = isl_union_map_from_map(map.release());
  ptr = res;
}

union_map::union_map(ctx ctx, const std::string &str) {
  auto res = isl_union_map_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}

union_map &union_map::operator=(union_map obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

union_map::~union_map() {
  if (ptr)
    isl_union_map_free(ptr);
}

__isl_give isl_union_map *union_map::copy() const & {
  return isl_union_map_copy(ptr);
}

__isl_keep isl_union_map *union_map::get() const {
  return ptr;
}

__isl_give isl_union_map *union_map::release() {
  isl_union_map *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_union_map *union_map::keep() const {
  return get();
}

__isl_give isl_union_map *union_map::take() {
  return release();
}

union_map::operator bool() const {
  return !is_null();
}

ctx union_map::get_ctx() const {
  return ctx(isl_union_map_get_ctx(ptr));
}

bool union_map::is_null() const {
  return ptr == nullptr;
}

std::string union_map::to_str() const {
  char *Tmp = isl_union_map_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
                                     const union_map &Obj) {
  OS << Obj.to_str();
  return OS;
}

union_map union_map::add_map(map map) const {
  auto res = isl_union_map_add_map(copy(), map.release());
  return manage(res);
}

union_map union_map::affine_hull() const {
  auto res = isl_union_map_affine_hull(copy());
  return manage(res);
}

union_map union_map::apply_domain(union_map umap2) const {
  auto res = isl_union_map_apply_domain(copy(), umap2.release());
  return manage(res);
}

union_map union_map::apply_range(union_map umap2) const {
  auto res = isl_union_map_apply_range(copy(), umap2.release());
  return manage(res);
}

union_map union_map::coalesce() const {
  auto res = isl_union_map_coalesce(copy());
  return manage(res);
}

union_map union_map::compute_divs() const {
  auto res = isl_union_map_compute_divs(copy());
  return manage(res);
}

union_set union_map::deltas() const {
  auto res = isl_union_map_deltas(copy());
  return manage(res);
}

union_map union_map::detect_equalities() const {
  auto res = isl_union_map_detect_equalities(copy());
  return manage(res);
}

union_set union_map::domain() const {
  auto res = isl_union_map_domain(copy());
  return manage(res);
}

union_map union_map::domain_factor_domain() const {
  auto res = isl_union_map_domain_factor_domain(copy());
  return manage(res);
}

union_map union_map::domain_factor_range() const {
  auto res = isl_union_map_domain_factor_range(copy());
  return manage(res);
}

union_map union_map::domain_map() const {
  auto res = isl_union_map_domain_map(copy());
  return manage(res);
}

union_pw_multi_aff union_map::domain_map_union_pw_multi_aff() const {
  auto res = isl_union_map_domain_map_union_pw_multi_aff(copy());
  return manage(res);
}

union_map union_map::domain_product(union_map umap2) const {
  auto res = isl_union_map_domain_product(copy(), umap2.release());
  return manage(res);
}

union_map union_map::empty(space dim) {
  auto res = isl_union_map_empty(dim.release());
  return manage(res);
}

union_map union_map::factor_domain() const {
  auto res = isl_union_map_factor_domain(copy());
  return manage(res);
}

union_map union_map::factor_range() const {
  auto res = isl_union_map_factor_range(copy());
  return manage(res);
}

union_map union_map::fixed_power(val exp) const {
  auto res = isl_union_map_fixed_power_val(copy(), exp.release());
  return manage(res);
}

union_map union_map::flat_range_product(union_map umap2) const {
  auto res = isl_union_map_flat_range_product(copy(), umap2.release());
  return manage(res);
}

stat union_map::foreach_map(std::function<stat(map)> &&fn) const {
  auto fn_lambda = [](isl_map *arg_0, void *arg_1) -> isl_stat {
    auto *func = (std::function<stat(map)> *)arg_1;
    stat ret = (*func)(isl::manage(arg_0));
    return isl_stat(ret);
  };
  auto res = isl_union_map_foreach_map(get(), fn_lambda, &fn);
  return stat(res);
}

union_map union_map::from(union_pw_multi_aff upma) {
  auto res = isl_union_map_from_union_pw_multi_aff(upma.release());
  return manage(res);
}

union_map union_map::from(multi_union_pw_aff mupa) {
  auto res = isl_union_map_from_multi_union_pw_aff(mupa.release());
  return manage(res);
}

union_map union_map::from_domain_and_range(union_set domain, union_set range) {
  auto res = isl_union_map_from_domain_and_range(domain.release(), range.release());
  return manage(res);
}

space union_map::get_space() const {
  auto res = isl_union_map_get_space(get());
  return manage(res);
}

union_map union_map::gist(union_map context) const {
  auto res = isl_union_map_gist(copy(), context.release());
  return manage(res);
}

union_map union_map::gist_domain(union_set uset) const {
  auto res = isl_union_map_gist_domain(copy(), uset.release());
  return manage(res);
}

union_map union_map::gist_params(set set) const {
  auto res = isl_union_map_gist_params(copy(), set.release());
  return manage(res);
}

union_map union_map::gist_range(union_set uset) const {
  auto res = isl_union_map_gist_range(copy(), uset.release());
  return manage(res);
}

union_map union_map::intersect(union_map umap2) const {
  auto res = isl_union_map_intersect(copy(), umap2.release());
  return manage(res);
}

union_map union_map::intersect_domain(union_set uset) const {
  auto res = isl_union_map_intersect_domain(copy(), uset.release());
  return manage(res);
}

union_map union_map::intersect_params(set set) const {
  auto res = isl_union_map_intersect_params(copy(), set.release());
  return manage(res);
}

union_map union_map::intersect_range(union_set uset) const {
  auto res = isl_union_map_intersect_range(copy(), uset.release());
  return manage(res);
}

boolean union_map::is_bijective() const {
  auto res = isl_union_map_is_bijective(get());
  return res;
}

boolean union_map::is_empty() const {
  auto res = isl_union_map_is_empty(get());
  return res;
}

boolean union_map::is_equal(const union_map &umap2) const {
  auto res = isl_union_map_is_equal(get(), umap2.get());
  return res;
}

boolean union_map::is_injective() const {
  auto res = isl_union_map_is_injective(get());
  return res;
}

boolean union_map::is_single_valued() const {
  auto res = isl_union_map_is_single_valued(get());
  return res;
}

boolean union_map::is_strict_subset(const union_map &umap2) const {
  auto res = isl_union_map_is_strict_subset(get(), umap2.get());
  return res;
}

boolean union_map::is_subset(const union_map &umap2) const {
  auto res = isl_union_map_is_subset(get(), umap2.get());
  return res;
}

union_map union_map::lexmax() const {
  auto res = isl_union_map_lexmax(copy());
  return manage(res);
}

union_map union_map::lexmin() const {
  auto res = isl_union_map_lexmin(copy());
  return manage(res);
}

union_map union_map::polyhedral_hull() const {
  auto res = isl_union_map_polyhedral_hull(copy());
  return manage(res);
}

union_map union_map::product(union_map umap2) const {
  auto res = isl_union_map_product(copy(), umap2.release());
  return manage(res);
}

union_set union_map::range() const {
  auto res = isl_union_map_range(copy());
  return manage(res);
}

union_map union_map::range_factor_domain() const {
  auto res = isl_union_map_range_factor_domain(copy());
  return manage(res);
}

union_map union_map::range_factor_range() const {
  auto res = isl_union_map_range_factor_range(copy());
  return manage(res);
}

union_map union_map::range_map() const {
  auto res = isl_union_map_range_map(copy());
  return manage(res);
}

union_map union_map::range_product(union_map umap2) const {
  auto res = isl_union_map_range_product(copy(), umap2.release());
  return manage(res);
}

union_map union_map::reverse() const {
  auto res = isl_union_map_reverse(copy());
  return manage(res);
}

union_map union_map::subtract(union_map umap2) const {
  auto res = isl_union_map_subtract(copy(), umap2.release());
  return manage(res);
}

union_map union_map::subtract_domain(union_set dom) const {
  auto res = isl_union_map_subtract_domain(copy(), dom.release());
  return manage(res);
}

union_map union_map::subtract_range(union_set dom) const {
  auto res = isl_union_map_subtract_range(copy(), dom.release());
  return manage(res);
}

union_map union_map::unite(union_map umap2) const {
  auto res = isl_union_map_union(copy(), umap2.release());
  return manage(res);
}

union_set union_map::wrap() const {
  auto res = isl_union_map_wrap(copy());
  return manage(res);
}

union_map union_map::zip() const {
  auto res = isl_union_map_zip(copy());
  return manage(res);
}

// implementations for isl::union_pw_aff
union_pw_aff manage(__isl_take isl_union_pw_aff *ptr) {
  return union_pw_aff(ptr);
}

union_pw_aff give(__isl_take isl_union_pw_aff *ptr) {
  return manage(ptr);
}

union_pw_aff::union_pw_aff()
    : ptr(nullptr) {}

union_pw_aff::union_pw_aff(const union_pw_aff &obj)
    : ptr(obj.copy()) {}

union_pw_aff::union_pw_aff(std::nullptr_t)
    : ptr(nullptr) {}

union_pw_aff::union_pw_aff(__isl_take isl_union_pw_aff *ptr)
    : ptr(ptr) {}

union_pw_aff::union_pw_aff(pw_aff pa) {
  auto res = isl_union_pw_aff_from_pw_aff(pa.release());
  ptr = res;
}

union_pw_aff::union_pw_aff(union_set domain, val v) {
  auto res = isl_union_pw_aff_val_on_domain(domain.release(), v.release());
  ptr = res;
}

union_pw_aff::union_pw_aff(ctx ctx, const std::string &str) {
  auto res = isl_union_pw_aff_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}

union_pw_aff &union_pw_aff::operator=(union_pw_aff obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

union_pw_aff::~union_pw_aff() {
  if (ptr)
    isl_union_pw_aff_free(ptr);
}

__isl_give isl_union_pw_aff *union_pw_aff::copy() const & {
  return isl_union_pw_aff_copy(ptr);
}

__isl_keep isl_union_pw_aff *union_pw_aff::get() const {
  return ptr;
}

__isl_give isl_union_pw_aff *union_pw_aff::release() {
  isl_union_pw_aff *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_union_pw_aff *union_pw_aff::keep() const {
  return get();
}

__isl_give isl_union_pw_aff *union_pw_aff::take() {
  return release();
}

union_pw_aff::operator bool() const {
  return !is_null();
}

ctx union_pw_aff::get_ctx() const {
  return ctx(isl_union_pw_aff_get_ctx(ptr));
}

bool union_pw_aff::is_null() const {
  return ptr == nullptr;
}

std::string union_pw_aff::to_str() const {
  char *Tmp = isl_union_pw_aff_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
                                     const union_pw_aff &Obj) {
  OS << Obj.to_str();
  return OS;
}

union_pw_aff union_pw_aff::add(union_pw_aff upa2) const {
  auto res = isl_union_pw_aff_add(copy(), upa2.release());
  return manage(res);
}

union_pw_aff union_pw_aff::empty(space space) {
  auto res = isl_union_pw_aff_empty(space.release());
  return manage(res);
}

stat union_pw_aff::foreach_pw_aff(std::function<stat(pw_aff)> &&fn) const {
  auto fn_lambda = [](isl_pw_aff *arg_0, void *arg_1) -> isl_stat {
    auto *func = (std::function<stat(pw_aff)> *)arg_1;
    stat ret = (*func)(isl::manage(arg_0));
    return isl_stat(ret);
  };
  auto res = isl_union_pw_aff_foreach_pw_aff(get(), fn_lambda, &fn);
  return stat(res);
}

space union_pw_aff::get_space() const {
  auto res = isl_union_pw_aff_get_space(get());
  return manage(res);
}

union_pw_aff union_pw_aff::pullback(union_pw_multi_aff upma) const {
  auto res = isl_union_pw_aff_pullback_union_pw_multi_aff(copy(), upma.release());
  return manage(res);
}

union_pw_aff union_pw_aff::sub(union_pw_aff upa2) const {
  auto res = isl_union_pw_aff_sub(copy(), upa2.release());
  return manage(res);
}

union_pw_aff union_pw_aff::union_add(union_pw_aff upa2) const {
  auto res = isl_union_pw_aff_union_add(copy(), upa2.release());
  return manage(res);
}

// implementations for isl::union_pw_multi_aff
union_pw_multi_aff manage(__isl_take isl_union_pw_multi_aff *ptr) {
  return union_pw_multi_aff(ptr);
}

union_pw_multi_aff give(__isl_take isl_union_pw_multi_aff *ptr) {
  return manage(ptr);
}

union_pw_multi_aff::union_pw_multi_aff()
    : ptr(nullptr) {}

union_pw_multi_aff::union_pw_multi_aff(const union_pw_multi_aff &obj)
    : ptr(obj.copy()) {}

union_pw_multi_aff::union_pw_multi_aff(std::nullptr_t)
    : ptr(nullptr) {}

union_pw_multi_aff::union_pw_multi_aff(__isl_take isl_union_pw_multi_aff *ptr)
    : ptr(ptr) {}

union_pw_multi_aff::union_pw_multi_aff(pw_multi_aff pma) {
  auto res = isl_union_pw_multi_aff_from_pw_multi_aff(pma.release());
  ptr = res;
}

union_pw_multi_aff::union_pw_multi_aff(union_set uset) {
  auto res = isl_union_pw_multi_aff_from_domain(uset.release());
  ptr = res;
}

union_pw_multi_aff::union_pw_multi_aff(union_map umap) {
  auto res = isl_union_pw_multi_aff_from_union_map(umap.release());
  ptr = res;
}

union_pw_multi_aff::union_pw_multi_aff(ctx ctx, const std::string &str) {
  auto res = isl_union_pw_multi_aff_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}

union_pw_multi_aff::union_pw_multi_aff(union_pw_aff upa) {
  auto res = isl_union_pw_multi_aff_from_union_pw_aff(upa.release());
  ptr = res;
}

union_pw_multi_aff &union_pw_multi_aff::operator=(union_pw_multi_aff obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

union_pw_multi_aff::~union_pw_multi_aff() {
  if (ptr)
    isl_union_pw_multi_aff_free(ptr);
}

__isl_give isl_union_pw_multi_aff *union_pw_multi_aff::copy() const & {
  return isl_union_pw_multi_aff_copy(ptr);
}

__isl_keep isl_union_pw_multi_aff *union_pw_multi_aff::get() const {
  return ptr;
}

__isl_give isl_union_pw_multi_aff *union_pw_multi_aff::release() {
  isl_union_pw_multi_aff *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_union_pw_multi_aff *union_pw_multi_aff::keep() const {
  return get();
}

__isl_give isl_union_pw_multi_aff *union_pw_multi_aff::take() {
  return release();
}

union_pw_multi_aff::operator bool() const {
  return !is_null();
}

ctx union_pw_multi_aff::get_ctx() const {
  return ctx(isl_union_pw_multi_aff_get_ctx(ptr));
}

bool union_pw_multi_aff::is_null() const {
  return ptr == nullptr;
}

std::string union_pw_multi_aff::to_str() const {
  char *Tmp = isl_union_pw_multi_aff_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
                                     const union_pw_multi_aff &Obj) {
  OS << Obj.to_str();
  return OS;
}

union_pw_multi_aff union_pw_multi_aff::add(union_pw_multi_aff upma2) const {
  auto res = isl_union_pw_multi_aff_add(copy(), upma2.release());
  return manage(res);
}

union_pw_multi_aff union_pw_multi_aff::flat_range_product(union_pw_multi_aff upma2) const {
  auto res = isl_union_pw_multi_aff_flat_range_product(copy(), upma2.release());
  return manage(res);
}

union_pw_multi_aff union_pw_multi_aff::pullback(union_pw_multi_aff upma2) const {
  auto res = isl_union_pw_multi_aff_pullback_union_pw_multi_aff(copy(), upma2.release());
  return manage(res);
}

union_pw_multi_aff union_pw_multi_aff::union_add(union_pw_multi_aff upma2) const {
  auto res = isl_union_pw_multi_aff_union_add(copy(), upma2.release());
  return manage(res);
}

// implementations for isl::union_set
union_set manage(__isl_take isl_union_set *ptr) {
  return union_set(ptr);
}

union_set give(__isl_take isl_union_set *ptr) {
  return manage(ptr);
}

union_set::union_set()
    : ptr(nullptr) {}

union_set::union_set(const union_set &obj)
    : ptr(obj.copy()) {}

union_set::union_set(std::nullptr_t)
    : ptr(nullptr) {}

union_set::union_set(__isl_take isl_union_set *ptr)
    : ptr(ptr) {}

union_set::union_set(basic_set bset) {
  auto res = isl_union_set_from_basic_set(bset.release());
  ptr = res;
}

union_set::union_set(set set) {
  auto res = isl_union_set_from_set(set.release());
  ptr = res;
}

union_set::union_set(point pnt) {
  auto res = isl_union_set_from_point(pnt.release());
  ptr = res;
}

union_set::union_set(ctx ctx, const std::string &str) {
  auto res = isl_union_set_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}

union_set &union_set::operator=(union_set obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

union_set::~union_set() {
  if (ptr)
    isl_union_set_free(ptr);
}

__isl_give isl_union_set *union_set::copy() const & {
  return isl_union_set_copy(ptr);
}

__isl_keep isl_union_set *union_set::get() const {
  return ptr;
}

__isl_give isl_union_set *union_set::release() {
  isl_union_set *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_union_set *union_set::keep() const {
  return get();
}

__isl_give isl_union_set *union_set::take() {
  return release();
}

union_set::operator bool() const {
  return !is_null();
}

ctx union_set::get_ctx() const {
  return ctx(isl_union_set_get_ctx(ptr));
}

bool union_set::is_null() const {
  return ptr == nullptr;
}

std::string union_set::to_str() const {
  char *Tmp = isl_union_set_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
                                     const union_set &Obj) {
  OS << Obj.to_str();
  return OS;
}

union_set union_set::affine_hull() const {
  auto res = isl_union_set_affine_hull(copy());
  return manage(res);
}

union_set union_set::apply(union_map umap) const {
  auto res = isl_union_set_apply(copy(), umap.release());
  return manage(res);
}

union_set union_set::coalesce() const {
  auto res = isl_union_set_coalesce(copy());
  return manage(res);
}

union_set union_set::compute_divs() const {
  auto res = isl_union_set_compute_divs(copy());
  return manage(res);
}

union_set union_set::detect_equalities() const {
  auto res = isl_union_set_detect_equalities(copy());
  return manage(res);
}

stat union_set::foreach_point(std::function<stat(point)> &&fn) const {
  auto fn_lambda = [](isl_point *arg_0, void *arg_1) -> isl_stat {
    auto *func = (std::function<stat(point)> *)arg_1;
    stat ret = (*func)(isl::manage(arg_0));
    return isl_stat(ret);
  };
  auto res = isl_union_set_foreach_point(get(), fn_lambda, &fn);
  return stat(res);
}

stat union_set::foreach_set(std::function<stat(set)> &&fn) const {
  auto fn_lambda = [](isl_set *arg_0, void *arg_1) -> isl_stat {
    auto *func = (std::function<stat(set)> *)arg_1;
    stat ret = (*func)(isl::manage(arg_0));
    return isl_stat(ret);
  };
  auto res = isl_union_set_foreach_set(get(), fn_lambda, &fn);
  return stat(res);
}

union_set union_set::gist(union_set context) const {
  auto res = isl_union_set_gist(copy(), context.release());
  return manage(res);
}

union_set union_set::gist_params(set set) const {
  auto res = isl_union_set_gist_params(copy(), set.release());
  return manage(res);
}

union_map union_set::identity() const {
  auto res = isl_union_set_identity(copy());
  return manage(res);
}

union_set union_set::intersect(union_set uset2) const {
  auto res = isl_union_set_intersect(copy(), uset2.release());
  return manage(res);
}

union_set union_set::intersect_params(set set) const {
  auto res = isl_union_set_intersect_params(copy(), set.release());
  return manage(res);
}

boolean union_set::is_empty() const {
  auto res = isl_union_set_is_empty(get());
  return res;
}

boolean union_set::is_equal(const union_set &uset2) const {
  auto res = isl_union_set_is_equal(get(), uset2.get());
  return res;
}

boolean union_set::is_strict_subset(const union_set &uset2) const {
  auto res = isl_union_set_is_strict_subset(get(), uset2.get());
  return res;
}

boolean union_set::is_subset(const union_set &uset2) const {
  auto res = isl_union_set_is_subset(get(), uset2.get());
  return res;
}

union_set union_set::lexmax() const {
  auto res = isl_union_set_lexmax(copy());
  return manage(res);
}

union_set union_set::lexmin() const {
  auto res = isl_union_set_lexmin(copy());
  return manage(res);
}

union_set union_set::polyhedral_hull() const {
  auto res = isl_union_set_polyhedral_hull(copy());
  return manage(res);
}

point union_set::sample_point() const {
  auto res = isl_union_set_sample_point(copy());
  return manage(res);
}

union_set union_set::subtract(union_set uset2) const {
  auto res = isl_union_set_subtract(copy(), uset2.release());
  return manage(res);
}

union_set union_set::unite(union_set uset2) const {
  auto res = isl_union_set_union(copy(), uset2.release());
  return manage(res);
}

union_map union_set::unwrap() const {
  auto res = isl_union_set_unwrap(copy());
  return manage(res);
}

// implementations for isl::val
val manage(__isl_take isl_val *ptr) {
  return val(ptr);
}

val give(__isl_take isl_val *ptr) {
  return manage(ptr);
}

val::val()
    : ptr(nullptr) {}

val::val(const val &obj)
    : ptr(obj.copy()) {}

val::val(std::nullptr_t)
    : ptr(nullptr) {}

val::val(__isl_take isl_val *ptr)
    : ptr(ptr) {}

val::val(ctx ctx, long i) {
  auto res = isl_val_int_from_si(ctx.release(), i);
  ptr = res;
}

val::val(ctx ctx, const std::string &str) {
  auto res = isl_val_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}

val &val::operator=(val obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

val::~val() {
  if (ptr)
    isl_val_free(ptr);
}

__isl_give isl_val *val::copy() const & {
  return isl_val_copy(ptr);
}

__isl_keep isl_val *val::get() const {
  return ptr;
}

__isl_give isl_val *val::release() {
  isl_val *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_val *val::keep() const {
  return get();
}

__isl_give isl_val *val::take() {
  return release();
}

val::operator bool() const {
  return !is_null();
}

ctx val::get_ctx() const {
  return ctx(isl_val_get_ctx(ptr));
}

bool val::is_null() const {
  return ptr == nullptr;
}

std::string val::to_str() const {
  char *Tmp = isl_val_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
                                     const val &Obj) {
  OS << Obj.to_str();
  return OS;
}

val val::two_exp() const {
  auto res = isl_val_2exp(copy());
  return manage(res);
}

val val::abs() const {
  auto res = isl_val_abs(copy());
  return manage(res);
}

boolean val::abs_eq(const val &v2) const {
  auto res = isl_val_abs_eq(get(), v2.get());
  return res;
}

val val::add(val v2) const {
  auto res = isl_val_add(copy(), v2.release());
  return manage(res);
}

val val::add_ui(unsigned long v2) const {
  auto res = isl_val_add_ui(copy(), v2);
  return manage(res);
}

val val::ceil() const {
  auto res = isl_val_ceil(copy());
  return manage(res);
}

int val::cmp_si(long i) const {
  auto res = isl_val_cmp_si(get(), i);
  return res;
}

val val::div(val v2) const {
  auto res = isl_val_div(copy(), v2.release());
  return manage(res);
}

boolean val::eq(const val &v2) const {
  auto res = isl_val_eq(get(), v2.get());
  return res;
}

val val::floor() const {
  auto res = isl_val_floor(copy());
  return manage(res);
}

val val::gcd(val v2) const {
  auto res = isl_val_gcd(copy(), v2.release());
  return manage(res);
}

boolean val::ge(const val &v2) const {
  auto res = isl_val_ge(get(), v2.get());
  return res;
}

boolean val::gt(const val &v2) const {
  auto res = isl_val_gt(get(), v2.get());
  return res;
}

val val::infty(ctx ctx) {
  auto res = isl_val_infty(ctx.release());
  return manage(res);
}

val val::inv() const {
  auto res = isl_val_inv(copy());
  return manage(res);
}

boolean val::is_divisible_by(const val &v2) const {
  auto res = isl_val_is_divisible_by(get(), v2.get());
  return res;
}

boolean val::is_infty() const {
  auto res = isl_val_is_infty(get());
  return res;
}

boolean val::is_int() const {
  auto res = isl_val_is_int(get());
  return res;
}

boolean val::is_nan() const {
  auto res = isl_val_is_nan(get());
  return res;
}

boolean val::is_neg() const {
  auto res = isl_val_is_neg(get());
  return res;
}

boolean val::is_neginfty() const {
  auto res = isl_val_is_neginfty(get());
  return res;
}

boolean val::is_negone() const {
  auto res = isl_val_is_negone(get());
  return res;
}

boolean val::is_nonneg() const {
  auto res = isl_val_is_nonneg(get());
  return res;
}

boolean val::is_nonpos() const {
  auto res = isl_val_is_nonpos(get());
  return res;
}

boolean val::is_one() const {
  auto res = isl_val_is_one(get());
  return res;
}

boolean val::is_pos() const {
  auto res = isl_val_is_pos(get());
  return res;
}

boolean val::is_rat() const {
  auto res = isl_val_is_rat(get());
  return res;
}

boolean val::is_zero() const {
  auto res = isl_val_is_zero(get());
  return res;
}

boolean val::le(const val &v2) const {
  auto res = isl_val_le(get(), v2.get());
  return res;
}

boolean val::lt(const val &v2) const {
  auto res = isl_val_lt(get(), v2.get());
  return res;
}

val val::max(val v2) const {
  auto res = isl_val_max(copy(), v2.release());
  return manage(res);
}

val val::min(val v2) const {
  auto res = isl_val_min(copy(), v2.release());
  return manage(res);
}

val val::mod(val v2) const {
  auto res = isl_val_mod(copy(), v2.release());
  return manage(res);
}

val val::mul(val v2) const {
  auto res = isl_val_mul(copy(), v2.release());
  return manage(res);
}

val val::nan(ctx ctx) {
  auto res = isl_val_nan(ctx.release());
  return manage(res);
}

boolean val::ne(const val &v2) const {
  auto res = isl_val_ne(get(), v2.get());
  return res;
}

val val::neg() const {
  auto res = isl_val_neg(copy());
  return manage(res);
}

val val::neginfty(ctx ctx) {
  auto res = isl_val_neginfty(ctx.release());
  return manage(res);
}

val val::negone(ctx ctx) {
  auto res = isl_val_negone(ctx.release());
  return manage(res);
}

val val::one(ctx ctx) {
  auto res = isl_val_one(ctx.release());
  return manage(res);
}

int val::sgn() const {
  auto res = isl_val_sgn(get());
  return res;
}

val val::sub(val v2) const {
  auto res = isl_val_sub(copy(), v2.release());
  return manage(res);
}

val val::sub_ui(unsigned long v2) const {
  auto res = isl_val_sub_ui(copy(), v2);
  return manage(res);
}

val val::trunc() const {
  auto res = isl_val_trunc(copy());
  return manage(res);
}

val val::zero(ctx ctx) {
  auto res = isl_val_zero(ctx.release());
  return manage(res);
}
} // namespace noexceptions
} // namespace isl

#endif /* ISL_CPP_NOEXCEPTIONS */