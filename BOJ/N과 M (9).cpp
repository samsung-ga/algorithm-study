//
//  N과 M (9).cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/15.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int visit[10000];

// 출력하는 값을 저장하는 맵을 만들고 거기 저장되어있으면 출력하지 않기
// 같은 depth에서
void dfs(int index, vector<int> p, vector<int> v, int m) {
    if (index == m) {
        for (int i = 0; i < p.size(); i++) {
            cout << p[i] << " ";
        }
        cout << "\n";
        return;
    }
    int used[10000] = { 0, };
    
    for (int i = 0; i < v.size(); i++) {
        if (!visit[i] && !used[v[i]]) {
            p.push_back(v[i]);
            visit[i] = 1;
            used[v[i]] = 1;
            dfs(index+1, p, v, m);
            visit[i] = 0;
            p.pop_back();
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

