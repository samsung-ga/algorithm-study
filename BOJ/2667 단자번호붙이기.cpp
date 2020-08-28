//
//  2667 단자번호붙이기.cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/28.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int map[27][27];
bool visited[27][27];
int houseNumber;
int dX[4] = {0, 0, 1, -1};
int dY[4] = {1, -1, 0, 0};
void dfs(int i, int j) {
    visited[i][j] = true;
    houseNumber++;
    for (int direction = 0; direction < 4; direction++) {
        int x = i + dX[direction];
        int y = j + dY[direction];
        if (visited[x][y] == false && map[x][y] == 1) {
            dfs(x, y);
        }
    }
}
int main(void) {
    int n;
    cin >> n;
    // 초기화
    for (int i = 0; i < 27; i++) {
        for (int j = 0; j < 27; j++) {
            map[i][j] = 0;
            visited[i][j] = false;
        }
    }
    // 입력
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            map[i][j] = s[j-1] - '0';
        }
    }
    
    // 계산
    vector<int> v;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (map[i][j] == 1 && visited[i][j] == false) {
                houseNumber = 0;
                dfs(i, j);
                v.push_back(houseNumber);
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }
    return 0;
}

