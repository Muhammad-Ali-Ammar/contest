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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef long long ll;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class unionFind{
  
  public : 
    vector<int> par;
    vector<int> nodeNums;

    /***** start with node = 1, 2 , 3 ... 1-indexed .. no node is number 0 */
    unionFind()=delete;

    unionFind(int n ){
      par.resize(n+1);
      nodeNums.resize(n+1,1);
      for(int i = 0;i<=n;++i) par[i]=i;
      nodeNums[0]=0; // start with node = 1; 
    }


    /// Functions 

    int find(int x){
      int Px = par[x];
      if(Px==x) return x;
      return par[x]=find(Px);
    }

   void uni(int a, int b){
    int Pa = find(a);
    int Pb = find(b);
    if(Pa==Pb) return ;
    if(nodeNums[Pb]>nodeNums[Pa]) swap(Pa,Pb);
    par[Pb] = Pa;
    nodeNums[Pa]+= nodeNums[Pb];
    nodeNums[Pb]=0;
   }

   int getNumberOfGraphs(){
    int ans = 0;
    for(auto i :nodeNums){
      if(i!=0) ans++;
    }
    return ans;
   }
};



int main() {

  return 0;
}