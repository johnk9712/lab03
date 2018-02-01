////Min Jea Kim, mk4cx,ListItr.cpp , January 29, 2018
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

ListItr::ListItr(){
//Constructor
  current = new ListNode;
}


ListItr::ListItr(ListNode* theNode){	// One parameter constructor
  current = theNode;
}

//--------------------------------------METHODS----------------------------
bool ListItr::isPastEnd() const{	//Returns true if past end position
  return current->next == NULL;
}
    
bool ListItr:: isPastBeginning() const{ //Returns true if past first position
  return current->previous == NULL;
}


void ListItr:: moveForward(){	//Advances current to next position in list
    //(unless already past end of list)
  if(isPastEnd() == false){
    current = current->next;
  }

}
  
void ListItr:: moveBackward(){	//Moves current back to previous position
    // in list (unless already past beginning of
    // list)
  if(isPastBeginning() == false)
    current = current->previous;

}
  
int ListItr::retrieve() const{	//Returns item in current position
  return current->value;
}
  
