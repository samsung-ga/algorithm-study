//
//  11053 가장 긴 증가하는 부분 수열.cpp
//  codingtest
//
//  Created by 이재용 on 2020/09/18.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
unsigned long int dp[1001];
int v[1001];
vector<int> res;
int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i+1];
    }
    
    dp[1] = 1;
    res.push_back(v[1]);
    
    for (int i = 2 ; i <= n; i++) {
        if (v[i] > res[res.size()-1]) {
            res.push_back(v[i]);
            dp[i] = res.size();
        } else {
            for (int j = 0; j < i; j++) {
                if (res[j] >= v[i]) {
                    res[j] = v[i];
                    break;
                }
            }
            dp[i] = dp[i-1];
        }
    }
    cout << dp[n] << "\n";
    return 0;
}

