//
//  11727 2xn 타일링 2.cpp
//  codingtest
//
//  Created by 이재용 on 2020/09/01.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
long long dp[1001];
int main(void) {
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i <= 1000; i++) {
        dp[i] = (dp[i-1] + 2*dp[i-2]) % 10007;
    }
    cout << dp[n] << "\n";
    return 0;
}

