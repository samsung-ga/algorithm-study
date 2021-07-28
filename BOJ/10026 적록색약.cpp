//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int n;
//vector<vector<char>> map;
//vector<vector<bool>> check;
//vector<vector<bool>> check_blind;
//
//void dfs(int x, int y) {
//    if (check[x][y] == false) {
//        check[x][y] = true;
//        if (x-1 >= 0 && y >= 0 && map[x-1][y] == map[x][y]) {
//            // 위
//            dfs(x-1, y);
//        }
//        if (x >= 0 && y+1 < n && map[x][y+1] == map[x][y]) {
//            // 오른쪽
//            dfs(x, y+1);
//        }
//        if (x+1 < n && y >=0 && map[x+1][y] == map[x][y]) {
//            // 아래
//            dfs(x+1, y);
//        }
//        if (x >= 0 && y-1 >= 0 && map[x][y-1] == map[x][y]){
//            // 왼쪽
//            dfs(x, y-1);
//        }
//    }
//}
//
//void dfs_blind(int x, int y) {
//    if (check_blind[x][y] == false) {
//        check_blind[x][y] = true;
//        
//            if (x-1 >= 0 && y >= 0 && map[x-1][y] == map[x][y]) {
//                // 위
//                dfs_blind(x-1, y);
//            } else if (x-1 >= 0 && y >= 0 && (map[x][y] == 'G' || map[x][y] == 'R')) {
//                if (map[x-1][y] == 'G' || map[x-1][y] == 'R') {
//                    dfs_blind(x-1, y);
//                }
//            }
//            if (x >= 0 && y+1 < n && map[x][y+1] == map[x][y]) {
//                // 오른쪽
//                dfs_blind(x, y+1);
//            } else if (x >= 0 && y+1 < n && (map[x][y] == 'G' || map[x][y] == 'R')) {
//                if (map[x][y+1] == 'G' || map[x][y+1] == 'R') {
//                    dfs_blind(x, y+1);
//                }
//            }
//            if (x+1 < n && y >=0 && map[x+1][y] == map[x][y]) {
//                // 아래
//                dfs_blind(x+1, y);
//            } else if (x+1 < n && y >= 0 && (map[x][y] == 'G' || map[x][y] == 'R')) {
//                if (map[x+1][y] == 'G' || map[x+1][y] == 'R') {
//                    dfs_blind(x+1, y);
//                }
//            }
//            if (x >= 0 && y-1 >= 0 && map[x][y-1] == map[x][y]){
//                // 왼쪽
//                dfs_blind(x, y-1);
//            } else if (x >= 0 && y-1 >= 0 && (map[x][y] == 'G' || map[x][y] == 'R')) {
//                if (map[x][y-1] == 'G' || map[x][y-1] == 'R') {
//                    dfs_blind(x, y-1);
//                }
//            }
// 
//    }
//}
//
//int main(void) {
//    cin >> n;
//    
//    for (int i = 0; i < n; i++) {
//        vector<char> str;
//        for (int j = 0; j < n; j++) {
//            char temp;
//            cin >> temp;
//            str.push_back(temp);
//        }
//        map.push_back(str);
//    }
//    
//    for (int i = 0; i < n; i++) {
//        vector<bool> temp;
//        vector<bool> temp2;
//        for (int j = 0; j < n; j++) {
//            temp.push_back(false);
//            temp2.push_back(false);
//        }
//        check.push_back(temp);
//        check_blind.push_back(temp2);
//    }
//
//    int color_blind = 0;
//    int color_yes = 0;
//
//    for (int i = 0; i < n ; i++) {
//        for (int j = 0; j < n; j++) {
//            if (check[i][j] == false) {
//                dfs(i,j);
//                color_yes++;
//            }
//            if (check_blind[i][j] == false ) {
//                dfs_blind(i, j);
//                color_blind++;
//            }
//        }
//    }
//    cout << color_yes << " " << color_blind;
//    return 0;
//}
