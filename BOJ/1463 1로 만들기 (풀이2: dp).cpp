//
//  1463 1로 만들기 (풀이2: dp).cpp
//  codingtest
//
//  Created by 이재용 on 2020/09/01.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
using namespace std;

long long dp[1000001];

int main(void) {
    int X;
    cin >> X;
    
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    
    for(int i = 5; i <= 1000000; i++) {
        // dp[i/3], dp[i/2], dp[i-1] 세 개중 가장 낮은 값 고름
        if (i % 3 == 0 && i % 2 == 0) {
            if (dp[i/3] <= dp[i/2]) {
                if(dp[i/3] <= dp[i-1]) {
                    dp[i] = dp[i/3] + 1;
                } else {
                    dp[i] = dp[i-1] + 1;
                }
            } else {
                if(dp[i/2] <= dp[i-1]) {
                    dp[i] = dp[i/2] + 1;
                } else {
                    dp[i] = dp[i-1] + 1;
                }
            }
        } else if (i % 3 == 0) {
            if (dp[i/3] <= dp[i-1]) {
                dp[i] = dp[i/3] + 1;
            } else {
                dp[i] = dp[i-1] + 1;
            }
        } else if (i % 2 == 0) {
            if (dp[i/2] <= dp[i-1]) {
                dp[i] = dp[i/2] + 1;
            } else {
                dp[i] = dp[i-1] + 1;
            }
        } else {
            dp[i] = dp[i-1] + 1;
        }
    }
    
    cout << dp[X] << endl;
    
    return 0;
}


