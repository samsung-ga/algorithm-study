//
//  13398 연속합 2.cpp
//  codingtest
//
//  Created by 이재용 on 2020/09/25.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int dp[100001][2];
int v[100001];
int main(void) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    dp[1][0] = v[1];
    dp[1][1] = v[1]; // 한개 이상 무조건 선택해야 하므로! 선택함
    
    for (int i = 2; i <= n; i++) {
        dp[i][0] = max(dp[i-1][0] + v[i], v[i]);
        dp[i][1] = max(dp[i-1][0], dp[i-1][1] + v[i]);
    }
    
    int answer = -100000000;
    for (int i = 1; i <= n; i++) {
        answer = max(answer, dp[i][0]);
        answer = max(answer, dp[i][1]);
    }
    cout << answer << "\n";
    return 0;
}
