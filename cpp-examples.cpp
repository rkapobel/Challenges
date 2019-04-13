// Example program
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

void load(int * memo) {
    for (int i = 0; i < 10; i++)
        memo[i] = i + 1;
}

void load2(int memo[]) {
    for (int i = 0; i < 10; i++)
        memo[i] = i + 1;
}

void print(int * memo) {
    for (int i = 0; i < 10; i++)
        cout << "value i: " << memo[i] << endl;
}

/*
void print2(int memo[]) {
    for (int elem : memo)
        cout << "value i: " << elem << endl;
}
*/

void test1() {
  int * memo = new int[10];
  int varNextToMemo = 0;
  load(memo);
  print(memo);
  cout << "memo: " << endl;
  cout << "value at position 0 (memo it is a pointer to the first position): " << *memo << endl;
  cout << "memory value &memo: " << &memo << endl;
  cout << "memory value &varNextToMemo: " << &varNextToMemo << endl;
  cout << "memory value memo: " << memo << endl;
  cout << "type: pointer array 10 int: " << typeid(&memo).name() << endl;
  cout << "type: array 10 int: " << typeid(memo).name() << endl;  
  delete[] memo;
}

void test2() {
  int memo2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  load(memo2);
  print(memo2);
  cout << "memo2: " << endl;
  cout << "value at position 0 (memo2 it is a pointer to the first position): " << *memo2 << endl;
  cout << "memory value: " << &memo2 << endl;
  cout << "type: pointer array 10 int: " << typeid(&memo2).name() << endl;
  cout << "type: array 10 int: " << typeid(memo2).name() << endl;
}

void test3() {
  int memo3[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  load2(memo3);
  cout << "memo3: " << endl;
  cout << "value at position 0 (memo3 it is a pointer to the first position): " << *memo3 << endl;
  cout << "memory value: " << &memo3 << endl;
  cout << "type: pointer array 10 int: " << typeid(&memo3).name() << endl;
  cout << "type: array 10 int: " << typeid(memo3).name() << endl;
  print(memo3);
}

void test4() {
   int  var;
   int  *ptr;
   int  **pptr;
   var = 3000;
   // take the address of var
   ptr = &var;
   // take the address of ptr using address of operator &
   pptr = &ptr;
   // take the value using pptr
   cout << "Value of var :" << var << endl;
   cout << "Value available at *ptr :" << *ptr << endl;
   cout << "Value available at **pptr :" << **pptr << endl;
}

int main() {
  /*
  string name;
  cout << "What is your name? ";
  getline (cin, name);
  cout << "Hello, " << name << "!" << endl;
  */
  test4();
}
