/**
 * Copyright (c) 2021 OceanBase
 * OceanBase CE is licensed under Mulan PubL v2.
 * You can use this software according to the terms and conditions of the Mulan PubL v2.
 * You may obtain a copy of Mulan PubL v2 at:
 *          http://license.coscl.org.cn/MulanPubL-2.0
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PubL v2 for more details.
 */

#ifndef GMOCK_INCLUDE_GMOCK_GMOCK_GENERATED_ACTIONS_H_
#define GMOCK_INCLUDE_GMOCK_GMOCK_GENERATED_ACTIONS_H_

#include "gmock/gmock-actions.h"
#include "gmock/internal/gmock-port.h"

namespace testing {
namespace internal {

// InvokeHelper<F> knows how to unpack an N-tuple and invoke an N-ary
// function or method with the unpacked values, where F is a function
// type that takes N arguments.
template <typename Result, typename ArgumentTuple>
class InvokeHelper;

template <typename R>
class InvokeHelper<R, ::testing::tuple<> > {
 public:
  template <typename Function>
  static R Invoke(Function function, const ::testing::tuple<>&) {
           return function();
  }

  template <class Class, typename MethodPtr>
  static R InvokeMethod(Class* obj_ptr,
                        MethodPtr method_ptr,
                        const ::testing::tuple<>&) {
           return (obj_ptr->*method_ptr)();
  }
};

template <typename R, typename A1>
class InvokeHelper<R, ::testing::tuple<A1> > {
 public:
  template <typename Function>
  static R Invoke(Function function, const ::testing::tuple<A1>& args) {
           return function(get<0>(args));
  }

  template <class Class, typename MethodPtr>
  static R InvokeMethod(Class* obj_ptr,
                        MethodPtr method_ptr,
                        const ::testing::tuple<A1>& args) {
           return (obj_ptr->*method_ptr)(get<0>(args));
  }
};

template <typename R, typename A1, typename A2>
class InvokeHelper<R, ::testing::tuple<A1, A2> > {
 public:
  template <typename Function>
  static R Invoke(Function function, const ::testing::tuple<A1, A2>& args) {
           return function(get<0>(args), get<1>(args));
  }

  template <class Class, typename MethodPtr>
  static R InvokeMethod(Class* obj_ptr,
                        MethodPtr method_ptr,
                        const ::testing::tuple<A1, A2>& args) {
           return (obj_ptr->*method_ptr)(get<0>(args), get<1>(args));
  }
};

template <typename R, typename A1, typename A2, typename A3>
class InvokeHelper<R, ::testing::tuple<A1, A2, A3> > {
 public:
  template <typename Function>
  static R Invoke(Function function, const ::testing::tuple<A1, A2, A3>& args) {
           return function(get<0>(args), get<1>(args), get<2>(args));
  }

  template <class Class, typename MethodPtr>
  static R InvokeMethod(Class* obj_ptr,
                        MethodPtr method_ptr,
                        const ::testing::tuple<A1, A2, A3>& args) {
           return (obj_ptr->*method_ptr)(get<0>(args), get<1>(args),
               get<2>(args));
  }
};

template <typename R, typename A1, typename A2, typename A3, typename A4>
class InvokeHelper<R, ::testing::tuple<A1, A2, A3, A4> > {
 public:
  template <typename Function>
  static R Invoke(Function function, const ::testing::tuple<A1, A2, A3,
      A4>& args) {
           return function(get<0>(args), get<1>(args), get<2>(args),
               get<3>(args));
  }

  template <class Class, typename MethodPtr>
  static R InvokeMethod(Class* obj_ptr,
                        MethodPtr method_ptr,
                        const ::testing::tuple<A1, A2, A3, A4>& args) {
           return (obj_ptr->*method_ptr)(get<0>(args), get<1>(args),
               get<2>(args), get<3>(args));
  }
};

template <typename R, typename A1, typename A2, typename A3, typename A4,
    typename A5>
class InvokeHelper<R, ::testing::tuple<A1, A2, A3, A4, A5> > {
 public:
  template <typename Function>
  static R Invoke(Function function, const ::testing::tuple<A1, A2, A3, A4,
      A5>& args) {
           return function(get<0>(args), get<1>(args), get<2>(args),
               get<3>(args), get<4>(args));
  }

  template <class Class, typename MethodPtr>
  static R InvokeMethod(Class* obj_ptr,
                        MethodPtr method_ptr,
                        const ::testing::tuple<A1, A2, A3, A4, A5>& args) {
           return (obj_ptr->*method_ptr)(get<0>(args), get<1>(args),
               get<2>(args), get<3>(args), get<4>(args));
  }
};

template <typename R, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6>
class InvokeHelper<R, ::testing::tuple<A1, A2, A3, A4, A5, A6> > {
 public:
  template <typename Function>
  static R Invoke(Function function, const ::testing::tuple<A1, A2, A3, A4, A5,
      A6>& args) {
           return function(get<0>(args), get<1>(args), get<2>(args),
               get<3>(args), get<4>(args), get<5>(args));
  }

  template <class Class, typename MethodPtr>
  static R InvokeMethod(Class* obj_ptr,
                        MethodPtr method_ptr,
                        const ::testing::tuple<A1, A2, A3, A4, A5, A6>& args) {
           return (obj_ptr->*method_ptr)(get<0>(args), get<1>(args),
               get<2>(args), get<3>(args), get<4>(args), get<5>(args));
  }
};

template <typename R, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6, typename A7>
class InvokeHelper<R, ::testing::tuple<A1, A2, A3, A4, A5, A6, A7> > {
 public:
  template <typename Function>
  static R Invoke(Function function, const ::testing::tuple<A1, A2, A3, A4, A5,
      A6, A7>& args) {
           return function(get<0>(args), get<1>(args), get<2>(args),
               get<3>(args), get<4>(args), get<5>(args), get<6>(args));
  }

  template <class Class, typename MethodPtr>
  static R InvokeMethod(Class* obj_ptr,
                        MethodPtr method_ptr,
                        const ::testing::tuple<A1, A2, A3, A4, A5, A6,
                            A7>& args) {
           return (obj_ptr->*method_ptr)(get<0>(args), get<1>(args),
               get<2>(args), get<3>(args), get<4>(args), get<5>(args),
               get<6>(args));
  }
};

template <typename R, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6, typename A7, typename A8>
class InvokeHelper<R, ::testing::tuple<A1, A2, A3, A4, A5, A6, A7, A8> > {
 public:
  template <typename Function>
  static R Invoke(Function function, const ::testing::tuple<A1, A2, A3, A4, A5,
      A6, A7, A8>& args) {
           return function(get<0>(args), get<1>(args), get<2>(args),
               get<3>(args), get<4>(args), get<5>(args), get<6>(args),
               get<7>(args));
  }

  template <class Class, typename MethodPtr>
  static R InvokeMethod(Class* obj_ptr,
                        MethodPtr method_ptr,
                        const ::testing::tuple<A1, A2, A3, A4, A5, A6, A7,
                            A8>& args) {
           return (obj_ptr->*method_ptr)(get<0>(args), get<1>(args),
               get<2>(args), get<3>(args), get<4>(args), get<5>(args),
               get<6>(args), get<7>(args));
  }
};

template <typename R, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6, typename A7, typename A8, typename A9>
class InvokeHelper<R, ::testing::tuple<A1, A2, A3, A4, A5, A6, A7, A8, A9> > {
 public:
  template <typename Function>
  static R Invoke(Function function, const ::testing::tuple<A1, A2, A3, A4, A5,
      A6, A7, A8, A9>& args) {
           return function(get<0>(args), get<1>(args), get<2>(args),
               get<3>(args), get<4>(args), get<5>(args), get<6>(args),
               get<7>(args), get<8>(args));
  }

  template <class Class, typename MethodPtr>
  static R InvokeMethod(Class* obj_ptr,
                        MethodPtr method_ptr,
                        const ::testing::tuple<A1, A2, A3, A4, A5, A6, A7, A8,
                            A9>& args) {
           return (obj_ptr->*method_ptr)(get<0>(args), get<1>(args),
               get<2>(args), get<3>(args), get<4>(args), get<5>(args),
               get<6>(args), get<7>(args), get<8>(args));
  }
};

template <typename R, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6, typename A7, typename A8, typename A9,
    typename A10>
class InvokeHelper<R, ::testing::tuple<A1, A2, A3, A4, A5, A6, A7, A8, A9,
    A10> > {
 public:
  template <typename Function>
  static R Invoke(Function function, const ::testing::tuple<A1, A2, A3, A4, A5,
      A6, A7, A8, A9, A10>& args) {
           return function(get<0>(args), get<1>(args), get<2>(args),
               get<3>(args), get<4>(args), get<5>(args), get<6>(args),
               get<7>(args), get<8>(args), get<9>(args));
  }

  template <class Class, typename MethodPtr>
  static R InvokeMethod(Class* obj_ptr,
                        MethodPtr method_ptr,
                        const ::testing::tuple<A1, A2, A3, A4, A5, A6, A7, A8,
                            A9, A10>& args) {
           return (obj_ptr->*method_ptr)(get<0>(args), get<1>(args),
               get<2>(args), get<3>(args), get<4>(args), get<5>(args),
               get<6>(args), get<7>(args), get<8>(args), get<9>(args));
  }
};

// An INTERNAL macro for extracting the type of a tuple field.  It's
// subject to change without notice - DO NOT USE IN USER CODE!
#define GMOCK_FIELD_(Tuple, N) \
    typename ::testing::tuple_element<N, Tuple>::type

// SelectArgs<Result, ArgumentTuple, k1, k2, ..., k_n>::type is the
// type of an n-ary function whose i-th (1-based) argument type is the
// k{i}-th (0-based) field of ArgumentTuple, which must be a tuple
// type, and whose return type is Result.  For example,
//   SelectArgs<int, ::testing::tuple<bool, char, double, long>, 0, 3>::type
// is int(bool, long).
//
// SelectArgs<Result, ArgumentTuple, k1, k2, ..., k_n>::Select(args)
// returns the selected fields (k1, k2, ..., k_n) of args as a tuple.
// For example,
//   SelectArgs<int, tuple<bool, char, double>, 2, 0>::Select(
//       ::testing::make_tuple(true, 'a', 2.5))
// returns tuple (2.5, true).
//
// The numbers in list k1, k2, ..., k_n must be >= 0, where n can be
// in the range [0, 10].  Duplicates are allowed and they don't have
// to be in an ascending or descending order.

template <typename Result, typename ArgumentTuple, int k1, int k2, int k3,
    int k4, int k5, int k6, int k7, int k8, int k9, int k10>
class SelectArgs {
 public:
  typedef Result type(GMOCK_FIELD_(ArgumentTuple, k1),
      GMOCK_FIELD_(ArgumentTuple, k2), GMOCK_FIELD_(ArgumentTuple, k3),
      GMOCK_FIELD_(ArgumentTuple, k4), GMOCK_FIELD_(ArgumentTuple, k5),
      GMOCK_FIELD_(ArgumentTuple, k6), GMOCK_FIELD_(ArgumentTuple, k7),
      GMOCK_FIELD_(ArgumentTuple, k8), GMOCK_FIELD_(ArgumentTuple, k9),
      GMOCK_FIELD_(ArgumentTuple, k10));
  typedef typename Function<type>::ArgumentTuple SelectedArgs;
  static SelectedArgs Select(const ArgumentTuple& args) {
    return SelectedArgs(get<k1>(args), get<k2>(args), get<k3>(args),
        get<k4>(args), get<k5>(args), get<k6>(args), get<k7>(args),
        get<k8>(args), get<k9>(args), get<k10>(args));
  }
};

template <typename Result, typename ArgumentTuple>
class SelectArgs<Result, ArgumentTuple,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1> {
 public:
  typedef Result type();
  typedef typename Function<type>::ArgumentTuple SelectedArgs;
  static SelectedArgs Select(const ArgumentTuple& /* args */) {
    return SelectedArgs();
  }
};

template <typename Result, typename ArgumentTuple, int k1>
class SelectArgs<Result, ArgumentTuple,
                 k1, -1, -1, -1, -1, -1, -1, -1, -1, -1> {
 public:
  typedef Result type(GMOCK_FIELD_(ArgumentTuple, k1));
  typedef typename Function<type>::ArgumentTuple SelectedArgs;
  static SelectedArgs Select(const ArgumentTuple& args) {
    return SelectedArgs(get<k1>(args));
  }
};

template <typename Result, typename ArgumentTuple, int k1, int k2>
class SelectArgs<Result, ArgumentTuple,
                 k1, k2, -1, -1, -1, -1, -1, -1, -1, -1> {
 public:
  typedef Result type(GMOCK_FIELD_(ArgumentTuple, k1),
      GMOCK_FIELD_(ArgumentTuple, k2));
  typedef typename Function<type>::ArgumentTuple SelectedArgs;
  static SelectedArgs Select(const ArgumentTuple& args) {
    return SelectedArgs(get<k1>(args), get<k2>(args));
  }
};

template <typename Result, typename ArgumentTuple, int k1, int k2, int k3>
class SelectArgs<Result, ArgumentTuple,
                 k1, k2, k3, -1, -1, -1, -1, -1, -1, -1> {
 public:
  typedef Result type(GMOCK_FIELD_(ArgumentTuple, k1),
      GMOCK_FIELD_(ArgumentTuple, k2), GMOCK_FIELD_(ArgumentTuple, k3));
  typedef typename Function<type>::ArgumentTuple SelectedArgs;
  static SelectedArgs Select(const ArgumentTuple& args) {
    return SelectedArgs(get<k1>(args), get<k2>(args), get<k3>(args));
  }
};

template <typename Result, typename ArgumentTuple, int k1, int k2, int k3,
    int k4>
class SelectArgs<Result, ArgumentTuple,
                 k1, k2, k3, k4, -1, -1, -1, -1, -1, -1> {
 public:
  typedef Result type(GMOCK_FIELD_(ArgumentTuple, k1),
      GMOCK_FIELD_(ArgumentTuple, k2), GMOCK_FIELD_(ArgumentTuple, k3),
      GMOCK_FIELD_(ArgumentTuple, k4));
  typedef typename Function<type>::ArgumentTuple SelectedArgs;
  static SelectedArgs Select(const ArgumentTuple& args) {
    return SelectedArgs(get<k1>(args), get<k2>(args), get<k3>(args),
        get<k4>(args));
  }
};

template <typename Result, typename ArgumentTuple, int k1, int k2, int k3,
    int k4, int k5>
class SelectArgs<Result, ArgumentTuple,
                 k1, k2, k3, k4, k5, -1, -1, -1, -1, -1> {
 public:
  typedef Result type(GMOCK_FIELD_(ArgumentTuple, k1),
      GMOCK_FIELD_(ArgumentTuple, k2), GMOCK_FIELD_(ArgumentTuple, k3),
      GMOCK_FIELD_(ArgumentTuple, k4), GMOCK_FIELD_(ArgumentTuple, k5));
  typedef typename Function<type>::ArgumentTuple SelectedArgs;
  static SelectedArgs Select(const ArgumentTuple& args) {
    return SelectedArgs(get<k1>(args), get<k2>(args), get<k3>(args),
        get<k4>(args), get<k5>(args));
  }
};

template <typename Result, typename ArgumentTuple, int k1, int k2, int k3,
    int k4, int k5, int k6>
class SelectArgs<Result, ArgumentTuple,
                 k1, k2, k3, k4, k5, k6, -1, -1, -1, -1> {
 public:
  typedef Result type(GMOCK_FIELD_(ArgumentTuple, k1),
      GMOCK_FIELD_(ArgumentTuple, k2), GMOCK_FIELD_(ArgumentTuple, k3),
      GMOCK_FIELD_(ArgumentTuple, k4), GMOCK_FIELD_(ArgumentTuple, k5),
      GMOCK_FIELD_(ArgumentTuple, k6));
  typedef typename Function<type>::ArgumentTuple SelectedArgs;
  static SelectedArgs Select(const ArgumentTuple& args) {
    return SelectedArgs(get<k1>(args), get<k2>(args), get<k3>(args),
        get<k4>(args), get<k5>(args), get<k6>(args));
  }
};

template <typename Result, typename ArgumentTuple, int k1, int k2, int k3,
    int k4, int k5, int k6, int k7>
class SelectArgs<Result, ArgumentTuple,
                 k1, k2, k3, k4, k5, k6, k7, -1, -1, -1> {
 public:
  typedef Result type(GMOCK_FIELD_(ArgumentTuple, k1),
      GMOCK_FIELD_(ArgumentTuple, k2), GMOCK_FIELD_(ArgumentTuple, k3),
      GMOCK_FIELD_(ArgumentTuple, k4), GMOCK_FIELD_(ArgumentTuple, k5),
      GMOCK_FIELD_(ArgumentTuple, k6), GMOCK_FIELD_(ArgumentTuple, k7));
  typedef typename Function<type>::ArgumentTuple SelectedArgs;
  static SelectedArgs Select(const ArgumentTuple& args) {
    return SelectedArgs(get<k1>(args), get<k2>(args), get<k3>(args),
        get<k4>(args), get<k5>(args), get<k6>(args), get<k7>(args));
  }
};

template <typename Result, typename ArgumentTuple, int k1, int k2, int k3,
    int k4, int k5, int k6, int k7, int k8>
class SelectArgs<Result, ArgumentTuple,
                 k1, k2, k3, k4, k5, k6, k7, k8, -1, -1> {
 public:
  typedef Result type(GMOCK_FIELD_(ArgumentTuple, k1),
      GMOCK_FIELD_(ArgumentTuple, k2), GMOCK_FIELD_(ArgumentTuple, k3),
      GMOCK_FIELD_(ArgumentTuple, k4), GMOCK_FIELD_(ArgumentTuple, k5),
      GMOCK_FIELD_(ArgumentTuple, k6), GMOCK_FIELD_(ArgumentTuple, k7),
      GMOCK_FIELD_(ArgumentTuple, k8));
  typedef typename Function<type>::ArgumentTuple SelectedArgs;
  static SelectedArgs Select(const ArgumentTuple& args) {
    return SelectedArgs(get<k1>(args), get<k2>(args), get<k3>(args),
        get<k4>(args), get<k5>(args), get<k6>(args), get<k7>(args),
        get<k8>(args));
  }
};

template <typename Result, typename ArgumentTuple, int k1, int k2, int k3,
    int k4, int k5, int k6, int k7, int k8, int k9>
class SelectArgs<Result, ArgumentTuple,
                 k1, k2, k3, k4, k5, k6, k7, k8, k9, -1> {
 public:
  typedef Result type(GMOCK_FIELD_(ArgumentTuple, k1),
      GMOCK_FIELD_(ArgumentTuple, k2), GMOCK_FIELD_(ArgumentTuple, k3),
      GMOCK_FIELD_(ArgumentTuple, k4), GMOCK_FIELD_(ArgumentTuple, k5),
      GMOCK_FIELD_(ArgumentTuple, k6), GMOCK_FIELD_(ArgumentTuple, k7),
      GMOCK_FIELD_(ArgumentTuple, k8), GMOCK_FIELD_(ArgumentTuple, k9));
  typedef typename Function<type>::ArgumentTuple SelectedArgs;
  static SelectedArgs Select(const ArgumentTuple& args) {
    return SelectedArgs(get<k1>(args), get<k2>(args), get<k3>(args),
        get<k4>(args), get<k5>(args), get<k6>(args), get<k7>(args),
        get<k8>(args), get<k9>(args));
  }
};

#undef GMOCK_FIELD_

// Implements the WithArgs action.
template <typename InnerAction, int k1 = -1, int k2 = -1, int k3 = -1,
    int k4 = -1, int k5 = -1, int k6 = -1, int k7 = -1, int k8 = -1,
    int k9 = -1, int k10 = -1>
class WithArgsAction {
 public:
  explicit WithArgsAction(const InnerAction& action) : action_(action) {}

