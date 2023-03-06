#include <cmath>
#include <cstring>
#include <functional>
#include <utility>
#include <iostream>

using std::pair;
using std::string;
using std::function;

template<class A>
using Writer = pair<A, string>;

template <class A> class optional {
  bool  _isValid;
  A     _value;
public:
  optional() : _isValid(false) {};
  optional(A v) : _isValid(true), _value(v) {};

  bool isValid() const {return _isValid;}
  A value() const {return _value;}
};

template<class A, class B, class C>
function<optional<C>(A)> compose (
  function<optional<B>(A)> m1,
  function<optional<C>(B)> m2
){
  return [m1, m2] (A x) {
    auto p1 = m1(x);
    if (!p1.isValid()) {
      return optional<C>();
    }
    return m2(p1.value());
  };

}

optional<double> safe_root(double x) {
  if (x >= 0) {
    return optional<double>(sqrt(x));
  } else {
    return optional<double>();
  } 
}

optional<double> safe_reciprocal(int x) {
  if (x != 0) {
    return optional<double> (1.0 / (double)x);
  } else {
    return optional<double>();
  }
}

optional<double> safe_plus(double x) {
  if (x >= 0) {
    return optional<double>(x + 10);
  } else {
    return optional<double>();
  } 
}


int main() {

  auto p1 = optional<double>();
  Writer<double> wri(42, "Hola");

  auto composed = compose<double, double, double>(safe_root, safe_plus);
  auto res1 = composed(9.0);
  std::cout << res1.isValid() << " and " << res1.value() << std::endl;

  auto safe_root_reciprocal = compose<int, double, double>(safe_root, safe_reciprocal);
  auto res2 = safe_root_reciprocal(9.0);
  std::cout << res2.isValid() << " and " << res2.value() << std::endl;

  auto res3 = safe_root_reciprocal(-9.0);
  std::cout << res3.isValid() << " and " << res3.value() << std::endl;

  auto res4 = safe_root_reciprocal(0.0);
  std::cout << res4.isValid() << " and " << res4.value() << std::endl;
}
