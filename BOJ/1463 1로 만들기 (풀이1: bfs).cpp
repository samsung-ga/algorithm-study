//
//  1463 1로 만들기 (풀이1: bfs).cpp
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
queue<pair<int, int>> q;
vector<int> v;
void bfs(int n) {
    q.push(make_pair(n, 0));
    while(!q.empty()) {
        int x = q.front().first;
        int count = q.front().second;
        q.pop();
        if (x == 1) {
            cout << count << "\n";
            return;
        }
        if (x>=1 && x%3 == 0) {
            q.push(make_pair(x/3, count+1));
        }
        if (x>=1 && x%2 == 0) {
            q.push(make_pair(x/2, count+1));
        }
        if (x>=1) {
            q.push(make_pair(x-1, count+1));
        }
    }
    return;
}
int main(void) {
    int n;
    cin >> n;
    bfs(n);
    return 0;
}

