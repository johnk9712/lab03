//Min Jea Kim, mk4cx, testPostfixCalc.cpp, February 2, 2018
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include "postfixCalculator.h"

using namespace std;

int main(){

  postfixCalculator* calc = new postfixCalculator();

  calc->pushNum(1);
  calc->pushNum(2);
  calc->pushNum(3);
  calc->pushNum(4);
  calc->pushNum(5);
  calc->add();
  calc->add();
  calc->add();
  calc->add();
  calc->negate();
  
  
      

  cout<<calc->getTopValue()<<endl;







  return 0;
}
