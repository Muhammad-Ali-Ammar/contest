#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;
void backTracking_go_go(vector<int>& arr, vector<int>& tempAns, int idx, int k ) {

    if(tempAns.size()==k){
	// Take Action 
    /*......................HERE ...............................*/
      
      // print array
      for(auto i : arr) cout<<i<<" ";
      cout<<endl;
      return ;
    }



  int n = arr.size();
  for (int i = idx; i < n; ++i) {
    tempAns.push_back(arr[i]);
    backTracking_go_go(arr, tempAns, i + 1,k);
    tempAns.pop_back();
  }
}


void generateAllKsubSquance(vector<int>& arr,int k) {
  vector<int> tempAns;


  backTracking_go_go(arr, tempAns, 0,k);
}

int main() {

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

