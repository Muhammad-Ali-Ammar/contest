#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;

int main() {
  /*.......................................................................*/
  /************************** Upper Bound *********/
  /*.......................................................................*/

  // first element that is (((greater))) than x

  vector<int> v3 = {10, 20, 30, 40, 50};
  auto it = upper_bound(v3.begin(), v3.end(), 20);

  // the answer is pos of 30
  // if no exist ==> return end
  /***************************************************************/

  /*.......................................................................*/
  /************************** Lower Bound **********************/
  /*.......................................................................*/
  // first element that is (((greater or Equal))) than x

  vector<int> v4 = {10, 20, 30, 40, 50};
  auto it2 = lower_bound(v4.begin(), v4.end(), 20);

  // the answer is pos of 20
  // if no exist ==> return end
  /***************************************************************/

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}