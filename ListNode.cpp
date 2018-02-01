//Min Jea Kim, mk4cx, , January 29, 2018
#include <iostream>
#include <string>
#include <ctype.h>
#include <stdlib.h>
using namespace std;

//Make sure your own files for the List and ListItr
//classes are included here.  These are the names I used.
#include "List.h"
#include "ListItr.h"
#include "ListNode.h"

ListNode::ListNode(){
  next = NULL;
  previous = NULL;
}
