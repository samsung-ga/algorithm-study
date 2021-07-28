//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <vector>
//using namespace std;
//
//int n;
//vector<vector<int>> map;
//vector<vector<int>> result;
//vector<bool> check;
//
//void dfs(int from, int to, int depth = 0) {
//    if (from == to && depth > 0) {
//        check[to] = true;
//    } else {
//        if (check[from] == false) {
//            if (from != to) {
//                check[from] = true;
//            }
//            for (int i = 0; i < map[from].size(); i++) {
//                if (map[from][i] == 1) {
//                    dfs(i, to, depth+1);
//                }
//            }
//        }
//    }
//}
//
//void init_check() {
//    while(!check.empty()) {
//        check.pop_back();
//    }
//    for (int i = 0; i < n; i++) {
//        check.push_back(false);
//    }
//}
//
//int main(void) {
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//        vector<int> temp_v;
//        for (int j = 0; j < n; j++) {
//            int temp;
//            cin >> temp;
//            temp_v.push_back(temp);
//        }
//        map.push_back(temp_v);
//    }
//    init_check();
//    for (int i = 0; i < n; i++) {
//        vector<int> temp_v;
//        for (int j = 0; j < n; j++) {
//            dfs(i,j);
//            if (check[j] == true) {
//                temp_v.push_back(1);
//            } else {
//                temp_v.push_back(0);
//            }
//            init_check();
//        }
//        result.push_back(temp_v);
//    }
//    
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << result[i][j] << " ";
//        }
//        cout << "\n";
//    }
//    
//    return 0;
//}
