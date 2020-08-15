//
//  15657 N과 M (8).cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/14.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void dfs(int index, vector<int> p, vector<int> v, int m) {
    if (index == m) {
        for (int i = 0; i < p.size(); i++) {
            cout << v[p[i]] << " ";
        }
        cout << "\n";
        return;
    }
    int smallest = p.empty() ? 0 : p.back();
    for (int i = smallest; i < v.size(); i++) {
        p.push_back(i);
        dfs(index+1, p, v, m);
        p.pop_back();
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

