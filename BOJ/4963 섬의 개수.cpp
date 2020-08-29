//
//  4963 섬의 개수.cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/29.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int map[52][52];
bool visited[52][52];
int dX[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dY[8] = {1, 0, -1, 1, -1, 1, 0, -1};
void dfs(int i, int j) {
    visited[i][j] = true;
    for (int direction = 0; direction < 8; direction++) {
        int x = i + dX[direction];
        int y = j + dY[direction];
        if (map[x][y] == 1 && visited[x][y] == false) {
            dfs(x, y);
        }
    }
}
int main(void) {
    while(1) {
        int w,h;
        cin >> w >> h;
        // 끝나는 조건
        if (w == 0 && h == 0) {
            break;
        }
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> map[i][j];
            }
        }
        int island = 0;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                if (map[i][j] == 1 && visited[i][j] == false) {
                    island++;
                    dfs(i, j);
                }
            }
        }
        cout << island << "\n";
        
        for (int i = 0; i < 52; i++) {
            for (int j = 0; j < 52; j++) {
                map[i][j] = 0;
                visited[i][j] = false;
            }
        }
    }
    return 0;
}

