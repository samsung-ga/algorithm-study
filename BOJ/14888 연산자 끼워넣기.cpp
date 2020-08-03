//
//  14888 연산자 끼워넣기.cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/04.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(void) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> v(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int oper[4] = { 0, 0, 0, 0};
    
    for (int i = 0; i < 4; i++) {
        cin >> oper[i];
    }
    
    // 초기화
    vector<int> temp;
    for (int i = 0; i < oper[0]; i++) { // +
        temp.push_back(0);
    }
    for (int i = 0; i < oper[1]; i++) { // -
        temp.push_back(1);
    }
    for (int i = 0; i < oper[2]; i++) { // x
        temp.push_back(2);
    }
    for (int i = 0; i < oper[3]; i++) { // 나누기
        temp.push_back(3);
    }
    
    
    long long int max = -10000000000;
    long long int min = 10000000000;
    do {
        long long int sum = v[0];
        for (int i = 0; i < temp.size(); i++) {
            
            switch (temp[i]) {
                case 0:
                    sum += v[i+1];
                    break;
                case 1:
                    sum -= v[i+1];
                    break;
                case 2:
                    sum *= v[i+1];
                    break;
                case 3:
                    sum /= v[i+1];
                    break;
                default:
                    break;
            }
        }
        max = sum > max ? sum : max;
        min = sum < min ? sum : min;
    } while(next_permutation(temp.begin(), temp.end()));
     
    cout << max << "\n" << min << "\n";
    
    return 0;
}
