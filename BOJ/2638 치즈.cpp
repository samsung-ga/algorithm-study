//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//int n,m;
//
//vector<vector<int>> map;
//vector<vector<bool>> visited;
//
//int dy[4] = {0,1,0,-1};
//int dx[4] = {-1,0,1,0};
//
//void find_inner() {
//  
//  
//  for (int i = 0; i < n; i++) {
//    for (int j = 0; j < m; j++) {
//      visited[i][j] = false;
//    }
//  }
//  
//  queue<pair<int, int>> que;
//  que.push({0,0});
//  visited[0][0] = true;
//  while (!que.empty()) {
//    int a = que.front().first;
//    int b = que.front().second;
//    que.pop();
//    for (int i = 0; i < 4; i++) {
//      int newA = a + dy[i];
//      int newB = b + dx[i];
//      if (newA >= 0 && newB >= 0 && newA < n && newB < m &&
//          visited[newA][newB] == false &&
//          map[newA][newB] != 1) {
//        
//        visited[newA][newB] = true;
//        map[newA][newB] = 3;
//        que.push({newA,newB});
//      }
//    }
//  }
//}
//
//bool find_melt_cheese(int a, int b) {
//  int number = 0;
//  for (int i = 0; i < 4; i++) {
//    int newA = a + dy[i];
//    int newB = b + dx[i];
//    if (newA >= 0 && newB >= 0 && newA < n && newB < m &&
//        map[newA][newB] == 3) {
//      number++;
//    }
//  }
//  return number >= 2 ? true : false;
//}
//
//int main(void) {
//  cin >> n >> m;
//  
//  for (int i = 0; i < n; i++) {
//    vector<int> temp;
//    for (int j = 0 ; j < m; j++) {
//      int tt;
//      cin >> tt;
//      temp.push_back(tt);
//    }
//    map.push_back(temp);
//  }
//  
//  for (int i = 0; i < n; i++) {
//    vector<bool> temp;
//    for (int j = 0; j < m; j++) {
//      temp.push_back(false);
//    }
//    visited.push_back(temp);
//  }
//  
//  
//  
//  
//
//  int result = 0;
//  while (1) {
//    find_inner();
//    
//    vector<pair<int, int>> store;
//    for (int i = 0; i < n; i++) {
//      for (int j = 0; j < m; j++) {
//        if (map[i][j] == 1 && find_melt_cheese(i, j)) {
//          store.push_back({i,j});
//        }
//      }
//    }
//    
//    if (store.empty()) {
//      break;
//    } else {
//      result++;
//      for (int i = 0; i < store.size(); i++) {
//        map[store[i].first][store[i].second] = 3;
//      }
//    }
//    
//    
////    for (int i = 0; i < n; i++) {
////      for (int j = 0; j < m; j++) {
////        cout << map[i][j] << " ";
////      }
////      cout << "\n";
////    }
////    break;
//  }
//  cout << result << "\n";
//  return 0;
//}
