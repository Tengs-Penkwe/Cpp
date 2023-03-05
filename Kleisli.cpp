#include <cmath>
#include <cstring>
#include <functional>
#include <utility>
#include <iostream>

using std::pair;
using std::string;
using std::function;

template <class A> class optional {
  bool  _isValid;
  A     _value;
public:
  optional() : _isValid(false) {};
  optional(A v) : _isValid(true), _value(v) {};

  bool isValid() const {return _isValid;}
  A value() const {return _value;}
};

optional<double> safe_root(double x) {
  if (x >= 0) {
    return optional<double>(sqrt(x));
  } else {
    return optional<double>();
  } 
}

template<class A>
using Writer = pair<A, string>;

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

int main() {
  auto p1 = optional<double>();

  Writer<double> wri(42, "Hola");

  

}
