//
//  11053 가장 긴 증가하는 수열 - 다른풀이.cpp
//  codingtest
//
//  Created by 이재용 on 2020/09/23.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dp[1001]; // d[i] = i번째 원소를 마지막으로 가장 긴 LIS 부분수열의 길이
int v[1001];
int main(void) {
    int n;
    cin >> n;
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        int here = 0;
        for (int j = 1; j < i; j++) {
            if(v[j] < v[i]) {
                here = max(here, dp[j]);
            }
        }
        dp[i] = here + 1;
        answer = answer > dp[i] ? answer : dp[i];
    }
    cout << answer << "\n";
    
    return 0;
}


