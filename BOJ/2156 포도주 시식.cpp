//
//  2156 포도주 시식.cpp
//  codingtest
//
//  Created by 이재용 on 2020/09/18.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int dp[10001];
int v[10001];
int main(void) {
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i+1];
    }
    dp[1] = v[1];
    dp[2] = v[1] + v[2];
    dp[3] = max(v[1]+v[3], max(v[2]+v[3], v[1] + v[2]));
    for (int i = 4; i <= n; i++)  {
        dp[i] = max(dp[i-1], max(dp[i-2] + v[i], dp[i-3] + v[i-1] + v[i]));
    }
    cout << dp[n] << "\n";
    return 0;
}

