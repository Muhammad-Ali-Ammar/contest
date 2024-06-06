#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define endl "\n"

#define rep(i, START_DUMMARY, END_DUMAMY) \
  for (int i = START_DUMMARY; i < (END_DUMAMY); ++i)

#define lim(x) (x.size())
#define isLower(x) ((x & 0b100000) >> 5)
#define Ceil(DUMMAY1, DUMMAY2) ((DUMMAY1 + DUMMAY2 - 1) / DUMMAY2)
/*........... Print Part ........................*/
#define watch(x) cout << (#x) << " = " << x << endl
#define print2dArray(arrrr)       \
  for (auto dummay : arrrr) {     \
    for (auto dummay2 : dummay) { \
      cout << dummay2 << " ";     \
    }                             \
    cout << endl;                 \
  }

#define print3dArray(arrrr)          \
  for (auto dummay : arrrr) {        \
    for (auto dummay2 : dummay) {    \
      for (auto dummay3 : dummay2) { \
        cout << dummay3 << " ";      \
      }                              \
    }                                \
    cout << endl;                    \
  }

#define printArray(arrrr)     \
  for (auto dummay : arrrr) { \
    cout << dummay << " ";    \
  }                           \
  cout << endl;

#define printMap(arrrr)                                   \
  for (auto dummay : arrrr) {                             \
    cout << dummay.first << " " << dummay.second << endl; \
  }                                                       \
  cout << endl;

/*............................................................................*/

#define isVisited(dummmay, element) (dummmay.find(element) != dummmay.end())
#define MB(X, Y) (make_pair(x, y))

typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef long long ll;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void solve();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) {
    solve();
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void solve() {
  string s1, s2;

  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  while (cin >> s1 >> s2) {
    // cin >> s2;
    // if (s1 == "0" || s2 == "0") {
    //   cout << "0" << endl;
    //   continue;
    // }
    int n1 = s1.size();
    int n2 = s2.size();
    // if (n1 + n2 == 0) {
    //   cout << "" << endl;
    //   continue;
    // }
    string ans = string(n1 + n2, '0');
    int idx = n2 + n1 - 1;
    int carry = 0;
    for (int i = n2 - 1; ~i; --i) {
      int dig2 = s2[i] - '0';
      for (int j = n1 - 1; ~j; --j) {
        idx = i + j + 1;
        carry += (s1[j] - '0') * dig2 + (ans[idx] - '0');
        ans[idx] = (carry % 10) + '0';
        carry /= 10;
      }
      while (carry) {
        idx--;
        ans[idx] = (carry % 10) + '0';
        carry /= 10;
      }
    }
    while (carry) {
      idx--;
      ans[idx] = (carry % 10) + '0';
      carry /= 10;
    }

    cout << ans.substr(idx) << endl;
  }
}
