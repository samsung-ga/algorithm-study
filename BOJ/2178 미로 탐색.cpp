//
//  2178 미로 탐색.cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/30.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int map[102][102];
bool visited[102][102];
queue<pair<int, int>> q;
int dX[4] = {-1, 0, 0, 1}; // 왼 위 아래 오른
int dY[4] = {0, 1, -1, 0};
void bfs(int n, int m) {
    while(!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if (i == n && j == m) {
            return;
        }
        for (int direction = 0; direction < 4; direction++) {
            int x = i + dX[direction];
            int y = j + dY[direction];
            if (map[x][y] != 0 && visited[x][y] == false) {
                map[x][y] = map[i][j] + 1;
                q.push(make_pair(x, y));
                visited[x][y] = true;
            }
        }
    }
    
}
int main(void) {
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < temp.size(); j++) {
            map[i][j+1] = temp[j] - '0';
        }
    }
    q.push(make_pair(1, 1));
    visited[1][1] = true;
    bfs(n, m);
    cout << map[n][m] << "\n";
    return 0;
}