  template <typename F>
  operator Action<F>() const { return MakeAction(new Impl<F>(action_)); }

 private:
  template <typename F>
  class Impl : public ActionInterface<F> {
   public:
    typedef typename Function<F>::Result Result;
    typedef typename Function<F>::ArgumentTuple ArgumentTuple;

    explicit Impl(const InnerAction& action) : action_(action) {}

    virtual Result Perform(const ArgumentTuple& args) {
      return action_.Perform(SelectArgs<Result, ArgumentTuple, k1, k2, k3, k4,
          k5, k6, k7, k8, k9, k10>::Select(args));
    }

   private:
    typedef typename SelectArgs<Result, ArgumentTuple,
        k1, k2, k3, k4, k5, k6, k7, k8, k9, k10>::type InnerFunctionType;

    Action<InnerFunctionType> action_;
  };

  const InnerAction action_;

  GTEST_DISALLOW_ASSIGN_(WithArgsAction);
};

// A macro from the ACTION* family (defined later in this file)
// defines an action that can be used in a mock function.  Typically,
// these actions only care about a subset of the arguments of the mock
// function.  For example, if such an action only uses the second
// argument, it can be used in any mock function that takes >= 2
// arguments where the type of the second argument is compatible.
//
// Therefore, the action implementation must be prepared to take more
// arguments than it needs.  The ExcessiveArg type is used to
// represent those excessive arguments.  In order to keep the compiler
// error messages tractable, we define it in the testing namespace
// instead of testing::internal.  However, this is an INTERNAL TYPE
// and subject to change without notice, so a user MUST NOT USE THIS
// TYPE DIRECTLY.
struct ExcessiveArg {};

// A helper class needed for implementing the ACTION* macros.
template <typename Result, class Impl>
class ActionHelper {
 public:
  static Result Perform(Impl* impl, const ::testing::tuple<>& args) {
    return impl->template gmock_PerformImpl<>(args, ExcessiveArg(),
        ExcessiveArg(), ExcessiveArg(), ExcessiveArg(), ExcessiveArg(),
        ExcessiveArg(), ExcessiveArg(), ExcessiveArg(), ExcessiveArg(),
        ExcessiveArg());
  }

  template <typename A0>
  static Result Perform(Impl* impl, const ::testing::tuple<A0>& args) {
    return impl->template gmock_PerformImpl<A0>(args, get<0>(args),
        ExcessiveArg(), ExcessiveArg(), ExcessiveArg(), ExcessiveArg(),
        ExcessiveArg(), ExcessiveArg(), ExcessiveArg(), ExcessiveArg(),
        ExcessiveArg());
  }

  template <typename A0, typename A1>
  static Result Perform(Impl* impl, const ::testing::tuple<A0, A1>& args) {
    return impl->template gmock_PerformImpl<A0, A1>(args, get<0>(args),
        get<1>(args), ExcessiveArg(), ExcessiveArg(), ExcessiveArg(),
        ExcessiveArg(), ExcessiveArg(), ExcessiveArg(), ExcessiveArg(),
        ExcessiveArg());
  }

  template <typename A0, typename A1, typename A2>
  static Result Perform(Impl* impl, const ::testing::tuple<A0, A1, A2>& args) {
    return impl->template gmock_PerformImpl<A0, A1, A2>(args, get<0>(args),
        get<1>(args), get<2>(args), ExcessiveArg(), ExcessiveArg(),
        ExcessiveArg(), ExcessiveArg(), ExcessiveArg(), ExcessiveArg(),
        ExcessiveArg());
  }

  template <typename A0, typename A1, typename A2, typename A3>
  static Result Perform(Impl* impl, const ::testing::tuple<A0, A1, A2,
      A3>& args) {
    return impl->template gmock_PerformImpl<A0, A1, A2, A3>(args, get<0>(args),
        get<1>(args), get<2>(args), get<3>(args), ExcessiveArg(),
        ExcessiveArg(), ExcessiveArg(), ExcessiveArg(), ExcessiveArg(),
        ExcessiveArg());
  }

  template <typename A0, typename A1, typename A2, typename A3, typename A4>
  static Result Perform(Impl* impl, const ::testing::tuple<A0, A1, A2, A3,
      A4>& args) {
    return impl->template gmock_PerformImpl<A0, A1, A2, A3, A4>(args,
        get<0>(args), get<1>(args), get<2>(args), get<3>(args), get<4>(args),
        ExcessiveArg(), ExcessiveArg(), ExcessiveArg(), ExcessiveArg(),
        ExcessiveArg());
  }

  template <typename A0, typename A1, typename A2, typename A3, typename A4,
      typename A5>
  static Result Perform(Impl* impl, const ::testing::tuple<A0, A1, A2, A3, A4,
      A5>& args) {
    return impl->template gmock_PerformImpl<A0, A1, A2, A3, A4, A5>(args,
        get<0>(args), get<1>(args), get<2>(args), get<3>(args), get<4>(args),
        get<5>(args), ExcessiveArg(), ExcessiveArg(), ExcessiveArg(),
        ExcessiveArg());
  }

  template <typename A0, typename A1, typename A2, typename A3, typename A4,
      typename A5, typename A6>
  static Result Perform(Impl* impl, const ::testing::tuple<A0, A1, A2, A3, A4,
      A5, A6>& args) {
    return impl->template gmock_PerformImpl<A0, A1, A2, A3, A4, A5, A6>(args,
        get<0>(args), get<1>(args), get<2>(args), get<3>(args), get<4>(args),
        get<5>(args), get<6>(args), ExcessiveArg(), ExcessiveArg(),
        ExcessiveArg());
  }

  template <typename A0, typename A1, typename A2, typename A3, typename A4,
      typename A5, typename A6, typename A7>
  static Result Perform(Impl* impl, const ::testing::tuple<A0, A1, A2, A3, A4,
      A5, A6, A7>& args) {
    return impl->template gmock_PerformImpl<A0, A1, A2, A3, A4, A5, A6,
        A7>(args, get<0>(args), get<1>(args), get<2>(args), get<3>(args),
        get<4>(args), get<5>(args), get<6>(args), get<7>(args), ExcessiveArg(),
        ExcessiveArg());
  }

  template <typename A0, typename A1, typename A2, typename A3, typename A4,
      typename A5, typename A6, typename A7, typename A8>
  static Result Perform(Impl* impl, const ::testing::tuple<A0, A1, A2, A3, A4,
      A5, A6, A7, A8>& args) {
    return impl->template gmock_PerformImpl<A0, A1, A2, A3, A4, A5, A6, A7,
        A8>(args, get<0>(args), get<1>(args), get<2>(args), get<3>(args),
        get<4>(args), get<5>(args), get<6>(args), get<7>(args), get<8>(args),
        ExcessiveArg());
  }

