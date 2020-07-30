//
//  9095 1,2,3 더하기.cpp
//  codingtest
//
//  Created by 이재용 on 2020/07/30.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int dp[11];
int main(void) {
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= 10; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    for (int i = 0 ; i < n; i++) {
        int temp;
        cin >> temp;
        cout << dp[temp] << "\n";
    }
    return 0;
}
