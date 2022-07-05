#include <iostream>
using namespace std;

class Stack {
  int i;
  int capacity;
  int *arr;

public:

  Stack () {
    i = -1;
    capacity = 1;
    arr = new int[capacity];
  }

  void doubleStack() {
    int *temp = arr;
    arr = new int[capacity * 2];
    for (int i = 0; i < capacity; i++) {
      arr[i] = temp[i];
    }

    capacity = capacity * 2;
    delete[] temp;
  }

  void push(int key) {
    if (i >= capacity - 1) {
      doubleStack();
    }

    arr[++i] = key;
  }

  int top() {
    if (i == -1) return -1;
    return arr[i];
  }

  void pop() {
    if (i == -1) return;
    i--;
  }

  bool empty() {
    return i == -1 ? true : false;
  }

  int size() {
    return i + 1;
  }

  int getCapacity() {
    return capacity;
  }
};

int main() {

  Stack s;
  for (int i = 0; i < 9; i++) {
    s.push(i);
  }

  cout << s.top() << " " << s.getCapacity() << "\n";
  s.pop();
  cout << s.top() << " " << s.getCapacity() << "\n";
  return 0;
}

// Here incStack implements increase the stack by +1
// doubleStack implements increase the stack by double
// Time complexity in inc +1
// T(1) =  0
// T(2) = 1 + 0
// T(n-1) = n-2 + .. 1 (no of copy operations)
// Therefore T(n) = n + n -1  + ..... 1 = o(n^2);

// Time Complexity for double strategy
// T(n) = n/2 + n/4 + n/8 + .... + 1;
// T(n) = n(1/2*(1 - (1/2)^k)/ =~ o(n)
// k = log2(n)
// Therefore Time Complexity of Double Strategy is less than the Time complexity of Inc + 1 Strategy.