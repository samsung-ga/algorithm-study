//
//  11054 가장 긴 바이토닉 부분 수열.cpp
//  codingtest
//
//  Created by 이재용 on 2020/10/03.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int arr[1001];
long int dp[1001][2];
int main(void) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    // 증가하는 가장 긴 부분수열
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            if (arr[j] < arr[i] && dp[i][0] < dp[j][0] + 1) {
                dp[i][0] = dp[j][0] + 1;
            }
        }
    }
    for (int i = n; i > 0; i--) {
        dp[i][1] = 1;
        for (int j = n; j >= i; j--) {
            if (arr[j] < arr[i] && dp[i][1] < dp[j][1] + 1) {
                dp[i][1] = dp[j][1] + 1;
            }
        }
    }
    int result = 0;
    for (int i = 1; i <= n; i++) {
        result = result > (dp[i][0] + dp[i][1] - 1) ? result : dp[i][0] + dp[i][1] - 1;
    }
    cout << result << "\n";
    return 0;
}

