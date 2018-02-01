//Min Jea Kim, mk4cx, postfixCalculator.cpp, February 2, 2018
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <stack>

using namespace std;
using std::stack;

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

class postfixCalculator{

 public:
  postfixCalculator();
  postfixCalculator(stack <int> a_stack);

  void pushNum(int x); //push a number to the stack
  
  void add(); //adds two numbers together

  void subtract(); //deletes two numbers
  
  void multiply(); //multiplies two numbers

  void divide(); //divides two numbers

  void negate(); //negates a number

  int getTopValue();

 private:
  int value;
  stack <int> a_stack;
  
};


#endif
