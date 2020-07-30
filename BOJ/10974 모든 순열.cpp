//
//  10974 모든 순열.cpp
//  codingtest
//
//  Created by 이재용 on 2020/07/31.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 1; i <= n; i++) {
        v[i-1] = i;
    }
    
    sort(v.begin(), v.end());
    do {
        for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
    } while(next_permutation(v.begin(), v.end()));
    return 0;
}

