#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;

/*.......................................................................*/
/************************** LCM  **********************/
/*.......................................................................*/

long long lcm(long long a, long long b) {
  return (a * b) / __gcd(a, b);
}

/***************************************************************/

int main() {
  int a = 2, b = 3, c = 7;

  cout << lcm(lcm(a, b), c) << endl;
}