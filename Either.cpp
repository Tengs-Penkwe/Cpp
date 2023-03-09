#include <iostream>
using std::string;

template<class A>class Either{
  bool    _isRight;
  string  left;
  A       right;
public:
  Either() : _isRight(false), left("Not initialized") {};
  Either(A x) : _isRight(true), right(x) {};

  void Left(string x) { left = x; _isRight = false;}
  void Right(A x) { right = x; _isRight = true;}

  bool isRight(){ return _isRight; } 
  string getLeft() { return left;}
  A    getRight() { return right;}
};

int i(int n) {return n;}
int j(bool b) {return b ? 0:1;}

int m(Either<string> const & e) {

}


int main(int argc, char** argv) {

  auto eith = Either<string>();

  if (argc >= 2) {
    eith.Left("haha");
  } else {
    eith.Right("jaja");
  }

  if (eith.isRight()) {
    std::cout << eith.getRight() << std::endl;
  } else {
    std::cout << eith.getLeft() << std::endl;
  }
  
}
