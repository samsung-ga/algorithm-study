//
//  3055 탈출.cpp
//  codingtest
//
//  Created by 이재용 on 2020/09/12.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string>
using namespace std;
char map[60][60];
bool visited[60][60];
int times[60][60];
pair<int, int> endd;
int r, c;
int dX[4] = {0, 0, -1, 1};
int dY[4] = {1, -1, 0, 0};
queue<pair<int, int>> q;
queue<pair<int, int>> water;
void bfs() {
        unsigned long int waterSize = water.size();
        while (waterSize--) {
            int newXForWater = water.front().first;
            int newYForWater = water.front().second;
            water.pop();
            for (int i = 0; i < 4; i ++) {
                int newX = newXForWater + dX[i];
                int newY = newYForWater + dY[i];
                if (newX < 1 || newY < 1 || newX > r || newY > c) continue;
                if (map[newX][newY] == '.') {
                    map[newX][newY] = '*';
                    water.push(make_pair(newX, newY));
                }
            }
        }
        unsigned long int qSize = q.size();
        while (qSize--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            if (x == endd.first && y == endd.second) {
                cout << times[x][y] << "\n";
                return;
            }
            for (int i = 0; i < 4; i++) {
                int newX = x + dX[i];
                int newY = y + dY[i];
                if (newX < 1 || newY < 1 || newX > r || newY > c)
                    continue;
                if (visited[newX][newY] == true || map[newX][newY] == 'X' || map[newX][newY] == '*')
                    continue;
                times[newX][newY] = times[x][y] + 1;
                visited[newX][newY] = true;
                q.push(make_pair(newX, newY));
            }
        }
    
    if (q.empty()) {
        cout << "KAKTUS" << "\n";
    } else {
        bfs();
    }
    return;
    
}
int main(void) {
    cin >> r >> c;
    
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 60; j++) {
            map[i][j] = -2;
        }
    }
    
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'S') {
                q.push(make_pair(i, j));
            } else if (map[i][j] == 'D'){
                endd = make_pair(i, j);
            } else if (map[i][j] == '*'){
                water.push(make_pair(i, j));
            }
            
        }
    }
    
    bfs();
    return 0;
}

