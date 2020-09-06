//
//  11057 오르막 수.cpp
//  codingtest
//
//  Created by 이재용 on 2020/09/06.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001][10];
int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) dp[i][j] = dp[i-1][j] % 10007;
            else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 10007;
        }
    }
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += dp[n][i];
    }
    cout << sum % 10007 << "\n";
    return 0;
}


