#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define endl "\n"

#define rep(i, START_DUMMARY, END_DUMAMY) \
  for (int i = START_DUMMARY; i < (END_DUMAMY); ++i)

#define lim(x) (x.size())
#define isLower(x) ((x & 0b100000) >> 5)
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

#define all(dummay) dummay.begin(), dummay.end()
#define isVisited(dummmay, element) (dummmay.find(element) != dummmay.end())
#define MB make_pair

typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef long long ll;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*....... Interactive Problems .................*/

string ask(ll guessedNumber) {
  cout << guessedNumber << endl;
  cout.flush();

  string ret;
  cin >> ret;
  return ret;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void solve();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void solve() {}
