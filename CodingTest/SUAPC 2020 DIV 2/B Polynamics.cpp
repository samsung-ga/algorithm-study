//
//  Polynamics.cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/15.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

int main(void) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long int n,m;
    cin >> n >> m;
    
    vector<pair<int, int>> v;
    
    for (int i = 0; i < n+1; i++) {
        long long int a,b;
        cin >> a>> b;
        v.push_back(make_pair(a, b));
    }
    
    sort(v.begin(), v.end(), comp);
    
    long long int i = 0;
    long long int res = v[i++].first;
    
    while (true) {
        
        if (i == n+1) {
            break;
        }
        res *= m;
        res = (res + v[i++].first) % 1000000007;
    }
    
    cout << res << "\n";
    return 0;
}

