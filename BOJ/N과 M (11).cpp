//
//  N과 M (11).cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/31.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
set<vector<int>> s;
void dfs(int index, vector<int> result, vector<int> v, int m) {
    if (index == m) {
        s.insert(result);
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        result.push_back(v[i]);
        dfs(index+1, result, v, m);
        result.pop_back();
    }
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<int> temp;
    dfs(0, temp, v, m);
    
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        temp = *iter;
        for (int i = 0 ; i < temp.size(); i++) {
            cout << temp[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

