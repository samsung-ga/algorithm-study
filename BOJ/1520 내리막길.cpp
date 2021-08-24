//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int m,n;
//int dp[500][500];
//vector<vector<int>> map;
//
//int dfs(int a, int b) {
//  
//  if (a == m-1 && b == n-1) { // 목적지 도달
//    return 1;
//  }
//  if (dp[a][b] == -1) { 
//    dp[a][b] = 0;
//    for (int i = 0; i < 4; i++) {
//      if (i == 0) { // 위
//        int aa = a-1;
//        int bb = b;
//        if (aa >= 0 && map[a][b] > map[aa][bb]) {
//          dp[a][b] += dfs(aa, bb);
//        }
//      } else if (i == 1) { // 오른쪽
//        int aa = a;
//        int bb = b+1;
//        if (bb < n && map[a][b] > map[aa][bb]) {
//          dp[a][b] += dfs(aa, bb);
//        }
//      } else if (i == 2) { // 아래
//        int aa = a+1;
//        int bb = b;
//        if (aa < m && map[a][b] > map[aa][bb]) {
//          dp[a][b] += dfs(aa, bb);
//        }
//      } else { // 왼쪽
//        int aa = a;
//        int bb = b-1;
//        if (bb >= 0 && map[a][b] > map[aa][bb]) {
//          dp[a][b] += dfs(aa, bb);
//        }
//      }
//    }
//  }
//  return dp[a][b];
//}
//
//int main() {
//  cin >> m >> n;
//  for (int i = 0; i < m; i++) {
//    vector<int> temp;
//    for (int j = 0 ; j < n; j++) {
//      int tt;
//      cin >> tt;
//      temp.push_back(tt);
//    }
//    map.push_back(temp);
//  }
//  
//  for (int i = 0; i < 500; i++) {
//    for (int j = 0; j < 500; j++) {
//      dp[i][j] = -1;
//    }
//  }
//  
//  cout << dfs(0,0);
//  return 0;
//}
