//
//  11724 연결 요소의 개수.cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/12.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

void dfs(int start, vector<int> v[], bool check[]) {
    check[start] = true;
    for (int i = 0; i < v[start].size(); i++) {
        int next = v[start][i];
        if (check[next] == false) {
            dfs(next, v, check);
        }
    }
}
int main(void) {
    int n,m;
    cin >> n >> m;
    vector<int> graph[n+1];
    for (int i = 0; i < m; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        graph[temp1].push_back(temp2);
        graph[temp2].push_back(temp1);
    }
    for (int i = 0; i < n+1; i++) {
        sort(graph[i].begin(),graph[i].end());
    }
    bool check[n+1];
    for (int i = 0; i < n+1; i++) {
        check[i] = false;
    }
    int sum = 0;
    for (int i = 1; i < n+1; i++) {
        if (check[i] == false) {
            dfs(i, graph, check);
            sum++;
        }
    }
    cout << sum << "\n";
    return 0;
}

