//
//  15988 1,2,3 더하기 3.cpp
//  codingtest
//
//  Created by 이재용 on 2020/09/03.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
long long int dp[1000001];
int main(void) {
    int test;
    cin >> test;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i < 1000001; i++) {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % 1000000009;
    }
    for (int test_case = 0; test_case < test; test_case++) {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}