  template <typename A0, typename A1, typename A2, typename A3, typename A4,
      typename A5, typename A6, typename A7, typename A8, typename A9>
  static Result Perform(Impl* impl, const ::testing::tuple<A0, A1, A2, A3, A4,
      A5, A6, A7, A8, A9>& args) {
    return impl->template gmock_PerformImpl<A0, A1, A2, A3, A4, A5, A6, A7, A8,
        A9>(args, get<0>(args), get<1>(args), get<2>(args), get<3>(args),
        get<4>(args), get<5>(args), get<6>(args), get<7>(args), get<8>(args),
        get<9>(args));
  }
};

}  // namespace internal

// Various overloads for Invoke().

// WithArgs<N1, N2, ..., Nk>(an_action) creates an action that passes
// the selected arguments of the mock function to an_action and
// performs it.  It serves as an adaptor between actions with
// different argument lists.  C++ doesn't support default arguments for
// function templates, so we have to overload it.
template <int k1, typename InnerAction>
inline internal::WithArgsAction<InnerAction, k1>
WithArgs(const InnerAction& action) {
  return internal::WithArgsAction<InnerAction, k1>(action);
}

template <int k1, int k2, typename InnerAction>
inline internal::WithArgsAction<InnerAction, k1, k2>
WithArgs(const InnerAction& action) {
  return internal::WithArgsAction<InnerAction, k1, k2>(action);
}

template <int k1, int k2, int k3, typename InnerAction>
inline internal::WithArgsAction<InnerAction, k1, k2, k3>
WithArgs(const InnerAction& action) {
  return internal::WithArgsAction<InnerAction, k1, k2, k3>(action);
}

template <int k1, int k2, int k3, int k4, typename InnerAction>
inline internal::WithArgsAction<InnerAction, k1, k2, k3, k4>
WithArgs(const InnerAction& action) {
  return internal::WithArgsAction<InnerAction, k1, k2, k3, k4>(action);
}

template <int k1, int k2, int k3, int k4, int k5, typename InnerAction>
inline internal::WithArgsAction<InnerAction, k1, k2, k3, k4, k5>
WithArgs(const InnerAction& action) {
  return internal::WithArgsAction<InnerAction, k1, k2, k3, k4, k5>(action);
}

template <int k1, int k2, int k3, int k4, int k5, int k6, typename InnerAction>
inline internal::WithArgsAction<InnerAction, k1, k2, k3, k4, k5, k6>
WithArgs(const InnerAction& action) {
  return internal::WithArgsAction<InnerAction, k1, k2, k3, k4, k5, k6>(action);
}

template <int k1, int k2, int k3, int k4, int k5, int k6, int k7,
    typename InnerAction>
inline internal::WithArgsAction<InnerAction, k1, k2, k3, k4, k5, k6, k7>
WithArgs(const InnerAction& action) {
  return internal::WithArgsAction<InnerAction, k1, k2, k3, k4, k5, k6,
      k7>(action);
}

template <int k1, int k2, int k3, int k4, int k5, int k6, int k7, int k8,
    typename InnerAction>
inline internal::WithArgsAction<InnerAction, k1, k2, k3, k4, k5, k6, k7, k8>
WithArgs(const InnerAction& action) {
  return internal::WithArgsAction<InnerAction, k1, k2, k3, k4, k5, k6, k7,
      k8>(action);
}

template <int k1, int k2, int k3, int k4, int k5, int k6, int k7, int k8,
    int k9, typename InnerAction>
inline internal::WithArgsAction<InnerAction, k1, k2, k3, k4, k5, k6, k7, k8, k9>
WithArgs(const InnerAction& action) {
  return internal::WithArgsAction<InnerAction, k1, k2, k3, k4, k5, k6, k7, k8,
      k9>(action);
}

template <int k1, int k2, int k3, int k4, int k5, int k6, int k7, int k8,
    int k9, int k10, typename InnerAction>
inline internal::WithArgsAction<InnerAction, k1, k2, k3, k4, k5, k6, k7, k8,
    k9, k10>
WithArgs(const InnerAction& action) {
  return internal::WithArgsAction<InnerAction, k1, k2, k3, k4, k5, k6, k7, k8,
      k9, k10>(action);
}

// Creates an action that does actions a1, a2, ..., sequentially in
// each invocation.
template <typename Action1, typename Action2>
inline internal::DoBothAction<Action1, Action2>
DoAll(Action1 a1, Action2 a2) {
  return internal::DoBothAction<Action1, Action2>(a1, a2);
}

template <typename Action1, typename Action2, typename Action3>
inline internal::DoBothAction<Action1, internal::DoBothAction<Action2,
    Action3> >
DoAll(Action1 a1, Action2 a2, Action3 a3) {
  return DoAll(a1, DoAll(a2, a3));
}

template <typename Action1, typename Action2, typename Action3,
    typename Action4>
inline internal::DoBothAction<Action1, internal::DoBothAction<Action2,
    internal::DoBothAction<Action3, Action4> > >
DoAll(Action1 a1, Action2 a2, Action3 a3, Action4 a4) {
  return DoAll(a1, DoAll(a2, a3, a4));
}

template <typename Action1, typename Action2, typename Action3,
    typename Action4, typename Action5>
inline internal::DoBothAction<Action1, internal::DoBothAction<Action2,
    internal::DoBothAction<Action3, internal::DoBothAction<Action4,
    Action5> > > >
DoAll(Action1 a1, Action2 a2, Action3 a3, Action4 a4, Action5 a5) {
  return DoAll(a1, DoAll(a2, a3, a4, a5));
}

template <typename Action1, typename Action2, typename Action3,
    typename Action4, typename Action5, typename Action6>
inline internal::DoBothAction<Action1, internal::DoBothAction<Action2,
    internal::DoBothAction<Action3, internal::DoBothAction<Action4,
    internal::DoBothAction<Action5, Action6> > > > >
DoAll(Action1 a1, Action2 a2, Action3 a3, Action4 a4, Action5 a5, Action6 a6) {
  return DoAll(a1, DoAll(a2, a3, a4, a5, a6));
}

template <typename Action1, typename Action2, typename Action3,
    typename Action4, typename Action5, typename Action6, typename Action7>
inline internal::DoBothAction<Action1, internal::DoBothAction<Action2,
    internal::DoBothAction<Action3, internal::DoBothAction<Action4,
    internal::DoBothAction<Action5, internal::DoBothAction<Action6,
    Action7> > > > > >
DoAll(Action1 a1, Action2 a2, Action3 a3, Action4 a4, Action5 a5, Action6 a6,
    Action7 a7) {
  return DoAll(a1, DoAll(a2, a3, a4, a5, a6, a7));
}

template <typename Action1, typename Action2, typename Action3,
    typename Action4, typename Action5, typename Action6, typename Action7,
    typename Action8>
inline internal::DoBothAction<Action1, internal::DoBothAction<Action2,
    internal::DoBothAction<Action3, internal::DoBothAction<Action4,
    internal::DoBothAction<Action5, internal::DoBothAction<Action6,
    internal::DoBothAction<Action7, Action8> > > > > > >
DoAll(Action1 a1, Action2 a2, Action3 a3, Action4 a4, Action5 a5, Action6 a6,
    Action7 a7, Action8 a8) {
  return DoAll(a1, DoAll(a2, a3, a4, a5, a6, a7, a8));
}

template <typename Action1, typename Action2, typename Action3,
    typename Action4, typename Action5, typename Action6, typename Action7,
    typename Action8, typename Action9>
inline internal::DoBothAction<Action1, internal::DoBothAction<Action2,
    internal::DoBothAction<Action3, internal::DoBothAction<Action4,
    internal::DoBothAction<Action5, internal::DoBothAction<Action6,
    internal::DoBothAction<Action7, internal::DoBothAction<Action8,
    Action9> > > > > > > >
DoAll(Action1 a1, Action2 a2, Action3 a3, Action4 a4, Action5 a5, Action6 a6,
    Action7 a7, Action8 a8, Action9 a9) {
  return DoAll(a1, DoAll(a2, a3, a4, a5, a6, a7, a8, a9));
}

template <typename Action1, typename Action2, typename Action3,
    typename Action4, typename Action5, typename Action6, typename Action7,
    typename Action8, typename Action9, typename Action10>
inline internal::DoBothAction<Action1, internal::DoBothAction<Action2,
    internal::DoBothAction<Action3, internal::DoBothAction<Action4,
    internal::DoBothAction<Action5, internal::DoBothAction<Action6,
    internal::DoBothAction<Action7, internal::DoBothAction<Action8,
    internal::DoBothAction<Action9, Action10> > > > > > > > >
DoAll(Action1 a1, Action2 a2, Action3 a3, Action4 a4, Action5 a5, Action6 a6,
    Action7 a7, Action8 a8, Action9 a9, Action10 a10) {
  return DoAll(a1, DoAll(a2, a3, a4, a5, a6, a7, a8, a9, a10));
}

}  // namespace testing

// The ACTION* family of macros can be used in a namespace scope to
// define custom actions easily.  The syntax:
//
//   ACTION(name) { statements; }
//
// will define an action with the given name that executes the
// statements.  The value returned by the statements will be used as
// the return value of the action.  Inside the statements, you can
// refer to the K-th (0-based) argument of the mock function by
// 'argK', and refer to its type by 'argK_type'.  For example:
//
//   ACTION(IncrementArg1) {
//     arg1_type temp = arg1;
//     return ++(*temp);
//   }
//
// allows you to write
//
//   ...WillOnce(IncrementArg1());
//
// You can also refer to the entire argument tuple and its type by
// 'args' and 'args_type', and refer to the mock function type and its
// return type by 'function_type' and 'return_type'.
//
// Note that you don't need to specify the types of the mock function
// arguments.  However rest assured that your code is still type-safe:
// you'll get a compiler error if *arg1 doesn't support the ++
// operator, or if the type of ++(*arg1) isn't compatible with the
// mock function's return type, for example.
//
// Sometimes you'll want to parameterize the action.   For that you can use
// another macro:
//
//   ACTION_P(name, param_name) { statements; }
//
// For example:
//
//   ACTION_P(Add, n) { return arg0 + n; }
//
// will allow you to write:
//
//   ...WillOnce(Add(5));
//
// Note that you don't need to provide the type of the parameter
// either.  If you need to reference the type of a parameter named
// 'foo', you can write 'foo_type'.  For example, in the body of
// ACTION_P(Add, n) above, you can write 'n_type' to refer to the type
// of 'n'.
//
// We also provide ACTION_P2, ACTION_P3, ..., up to ACTION_P10 to support
// multi-parameter actions.
//
// For the purpose of typing, you can view
//
//   ACTION_Pk(Foo, p1, ..., pk) { ... }
//
// as shorthand for
//
//   template <typename p1_type, ..., typename pk_type>
//   FooActionPk<p1_type, ..., pk_type> Foo(p1_type p1, ..., pk_type pk) { ... }
//
// In particular, you can provide the template type arguments
// explicitly when invoking Foo(), as in Foo<long, bool>(5, false);
// although usually you can rely on the compiler to infer the types
// for you automatically.  You can assign the result of expression
// Foo(p1, ..., pk) to a variable of type FooActionPk<p1_type, ...,
// pk_type>.  This can be useful when composing actions.
//
// You can also overload actions with different numbers of parameters:
//
//   ACTION_P(Plus, a) { ... }
//   ACTION_P2(Plus, a, b) { ... }
//
// While it's tempting to always use the ACTION* macros when defining
// a new action, you should also consider implementing ActionInterface
// or using MakePolymorphicAction() instead, especially if you need to
// use the action a lot.  While these approaches require more work,
// they give you more control on the types of the mock function
// arguments and the action parameters, which in general leads to
// better compiler error messages that pay off in the long run.  They
// also allow overloading actions based on parameter types (as opposed
// to just based on the number of parameters).
//
// CAVEAT:
//
// ACTION*() can only be used in a namespace scope.  The reason is
// that C++ doesn't yet allow function-local types to be used to
// instantiate templates.  The up-coming C++0x standard will fix this.
// Once that's done, we'll consider supporting using ACTION*() inside
// a function.
//
// MORE INFORMATION:
//
// To learn more about using these macros, please search for 'ACTION'
// on http://code.google.com/p/googlemock/wiki/CookBook.

// An internal macro needed for implementing ACTION*().
#define GMOCK_ACTION_ARG_TYPES_AND_NAMES_UNUSED_\
    const args_type& args GTEST_ATTRIBUTE_UNUSED_, \
    arg0_type arg0 GTEST_ATTRIBUTE_UNUSED_, \
    arg1_type arg1 GTEST_ATTRIBUTE_UNUSED_, \
    arg2_type arg2 GTEST_ATTRIBUTE_UNUSED_, \
    arg3_type arg3 GTEST_ATTRIBUTE_UNUSED_, \
    arg4_type arg4 GTEST_ATTRIBUTE_UNUSED_, \
    arg5_type arg5 GTEST_ATTRIBUTE_UNUSED_, \
    arg6_type arg6 GTEST_ATTRIBUTE_UNUSED_, \
    arg7_type arg7 GTEST_ATTRIBUTE_UNUSED_, \
    arg8_type arg8 GTEST_ATTRIBUTE_UNUSED_, \
    arg9_type arg9 GTEST_ATTRIBUTE_UNUSED_

// Sometimes you want to give an action explicit template parameters
// that cannot be inferred from its value parameters.  ACTION() and
// ACTION_P*() don't support that.  ACTION_TEMPLATE() remedies that
// and can be viewed as an extension to ACTION() and ACTION_P*().
//
// The syntax:
//
//   ACTION_TEMPLATE(ActionName,
//                   HAS_m_TEMPLATE_PARAMS(kind1, name1, ..., kind_m, name_m),
//                   AND_n_VALUE_PARAMS(p1, ..., p_n)) { statements; }
//
// defines an action template that takes m explicit template
// parameters and n value parameters.  name_i is the name of the i-th
// template parameter, and kind_i specifies whether it's a typename,
// an integral constant, or a template.  p_i is the name of the i-th
// value parameter.
//
// Example:
//
//   // DuplicateArg<k, T>(output) converts the k-th argument of the mock
//   // function to type T and copies it to *output.
//   ACTION_TEMPLATE(DuplicateArg,
//                   HAS_2_TEMPLATE_PARAMS(int, k, typename, T),
//                   AND_1_VALUE_PARAMS(output)) {
//     *output = T(::testing::get<k>(args));
//   }
//   ...
//     int n;
//     EXPECT_CALL(mock, Foo(_, _))
//         .WillOnce(DuplicateArg<1, unsigned char>(&n));
//
// To create an instance of an action template, write:
//
//   ActionName<t1, ..., t_m>(v1, ..., v_n)
//
// where the ts are the template arguments and the vs are the value
// arguments.  The value argument types are inferred by the compiler.
// If you want to explicitly specify the value argument types, you can
// provide additional template arguments:
//
//   ActionName<t1, ..., t_m, u1, ..., u_k>(v1, ..., v_n)
//
// where u_i is the desired type of v_i.
//
// ACTION_TEMPLATE and ACTION/ACTION_P* can be overloaded on the
// number of value parameters, but not on the number of template
// parameters.  Without the restriction, the meaning of the following
// is unclear:
//
//   OverloadedAction<int, bool>(x);
//
// Are we using a single-template-parameter action where 'bool' refers
// to the type of x, or are we using a two-template-parameter action
// where the compiler is asked to infer the type of x?
//
// Implementation notes:
//
// GMOCK_INTERNAL_*_HAS_m_TEMPLATE_PARAMS and
// GMOCK_INTERNAL_*_AND_n_VALUE_PARAMS are internal macros for
// implementing ACTION_TEMPLATE.  The main trick we use is to create
// new macro invocations when expanding a macro.  For example, we have
//
//   #define ACTION_TEMPLATE(name, template_params, value_params)
//       ... GMOCK_INTERNAL_DECL_##template_params ...
//
// which causes ACTION_TEMPLATE(..., HAS_1_TEMPLATE_PARAMS(typename, T), ...)
// to expand to
//
//       ... GMOCK_INTERNAL_DECL_HAS_1_TEMPLATE_PARAMS(typename, T) ...
//
// Since GMOCK_INTERNAL_DECL_HAS_1_TEMPLATE_PARAMS is a macro, the
// preprocessor will continue to expand it to
//
//       ... typename T ...
//
// This technique conforms to the C++ standard and is portable.  It
// allows us to implement action templates using O(N) code, where N is
// the maximum number of template/value parameters supported.  Without
// using it, we'd have to devote O(N^2) amount of code to implement all
// combinations of m and n.

// Declares the template parameters.
#define GMOCK_INTERNAL_DECL_HAS_1_TEMPLATE_PARAMS(kind0, name0) kind0 name0
#define GMOCK_INTERNAL_DECL_HAS_2_TEMPLATE_PARAMS(kind0, name0, kind1, \
    name1) kind0 name0, kind1 name1
#define GMOCK_INTERNAL_DECL_HAS_3_TEMPLATE_PARAMS(kind0, name0, kind1, name1, \
    kind2, name2) kind0 name0, kind1 name1, kind2 name2
#define GMOCK_INTERNAL_DECL_HAS_4_TEMPLATE_PARAMS(kind0, name0, kind1, name1, \
    kind2, name2, kind3, name3) kind0 name0, kind1 name1, kind2 name2, \
    kind3 name3
