//
//  10971 외판원 순회 2.cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/02.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

int arr[10][10];
int main(void) {
    
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    
    vector<int> cities(n);
    for (int i = 0; i < n; i++) {
        cities[i] = i;
    }
    sort(cities.begin(), cities.end());
    
    long long min = 1000000000;
    do {
        long long sum = 0;
        int flag = 0;
        for (int i = 0 ; i < cities.size(); i++) {
            if (i == cities.size() - 1) {
                if (arr[cities[i]][cities[0]] == 0) { // 길이 없다면 다른 경우 실행
                    flag = 1;
                    break;
                }
                sum += arr[cities[i]][cities[0]];
            } else {
                if (arr[cities[i]][cities[i+1]] == 0) {
                    flag = 1;
                    break;
                }
                sum += arr[cities[i]][cities[i+1]];
            }
        }
        if (flag == 0) {
            min = sum < min ? sum : min;
        }
        
    } while(next_permutation(cities.begin(), cities.end()));
    
    cout << min << "\n";
    return 0;
}
