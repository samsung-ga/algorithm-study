//
//  10844 쉬운 계단 수.cpp
//  codingtest
//
//  Created by 이재용 on 2020/09/05.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
long long int dp[101][10];
int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < 10; i++) {
        if (i == 0) dp[1][0] = 0;
        else dp[1][i] = 1;
    }
    for (int i = 2; i < 101; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) {
                dp[i][j] = dp[i-1][j+1] % 1000000000;
            } else if (j >=1 && j <= 8) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
            } else {
                dp[i][j] = dp[i-1][j-1] % 1000000000;
            }
        }
    }
    long long int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += dp[n][i];
    }
    cout << sum % 1000000000 << "\n";
    return 0;
}

