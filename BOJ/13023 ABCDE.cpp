//
//  13023 ABCDE.cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/13.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
bool dfs(int start, vector<int> graph[], vector<bool> check, int count) {
    check[start] = true;
    for (int i = 0; i < graph[start].size(); i++) {
        int next = graph[start][i];
        if (check[next] == false) {
            if (count + 1 == 4) return true;
            if (dfs(next, graph, check, count+1)) return true;
        }
    }
    return false;
}
int main(void) {
    int n,m;
    cin >> n >> m;
    vector<int> graph[n];
    for (int i = 0; i < m; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        graph[temp1].push_back(temp2);
        graph[temp2].push_back(temp1);
    }
    for (int i = 0; i < n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    vector<bool> check(n);
    for (int i = 0; i < n; i++) {
        if (dfs(i, graph, check, 0)) {
            cout << "1\n";
            return 0;
        } else {
            for (int i = 0; i < n; i++) {
                check[i] = false;
            }
        }
    }
    cout << "0\n";
    return 0;
}

