//
//  14501 퇴사.cpp
//  codingtest
//
//  Created by 이재용 on 2020/09/02.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int maxProfit = 0;
void dfs(int index, int profit, vector<pair<int, int>> v, int n) {
    if (index > n) {
        return;
    }
    maxProfit = maxProfit > profit ? maxProfit : profit;
    for (int i = index; i < v.size(); i++) {
        dfs(i + v[i].first, profit+v[i].second, v, n);
    }
    
}
int main(void) {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int days, money;
        cin >> days >> money;
        v[i] = make_pair(days, money);
    }
    for (int i = 0; i < v.size(); i++) {
        dfs(i+v[i].first, v[i].second, v, n);
    }
    cout << maxProfit << "\n";
    return 0;
}

