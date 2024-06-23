#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;

int main() {
  // vector
  vector<int> vec1 = {1, 3, 5, 7};
  vector<int> vec2 = {2, 4, 6, 8};
  vector<int> result(vec1.size() + vec2.size());

  merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), result.begin());

  // string

  string s1 = "abc";
  string s2 = "defg";

    string s3(s1.size() + s2.size(), '\0');

    merge(s1.begin(), s1.end(), s2.begin(), s2.end(), s3.begin());
  cout << s3 << endl;

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}