//
//  6603 로또.cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/03.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

int main(void) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
    
        vector<int> v(n);
        vector<int> flag;
        int k = 6;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        for (int i = 0; i < k; i++) {
            flag.push_back(1);
        }
        for (int i = 0; i < n-k; i++) {
            flag.push_back(0);
        }
        
        do {
            for (int i = 0; i < flag.size(); i++) {
                if (flag[i] == 1) {
                    cout << v[i] << " ";
                }
            }
            cout << "\n";
        } while(prev_permutation(flag.begin(), flag.end()));
        
        cout << "\n";
        
    }
    return 0;
}

// 시간초과가 나는 이유: 조합을 묻는 문제이므로 순열로 구하면 시간초과가 나올 확률 높음 C와 P는 다르니까!
// 아래는 순열을 구한 후, 6개를 모두 더한 값의 합을 구별하여 출력하는 방식
// 위는 따로 1,0으로 이루어진 배열을 만들어, 이를 순열로 돌리는 방식

/*
 do {
     int ss = 0;
     for (int i = 0; i < 6; i++) {
         ss += v[i];
     }
     bool flag = false;
     
     for (int i = 0; i < sum.size(); i++) {
         if (sum[i] == ss) {
             flag = true;
             break;
         }
     }
     
     if (flag) {
         continue;
     } else {
         sum.push_back(ss);
         for (int i = 0; i < 6; i++) {
             cout << v[i] << " ";
         }
         cout << "\n";
     }
     
     
 } while (next_permutation(v.begin(), v.end()));
 */

