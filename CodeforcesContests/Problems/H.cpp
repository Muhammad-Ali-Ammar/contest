#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define BOOST_SPEED                 \
                                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);

#define endl "\n"

#define rep(i, START_DUMMARY, END_DUMAMY) \
  for (int i = START_DUMMARY; i < (END_DUMAMY); ++i)

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

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef long long ll;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class unionFind {
 public:
  vector<int> par;
  vector<int> nodeNums;

  /***** start with node = 1, 2 , 3 ... 1-indexed .. no node is number 0 */
  unionFind() = delete;

  unionFind(int n) {
    par.resize(n + 1);
    nodeNums.resize(n + 1, 1);
    for (int i = 0; i <= n; ++i)
      par[i] = i;
    nodeNums[0] = 0;  // start with node = 1;
  }

  /// Functions

  int find(int x) {
    int Px = par[x];
    if (Px == x)
      return x;
    return par[x] = find(Px);
  }

  void uni(int a, int b) {
    int Pa = find(a);
    int Pb = find(b);
    if (Pa == Pb)
      return;
    if (nodeNums[Pb] > nodeNums[Pa])
      swap(Pa, Pb);
    par[Pb] = Pa;
    nodeNums[Pa] += nodeNums[Pb];
    nodeNums[Pb] = 0;
  }

  int getNumberOfGraphs() {
    int ans = 0;
    for (auto i : nodeNums) {
      if (i != 0)
        ans++;
    }
    return ans;
  }
};

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

void solve() {
  int x, y;
  cin >> x >> y;
  cout << min(x, y) << " " << max(x, y) << endl;
}
