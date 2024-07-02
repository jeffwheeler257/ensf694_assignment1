// lab1exe_E.cpp
// ENSF 694 Lab 1 Exercise E

#include <iostream>
using namespace std;

int what(const int *a, int n);

// This function was not written for easy readability!
// It's a drill exercise about pointer arithmetic!
int what(const int *a, int n)
{
  const int *max = a, *min = a + n - 1, *guard = a + n;
  const int *p, *q;

  cout << "At the start of the function: \n";
  cout << "*max is "  << *max << " *min is " << *min << " *guard is " << *guard << "\n";
  cout << "*p is uninitialized" << "*q is uninitialized" << "\n";

  for (p = a + 1; p != guard; p++) {
    if (*p > *max)
      max = p;
  }
  for (q = a + n - 1; q != a; q--) {
    if (q[-1] < *min)
      min = q - 1;
  }
  
  cout << "At the end of the function: \n";
  cout << "*max is "  << *max << " *min is " << *min << " *guard is " << *guard << "\n";
  cout << "*p is " << *p << "*q is " << *q << "\n";
  // point one (after the 2nd loop has finished)

  return min - max;
}

int main(void)
{
  int w;
  int x[] = {99, 0, 0, -99, 0, 0};
  int y[] = {1, 0, 100, 2, 0, 3};
  w = what(x, sizeof(x) / sizeof(int));
  cout << "1st result: " << w << ".\n";
  w = what(y, sizeof(y) / sizeof(int));
  cout << "2nd result: " << w << ".\n";
  return 0;
}
