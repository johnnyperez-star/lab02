#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = nullptr;
}

void StudentRoll::insertAtTail(const Student &s) {
  Node* headNode = new Node();
  headNode->s = new Student(s);
  headNode->next = nullptr;

  if (head == nullptr){
    head = headNode;
    tail = headNode;
  }
    else{
      tail->next = headNode;
      tail = headNode;
    }
  }


std::string StudentRoll::toString() const {
  std::string fullStr;
  fullStr = "[";
  Node* temp = head;

  while(temp != nullptr){
    fullStr += temp->s->toString();

    if (temp->next != nullptr){
      fullStr += ",";
    }
    temp = temp->next;
  }
  fullStr += "]";
  return fullStr;
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  // STUB
  head = tail = nullptr;
  Node* nodeStart = orig.head;
  while(nodeStart != nullptr){
    insertAtTail(*(nodeStart->s));
    nodeStart = nodeStart->next;
  }
}

StudentRoll::~StudentRoll() {
  Node* begin = head;
  while(begin != nullptr){
    Node* temp = begin;
    begin = begin->next;
    delete temp->s;
  }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  Node* begin = head;
  while(begin != nullptr){
    Node* temp = begin;
    begin = begin->next;
    delete temp->s;
  }
    head = tail = nullptr;
  Node* nodeStart = right.head;
  while(nodeStart != nullptr){
    insertAtTail(*(nodeStart->s));
    nodeStart = nodeStart->next;
  }
  // TODO... Here is where there is code missing that you need to 
  // fill in...


  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}
