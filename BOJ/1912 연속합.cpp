//
//  1912 연속합.cpp
//  codingtest
//
//  Created by 이재용 on 2020/09/24.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int dp[100001];
int main(void) {
    int n;
    cin >> n;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    
    dp[1] = v[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i-1] + v[i], v[i]);
    }
    int answer = -10000;
    for (int i = 1; i <= n; i++) {
        answer = max(dp[i], answer);
    }
    
    cout << answer << "\n";
}


