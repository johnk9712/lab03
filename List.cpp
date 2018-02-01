//Min Jea Kim, mk4cx,List.cpp , January 29, 2018
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

List::List(){
  //default constructor, create a head and tail node
  head = new ListNode;
  tail = new ListNode;

  //make the head point to the memory of tail and vice versa
  head->next = tail;
  tail->previous = head;

  head->previous = NULL; //head node should have no previous
  tail->next = NULL; //tail node should have no next
 
}

//----------------------------------------------------------------------
List::~List(){
  //deconstructor, get rid of two nodes once done
  delete head;
  delete tail;
  
}

List::List(const List& source) {      // Copy Constructor
    head=new ListNode;
    tail=new ListNode;
    head->next=tail;
    tail->previous=head;
    count=0;
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {       // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

List& List::operator=(const List& source) { //Equals operator
    if (this == &source)
        return *this;
    else {
      //make the whole list empty first
        makeEmpty();
        ListItr iter(source.head->next);
	//copy the values until NULL is reached
	while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}
//-------------------------------GOOD------------------------------------

//
bool List::isEmpty() const{
  //Returns true if empty; else false
  return (count == 0); 

}

//------------------------------FIX, DELETE THE NODES---------------------------

void List::makeEmpty(){
//Removes all items except blank head and tail
  // ListNode* new_node = head->next;
  ListItr* iter = new ListItr(head->next);
  while(iter->current->next != NULL){
    int x = iter->current->value;
    iter->moveForward();
    remove(x);
    
  }

}

//------------------------------GOOD-------------------------------------

ListItr List::first(){
//Returns an iterator that points to the ListNode in the first position
  ListItr* iterator = new ListItr(head->next);
  return *iterator;
}

//--------------------------------GOOD------------------------------------

ListItr List::last(){
//Returns an iterator that points to the ListNode in the last position
  ListItr* iterator = new ListItr(tail->previous);
  return *iterator;
}

//----------------------------GOOD--------------------------------------
void List::insertAfter(int x, ListItr position){
//Inserts x after current iterator position p

  ListNode* new_node = new ListNode;
  new_node->value = x;

  ListNode* mover = position.current;
  //assuming position isn't the last node
  if(position.isPastEnd() == false){
    new_node->previous = position.current;
    position.current = position.current->next;
    new_node->next = position.current;
    position.current->previous = new_node;
    position.current = position.current->previous;
    position.current = position.current->previous;
    position.current->next = new_node;
    count +=1;
    
    
  }
  else if(  position.isPastEnd() == true ){
    position.current->next = new_node;
    new_node->previous = position.current;
    tail->previous = new_node;
    count += 1;
  }
  
}

//---------------------------GOOD---------------------------------------
void List::insertBefore(int x, ListItr position){
 //Inserts x before current iterator position p


  ListNode* new_node = new ListNode;
  new_node->value = x;

  //assuming position is not the head
  if(position.isPastBeginning() == false){
    //set the new pointers for the new_node
    new_node->previous = position.current->previous;
    new_node->next = position.current;
    //make current pointer previous to new_node
    position.current->previous = new_node;
    //move back twice because it's connected to the new node
    position.current = position.current->previous;
    position.current = position.current->previous;
    //set pointer of node's next to new node  before original position 
    position.current->next = new_node;
    
    count +=1;
  }
  //assuming position is the head
  else if(position.isPastBeginning() == true){
    new_node->next = position.current;
    new_node->previous = head;
    tail->next = new_node;
    position.current->previous = new_node;
    
    count+=1;

  }
  
}

//------------------------------------------------------------------
void  List::insertAtTail(int x){
 //Insert x at tail of list
  ListNode* node = new ListNode;

  node->value = x;
  ListNode* prev = tail->previous;
  node->next = tail;
  node->previous = prev;
  prev->next = node;
  tail->previous = node;

  count += 1;

}

//-----------------------------------------------------------------
void List::remove(int x){
//Removes the first occurrence of x
  this->find(x);

  if(find(x).current->next != NULL){
    ListItr iterator = find(x);
    ListNode* temp = new ListNode;
    temp->previous = iterator.current->previous;
    temp->next = iterator.current->next;
    iterator.current->previous->next = temp->next;
    iterator.current->next->previous = temp->previous;
    //  delete *iterator;
    count -= 1;
  }
  
}

//-----------------------------------------------------------------
ListItr List::find(int x){	//Returns an iterator that points to
    // the first occurrence of x, else return a iterator to the dummy tail node
  
  ListItr* iterator = new ListItr(tail);
  
  int return_what = 0;
  
  while(iterator->retrieve() != x){
    if(iterator->isPastBeginning() == false)
      iterator->moveBackward();
    else if (iterator->isPastBeginning() == true)
      break;
  }

  if(iterator->retrieve() == x){
     return_what = 1; //1 will return the iterator
  }
  if(return_what == 1){
    return *iterator;
  }
  else{
    iterator = new ListItr(tail);
    return* iterator;
  }
  
}

//------------------------------------------------------------------
int List::size() const{
//Returns the number of elements in the list

  ListNode* node = head->next;
  int size = 0;
  while(node->next != NULL){
    node = node->next;
    size += 1;
  }

  return size;
}
//--------------------------------------------------------------------
void printList(List& source, bool direction){
//prints list forwards when direction is true
//or backwards when direction is false

  if(direction == true){
    ListItr* iterator = new ListItr(source.first());
    while(iterator->isPastEnd() == false){
      cout<<iterator->retrieve()<<endl;
      iterator->moveForward();
    }
  }
  if(direction == false){
    ListItr* iterator = new ListItr(source.last());
    while(iterator->isPastBeginning() ==false){
      cout<<iterator->retrieve()<<endl;
      iterator->moveBackward();
    }

  }
  
}
