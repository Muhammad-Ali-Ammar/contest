#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;

int main() {
  /*.......................................................................*/
  /************************** Binary Search **********************/
  /*.......................................................................*/

  vector<int> v5 = {10, 20, 30, 40, 50};
  bool ok = binary_search(v5.begin(), v5.end(), 20);
  cout << ok << endl;

  int max_range_possible = 10;
  int left = 1, right = max_range_possible;
  int ans = -1;
  while (left <= right) {
    // ans should be updated ...
    int mid = left + right >> 1;
    //   if () {
    //     right = mid - 1;
    //   } else {
    //     left = mid + 1;
    //   }
  }

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}