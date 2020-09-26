//
//  11055 가장 큰 증가 부분 수열.cpp
//  codingtest
//
//  Created by 이재용 on 2020/09/26.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
using namespace std;
int a[1001];
int dp[1001];
int main(void) {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    dp[1] = a[1];
    int answer = dp[1];
    for (int i = 2; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i]) {
                sum = max(dp[j], sum);
            }
        }
        dp[i] = sum + a[i];
        answer = answer > dp[i] ? answer : dp[i];
    }
    cout << answer << "\n";
    return 0;
}
