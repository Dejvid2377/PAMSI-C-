#include "libraries.hh"
#include "All_Structures.hh"


int main() {
  StackTab<int> Stack;
  Stack.push(1);
  Stack.push(2);
  Stack.pop();
  Stack.pop();
  Stack.pop();
  Stack.pop();
  Stack.pop();
  return 0;

}