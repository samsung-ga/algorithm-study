//
//  11722 가장 긴 감소하는 부분 수열.cpp
//  codingtest
//
//  Created by 이재용 on 2020/10/02.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[1001];
int dp[1001];
int main(void) {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    vector<int> v;
    v.push_back(arr[1]);
    for (int i = 2; i <= n; i++) {
        if (arr[i] < v[v.size()-1]) {
            v.push_back(arr[i]);
        } else {
            for (int j = 0; j < i; j++) {
                if (v[j] <= arr[i]) {
                    v[j] = arr[i];
                    break;
                }
            }
        }
    }
    cout << v.size() << "\n";
    return 0;
}

