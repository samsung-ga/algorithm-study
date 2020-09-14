//
//  2206 벽 부수고 이동하기.cpp
//  codingtest
//
//  Created by 이재용 on 2020/09/12.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
int map[1002][1002];
int dist[1002][1002][2];
int dX[4] = {0,0,1,-1};
int dY[4] = {1,-1,0,0};
// x y count(벽)
queue<pair<pair<int, int>, int>> q;
void bfs(int n, int m) {
    q.push({{0,0},0});
    dist[0][0][0] = 1;
    dist[0][0][1] = 1;
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int count = q.front().second;
        q.pop();
        if (x == n-1 && y == m-1) {
            cout << dist[n-1][m-1][count] << "\n";
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dX[i];
            int ny = y + dY[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (dist[nx][ny][count] == 0 && map[nx][ny] == 1 && count == 0) {
                dist[nx][ny][1] = dist[x][y][count] + 1;
                q.push({{nx, ny}, count + 1});
            } else if (dist[nx][ny][count] == 0 && map[nx][ny] == 0) {
                dist[nx][ny][count] = dist[x][y][count] + 1;
                q.push({{nx, ny}, count});
            }
        }
    }
    
    cout << "-1\n";
    
    
    return;
}
int main(void) {
    int n,m;
    cin >> n >> m;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < m; j++) {
            map[i][j] = str[j] - '0';
        }
    }
    bfs(n,m);
    return 0;
}
