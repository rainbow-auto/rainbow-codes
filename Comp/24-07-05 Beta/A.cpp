#include <iostream>

using namespace std;

int foo(char *x) {
  return 3**x*2;
}

int main() {
  char arr[10] = {char(10)};
  arr[1] = foo(arr);
  cout << int(arr[0]) * int(arr[1]) << endl;
}