#define GMOCK_INTERNAL_DECL_HAS_5_TEMPLATE_PARAMS(kind0, name0, kind1, name1, \
    kind2, name2, kind3, name3, kind4, name4) kind0 name0, kind1 name1, \
    kind2 name2, kind3 name3, kind4 name4
#define GMOCK_INTERNAL_DECL_HAS_6_TEMPLATE_PARAMS(kind0, name0, kind1, name1, \
    kind2, name2, kind3, name3, kind4, name4, kind5, name5) kind0 name0, \
    kind1 name1, kind2 name2, kind3 name3, kind4 name4, kind5 name5
#define GMOCK_INTERNAL_DECL_HAS_7_TEMPLATE_PARAMS(kind0, name0, kind1, name1, \
    kind2, name2, kind3, name3, kind4, name4, kind5, name5, kind6, \
    name6) kind0 name0, kind1 name1, kind2 name2, kind3 name3, kind4 name4, \
    kind5 name5, kind6 name6
#define GMOCK_INTERNAL_DECL_HAS_8_TEMPLATE_PARAMS(kind0, name0, kind1, name1, \
    kind2, name2, kind3, name3, kind4, name4, kind5, name5, kind6, name6, \
    kind7, name7) kind0 name0, kind1 name1, kind2 name2, kind3 name3, \
    kind4 name4, kind5 name5, kind6 name6, kind7 name7
#define GMOCK_INTERNAL_DECL_HAS_9_TEMPLATE_PARAMS(kind0, name0, kind1, name1, \
    kind2, name2, kind3, name3, kind4, name4, kind5, name5, kind6, name6, \
    kind7, name7, kind8, name8) kind0 name0, kind1 name1, kind2 name2, \
    kind3 name3, kind4 name4, kind5 name5, kind6 name6, kind7 name7, \
    kind8 name8
#define GMOCK_INTERNAL_DECL_HAS_10_TEMPLATE_PARAMS(kind0, name0, kind1, \
    name1, kind2, name2, kind3, name3, kind4, name4, kind5, name5, kind6, \
    name6, kind7, name7, kind8, name8, kind9, name9) kind0 name0, \
    kind1 name1, kind2 name2, kind3 name3, kind4 name4, kind5 name5, \
    kind6 name6, kind7 name7, kind8 name8, kind9 name9

// Lists the template parameters.
#define GMOCK_INTERNAL_LIST_HAS_1_TEMPLATE_PARAMS(kind0, name0) name0
#define GMOCK_INTERNAL_LIST_HAS_2_TEMPLATE_PARAMS(kind0, name0, kind1, \
    name1) name0, name1
#define GMOCK_INTERNAL_LIST_HAS_3_TEMPLATE_PARAMS(kind0, name0, kind1, name1, \
    kind2, name2) name0, name1, name2
#define GMOCK_INTERNAL_LIST_HAS_4_TEMPLATE_PARAMS(kind0, name0, kind1, name1, \
    kind2, name2, kind3, name3) name0, name1, name2, name3
#define GMOCK_INTERNAL_LIST_HAS_5_TEMPLATE_PARAMS(kind0, name0, kind1, name1, \
    kind2, name2, kind3, name3, kind4, name4) name0, name1, name2, name3, \
    name4
#define GMOCK_INTERNAL_LIST_HAS_6_TEMPLATE_PARAMS(kind0, name0, kind1, name1, \
    kind2, name2, kind3, name3, kind4, name4, kind5, name5) name0, name1, \
    name2, name3, name4, name5
#define GMOCK_INTERNAL_LIST_HAS_7_TEMPLATE_PARAMS(kind0, name0, kind1, name1, \
    kind2, name2, kind3, name3, kind4, name4, kind5, name5, kind6, \
    name6) name0, name1, name2, name3, name4, name5, name6
#define GMOCK_INTERNAL_LIST_HAS_8_TEMPLATE_PARAMS(kind0, name0, kind1, name1, \
    kind2, name2, kind3, name3, kind4, name4, kind5, name5, kind6, name6, \
    kind7, name7) name0, name1, name2, name3, name4, name5, name6, name7
#define GMOCK_INTERNAL_LIST_HAS_9_TEMPLATE_PARAMS(kind0, name0, kind1, name1, \
    kind2, name2, kind3, name3, kind4, name4, kind5, name5, kind6, name6, \
    kind7, name7, kind8, name8) name0, name1, name2, name3, name4, name5, \
    name6, name7, name8
#define GMOCK_INTERNAL_LIST_HAS_10_TEMPLATE_PARAMS(kind0, name0, kind1, \
    name1, kind2, name2, kind3, name3, kind4, name4, kind5, name5, kind6, \
    name6, kind7, name7, kind8, name8, kind9, name9) name0, name1, name2, \
    name3, name4, name5, name6, name7, name8, name9

// Declares the types of value parameters.
#define GMOCK_INTERNAL_DECL_TYPE_AND_0_VALUE_PARAMS()
#define GMOCK_INTERNAL_DECL_TYPE_AND_1_VALUE_PARAMS(p0) , typename p0##_type
#define GMOCK_INTERNAL_DECL_TYPE_AND_2_VALUE_PARAMS(p0, p1) , \
    typename p0##_type, typename p1##_type
#define GMOCK_INTERNAL_DECL_TYPE_AND_3_VALUE_PARAMS(p0, p1, p2) , \
    typename p0##_type, typename p1##_type, typename p2##_type
#define GMOCK_INTERNAL_DECL_TYPE_AND_4_VALUE_PARAMS(p0, p1, p2, p3) , \
    typename p0##_type, typename p1##_type, typename p2##_type, \
    typename p3##_type
#define GMOCK_INTERNAL_DECL_TYPE_AND_5_VALUE_PARAMS(p0, p1, p2, p3, p4) , \
    typename p0##_type, typename p1##_type, typename p2##_type, \
    typename p3##_type, typename p4##_type
#define GMOCK_INTERNAL_DECL_TYPE_AND_6_VALUE_PARAMS(p0, p1, p2, p3, p4, p5) , \
    typename p0##_type, typename p1##_type, typename p2##_type, \
    typename p3##_type, typename p4##_type, typename p5##_type
#define GMOCK_INTERNAL_DECL_TYPE_AND_7_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, \
    p6) , typename p0##_type, typename p1##_type, typename p2##_type, \
    typename p3##_type, typename p4##_type, typename p5##_type, \
    typename p6##_type
#define GMOCK_INTERNAL_DECL_TYPE_AND_8_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, \
    p6, p7) , typename p0##_type, typename p1##_type, typename p2##_type, \
    typename p3##_type, typename p4##_type, typename p5##_type, \
    typename p6##_type, typename p7##_type
#define GMOCK_INTERNAL_DECL_TYPE_AND_9_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, \
    p6, p7, p8) , typename p0##_type, typename p1##_type, typename p2##_type, \
    typename p3##_type, typename p4##_type, typename p5##_type, \
    typename p6##_type, typename p7##_type, typename p8##_type
#define GMOCK_INTERNAL_DECL_TYPE_AND_10_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, \
    p6, p7, p8, p9) , typename p0##_type, typename p1##_type, \
    typename p2##_type, typename p3##_type, typename p4##_type, \
    typename p5##_type, typename p6##_type, typename p7##_type, \
    typename p8##_type, typename p9##_type

// Initializes the value parameters.
#define GMOCK_INTERNAL_INIT_AND_0_VALUE_PARAMS()\
    ()
#define GMOCK_INTERNAL_INIT_AND_1_VALUE_PARAMS(p0)\
    (p0##_type gmock_p0) : p0(gmock_p0)
#define GMOCK_INTERNAL_INIT_AND_2_VALUE_PARAMS(p0, p1)\
    (p0##_type gmock_p0, p1##_type gmock_p1) : p0(gmock_p0), p1(gmock_p1)
#define GMOCK_INTERNAL_INIT_AND_3_VALUE_PARAMS(p0, p1, p2)\
    (p0##_type gmock_p0, p1##_type gmock_p1, \
        p2##_type gmock_p2) : p0(gmock_p0), p1(gmock_p1), p2(gmock_p2)
#define GMOCK_INTERNAL_INIT_AND_4_VALUE_PARAMS(p0, p1, p2, p3)\
    (p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
        p3##_type gmock_p3) : p0(gmock_p0), p1(gmock_p1), p2(gmock_p2), \
        p3(gmock_p3)
#define GMOCK_INTERNAL_INIT_AND_5_VALUE_PARAMS(p0, p1, p2, p3, p4)\
    (p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
        p3##_type gmock_p3, p4##_type gmock_p4) : p0(gmock_p0), p1(gmock_p1), \
        p2(gmock_p2), p3(gmock_p3), p4(gmock_p4)
#define GMOCK_INTERNAL_INIT_AND_6_VALUE_PARAMS(p0, p1, p2, p3, p4, p5)\
    (p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
        p3##_type gmock_p3, p4##_type gmock_p4, \
        p5##_type gmock_p5) : p0(gmock_p0), p1(gmock_p1), p2(gmock_p2), \
        p3(gmock_p3), p4(gmock_p4), p5(gmock_p5)
#define GMOCK_INTERNAL_INIT_AND_7_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6)\
    (p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
        p3##_type gmock_p3, p4##_type gmock_p4, p5##_type gmock_p5, \
        p6##_type gmock_p6) : p0(gmock_p0), p1(gmock_p1), p2(gmock_p2), \
        p3(gmock_p3), p4(gmock_p4), p5(gmock_p5), p6(gmock_p6)
#define GMOCK_INTERNAL_INIT_AND_8_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, p7)\
    (p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
        p3##_type gmock_p3, p4##_type gmock_p4, p5##_type gmock_p5, \
        p6##_type gmock_p6, p7##_type gmock_p7) : p0(gmock_p0), p1(gmock_p1), \
        p2(gmock_p2), p3(gmock_p3), p4(gmock_p4), p5(gmock_p5), p6(gmock_p6), \
        p7(gmock_p7)
#define GMOCK_INTERNAL_INIT_AND_9_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, \
    p7, p8)\
    (p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
        p3##_type gmock_p3, p4##_type gmock_p4, p5##_type gmock_p5, \
        p6##_type gmock_p6, p7##_type gmock_p7, \
        p8##_type gmock_p8) : p0(gmock_p0), p1(gmock_p1), p2(gmock_p2), \
        p3(gmock_p3), p4(gmock_p4), p5(gmock_p5), p6(gmock_p6), p7(gmock_p7), \
        p8(gmock_p8)
#define GMOCK_INTERNAL_INIT_AND_10_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, \
    p7, p8, p9)\
    (p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
        p3##_type gmock_p3, p4##_type gmock_p4, p5##_type gmock_p5, \
        p6##_type gmock_p6, p7##_type gmock_p7, p8##_type gmock_p8, \
        p9##_type gmock_p9) : p0(gmock_p0), p1(gmock_p1), p2(gmock_p2), \
        p3(gmock_p3), p4(gmock_p4), p5(gmock_p5), p6(gmock_p6), p7(gmock_p7), \
        p8(gmock_p8), p9(gmock_p9)

// Declares the fields for storing the value parameters.
#define GMOCK_INTERNAL_DEFN_AND_0_VALUE_PARAMS()
#define GMOCK_INTERNAL_DEFN_AND_1_VALUE_PARAMS(p0) p0##_type p0;
#define GMOCK_INTERNAL_DEFN_AND_2_VALUE_PARAMS(p0, p1) p0##_type p0; \
    p1##_type p1;
#define GMOCK_INTERNAL_DEFN_AND_3_VALUE_PARAMS(p0, p1, p2) p0##_type p0; \
    p1##_type p1; p2##_type p2;
#define GMOCK_INTERNAL_DEFN_AND_4_VALUE_PARAMS(p0, p1, p2, p3) p0##_type p0; \
    p1##_type p1; p2##_type p2; p3##_type p3;
#define GMOCK_INTERNAL_DEFN_AND_5_VALUE_PARAMS(p0, p1, p2, p3, \
    p4) p0##_type p0; p1##_type p1; p2##_type p2; p3##_type p3; p4##_type p4;
#define GMOCK_INTERNAL_DEFN_AND_6_VALUE_PARAMS(p0, p1, p2, p3, p4, \
    p5) p0##_type p0; p1##_type p1; p2##_type p2; p3##_type p3; p4##_type p4; \
    p5##_type p5;
#define GMOCK_INTERNAL_DEFN_AND_7_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, \
    p6) p0##_type p0; p1##_type p1; p2##_type p2; p3##_type p3; p4##_type p4; \
    p5##_type p5; p6##_type p6;
#define GMOCK_INTERNAL_DEFN_AND_8_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, \
    p7) p0##_type p0; p1##_type p1; p2##_type p2; p3##_type p3; p4##_type p4; \
    p5##_type p5; p6##_type p6; p7##_type p7;
#define GMOCK_INTERNAL_DEFN_AND_9_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, \
    p7, p8) p0##_type p0; p1##_type p1; p2##_type p2; p3##_type p3; \
    p4##_type p4; p5##_type p5; p6##_type p6; p7##_type p7; p8##_type p8;
#define GMOCK_INTERNAL_DEFN_AND_10_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, \
    p7, p8, p9) p0##_type p0; p1##_type p1; p2##_type p2; p3##_type p3; \
    p4##_type p4; p5##_type p5; p6##_type p6; p7##_type p7; p8##_type p8; \
    p9##_type p9;

// Lists the value parameters.
#define GMOCK_INTERNAL_LIST_AND_0_VALUE_PARAMS()
#define GMOCK_INTERNAL_LIST_AND_1_VALUE_PARAMS(p0) p0
#define GMOCK_INTERNAL_LIST_AND_2_VALUE_PARAMS(p0, p1) p0, p1
#define GMOCK_INTERNAL_LIST_AND_3_VALUE_PARAMS(p0, p1, p2) p0, p1, p2
#define GMOCK_INTERNAL_LIST_AND_4_VALUE_PARAMS(p0, p1, p2, p3) p0, p1, p2, p3
#define GMOCK_INTERNAL_LIST_AND_5_VALUE_PARAMS(p0, p1, p2, p3, p4) p0, p1, \
    p2, p3, p4
#define GMOCK_INTERNAL_LIST_AND_6_VALUE_PARAMS(p0, p1, p2, p3, p4, p5) p0, \
    p1, p2, p3, p4, p5
#define GMOCK_INTERNAL_LIST_AND_7_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, \
    p6) p0, p1, p2, p3, p4, p5, p6
#define GMOCK_INTERNAL_LIST_AND_8_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, \
    p7) p0, p1, p2, p3, p4, p5, p6, p7
#define GMOCK_INTERNAL_LIST_AND_9_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, \
    p7, p8) p0, p1, p2, p3, p4, p5, p6, p7, p8
