#include "libraries.hh"
#include "All_Structures.hh"
#include "SinglyLinkedList.hh"


int main() {
  SinglyLinkedList<int> Lista;
  for (int i=0;i<4;i++){
    Lista.addBack(i);
    Lista.write_out();
  }
  while(!Lista.empty()) {
    Lista.removeBack();
    Lista.write_out();
  };
  Lista.addBack(1);
  Lista.write_out();
  return 0;
}