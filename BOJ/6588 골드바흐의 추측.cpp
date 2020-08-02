//
//  6588 골드바흐의 추측.cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/02.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 에라토스테네스의 체
    bool map[1000001];
    
    for (int i = 0; i < 1000001; i++) {
        map[i] = true;
    }
    map[1] = false;
    for (int i = 2; i * i < 1000001; i++) {
        if (map[i])
            for (int j = i + i; j < 1000001; j+=i) {
                map[j] = false;
            }
    }
    
    while(true) {
        int n;
        cin >> n;
        if (n == 0) break;
        
        
        int check = 0;
        for (int i = 3; i * 2 <= n; i+=2) {
            if (map[i] && map[n-i]) {
                cout << n << " = " << i << " + " << n-i << "\n";
                check = 1;
                break;
            }
        }
        if (check == 0) {
            cout << "Goldbach's conjecture is wrong." << "\n";
        }
        
    }
    return 0;
    
}