#define GMOCK_INTERNAL_LIST_AND_10_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, \
    p7, p8, p9) p0, p1, p2, p3, p4, p5, p6, p7, p8, p9

// Lists the value parameter types.
#define GMOCK_INTERNAL_LIST_TYPE_AND_0_VALUE_PARAMS()
#define GMOCK_INTERNAL_LIST_TYPE_AND_1_VALUE_PARAMS(p0) , p0##_type
#define GMOCK_INTERNAL_LIST_TYPE_AND_2_VALUE_PARAMS(p0, p1) , p0##_type, \
    p1##_type
#define GMOCK_INTERNAL_LIST_TYPE_AND_3_VALUE_PARAMS(p0, p1, p2) , p0##_type, \
    p1##_type, p2##_type
#define GMOCK_INTERNAL_LIST_TYPE_AND_4_VALUE_PARAMS(p0, p1, p2, p3) , \
    p0##_type, p1##_type, p2##_type, p3##_type
#define GMOCK_INTERNAL_LIST_TYPE_AND_5_VALUE_PARAMS(p0, p1, p2, p3, p4) , \
    p0##_type, p1##_type, p2##_type, p3##_type, p4##_type
#define GMOCK_INTERNAL_LIST_TYPE_AND_6_VALUE_PARAMS(p0, p1, p2, p3, p4, p5) , \
    p0##_type, p1##_type, p2##_type, p3##_type, p4##_type, p5##_type
#define GMOCK_INTERNAL_LIST_TYPE_AND_7_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, \
    p6) , p0##_type, p1##_type, p2##_type, p3##_type, p4##_type, p5##_type, \
    p6##_type
#define GMOCK_INTERNAL_LIST_TYPE_AND_8_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, \
    p6, p7) , p0##_type, p1##_type, p2##_type, p3##_type, p4##_type, \
    p5##_type, p6##_type, p7##_type
#define GMOCK_INTERNAL_LIST_TYPE_AND_9_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, \
    p6, p7, p8) , p0##_type, p1##_type, p2##_type, p3##_type, p4##_type, \
    p5##_type, p6##_type, p7##_type, p8##_type
#define GMOCK_INTERNAL_LIST_TYPE_AND_10_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, \
    p6, p7, p8, p9) , p0##_type, p1##_type, p2##_type, p3##_type, p4##_type, \
    p5##_type, p6##_type, p7##_type, p8##_type, p9##_type

// Declares the value parameters.
#define GMOCK_INTERNAL_DECL_AND_0_VALUE_PARAMS()
#define GMOCK_INTERNAL_DECL_AND_1_VALUE_PARAMS(p0) p0##_type p0
#define GMOCK_INTERNAL_DECL_AND_2_VALUE_PARAMS(p0, p1) p0##_type p0, \
    p1##_type p1
#define GMOCK_INTERNAL_DECL_AND_3_VALUE_PARAMS(p0, p1, p2) p0##_type p0, \
    p1##_type p1, p2##_type p2
#define GMOCK_INTERNAL_DECL_AND_4_VALUE_PARAMS(p0, p1, p2, p3) p0##_type p0, \
    p1##_type p1, p2##_type p2, p3##_type p3
#define GMOCK_INTERNAL_DECL_AND_5_VALUE_PARAMS(p0, p1, p2, p3, \
    p4) p0##_type p0, p1##_type p1, p2##_type p2, p3##_type p3, p4##_type p4
#define GMOCK_INTERNAL_DECL_AND_6_VALUE_PARAMS(p0, p1, p2, p3, p4, \
    p5) p0##_type p0, p1##_type p1, p2##_type p2, p3##_type p3, p4##_type p4, \
    p5##_type p5
#define GMOCK_INTERNAL_DECL_AND_7_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, \
    p6) p0##_type p0, p1##_type p1, p2##_type p2, p3##_type p3, p4##_type p4, \
    p5##_type p5, p6##_type p6
#define GMOCK_INTERNAL_DECL_AND_8_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, \
    p7) p0##_type p0, p1##_type p1, p2##_type p2, p3##_type p3, p4##_type p4, \
    p5##_type p5, p6##_type p6, p7##_type p7
#define GMOCK_INTERNAL_DECL_AND_9_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, \
    p7, p8) p0##_type p0, p1##_type p1, p2##_type p2, p3##_type p3, \
    p4##_type p4, p5##_type p5, p6##_type p6, p7##_type p7, p8##_type p8
#define GMOCK_INTERNAL_DECL_AND_10_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, \
    p7, p8, p9) p0##_type p0, p1##_type p1, p2##_type p2, p3##_type p3, \
    p4##_type p4, p5##_type p5, p6##_type p6, p7##_type p7, p8##_type p8, \
    p9##_type p9

// The suffix of the class template implementing the action template.
#define GMOCK_INTERNAL_COUNT_AND_0_VALUE_PARAMS()
#define GMOCK_INTERNAL_COUNT_AND_1_VALUE_PARAMS(p0) P
#define GMOCK_INTERNAL_COUNT_AND_2_VALUE_PARAMS(p0, p1) P2
#define GMOCK_INTERNAL_COUNT_AND_3_VALUE_PARAMS(p0, p1, p2) P3
#define GMOCK_INTERNAL_COUNT_AND_4_VALUE_PARAMS(p0, p1, p2, p3) P4
#define GMOCK_INTERNAL_COUNT_AND_5_VALUE_PARAMS(p0, p1, p2, p3, p4) P5
#define GMOCK_INTERNAL_COUNT_AND_6_VALUE_PARAMS(p0, p1, p2, p3, p4, p5) P6
#define GMOCK_INTERNAL_COUNT_AND_7_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6) P7
#define GMOCK_INTERNAL_COUNT_AND_8_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, \
    p7) P8
#define GMOCK_INTERNAL_COUNT_AND_9_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, \
    p7, p8) P9
#define GMOCK_INTERNAL_COUNT_AND_10_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, \
    p7, p8, p9) P10

// The name of the class template implementing the action template.
#define GMOCK_ACTION_CLASS_(name, value_params)\
    GTEST_CONCAT_TOKEN_(name##Action, GMOCK_INTERNAL_COUNT_##value_params)

#define ACTION_TEMPLATE(name, template_params, value_params)\
  template <GMOCK_INTERNAL_DECL_##template_params\
            GMOCK_INTERNAL_DECL_TYPE_##value_params>\
  class GMOCK_ACTION_CLASS_(name, value_params) {\
   public:\
    explicit GMOCK_ACTION_CLASS_(name, value_params)\
        GMOCK_INTERNAL_INIT_##value_params {}\
    template <typename F>\
    class gmock_Impl : public ::testing::ActionInterface<F> {\
     public:\
      typedef F function_type;\
      typedef typename ::testing::internal::Function<F>::Result return_type;\
      typedef typename ::testing::internal::Function<F>::ArgumentTuple\
          args_type;\
      explicit gmock_Impl GMOCK_INTERNAL_INIT_##value_params {}\
      virtual return_type Perform(const args_type& args) {\
        return ::testing::internal::ActionHelper<return_type, gmock_Impl>::\
            Perform(this, args);\
      }\
      template <typename arg0_type, typename arg1_type, typename arg2_type, \
          typename arg3_type, typename arg4_type, typename arg5_type, \
          typename arg6_type, typename arg7_type, typename arg8_type, \
          typename arg9_type>\
      return_type gmock_PerformImpl(const args_type& args, arg0_type arg0, \
          arg1_type arg1, arg2_type arg2, arg3_type arg3, arg4_type arg4, \
          arg5_type arg5, arg6_type arg6, arg7_type arg7, arg8_type arg8, \
          arg9_type arg9) const;\
      GMOCK_INTERNAL_DEFN_##value_params\
     private:\
      GTEST_DISALLOW_ASSIGN_(gmock_Impl);\
    };\
    template <typename F> operator ::testing::Action<F>() const {\
      return ::testing::Action<F>(\
          new gmock_Impl<F>(GMOCK_INTERNAL_LIST_##value_params));\
    }\
    GMOCK_INTERNAL_DEFN_##value_params\
   private:\
    GTEST_DISALLOW_ASSIGN_(GMOCK_ACTION_CLASS_(name, value_params));\
  };\
  template <GMOCK_INTERNAL_DECL_##template_params\
            GMOCK_INTERNAL_DECL_TYPE_##value_params>\
  inline GMOCK_ACTION_CLASS_(name, value_params)<\
      GMOCK_INTERNAL_LIST_##template_params\
      GMOCK_INTERNAL_LIST_TYPE_##value_params> name(\
          GMOCK_INTERNAL_DECL_##value_params) {\
    return GMOCK_ACTION_CLASS_(name, value_params)<\
        GMOCK_INTERNAL_LIST_##template_params\
        GMOCK_INTERNAL_LIST_TYPE_##value_params>(\
            GMOCK_INTERNAL_LIST_##value_params);\
  }\
  template <GMOCK_INTERNAL_DECL_##template_params\
            GMOCK_INTERNAL_DECL_TYPE_##value_params>\
  template <typename F>\
  template <typename arg0_type, typename arg1_type, typename arg2_type, \
      typename arg3_type, typename arg4_type, typename arg5_type, \
      typename arg6_type, typename arg7_type, typename arg8_type, \
      typename arg9_type>\
  typename ::testing::internal::Function<F>::Result\
      GMOCK_ACTION_CLASS_(name, value_params)<\
          GMOCK_INTERNAL_LIST_##template_params\
          GMOCK_INTERNAL_LIST_TYPE_##value_params>::gmock_Impl<F>::\
              gmock_PerformImpl(\
          GMOCK_ACTION_ARG_TYPES_AND_NAMES_UNUSED_) const

#define ACTION(name)\
  class name##Action {\
   public:\
    name##Action() {}\
    template <typename F>\
    class gmock_Impl : public ::testing::ActionInterface<F> {\
     public:\
      typedef F function_type;\
      typedef typename ::testing::internal::Function<F>::Result return_type;\
      typedef typename ::testing::internal::Function<F>::ArgumentTuple\
          args_type;\
      gmock_Impl() {}\
      virtual return_type Perform(const args_type& args) {\
        return ::testing::internal::ActionHelper<return_type, gmock_Impl>::\
            Perform(this, args);\
      }\
      template <typename arg0_type, typename arg1_type, typename arg2_type, \
          typename arg3_type, typename arg4_type, typename arg5_type, \
          typename arg6_type, typename arg7_type, typename arg8_type, \
          typename arg9_type>\
      return_type gmock_PerformImpl(const args_type& args, arg0_type arg0, \
          arg1_type arg1, arg2_type arg2, arg3_type arg3, arg4_type arg4, \
          arg5_type arg5, arg6_type arg6, arg7_type arg7, arg8_type arg8, \
          arg9_type arg9) const;\
     private:\
      GTEST_DISALLOW_ASSIGN_(gmock_Impl);\
    };\
    template <typename F> operator ::testing::Action<F>() const {\
      return ::testing::Action<F>(new gmock_Impl<F>());\
    }\
   private:\
    GTEST_DISALLOW_ASSIGN_(name##Action);\
  };\
  inline name##Action name() {\
    return name##Action();\
  }\
  template <typename F>\
  template <typename arg0_type, typename arg1_type, typename arg2_type, \
      typename arg3_type, typename arg4_type, typename arg5_type, \
      typename arg6_type, typename arg7_type, typename arg8_type, \
      typename arg9_type>\
  typename ::testing::internal::Function<F>::Result\
      name##Action::gmock_Impl<F>::gmock_PerformImpl(\
          GMOCK_ACTION_ARG_TYPES_AND_NAMES_UNUSED_) const

#define ACTION_P(name, p0)\
  template <typename p0##_type>\
  class name##ActionP {\
   public:\
    explicit name##ActionP(p0##_type gmock_p0) : p0(gmock_p0) {}\
    template <typename F>\
    class gmock_Impl : public ::testing::ActionInterface<F> {\
     public:\
      typedef F function_type;\
      typedef typename ::testing::internal::Function<F>::Result return_type;\
      typedef typename ::testing::internal::Function<F>::ArgumentTuple\
          args_type;\
      explicit gmock_Impl(p0##_type gmock_p0) : p0(gmock_p0) {}\
      virtual return_type Perform(const args_type& args) {\
        return ::testing::internal::ActionHelper<return_type, gmock_Impl>::\
            Perform(this, args);\
      }\
      template <typename arg0_type, typename arg1_type, typename arg2_type, \
          typename arg3_type, typename arg4_type, typename arg5_type, \
          typename arg6_type, typename arg7_type, typename arg8_type, \
          typename arg9_type>\
      return_type gmock_PerformImpl(const args_type& args, arg0_type arg0, \
          arg1_type arg1, arg2_type arg2, arg3_type arg3, arg4_type arg4, \
          arg5_type arg5, arg6_type arg6, arg7_type arg7, arg8_type arg8, \
          arg9_type arg9) const;\
      p0##_type p0;\
     private:\
      GTEST_DISALLOW_ASSIGN_(gmock_Impl);\
    };\
    template <typename F> operator ::testing::Action<F>() const {\
      return ::testing::Action<F>(new gmock_Impl<F>(p0));\
    }\
    p0##_type p0;\
   private:\
    GTEST_DISALLOW_ASSIGN_(name##ActionP);\
  };\
  template <typename p0##_type>\
  inline name##ActionP<p0##_type> name(p0##_type p0) {\
    return name##ActionP<p0##_type>(p0);\
  }\
  template <typename p0##_type>\
  template <typename F>\
  template <typename arg0_type, typename arg1_type, typename arg2_type, \
      typename arg3_type, typename arg4_type, typename arg5_type, \
      typename arg6_type, typename arg7_type, typename arg8_type, \
      typename arg9_type>\
  typename ::testing::internal::Function<F>::Result\
      name##ActionP<p0##_type>::gmock_Impl<F>::gmock_PerformImpl(\
          GMOCK_ACTION_ARG_TYPES_AND_NAMES_UNUSED_) const

