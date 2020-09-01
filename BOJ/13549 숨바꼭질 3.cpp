//
//  13549 숨바꼭질 3.cpp
//  codingtest
//
//  Created by 이재용 on 2020/09/01.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

bool visited[100001];
queue<pair<int, int>> q;
void bfs(int n, int k) {
    q.push(make_pair(n, 0));
    while (!q.empty()) {
        int x = q.front().first;
        int time = q.front().second;
        q.pop();
        visited[x] = true;
        if (x == k) {
            cout << time << "\n";
            return;
        }
        int newX;
        newX = x - 1;
        if (newX >= 0 && visited[newX] == false) {
            q.push(make_pair(newX, time+1));
        }
        newX = x * 2;
        if (newX <= 100000 && visited[newX] == false) {
            q.push(make_pair(newX, time));
        }
        newX = x + 1;
        if (newX <= 100000 && visited[newX] == false) {
            q.push(make_pair(newX, time+1));
        }
    }
}
int main(void) {
    int n,k;
    cin >> n >> k;
    bfs(n, k);
    return 0;
}


