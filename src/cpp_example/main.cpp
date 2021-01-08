#include <stdio.h>
#include <cstdlib>

int main(int argc, char** argv){

  printf("Arguement List: \n");
  for(int i=0; i<argc; i++){
    printf("%d: %s\n", i, argv[i]);
  }

  if(argc != 3){
      printf("Incorrect number of arguements!\n");
      return 1;
  }

  int a = std::atoi(argv[1]);
  int b = std::atoi(argv[2]);

  int c = a*b;

  printf("Result: %d\n", c);

  return 0;
  
}