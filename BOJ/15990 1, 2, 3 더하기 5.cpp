//
//  15990 1, 2, 3 더하기 5.cpp
//  codingtest
//
//  Created by 이재용 on 2020/09/04.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long int dp[100001][4];
long long int res[100001];
int main(void) {
    int t;
    cin >> t;
    
    dp[1][1] = 1;
    res[1] = 1;
    dp[2][2] = 1;
    res[2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    res[3] = 3;
    for (int i = 4; i < 100001; i++) {
        dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % 1000000009;
        dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % 1000000009;
        dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % 1000000009;
        res[i] = (dp[i][1] + dp[i][2] + dp[i][3]) % 1000000009;
    }
    for (int test_case = 0; test_case < t; test_case++) {
        int n;
        cin >> n;
        cout << res[n] << "\n";
    }
    return 0;
}

