#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "data_structures/All_Structures.hh"

using namespace std::string_literals;

//--------Testy dla Stosu implementacja tablicowa-------//
TEST_CASE("StackTab/push")
{
    StackTab<int> stack;

    stack.push(10);
    REQUIRE(stack.stacksize() == 1);

    stack.push(20);
    REQUIRE(stack.stacksize() == 2);

    stack.push(30);
    REQUIRE(stack.stacksize() == 3);
}

TEST_CASE("StackTab/pop")
{
    StackTab<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    REQUIRE(stack.pop() == 30);
    REQUIRE(stack.pop() == 20);
    REQUIRE(stack.pop() == 10);
}

TEST_CASE("StackTab/empty")
{
    StackTab<int> stack;

    REQUIRE(stack.empty() == true);

    stack.push(10);
    stack.push(20);
    REQUIRE(stack.empty() == false);

    stack.pop();
    REQUIRE(stack.empty() == false);

    stack.pop();
    REQUIRE(stack.empty() == true);
}

TEST_CASE("StackTab/top")
{
    StackTab<int> stack;

    stack.push(10);
    stack.push(20);

    REQUIRE(stack.top() == 20);
    REQUIRE(stack.stacksize() == 2);
    stack.pop();

    REQUIRE(stack.top() == 10);
    REQUIRE(stack.stacksize() == 1);
}

TEST_CASE("StackTab/resizeTabWhenNeeded")
{
    StackTab<int> stack(1);

    stack.push(10);
    REQUIRE_NOTHROW(stack.push(20));
    REQUIRE_NOTHROW(stack.push(30));

    REQUIRE(stack.top() == 30);
    REQUIRE(stack.stacksize() == 3);
}

//---------Testy dla kolejki implementacja tablicowa------//
TEST_CASE("QueueTab")
{
    QueueTab<int> queue(2);

    queue.enqueue(10);
    queue.enqueue(20);

    REQUIRE(queue.empty() == false);

    REQUIRE(queue.front() == 10);
    REQUIRE(queue.queueSize() == 2);
    REQUIRE(queue.dequeue() == 10);
    REQUIRE(queue.queueSize() == 1);
    REQUIRE(queue.front() == 20);

    queue.enqueue(30);
    queue.enqueue(40);

    REQUIRE(queue.queueSize() == 3);

    REQUIRE(queue.dequeue() == 20);
    REQUIRE(queue.dequeue() == 30);
    REQUIRE(queue.dequeue() == 40);

    REQUIRE(queue.empty() == true);
}

//--------Testy dla list-------//
TEST_CASE("SinglyLinkedList/addingFrontAndBackElements")
{
    SinglyLinkedList<int> list;
    list.addFront(10);
    REQUIRE(list.front() == 10);
    list.addFront(20);
    REQUIRE(list.front() == 20);

    REQUIRE(list.size() == 2);

    REQUIRE(list.back() == 10);
    list.addBack(30);
    REQUIRE(list.back() == 30);

    REQUIRE(list.size() == 3);
}

TEST_CASE("SinglyLinkedList/removingFrontAndBackElements")
{
    SinglyLinkedList<int> list;
    list.addFront(10);
    list.addFront(20);
    list.addFront(30);

    REQUIRE(list.front() == 30);
    REQUIRE(list.back() == 10);
    REQUIRE(list.size() == 3);

    list.removeFront();
    REQUIRE(list.front() == 20);
    REQUIRE(list.size() == 2);

    list.removeBack();
    REQUIRE(list.back() == 20);
    REQUIRE(list.size() == 1);
}

TEST_CASE("SinglyLinkedList/isEmpty")
{
    SinglyLinkedList<int> list;
    REQUIRE(list.empty() == true);
    list.addFront(10);
    REQUIRE(list.empty() == false);
    list.removeFront();
    REQUIRE(list.empty() == true);
}

TEST_CASE("SinglyLinkedList/indexing")
{
    SinglyLinkedList<int> list;
    list.addFront(10);
    list.addFront(20);
    list.addFront(30);
    list.addFront(40);
    REQUIRE(list[0] == 40);
    REQUIRE(list[1] == 30);
    REQUIRE(list[2] == 20);
    REQUIRE(list[3] == 10);
}
/*
TEST_CASE("SinglyLinkedList/insert")
{
    SinglyLinkedList<int> list;
    list.addBack(10);
    list.addBack(20);
    REQUIRE(list[0] == 10);
    REQUIRE(list[1] == 20);

    list.insert(40, 1);
    REQUIRE(list[0] == 10);
    REQUIRE(list[1] == 40);
    REQUIRE(list[2] == 20);
}

TEST_CASE("SinglyLinkedList/remove")
{
    SinglyLinkedList<int> list;
    list.addBack(10);
    list.addBack(20);
    list.addBack(10);
    REQUIRE(list.size() == 3);
    list.remove(10);
    REQUIRE(list.size() == 1);
}
*/

TEST_CASE("DoublyLinkedList/addingFrontAndBackElements")
{
    DoublyLinkedList<int> list;
    list.addFront(10);
    REQUIRE(list.front() == 10);
    list.addFront(20);
    REQUIRE(list.front() == 20);

    REQUIRE(list.size() == 2);

    REQUIRE(list.back() == 10);
    list.addBack(30);
    REQUIRE(list.back() == 30);

    REQUIRE(list.size() == 3);
}