#define ACTION_P2(name, p0, p1)\
  template <typename p0##_type, typename p1##_type>\
  class name##ActionP2 {\
   public:\
    name##ActionP2(p0##_type gmock_p0, p1##_type gmock_p1) : p0(gmock_p0), \
        p1(gmock_p1) {}\
    template <typename F>\
    class gmock_Impl : public ::testing::ActionInterface<F> {\
     public:\
      typedef F function_type;\
      typedef typename ::testing::internal::Function<F>::Result return_type;\
      typedef typename ::testing::internal::Function<F>::ArgumentTuple\
          args_type;\
      gmock_Impl(p0##_type gmock_p0, p1##_type gmock_p1) : p0(gmock_p0), \
          p1(gmock_p1) {}\
      virtual return_type Perform(const args_type& args) {\
        return ::testing::internal::ActionHelper<return_type, gmock_Impl>::\
            Perform(this, args);\
      }\
      template <typename arg0_type, typename arg1_type, typename arg2_type, \
          typename arg3_type, typename arg4_type, typename arg5_type, \
          typename arg6_type, typename arg7_type, typename arg8_type, \
          typename arg9_type>\
      return_type gmock_PerformImpl(const args_type& args, arg0_type arg0, \
          arg1_type arg1, arg2_type arg2, arg3_type arg3, arg4_type arg4, \
          arg5_type arg5, arg6_type arg6, arg7_type arg7, arg8_type arg8, \
          arg9_type arg9) const;\
      p0##_type p0;\
      p1##_type p1;\
     private:\
      GTEST_DISALLOW_ASSIGN_(gmock_Impl);\
    };\
    template <typename F> operator ::testing::Action<F>() const {\
      return ::testing::Action<F>(new gmock_Impl<F>(p0, p1));\
    }\
    p0##_type p0;\
    p1##_type p1;\
   private:\
    GTEST_DISALLOW_ASSIGN_(name##ActionP2);\
  };\
  template <typename p0##_type, typename p1##_type>\
  inline name##ActionP2<p0##_type, p1##_type> name(p0##_type p0, \
      p1##_type p1) {\
    return name##ActionP2<p0##_type, p1##_type>(p0, p1);\
  }\
  template <typename p0##_type, typename p1##_type>\
  template <typename F>\
  template <typename arg0_type, typename arg1_type, typename arg2_type, \
      typename arg3_type, typename arg4_type, typename arg5_type, \
      typename arg6_type, typename arg7_type, typename arg8_type, \
      typename arg9_type>\
  typename ::testing::internal::Function<F>::Result\
      name##ActionP2<p0##_type, p1##_type>::gmock_Impl<F>::gmock_PerformImpl(\
          GMOCK_ACTION_ARG_TYPES_AND_NAMES_UNUSED_) const

#define ACTION_P3(name, p0, p1, p2)\
  template <typename p0##_type, typename p1##_type, typename p2##_type>\
  class name##ActionP3 {\
   public:\
    name##ActionP3(p0##_type gmock_p0, p1##_type gmock_p1, \
        p2##_type gmock_p2) : p0(gmock_p0), p1(gmock_p1), p2(gmock_p2) {}\
    template <typename F>\
    class gmock_Impl : public ::testing::ActionInterface<F> {\
     public:\
      typedef F function_type;\
      typedef typename ::testing::internal::Function<F>::Result return_type;\
      typedef typename ::testing::internal::Function<F>::ArgumentTuple\
          args_type;\
      gmock_Impl(p0##_type gmock_p0, p1##_type gmock_p1, \
          p2##_type gmock_p2) : p0(gmock_p0), p1(gmock_p1), p2(gmock_p2) {}\
      virtual return_type Perform(const args_type& args) {\
        return ::testing::internal::ActionHelper<return_type, gmock_Impl>::\
            Perform(this, args);\
      }\
      template <typename arg0_type, typename arg1_type, typename arg2_type, \
          typename arg3_type, typename arg4_type, typename arg5_type, \
          typename arg6_type, typename arg7_type, typename arg8_type, \
          typename arg9_type>\
      return_type gmock_PerformImpl(const args_type& args, arg0_type arg0, \
          arg1_type arg1, arg2_type arg2, arg3_type arg3, arg4_type arg4, \
          arg5_type arg5, arg6_type arg6, arg7_type arg7, arg8_type arg8, \
          arg9_type arg9) const;\
      p0##_type p0;\
      p1##_type p1;\
      p2##_type p2;\
     private:\
      GTEST_DISALLOW_ASSIGN_(gmock_Impl);\
    };\
    template <typename F> operator ::testing::Action<F>() const {\
      return ::testing::Action<F>(new gmock_Impl<F>(p0, p1, p2));\
    }\
    p0##_type p0;\
    p1##_type p1;\
    p2##_type p2;\
   private:\
    GTEST_DISALLOW_ASSIGN_(name##ActionP3);\
  };\
  template <typename p0##_type, typename p1##_type, typename p2##_type>\
  inline name##ActionP3<p0##_type, p1##_type, p2##_type> name(p0##_type p0, \
      p1##_type p1, p2##_type p2) {\
    return name##ActionP3<p0##_type, p1##_type, p2##_type>(p0, p1, p2);\
  }\
  template <typename p0##_type, typename p1##_type, typename p2##_type>\
  template <typename F>\
  template <typename arg0_type, typename arg1_type, typename arg2_type, \
      typename arg3_type, typename arg4_type, typename arg5_type, \
      typename arg6_type, typename arg7_type, typename arg8_type, \
      typename arg9_type>\
  typename ::testing::internal::Function<F>::Result\
      name##ActionP3<p0##_type, p1##_type, \
          p2##_type>::gmock_Impl<F>::gmock_PerformImpl(\
          GMOCK_ACTION_ARG_TYPES_AND_NAMES_UNUSED_) const

#define ACTION_P4(name, p0, p1, p2, p3)\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type>\
  class name##ActionP4 {\
   public:\
    name##ActionP4(p0##_type gmock_p0, p1##_type gmock_p1, \
        p2##_type gmock_p2, p3##_type gmock_p3) : p0(gmock_p0), p1(gmock_p1), \
        p2(gmock_p2), p3(gmock_p3) {}\
    template <typename F>\
    class gmock_Impl : public ::testing::ActionInterface<F> {\
     public:\
      typedef F function_type;\
      typedef typename ::testing::internal::Function<F>::Result return_type;\
      typedef typename ::testing::internal::Function<F>::ArgumentTuple\
          args_type;\
      gmock_Impl(p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
          p3##_type gmock_p3) : p0(gmock_p0), p1(gmock_p1), p2(gmock_p2), \
          p3(gmock_p3) {}\
      virtual return_type Perform(const args_type& args) {\
        return ::testing::internal::ActionHelper<return_type, gmock_Impl>::\
            Perform(this, args);\
      }\
      template <typename arg0_type, typename arg1_type, typename arg2_type, \
          typename arg3_type, typename arg4_type, typename arg5_type, \
          typename arg6_type, typename arg7_type, typename arg8_type, \
          typename arg9_type>\
      return_type gmock_PerformImpl(const args_type& args, arg0_type arg0, \
          arg1_type arg1, arg2_type arg2, arg3_type arg3, arg4_type arg4, \
          arg5_type arg5, arg6_type arg6, arg7_type arg7, arg8_type arg8, \
          arg9_type arg9) const;\
      p0##_type p0;\
      p1##_type p1;\
      p2##_type p2;\
      p3##_type p3;\
     private:\
      GTEST_DISALLOW_ASSIGN_(gmock_Impl);\
    };\
    template <typename F> operator ::testing::Action<F>() const {\
      return ::testing::Action<F>(new gmock_Impl<F>(p0, p1, p2, p3));\
    }\
    p0##_type p0;\
    p1##_type p1;\
    p2##_type p2;\
    p3##_type p3;\
   private:\
    GTEST_DISALLOW_ASSIGN_(name##ActionP4);\
  };\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type>\
  inline name##ActionP4<p0##_type, p1##_type, p2##_type, \
      p3##_type> name(p0##_type p0, p1##_type p1, p2##_type p2, \
      p3##_type p3) {\
    return name##ActionP4<p0##_type, p1##_type, p2##_type, p3##_type>(p0, p1, \
        p2, p3);\
  }\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type>\
  template <typename F>\
  template <typename arg0_type, typename arg1_type, typename arg2_type, \
      typename arg3_type, typename arg4_type, typename arg5_type, \
      typename arg6_type, typename arg7_type, typename arg8_type, \
      typename arg9_type>\
  typename ::testing::internal::Function<F>::Result\
      name##ActionP4<p0##_type, p1##_type, p2##_type, \
          p3##_type>::gmock_Impl<F>::gmock_PerformImpl(\
          GMOCK_ACTION_ARG_TYPES_AND_NAMES_UNUSED_) const

#define ACTION_P5(name, p0, p1, p2, p3, p4)\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type>\
  class name##ActionP5 {\
   public:\
    name##ActionP5(p0##_type gmock_p0, p1##_type gmock_p1, \
        p2##_type gmock_p2, p3##_type gmock_p3, \
        p4##_type gmock_p4) : p0(gmock_p0), p1(gmock_p1), p2(gmock_p2), \
        p3(gmock_p3), p4(gmock_p4) {}\
    template <typename F>\
    class gmock_Impl : public ::testing::ActionInterface<F> {\
     public:\
      typedef F function_type;\
      typedef typename ::testing::internal::Function<F>::Result return_type;\
      typedef typename ::testing::internal::Function<F>::ArgumentTuple\
          args_type;\
      gmock_Impl(p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
          p3##_type gmock_p3, p4##_type gmock_p4) : p0(gmock_p0), \
          p1(gmock_p1), p2(gmock_p2), p3(gmock_p3), p4(gmock_p4) {}\
      virtual return_type Perform(const args_type& args) {\
        return ::testing::internal::ActionHelper<return_type, gmock_Impl>::\
            Perform(this, args);\
      }\
      template <typename arg0_type, typename arg1_type, typename arg2_type, \
          typename arg3_type, typename arg4_type, typename arg5_type, \
          typename arg6_type, typename arg7_type, typename arg8_type, \
          typename arg9_type>\
      return_type gmock_PerformImpl(const args_type& args, arg0_type arg0, \
          arg1_type arg1, arg2_type arg2, arg3_type arg3, arg4_type arg4, \
          arg5_type arg5, arg6_type arg6, arg7_type arg7, arg8_type arg8, \
          arg9_type arg9) const;\
      p0##_type p0;\
      p1##_type p1;\
      p2##_type p2;\
      p3##_type p3;\
      p4##_type p4;\
     private:\
      GTEST_DISALLOW_ASSIGN_(gmock_Impl);\
    };\
    template <typename F> operator ::testing::Action<F>() const {\
      return ::testing::Action<F>(new gmock_Impl<F>(p0, p1, p2, p3, p4));\
    }\
    p0##_type p0;\
    p1##_type p1;\
    p2##_type p2;\
    p3##_type p3;\
    p4##_type p4;\
   private:\
    GTEST_DISALLOW_ASSIGN_(name##ActionP5);\
  };\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type>\
  inline name##ActionP5<p0##_type, p1##_type, p2##_type, p3##_type, \
      p4##_type> name(p0##_type p0, p1##_type p1, p2##_type p2, p3##_type p3, \
      p4##_type p4) {\
    return name##ActionP5<p0##_type, p1##_type, p2##_type, p3##_type, \
        p4##_type>(p0, p1, p2, p3, p4);\
  }\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type>\
  template <typename F>\
  template <typename arg0_type, typename arg1_type, typename arg2_type, \
      typename arg3_type, typename arg4_type, typename arg5_type, \
      typename arg6_type, typename arg7_type, typename arg8_type, \
      typename arg9_type>\
  typename ::testing::internal::Function<F>::Result\
      name##ActionP5<p0##_type, p1##_type, p2##_type, p3##_type, \
          p4##_type>::gmock_Impl<F>::gmock_PerformImpl(\
          GMOCK_ACTION_ARG_TYPES_AND_NAMES_UNUSED_) const

#define ACTION_P6(name, p0, p1, p2, p3, p4, p5)\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type>\
  class name##ActionP6 {\
   public:\
    name##ActionP6(p0##_type gmock_p0, p1##_type gmock_p1, \
        p2##_type gmock_p2, p3##_type gmock_p3, p4##_type gmock_p4, \
        p5##_type gmock_p5) : p0(gmock_p0), p1(gmock_p1), p2(gmock_p2), \
        p3(gmock_p3), p4(gmock_p4), p5(gmock_p5) {}\
    template <typename F>\
    class gmock_Impl : public ::testing::ActionInterface<F> {\
     public:\
      typedef F function_type;\
      typedef typename ::testing::internal::Function<F>::Result return_type;\
      typedef typename ::testing::internal::Function<F>::ArgumentTuple\
          args_type;\
      gmock_Impl(p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
          p3##_type gmock_p3, p4##_type gmock_p4, \
          p5##_type gmock_p5) : p0(gmock_p0), p1(gmock_p1), p2(gmock_p2), \
          p3(gmock_p3), p4(gmock_p4), p5(gmock_p5) {}\
      virtual return_type Perform(const args_type& args) {\
        return ::testing::internal::ActionHelper<return_type, gmock_Impl>::\
            Perform(this, args);\
      }\
      template <typename arg0_type, typename arg1_type, typename arg2_type, \
          typename arg3_type, typename arg4_type, typename arg5_type, \
          typename arg6_type, typename arg7_type, typename arg8_type, \
          typename arg9_type>\
      return_type gmock_PerformImpl(const args_type& args, arg0_type arg0, \
          arg1_type arg1, arg2_type arg2, arg3_type arg3, arg4_type arg4, \
          arg5_type arg5, arg6_type arg6, arg7_type arg7, arg8_type arg8, \
          arg9_type arg9) const;\
      p0##_type p0;\
      p1##_type p1;\
      p2##_type p2;\
      p3##_type p3;\
      p4##_type p4;\
      p5##_type p5;\
     private:\
      GTEST_DISALLOW_ASSIGN_(gmock_Impl);\
    };\
    template <typename F> operator ::testing::Action<F>() const {\
      return ::testing::Action<F>(new gmock_Impl<F>(p0, p1, p2, p3, p4, p5));\
    }\
    p0##_type p0;\
    p1##_type p1;\
    p2##_type p2;\
    p3##_type p3;\
    p4##_type p4;\
    p5##_type p5;\
   private:\
    GTEST_DISALLOW_ASSIGN_(name##ActionP6);\
  };\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type>\
  inline name##ActionP6<p0##_type, p1##_type, p2##_type, p3##_type, \
      p4##_type, p5##_type> name(p0##_type p0, p1##_type p1, p2##_type p2, \
      p3##_type p3, p4##_type p4, p5##_type p5) {\
    return name##ActionP6<p0##_type, p1##_type, p2##_type, p3##_type, \
        p4##_type, p5##_type>(p0, p1, p2, p3, p4, p5);\
  }\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type>\
  template <typename F>\
  template <typename arg0_type, typename arg1_type, typename arg2_type, \
      typename arg3_type, typename arg4_type, typename arg5_type, \
      typename arg6_type, typename arg7_type, typename arg8_type, \
      typename arg9_type>\
  typename ::testing::internal::Function<F>::Result\
      name##ActionP6<p0##_type, p1##_type, p2##_type, p3##_type, p4##_type, \
          p5##_type>::gmock_Impl<F>::gmock_PerformImpl(\
          GMOCK_ACTION_ARG_TYPES_AND_NAMES_UNUSED_) const

