#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;

#define pofp pair<int, pair<int, int>>

int swimInWater(vector<vector<int>>& grid) {
  priority_queue<pofp, vector<pofp>, greater<pofp>> pq;

  int rows = grid.size();
  int cols = grid[0].size();

  pq.push(make_pair(grid[0][0], make_pair(0, 0)));

  pair<int, int> dest = make_pair(rows - 1, cols - 1);
  while (pq.top().second != dest) {
    pofp cur = pq.top();
    pq.pop();

    int val = cur.first;
    int i = cur.second.first;
    int j = cur.second.second;
    // right
    if (j + 1 < cols && grid[i][j + 1] != INT_MAX) {
      pq.push(make_pair(max(val, grid[i][j + 1]), make_pair(i, j + 1)));
      grid[i][j + 1] = INT_MAX;
    }

    // down
    if (i + 1 < rows && grid[i + 1][j] != INT_MAX) {
      pq.push(make_pair(max(val, grid[i + 1][j]), make_pair(i + 1, j)));
      grid[i + 1][j] = INT_MAX;
    }

    // up
    if (i - 1 >= 0 && grid[i - 1][j] != INT_MAX) {
      pq.push(make_pair(max(val, grid[i - 1][j]), make_pair(i - 1, j)));
      grid[i - 1][j] = INT_MAX;
    }

    // left
    if (j - 1 >= 0 && grid[i][j - 1] != INT_MAX) {
      pq.push(make_pair(max(val, grid[i][j - 1]), make_pair(i, j - 1)));
      grid[i][j - 1] = INT_MAX;
    }
  }

  return pq.top().first;
}

int main() {
  return 0;
}