//Min Jea Kim, mk4cx, testPostfixCalc.cpp, February 2, 2018
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include "postfixCalculator.h"

using namespace std;

class stack{
 public:
  stack();
  ~stack();
  
  void push(int x); //pushes an integer onto the stack
  
  void pop(); //gets the top integer from the stack
  
  int top(); //returns the value of the top
  
  void empty(); //gets rid of the whole stack



 private:
  




}