TEST_CASE("DoublyLinkedList/removingFrontAndBackElements")
{
    DoublyLinkedList<int> list;
    list.addFront(10);
    list.addFront(20);
    list.addFront(30);

    REQUIRE(list.front() == 30);
    REQUIRE(list.back() == 10);
    REQUIRE(list.size() == 3);

    list.removeFront();
    REQUIRE(list.front() == 20);
    REQUIRE(list.size() == 2);

    list.removeBack();
    REQUIRE(list.back() == 20);
    REQUIRE(list.size() == 1);
}

TEST_CASE("DoublyLinkedList/isEmpty")
{
    DoublyLinkedList<int> list;
    REQUIRE(list.empty() == true);
    list.addFront(10);
    REQUIRE(list.empty() == false);
    list.removeFront();
    REQUIRE(list.empty() == true);
}

TEST_CASE("DoublyLinkedList/indexing")
{
    DoublyLinkedList<int> list;
    list.addFront(10);
    list.addFront(20);
    list.addFront(30);
    list.addFront(40);
    REQUIRE(list[0] == 40);
    REQUIRE(list[1] == 30);
    REQUIRE(list[2] == 20);
    REQUIRE(list[3] == 10);
}

/*
TEST_CASE("DoublyLinkedList/insert")
{
    DoublyLinkedList<int> list;
    list.addBack(10);
    list.addBack(20);
    REQUIRE(list[0] == 10);
    REQUIRE(list[1] == 20);

    list.insert(40, 1);
    REQUIRE(list[0] == 10);
    REQUIRE(list[1] == 40);
    REQUIRE(list[2] == 20);
}

TEST_CASE("DoublyLinkedList/remove")
{
    DoublyLinkedList<int> list;
    list.addBack(10);
    list.addBack(20);
    list.addBack(10);
    REQUIRE(list.size() == 3);
    list.remove(10);
    REQUIRE(list.size() == 1);
}
*/

//---------Testy dla Stos implementacja na liście----//
TEST_CASE("StackList/push")
{
    StackList<int> stack;

    stack.push(10);
    REQUIRE(stack.stackSize() == 1);

    stack.push(20);
    REQUIRE(stack.stackSize() == 2);

    stack.push(30);
    REQUIRE(stack.stackSize() == 3);
}
/*
TEST_CASE("StackList/pop")
{
    StackList<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    REQUIRE(stack.pop() == 30);
    REQUIRE(stack.pop() == 20);
    REQUIRE(stack.pop() == 10);
}
*/
TEST_CASE("StackList/empty")
{
    StackList<int> stack;

    REQUIRE(stack.empty() == true);

    stack.push(10);
    stack.push(20);
    REQUIRE(stack.empty() == false);

    stack.pop();
    REQUIRE(stack.empty() == false);

    stack.pop();
    REQUIRE(stack.empty() == true);
}

TEST_CASE("StackList/top")
{
    StackList<int> stack;

    stack.push(10);
    stack.push(20);

    REQUIRE(stack.top() == 20);
    REQUIRE(stack.stackSize() == 2);
    stack.pop();

    REQUIRE(stack.top() == 10);
    REQUIRE(stack.stackSize() == 1);
}

//---------Testy dla kolejki implementacja listowa------//
TEST_CASE("QueueList")
{
    QueueList<int> queue;

    queue.enqueue(10);
    queue.enqueue(20);

    REQUIRE(queue.empty() == false);

    REQUIRE(queue.front() == 10);
    REQUIRE(queue.queueSize() == 2);
  //  REQUIRE(queue.dequeue() == 10);
    queue.dequeue();
    REQUIRE(queue.queueSize() == 1);
    REQUIRE(queue.front() == 20);

    queue.enqueue(30);
    queue.enqueue(40);

    REQUIRE(queue.queueSize() == 3);
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
   // REQUIRE(queue.dequeue() == 20);
   // REQUIRE(queue.dequeue() == 30);
   // REQUIRE(queue.dequeue() == 40);

    REQUIRE(queue.empty() == true);
}
/*
//---------Testy Kopiec-------//
TEST_CASE("Heap/insert")
{
    Heap<int> heap;
    REQUIRE(heap.size() == 0);

    heap.insert(10);
    heap.insert(20);

    REQUIRE(heap[1] == 20);
    REQUIRE(heap[2] == 10);
    REQUIRE(heap.size() == 2);

    heap.insert(30);

    REQUIRE(heap[1] == 30);
    REQUIRE(heap[2] < 30);
    REQUIRE(heap[3] < 30);
    REQUIRE(heap.size() == 3);
}

TEST_CASE("Heap/removeMax")
{
    Heap<int> heap;
    REQUIRE(heap.empty() == true);

    heap.insert(10);
    heap.insert(40);
    heap.insert(30);
    heap.insert(20);

    REQUIRE(heap[1] == 40);
    REQUIRE(heap.size() == 4);

    heap.removeMax();

    REQUIRE(heap.size() == 3);
    REQUIRE(heap[1] == 30);
    REQUIRE(heap.empty() == false);
}
*/