//
//  1260 DFS와 BFS.cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/12.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(int start, vector<int> graph[], bool check[]) {
    check[start] = true;
    cout << start << " ";
    for (int i = 0; i < graph[start].size(); i++) {
        int next = graph[start][i];
        if (check[next] == false) {
            dfs(next, graph, check);
        }
    }
}

void bfs(int start, vector<int> graph[], bool check[]) {
    check[start] = true;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        start = q.front();
        q.pop();
        cout << start << " ";
        for (int i = 0; i < graph[start].size(); i++) {
            int next = graph[start][i];
            if (check[next] == false) {
                q.push(next);
                check[next] = true;
            }
        }
    }
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,v;
    cin >> n >> m >> v;
    vector<int> graph[n+1]; // 이중배열
    for (int i = 0; i < m; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        graph[temp1].push_back(temp2);
        graph[temp2].push_back(temp1);
    }
    
    for (int i = 0; i < n+1; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    bool check[n+1];
    for (int i = 0; i < n+1; i++) {
        check[i] = false;
    }
    dfs(v, graph, check);
    cout << "\n";
    for (int i = 0; i < n+1; i++) {
        check[i] = false;
    }
    bfs(v, graph, check);
    return 0;
}