#define ACTION_P7(name, p0, p1, p2, p3, p4, p5, p6)\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type>\
  class name##ActionP7 {\
   public:\
    name##ActionP7(p0##_type gmock_p0, p1##_type gmock_p1, \
        p2##_type gmock_p2, p3##_type gmock_p3, p4##_type gmock_p4, \
        p5##_type gmock_p5, p6##_type gmock_p6) : p0(gmock_p0), p1(gmock_p1), \
        p2(gmock_p2), p3(gmock_p3), p4(gmock_p4), p5(gmock_p5), \
        p6(gmock_p6) {}\
    template <typename F>\
    class gmock_Impl : public ::testing::ActionInterface<F> {\
     public:\
      typedef F function_type;\
      typedef typename ::testing::internal::Function<F>::Result return_type;\
      typedef typename ::testing::internal::Function<F>::ArgumentTuple\
          args_type;\
      gmock_Impl(p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
          p3##_type gmock_p3, p4##_type gmock_p4, p5##_type gmock_p5, \
          p6##_type gmock_p6) : p0(gmock_p0), p1(gmock_p1), p2(gmock_p2), \
          p3(gmock_p3), p4(gmock_p4), p5(gmock_p5), p6(gmock_p6) {}\
      virtual return_type Perform(const args_type& args) {\
        return ::testing::internal::ActionHelper<return_type, gmock_Impl>::\
            Perform(this, args);\
      }\
      template <typename arg0_type, typename arg1_type, typename arg2_type, \
          typename arg3_type, typename arg4_type, typename arg5_type, \
          typename arg6_type, typename arg7_type, typename arg8_type, \
          typename arg9_type>\
      return_type gmock_PerformImpl(const args_type& args, arg0_type arg0, \
          arg1_type arg1, arg2_type arg2, arg3_type arg3, arg4_type arg4, \
          arg5_type arg5, arg6_type arg6, arg7_type arg7, arg8_type arg8, \
          arg9_type arg9) const;\
      p0##_type p0;\
      p1##_type p1;\
      p2##_type p2;\
      p3##_type p3;\
      p4##_type p4;\
      p5##_type p5;\
      p6##_type p6;\
     private:\
      GTEST_DISALLOW_ASSIGN_(gmock_Impl);\
    };\
    template <typename F> operator ::testing::Action<F>() const {\
      return ::testing::Action<F>(new gmock_Impl<F>(p0, p1, p2, p3, p4, p5, \
          p6));\
    }\
    p0##_type p0;\
    p1##_type p1;\
    p2##_type p2;\
    p3##_type p3;\
    p4##_type p4;\
    p5##_type p5;\
    p6##_type p6;\
   private:\
    GTEST_DISALLOW_ASSIGN_(name##ActionP7);\
  };\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type>\
  inline name##ActionP7<p0##_type, p1##_type, p2##_type, p3##_type, \
      p4##_type, p5##_type, p6##_type> name(p0##_type p0, p1##_type p1, \
      p2##_type p2, p3##_type p3, p4##_type p4, p5##_type p5, \
      p6##_type p6) {\
    return name##ActionP7<p0##_type, p1##_type, p2##_type, p3##_type, \
        p4##_type, p5##_type, p6##_type>(p0, p1, p2, p3, p4, p5, p6);\
  }\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type>\
  template <typename F>\
  template <typename arg0_type, typename arg1_type, typename arg2_type, \
      typename arg3_type, typename arg4_type, typename arg5_type, \
      typename arg6_type, typename arg7_type, typename arg8_type, \
      typename arg9_type>\
  typename ::testing::internal::Function<F>::Result\
      name##ActionP7<p0##_type, p1##_type, p2##_type, p3##_type, p4##_type, \
          p5##_type, p6##_type>::gmock_Impl<F>::gmock_PerformImpl(\
          GMOCK_ACTION_ARG_TYPES_AND_NAMES_UNUSED_) const

#define ACTION_P8(name, p0, p1, p2, p3, p4, p5, p6, p7)\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type, typename p7##_type>\
  class name##ActionP8 {\
   public:\
    name##ActionP8(p0##_type gmock_p0, p1##_type gmock_p1, \
        p2##_type gmock_p2, p3##_type gmock_p3, p4##_type gmock_p4, \
        p5##_type gmock_p5, p6##_type gmock_p6, \
        p7##_type gmock_p7) : p0(gmock_p0), p1(gmock_p1), p2(gmock_p2), \
        p3(gmock_p3), p4(gmock_p4), p5(gmock_p5), p6(gmock_p6), \
        p7(gmock_p7) {}\
    template <typename F>\
    class gmock_Impl : public ::testing::ActionInterface<F> {\
     public:\
      typedef F function_type;\
      typedef typename ::testing::internal::Function<F>::Result return_type;\
      typedef typename ::testing::internal::Function<F>::ArgumentTuple\
          args_type;\
      gmock_Impl(p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
          p3##_type gmock_p3, p4##_type gmock_p4, p5##_type gmock_p5, \
          p6##_type gmock_p6, p7##_type gmock_p7) : p0(gmock_p0), \
          p1(gmock_p1), p2(gmock_p2), p3(gmock_p3), p4(gmock_p4), \
          p5(gmock_p5), p6(gmock_p6), p7(gmock_p7) {}\
      virtual return_type Perform(const args_type& args) {\
        return ::testing::internal::ActionHelper<return_type, gmock_Impl>::\
            Perform(this, args);\
      }\
      template <typename arg0_type, typename arg1_type, typename arg2_type, \
          typename arg3_type, typename arg4_type, typename arg5_type, \
          typename arg6_type, typename arg7_type, typename arg8_type, \
          typename arg9_type>\
      return_type gmock_PerformImpl(const args_type& args, arg0_type arg0, \
          arg1_type arg1, arg2_type arg2, arg3_type arg3, arg4_type arg4, \
          arg5_type arg5, arg6_type arg6, arg7_type arg7, arg8_type arg8, \
          arg9_type arg9) const;\
      p0##_type p0;\
      p1##_type p1;\
      p2##_type p2;\
      p3##_type p3;\
      p4##_type p4;\
      p5##_type p5;\
      p6##_type p6;\
      p7##_type p7;\
     private:\
      GTEST_DISALLOW_ASSIGN_(gmock_Impl);\
    };\
    template <typename F> operator ::testing::Action<F>() const {\
      return ::testing::Action<F>(new gmock_Impl<F>(p0, p1, p2, p3, p4, p5, \
          p6, p7));\
    }\
    p0##_type p0;\
    p1##_type p1;\
    p2##_type p2;\
    p3##_type p3;\
    p4##_type p4;\
    p5##_type p5;\
    p6##_type p6;\
    p7##_type p7;\
   private:\
    GTEST_DISALLOW_ASSIGN_(name##ActionP8);\
  };\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type, typename p7##_type>\
  inline name##ActionP8<p0##_type, p1##_type, p2##_type, p3##_type, \
      p4##_type, p5##_type, p6##_type, p7##_type> name(p0##_type p0, \
      p1##_type p1, p2##_type p2, p3##_type p3, p4##_type p4, p5##_type p5, \
      p6##_type p6, p7##_type p7) {\
    return name##ActionP8<p0##_type, p1##_type, p2##_type, p3##_type, \
        p4##_type, p5##_type, p6##_type, p7##_type>(p0, p1, p2, p3, p4, p5, \
        p6, p7);\
  }\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type, typename p7##_type>\
  template <typename F>\
  template <typename arg0_type, typename arg1_type, typename arg2_type, \
      typename arg3_type, typename arg4_type, typename arg5_type, \
      typename arg6_type, typename arg7_type, typename arg8_type, \
      typename arg9_type>\
  typename ::testing::internal::Function<F>::Result\
      name##ActionP8<p0##_type, p1##_type, p2##_type, p3##_type, p4##_type, \
          p5##_type, p6##_type, \
          p7##_type>::gmock_Impl<F>::gmock_PerformImpl(\
          GMOCK_ACTION_ARG_TYPES_AND_NAMES_UNUSED_) const

#define ACTION_P9(name, p0, p1, p2, p3, p4, p5, p6, p7, p8)\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type, typename p7##_type, typename p8##_type>\
  class name##ActionP9 {\
   public:\
    name##ActionP9(p0##_type gmock_p0, p1##_type gmock_p1, \
        p2##_type gmock_p2, p3##_type gmock_p3, p4##_type gmock_p4, \
        p5##_type gmock_p5, p6##_type gmock_p6, p7##_type gmock_p7, \
        p8##_type gmock_p8) : p0(gmock_p0), p1(gmock_p1), p2(gmock_p2), \
        p3(gmock_p3), p4(gmock_p4), p5(gmock_p5), p6(gmock_p6), p7(gmock_p7), \
        p8(gmock_p8) {}\
    template <typename F>\
    class gmock_Impl : public ::testing::ActionInterface<F> {\
     public:\
      typedef F function_type;\
      typedef typename ::testing::internal::Function<F>::Result return_type;\
      typedef typename ::testing::internal::Function<F>::ArgumentTuple\
          args_type;\
      gmock_Impl(p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
          p3##_type gmock_p3, p4##_type gmock_p4, p5##_type gmock_p5, \
          p6##_type gmock_p6, p7##_type gmock_p7, \
          p8##_type gmock_p8) : p0(gmock_p0), p1(gmock_p1), p2(gmock_p2), \
          p3(gmock_p3), p4(gmock_p4), p5(gmock_p5), p6(gmock_p6), \
          p7(gmock_p7), p8(gmock_p8) {}\
      virtual return_type Perform(const args_type& args) {\
        return ::testing::internal::ActionHelper<return_type, gmock_Impl>::\
            Perform(this, args);\
      }\
      template <typename arg0_type, typename arg1_type, typename arg2_type, \
          typename arg3_type, typename arg4_type, typename arg5_type, \
          typename arg6_type, typename arg7_type, typename arg8_type, \
          typename arg9_type>\
      return_type gmock_PerformImpl(const args_type& args, arg0_type arg0, \
          arg1_type arg1, arg2_type arg2, arg3_type arg3, arg4_type arg4, \
          arg5_type arg5, arg6_type arg6, arg7_type arg7, arg8_type arg8, \
          arg9_type arg9) const;\
      p0##_type p0;\
      p1##_type p1;\
      p2##_type p2;\
      p3##_type p3;\
      p4##_type p4;\
      p5##_type p5;\
      p6##_type p6;\
      p7##_type p7;\
      p8##_type p8;\
     private:\
      GTEST_DISALLOW_ASSIGN_(gmock_Impl);\
    };\
    template <typename F> operator ::testing::Action<F>() const {\
      return ::testing::Action<F>(new gmock_Impl<F>(p0, p1, p2, p3, p4, p5, \
          p6, p7, p8));\
    }\
    p0##_type p0;\
    p1##_type p1;\
    p2##_type p2;\
    p3##_type p3;\
    p4##_type p4;\
    p5##_type p5;\
    p6##_type p6;\
    p7##_type p7;\
    p8##_type p8;\
   private:\
    GTEST_DISALLOW_ASSIGN_(name##ActionP9);\
  };\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type, typename p7##_type, typename p8##_type>\
  inline name##ActionP9<p0##_type, p1##_type, p2##_type, p3##_type, \
      p4##_type, p5##_type, p6##_type, p7##_type, \
      p8##_type> name(p0##_type p0, p1##_type p1, p2##_type p2, p3##_type p3, \
      p4##_type p4, p5##_type p5, p6##_type p6, p7##_type p7, \
      p8##_type p8) {\
    return name##ActionP9<p0##_type, p1##_type, p2##_type, p3##_type, \
        p4##_type, p5##_type, p6##_type, p7##_type, p8##_type>(p0, p1, p2, \
        p3, p4, p5, p6, p7, p8);\
  }\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type, typename p7##_type, typename p8##_type>\
  template <typename F>\
  template <typename arg0_type, typename arg1_type, typename arg2_type, \
      typename arg3_type, typename arg4_type, typename arg5_type, \
      typename arg6_type, typename arg7_type, typename arg8_type, \
      typename arg9_type>\
  typename ::testing::internal::Function<F>::Result\
      name##ActionP9<p0##_type, p1##_type, p2##_type, p3##_type, p4##_type, \
          p5##_type, p6##_type, p7##_type, \
          p8##_type>::gmock_Impl<F>::gmock_PerformImpl(\
          GMOCK_ACTION_ARG_TYPES_AND_NAMES_UNUSED_) const

