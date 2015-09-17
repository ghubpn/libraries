#include "sort.h"

#include <iostream>

void Sort::insertionSort( int* keys, int size ) {
  int key;
  int cur;
  for ( int i = 1; i < size; ++i ) {
    cur = i - 1;
    key = keys[i];
    while ( cur >= 0 && keys[cur] > key ) {
      keys[cur+1] = keys[cur];
      --cur;
      keys[cur+1] = key;
    }
  }
}
