//
//  7576 토마토.cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/31.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int box[1002][1002];
bool visited[1002][1002];
int dX[4] = {0, 0, 1, -1}; // 위, 아래, 오른쪽, 아래
int dY[4] = {1, -1, 0, 0};
queue<pair<int, int>> q;
void bfs() {
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int newX = x + dX[i];
            int newY = y + dY[i];
            if (box[newX][newY] == 0 && visited[newX][newY] == false) {
                box[newX][newY] = box[x][y] + 1;
                visited[newX][newY] = true;
                q.push(make_pair(newX, newY));
            }
        }
    }
}
int main(void) {
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < n+2; i++) {
        for (int j = 0; j < m+2; j++) {
            box[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1) {
                visited[i][j] = true;
                q.push(make_pair(i, j));
            }
        }
    }
    bfs();
    int cnt = 0;
    bool check = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (box[i][j] == 0 && visited[i][j] == false) {
                check = false;
                break;
            } else {
                cnt = box[i][j] > cnt ? box[i][j] : cnt;
            }
        }
    }
    if (check) {
        cout << cnt - 1 << "\n";
    } else {
        cout << "-1" << "\n";
    }
    return 0;
}


