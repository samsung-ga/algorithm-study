//
//  9465 스티커.cpp
//  codingtest
//
//  Created by 이재용 on 2020/09/16.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dp[100001][3];
int v[2][100001];
int main(void) {
    int testCase;
    cin >> testCase;
    for (int test_case = 0; test_case < testCase; test_case++) {
        int n;
        cin >> n;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }
        dp[1][0] = v[0][0];
        dp[1][1] = v[1][0];
        dp[1][2] = 0;
        for (int i = 2; i <= n; i++) {
            dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + v[0][i-1];
            dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + v[1][i-1];
            dp[i][2] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
        }
        
        int res = max(max(dp[n][0], dp[n][1]), dp[n][2]);
        cout << res << "\n";
    }
    return 0;
}

