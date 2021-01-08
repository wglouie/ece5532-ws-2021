#ifndef FACTORIAL
#define FACTORIAL

namespace cpp_example{
  
  class Factorial{
    public:
      Factorial();
      Factorial(int n);
      ~Factorial();
      int compute();

    private:
      int n_;
  };


}

#endif