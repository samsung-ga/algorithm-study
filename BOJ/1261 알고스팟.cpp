//
//  1261 알고스팟.cpp
//  codingtest
//
//  Created by 이재용 on 2020/09/12.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int m,n;
int map[101][101];
int cost[101][101];
int dX[4] = {0,0,1,-1};
int dY[4] = {1,-1,0,0};
queue<pair<int, int>> q;
void bfs() {
    q.push({0,0});
    cost[0][0] = 0;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int newX = x + dX[i];
            int newY = y + dY[i];
            if (newX < 0 || newY < 0 || newX >= m|| newY >= n)
                continue;
            if (map[newX][newY] == 1) {
                if (cost[newX][newY] > cost[x][y] + 1) {
                    cost[newX][newY] = cost[x][y] + 1;
                    q.push(make_pair(newX, newY));
                }
            } else if (map[newX][newY] == 0){
                if (cost[newX][newY] > cost[x][y]) {
                    cost[newX][newY] = cost[x][y];
                    q.push(make_pair(newX, newY));
                }
            }
        }
    }
    cout << cost[m-1][n-1] << "\n";
    return;
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < n; j++) {
            cost[i][j] = 1000000;
            map[i][j] = temp[j] - '0';
        }
    }
    bfs();
    return 0;
}

