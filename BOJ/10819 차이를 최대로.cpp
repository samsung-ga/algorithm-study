//
//  10819 차이를 최대로.cpp
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

int main(void) {
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    sort(v.begin(),v.end());
    
    int max = 0;
    
    do {
        int sum = 0;
        for (int i = 0; i < n - 1; i++) {
            sum += abs(v[i] - v[i+1]);
        }
        max = sum > max ? sum : max;
    } while(next_permutation(v.begin(), v.end()));
    
    cout << max << "\n";
    return 0;
}
