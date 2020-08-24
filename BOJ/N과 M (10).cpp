//
//  N과 M (10).cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/24.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void dfs(int index,vector<int> res, vector<int> v, int m) {
    if (index == m) {
        for (int i = 0; i < res.size(); i++) {
            cout << v[res[i]] << " ";
        }
        cout << "\n";
        return;
    }
    int smallest = res.empty() ? 0 : res.back() + 1;
    int used[10000] = {0,};
    for(int i = smallest; i < v.size(); i++) {
        if (!used[v[i]]) {
            res.push_back(i);
            used[v[i]] = 1;
            dfs(index+1, res, v, m);
            res.pop_back();
        }
    }
}
int main(void) {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<int> temp;
    dfs(0, temp, v, m);
    
    return 0;
}

