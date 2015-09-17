#include <iostream>

#include "sort.h"

using namespace std;

int main() {
  Sort s;
  int arry[] = {3,2,6,1};
  s.insertionSort( arry, 4 );
  cout << endl;
  for ( int i = 0; i < 4; ++i ) {
    cout << arry[i] << " ";
  }
  cout << endl;
  return 0;
}
