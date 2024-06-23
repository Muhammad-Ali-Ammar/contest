#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;

typedef long long ll;
#define watch(x) cout << (#x) << " = " << x << endl

#define printArray(arrrr)     \
  for (auto dummay : arrrr) { \
    cout << dummay << " ";    \
  }                           \
  cout << endl;

class SegmentTree {
#define get_leftIdx(curNodeIdx_Dummay) (2 * curNodeIdx_Dummay + 1)
#define get_rightIdx(curNodeIdx_Dummay) (2 * curNodeIdx_Dummay + 2)
#define get_midIdx(leftIdx_Dum, rightIdx_Dum) \
  ((leftIdx_Dum + rightIdx_Dum) >> 1)

 private:
  int n;
  vector<ll> seg;

 private:
  /////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////
  /*..........Change....................*/
  // action  = merage function
  ll priv_takeAction(ll a, ll b) {
    return a + b; /*..........Change....................*/
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////
  /*..........Fixed....................*/
  // build function
  void priv_build(int leftRange,
                  int rightRange,
                  int curNodeIdx,
                  vector<ll>& cpyV)
  // PostOrder DFS
  {
    if (leftRange == rightRange) {
      // base condition

      if (leftRange < cpyV.size()) {
        seg[curNodeIdx] = cpyV[leftRange];
      }

      return;
    }

    // go left
    priv_build(leftRange, get_midIdx(leftRange, rightRange),
               get_leftIdx(curNodeIdx), cpyV);
    // got right
    priv_build(get_midIdx(leftRange, rightRange) + 1, rightRange,
               get_rightIdx(curNodeIdx), cpyV);

    // process

    seg[curNodeIdx] =
        (seg[get_leftIdx(curNodeIdx)] + seg[get_rightIdx(curNodeIdx)]);
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////
  // update function
  void priv_update(int leftRange,
                   int rightRange,
                   int curNodeIdx,
                   int reqIdx,
                   ll val)
  // update point
  {
    // reach to the required node
    if (leftRange == rightRange && leftRange == reqIdx) {
      seg[curNodeIdx] = val;
      return;
    }

    if (reqIdx <= get_midIdx(leftRange, rightRange)) {
      // go left
      priv_update(leftRange, get_midIdx(leftRange, rightRange),
                  get_leftIdx(curNodeIdx), reqIdx, val);
    } else {
      // go right
      priv_update(get_midIdx(leftRange, rightRange) + 1, rightRange,
                  get_rightIdx(curNodeIdx), reqIdx, val);
    }

    // process
    seg[curNodeIdx] = priv_takeAction(seg[get_leftIdx(curNodeIdx)],
                                      seg[get_rightIdx(curNodeIdx)]);
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////
  /*..........Change....................*/
  /*..........Change....................*/
  /*..........Change....................*/
  /*..........Change....................*/
  // query
  ll priv_query(int leftRange, int rightRange, int QL, int QR, int curNodeIdx) {
    // 4 cases..

    // 1,2  ..out of range

    if (leftRange > QR || rightRange < QL)
      return 0; /*..........Change....................*/

    // if included
    if (leftRange >= QL && rightRange <= QR) {
      return seg[curNodeIdx];
    }

    // go left

    ll ansLeft = priv_query(leftRange, get_midIdx(leftRange, rightRange), QL,
                            QR, get_leftIdx(curNodeIdx));
    // go right

    ll ansRight = priv_query(get_midIdx(leftRange, rightRange) + 1, rightRange,
                             QL, QR, get_rightIdx(curNodeIdx));

    return priv_takeAction(ansLeft, ansRight);
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////
 public:
  SegmentTree() = default;

  SegmentTree(vector<ll>& cpyV) {
    int loc_n = cpyV.size();
    n = 1 << (int)ceil(log2(loc_n));  // larger power of 2

    /*...........Change Inital Value..........................*/
    /*...........Change Inital Value..........................*/
    /*...........Change Inital Value..........................*/
    /*...........Change Inital Value..........................*/
    seg = vector<ll>(2 * n, 0);
    priv_build(0, n - 1, 0, cpyV);
  }

  SegmentTree(int cpyN) {
    int loc_n = cpyN;
    n = 1 << (int)ceil(log2(loc_n));  // larger power of 2

    /*...........Change Inital Value..........................*/
    /*...........Change Inital Value..........................*/
    /*...........Change Inital Value..........................*/
    /*...........Change Inital Value..........................*/
    seg = vector<ll>(2 * n, 0);
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////
  // public_update

  void update(int idx, ll val) { priv_update(0, n - 1, 0, idx, val); }

  /////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////

  // public query

  ll query(int QL, int QR) { return priv_query(0, n - 1, QL, QR, 0); }

#undef leftIdx
#undef rightIdx
#undef midIdx
};

int main() {
  int n, q = 1;
  cin >> n >> q;
  vector<ll> v(n);
  for (auto& i : v)
    cin >> i;
  SegmentTree tree = SegmentTree(v);

  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int idx, val;
      cin >> idx >> val;
      tree.update(idx, val);
    } else {
      int l, r;
      cin >> l >> r;
      cout << tree.query(l, r - 1) << endl;
    }
  }

  return 0;
}
