#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;

int main() {
  int a = 10;
  int b = 4;

  /*........print ......*/
  // cout << bitset<32>(a) << endl;

  /*........get count of ones ......*/
  // cout << bitset<10>(a).count() << endl;

  /*........operation 2 bitsets ......*/

  bitset<32> b1 = a;
  bitset<32> b2 = b;

  bitset<32> result = b1 ^ b2;

  cout << result << endl;

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}