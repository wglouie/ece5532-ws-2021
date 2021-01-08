#include "Factorial.h"
#include <stdio.h>

int main(int argc, char** argv){
  cpp_example::Factorial f;
  cpp_example::Factorial g(5);

  int result = f.compute();
  int result2 = g.compute();
  printf("Result1 : %d \n", result);
  printf("Result2: %d \n", result2);
  
  return 0;
}