#define ACTION_P10(name, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type, typename p7##_type, typename p8##_type, \
      typename p9##_type>\
  class name##ActionP10 {\
   public:\
    name##ActionP10(p0##_type gmock_p0, p1##_type gmock_p1, \
        p2##_type gmock_p2, p3##_type gmock_p3, p4##_type gmock_p4, \
        p5##_type gmock_p5, p6##_type gmock_p6, p7##_type gmock_p7, \
        p8##_type gmock_p8, p9##_type gmock_p9) : p0(gmock_p0), p1(gmock_p1), \
        p2(gmock_p2), p3(gmock_p3), p4(gmock_p4), p5(gmock_p5), p6(gmock_p6), \
        p7(gmock_p7), p8(gmock_p8), p9(gmock_p9) {}\
    template <typename F>\
    class gmock_Impl : public ::testing::ActionInterface<F> {\
     public:\
      typedef F function_type;\
      typedef typename ::testing::internal::Function<F>::Result return_type;\
      typedef typename ::testing::internal::Function<F>::ArgumentTuple\
          args_type;\
      gmock_Impl(p0##_type gmock_p0, p1##_type gmock_p1, p2##_type gmock_p2, \
          p3##_type gmock_p3, p4##_type gmock_p4, p5##_type gmock_p5, \
          p6##_type gmock_p6, p7##_type gmock_p7, p8##_type gmock_p8, \
          p9##_type gmock_p9) : p0(gmock_p0), p1(gmock_p1), p2(gmock_p2), \
          p3(gmock_p3), p4(gmock_p4), p5(gmock_p5), p6(gmock_p6), \
          p7(gmock_p7), p8(gmock_p8), p9(gmock_p9) {}\
      virtual return_type Perform(const args_type& args) {\
        return ::testing::internal::ActionHelper<return_type, gmock_Impl>::\
            Perform(this, args);\
      }\
      template <typename arg0_type, typename arg1_type, typename arg2_type, \
          typename arg3_type, typename arg4_type, typename arg5_type, \
          typename arg6_type, typename arg7_type, typename arg8_type, \
          typename arg9_type>\
      return_type gmock_PerformImpl(const args_type& args, arg0_type arg0, \
          arg1_type arg1, arg2_type arg2, arg3_type arg3, arg4_type arg4, \
          arg5_type arg5, arg6_type arg6, arg7_type arg7, arg8_type arg8, \
          arg9_type arg9) const;\
      p0##_type p0;\
      p1##_type p1;\
      p2##_type p2;\
      p3##_type p3;\
      p4##_type p4;\
      p5##_type p5;\
      p6##_type p6;\
      p7##_type p7;\
      p8##_type p8;\
      p9##_type p9;\
     private:\
      GTEST_DISALLOW_ASSIGN_(gmock_Impl);\
    };\
    template <typename F> operator ::testing::Action<F>() const {\
      return ::testing::Action<F>(new gmock_Impl<F>(p0, p1, p2, p3, p4, p5, \
          p6, p7, p8, p9));\
    }\
    p0##_type p0;\
    p1##_type p1;\
    p2##_type p2;\
    p3##_type p3;\
    p4##_type p4;\
    p5##_type p5;\
    p6##_type p6;\
    p7##_type p7;\
    p8##_type p8;\
    p9##_type p9;\
   private:\
    GTEST_DISALLOW_ASSIGN_(name##ActionP10);\
  };\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type, typename p7##_type, typename p8##_type, \
      typename p9##_type>\
  inline name##ActionP10<p0##_type, p1##_type, p2##_type, p3##_type, \
      p4##_type, p5##_type, p6##_type, p7##_type, p8##_type, \
      p9##_type> name(p0##_type p0, p1##_type p1, p2##_type p2, p3##_type p3, \
      p4##_type p4, p5##_type p5, p6##_type p6, p7##_type p7, p8##_type p8, \
      p9##_type p9) {\
    return name##ActionP10<p0##_type, p1##_type, p2##_type, p3##_type, \
        p4##_type, p5##_type, p6##_type, p7##_type, p8##_type, p9##_type>(p0, \
        p1, p2, p3, p4, p5, p6, p7, p8, p9);\
  }\
  template <typename p0##_type, typename p1##_type, typename p2##_type, \
      typename p3##_type, typename p4##_type, typename p5##_type, \
      typename p6##_type, typename p7##_type, typename p8##_type, \
      typename p9##_type>\
  template <typename F>\
  template <typename arg0_type, typename arg1_type, typename arg2_type, \
      typename arg3_type, typename arg4_type, typename arg5_type, \
      typename arg6_type, typename arg7_type, typename arg8_type, \
      typename arg9_type>\
  typename ::testing::internal::Function<F>::Result\
      name##ActionP10<p0##_type, p1##_type, p2##_type, p3##_type, p4##_type, \
          p5##_type, p6##_type, p7##_type, p8##_type, \
          p9##_type>::gmock_Impl<F>::gmock_PerformImpl(\
          GMOCK_ACTION_ARG_TYPES_AND_NAMES_UNUSED_) const

namespace testing {


// The ACTION*() macros trigger warning C4100 (unreferenced formal
// parameter) in MSVC with -W4.  Unfortunately they cannot be fixed in
// the macro definition, as the warnings are generated when the macro
// is expanded and macro expansion cannot contain #pragma.  Therefore
// we suppress them here.
#ifdef _MSC_VER
# pragma warning(push)
# pragma warning(disable:4100)
#endif

// Various overloads for InvokeArgument<N>().
//
// The InvokeArgument<N>(a1, a2, ..., a_k) action invokes the N-th
// (0-based) argument, which must be a k-ary callable, of the mock
// function, with arguments a1, a2, ..., a_k.
//
// Notes:
//
//   1. The arguments are passed by value by default.  If you need to
//   pass an argument by reference, wrap it inside ByRef().  For
//   example,
//
//     InvokeArgument<1>(5, string("Hello"), ByRef(foo))
//
//   passes 5 and string("Hello") by value, and passes foo by
//   reference.
//
//   2. If the callable takes an argument by reference but ByRef() is
//   not used, it will receive the reference to a copy of the value,
//   instead of the original value.  For example, when the 0-th
//   argument of the mock function takes a const string&, the action
//
//     InvokeArgument<0>(string("Hello"))
//
//   makes a copy of the temporary string("Hello") object and passes a
//   reference of the copy, instead of the original temporary object,
//   to the callable.  This makes it easy for a user to define an
//   InvokeArgument action from temporary values and have it performed
//   later.

namespace internal {
namespace invoke_argument {

// Appears in InvokeArgumentAdl's argument list to help avoid
// accidental calls to user functions of the same name.
struct AdlTag {};

// InvokeArgumentAdl - a helper for InvokeArgument.
// The basic overloads are provided here for generic functors.
// Overloads for other custom-callables are provided in the
// internal/custom/callback-actions.h header.

template <typename R, typename F>
R InvokeArgumentAdl(AdlTag, F f) {
  return f();
}
template <typename R, typename F, typename A1>
R InvokeArgumentAdl(AdlTag, F f, A1 a1) {
  return f(a1);
}
template <typename R, typename F, typename A1, typename A2>
R InvokeArgumentAdl(AdlTag, F f, A1 a1, A2 a2) {
  return f(a1, a2);
}
template <typename R, typename F, typename A1, typename A2, typename A3>
R InvokeArgumentAdl(AdlTag, F f, A1 a1, A2 a2, A3 a3) {
  return f(a1, a2, a3);
}
template <typename R, typename F, typename A1, typename A2, typename A3,
    typename A4>
R InvokeArgumentAdl(AdlTag, F f, A1 a1, A2 a2, A3 a3, A4 a4) {
  return f(a1, a2, a3, a4);
}
template <typename R, typename F, typename A1, typename A2, typename A3,
    typename A4, typename A5>
R InvokeArgumentAdl(AdlTag, F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5) {
  return f(a1, a2, a3, a4, a5);
}
template <typename R, typename F, typename A1, typename A2, typename A3,
    typename A4, typename A5, typename A6>
R InvokeArgumentAdl(AdlTag, F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6) {
  return f(a1, a2, a3, a4, a5, a6);
}
template <typename R, typename F, typename A1, typename A2, typename A3,
    typename A4, typename A5, typename A6, typename A7>
R InvokeArgumentAdl(AdlTag, F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6,
    A7 a7) {
  return f(a1, a2, a3, a4, a5, a6, a7);
}
template <typename R, typename F, typename A1, typename A2, typename A3,
    typename A4, typename A5, typename A6, typename A7, typename A8>
R InvokeArgumentAdl(AdlTag, F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6,
    A7 a7, A8 a8) {
  return f(a1, a2, a3, a4, a5, a6, a7, a8);
}
template <typename R, typename F, typename A1, typename A2, typename A3,
    typename A4, typename A5, typename A6, typename A7, typename A8,
    typename A9>
R InvokeArgumentAdl(AdlTag, F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6,
    A7 a7, A8 a8, A9 a9) {
  return f(a1, a2, a3, a4, a5, a6, a7, a8, a9);
}
template <typename R, typename F, typename A1, typename A2, typename A3,
    typename A4, typename A5, typename A6, typename A7, typename A8,
    typename A9, typename A10>
R InvokeArgumentAdl(AdlTag, F f, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6,
    A7 a7, A8 a8, A9 a9, A10 a10) {
  return f(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}
}  // namespace invoke_argument
}  // namespace internal

ACTION_TEMPLATE(InvokeArgument,
                HAS_1_TEMPLATE_PARAMS(int, k),
                AND_0_VALUE_PARAMS()) {
  using internal::invoke_argument::InvokeArgumentAdl;
  return InvokeArgumentAdl<return_type>(
      internal::invoke_argument::AdlTag(),
      ::testing::get<k>(args));
}

ACTION_TEMPLATE(InvokeArgument,
                HAS_1_TEMPLATE_PARAMS(int, k),
                AND_1_VALUE_PARAMS(p0)) {
  using internal::invoke_argument::InvokeArgumentAdl;
  return InvokeArgumentAdl<return_type>(
      internal::invoke_argument::AdlTag(),
      ::testing::get<k>(args), p0);
}

ACTION_TEMPLATE(InvokeArgument,
                HAS_1_TEMPLATE_PARAMS(int, k),
                AND_2_VALUE_PARAMS(p0, p1)) {
  using internal::invoke_argument::InvokeArgumentAdl;
  return InvokeArgumentAdl<return_type>(
      internal::invoke_argument::AdlTag(),
      ::testing::get<k>(args), p0, p1);
}

ACTION_TEMPLATE(InvokeArgument,
                HAS_1_TEMPLATE_PARAMS(int, k),
                AND_3_VALUE_PARAMS(p0, p1, p2)) {
  using internal::invoke_argument::InvokeArgumentAdl;
  return InvokeArgumentAdl<return_type>(
      internal::invoke_argument::AdlTag(),
      ::testing::get<k>(args), p0, p1, p2);
}

ACTION_TEMPLATE(InvokeArgument,
                HAS_1_TEMPLATE_PARAMS(int, k),
                AND_4_VALUE_PARAMS(p0, p1, p2, p3)) {
  using internal::invoke_argument::InvokeArgumentAdl;
  return InvokeArgumentAdl<return_type>(
      internal::invoke_argument::AdlTag(),
      ::testing::get<k>(args), p0, p1, p2, p3);
}

ACTION_TEMPLATE(InvokeArgument,
                HAS_1_TEMPLATE_PARAMS(int, k),
                AND_5_VALUE_PARAMS(p0, p1, p2, p3, p4)) {
  using internal::invoke_argument::InvokeArgumentAdl;
  return InvokeArgumentAdl<return_type>(
      internal::invoke_argument::AdlTag(),
      ::testing::get<k>(args), p0, p1, p2, p3, p4);
}

ACTION_TEMPLATE(InvokeArgument,
                HAS_1_TEMPLATE_PARAMS(int, k),
                AND_6_VALUE_PARAMS(p0, p1, p2, p3, p4, p5)) {
  using internal::invoke_argument::InvokeArgumentAdl;
  return InvokeArgumentAdl<return_type>(
      internal::invoke_argument::AdlTag(),
      ::testing::get<k>(args), p0, p1, p2, p3, p4, p5);
}

ACTION_TEMPLATE(InvokeArgument,
                HAS_1_TEMPLATE_PARAMS(int, k),
                AND_7_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6)) {
  using internal::invoke_argument::InvokeArgumentAdl;
  return InvokeArgumentAdl<return_type>(
      internal::invoke_argument::AdlTag(),
      ::testing::get<k>(args), p0, p1, p2, p3, p4, p5, p6);
}

ACTION_TEMPLATE(InvokeArgument,
                HAS_1_TEMPLATE_PARAMS(int, k),
                AND_8_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, p7)) {
  using internal::invoke_argument::InvokeArgumentAdl;
  return InvokeArgumentAdl<return_type>(
      internal::invoke_argument::AdlTag(),
      ::testing::get<k>(args), p0, p1, p2, p3, p4, p5, p6, p7);
}

ACTION_TEMPLATE(InvokeArgument,
                HAS_1_TEMPLATE_PARAMS(int, k),
                AND_9_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, p7, p8)) {
  using internal::invoke_argument::InvokeArgumentAdl;
  return InvokeArgumentAdl<return_type>(
      internal::invoke_argument::AdlTag(),
      ::testing::get<k>(args), p0, p1, p2, p3, p4, p5, p6, p7, p8);
}

ACTION_TEMPLATE(InvokeArgument,
                HAS_1_TEMPLATE_PARAMS(int, k),
                AND_10_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)) {
  using internal::invoke_argument::InvokeArgumentAdl;
  return InvokeArgumentAdl<return_type>(
      internal::invoke_argument::AdlTag(),
      ::testing::get<k>(args), p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
}

// Various overloads for ReturnNew<T>().
//
// The ReturnNew<T>(a1, a2, ..., a_k) action returns a pointer to a new
// instance of type T, constructed on the heap with constructor arguments
// a1, a2, ..., and a_k. The caller assumes ownership of the returned value.
ACTION_TEMPLATE(ReturnNew,
                HAS_1_TEMPLATE_PARAMS(typename, T),
                AND_0_VALUE_PARAMS()) {
  return new T();
}

ACTION_TEMPLATE(ReturnNew,
                HAS_1_TEMPLATE_PARAMS(typename, T),
                AND_1_VALUE_PARAMS(p0)) {
  return new T(p0);
}

ACTION_TEMPLATE(ReturnNew,
                HAS_1_TEMPLATE_PARAMS(typename, T),
                AND_2_VALUE_PARAMS(p0, p1)) {
  return new T(p0, p1);
}

ACTION_TEMPLATE(ReturnNew,
                HAS_1_TEMPLATE_PARAMS(typename, T),
                AND_3_VALUE_PARAMS(p0, p1, p2)) {
  return new T(p0, p1, p2);
}

ACTION_TEMPLATE(ReturnNew,
                HAS_1_TEMPLATE_PARAMS(typename, T),
                AND_4_VALUE_PARAMS(p0, p1, p2, p3)) {
  return new T(p0, p1, p2, p3);
}

ACTION_TEMPLATE(ReturnNew,
                HAS_1_TEMPLATE_PARAMS(typename, T),
                AND_5_VALUE_PARAMS(p0, p1, p2, p3, p4)) {
  return new T(p0, p1, p2, p3, p4);
}

ACTION_TEMPLATE(ReturnNew,
                HAS_1_TEMPLATE_PARAMS(typename, T),
                AND_6_VALUE_PARAMS(p0, p1, p2, p3, p4, p5)) {
  return new T(p0, p1, p2, p3, p4, p5);
}

ACTION_TEMPLATE(ReturnNew,
                HAS_1_TEMPLATE_PARAMS(typename, T),
                AND_7_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6)) {
  return new T(p0, p1, p2, p3, p4, p5, p6);
}

ACTION_TEMPLATE(ReturnNew,
                HAS_1_TEMPLATE_PARAMS(typename, T),
                AND_8_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, p7)) {
  return new T(p0, p1, p2, p3, p4, p5, p6, p7);
}

ACTION_TEMPLATE(ReturnNew,
                HAS_1_TEMPLATE_PARAMS(typename, T),
                AND_9_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, p7, p8)) {
  return new T(p0, p1, p2, p3, p4, p5, p6, p7, p8);
}

ACTION_TEMPLATE(ReturnNew,
                HAS_1_TEMPLATE_PARAMS(typename, T),
                AND_10_VALUE_PARAMS(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)) {
  return new T(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
}

#ifdef _MSC_VER
# pragma warning(pop)
#endif

}  // namespace testing

// Include any custom actions added by the local installation.
// We must include this header at the end to make sure it can use the
// declarations from this file.
#include "gmock/internal/custom/gmock-generated-actions.h"

#endif  // GMOCK_INCLUDE_GMOCK_GMOCK_GENERATED_ACTIONS_H_
