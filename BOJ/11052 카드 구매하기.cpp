//
//  11052 카드 구매하기.cpp
//  codingtest
//
//  Created by 이재용 on 2020/09/09.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int dp[1001];
int main(void) {
    int n;
    cin >> n;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    dp[1] = v[1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == i) {
                dp[i] = dp[i] > v[j] ? dp[i] : v[j];
            } else {
                dp[i] = dp[i] > dp[i-j] + v[j] ? dp[i] : dp[i-j] + v[j];
            }
        }
    }
    
    cout << dp[n] << "\n";
    return 0;
}

