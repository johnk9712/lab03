//Min Jea Kim, mk4cx, postfixCalculator.cpp, February 2, 2018
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <stack>
#include "postfixCalculator.h"

using namespace std;
using std::stack;

postfixCalculator::postfixCalculator(){ //default constructor
  stack <int> a_stack;
}


postfixCalculator::postfixCalculator(stack <int> theStack){ //copy constructor
  a_stack = theStack;
}

void postfixCalculator::pushNum(int x){

  a_stack.push(x);

}

void postfixCalculator::add(){

  int num1 = a_stack.top();
  a_stack.pop();
  int num2 = a_stack.top();
  a_stack.pop();
  int added = num1 + num2;

  a_stack.push(added);
  
}

void postfixCalculator::subtract(){
  int num1 = a_stack.top();
  a_stack.pop();
  int num2 = a_stack.top();
  a_stack.pop();
  int subtracted = num1 - num2;

  a_stack.push(subtracted);

}


void postfixCalculator::multiply(){
  int num1 = a_stack.top();
  a_stack.pop();
  int num2 = a_stack.top();
  a_stack.pop();
  int multiplied = num1 * num2;

  a_stack.push(multiplied);

}



void postfixCalculator::divide(){
  int num1 = a_stack.top();
  a_stack.pop();
  int num2 = a_stack.top();
  a_stack.pop();
  int divided = num1 + num2;

  a_stack.push(divided);

}


void postfixCalculator::negate(){
  int foo = a_stack.top();
  int negated = -1 * foo;
  a_stack.push(negated);

}

int  postfixCalculator::getTopValue(){

  return a_stack.top();
}
