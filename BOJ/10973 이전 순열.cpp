//
//  10973 이전 순열.cpp
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
    for (int i = 0 ; i < n; i++) {
        cin >> v[i];
    }
    if (prev_permutation(v.begin(), v.end())) {
        for (int i = 0 ; i < n; i++) {
            cout << v[i] << " ";
        }
    } else {
        cout << "-1";
    }
    return 0;
}

