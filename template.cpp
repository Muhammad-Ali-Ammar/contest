#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define BOOST_SPEED                   \
  {                                   \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);                \
  }

#define endl "\n"
#define rep(i, n) for (int i = 0; i < n; ++i)
#define watch(x) cout << (#x) << " = " << x << endl
#define lim(x) (x.size())
#define appendNtimes(str, N, word)          \
  for (int DumMy = 0; DumMy < (N); ++DumMy) \
    str += word;

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

#define pr pair<int, int>

#define isVisited(dummmay, element) (dummmay.find(element) != dummmay.end())
#define MB(X, Y) (make_pair(x, y))

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef long long ll;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void solve();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
  // BOOST_SPEED

  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void solve() {}

