//
//  1182 부분수열의 합.cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/07.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,s;
    cin >> n >> s;
    vector<int> v(n);
    
    for (int i = 0 ; i < v.size(); i++) {
        cin >> v[i];
    }
    int res = 0;
    for (int i = 1; i <= v.size(); i++) {
        vector<int> temp;
        for (int j = 0; j < i; j++) {
            temp.push_back(1);
        }
        for (int j = 0; j < n - i; j++) {
            temp.push_back(0);
        }
        do {
            long long sum = 0;
            for (int j = 0; j < v.size(); j++) {
                if (temp[j]) {
                    sum += v[j];
                }
            }
            if (sum == s) {
                res++;
            }
        } while (prev_permutation(temp.begin(), temp.end()));
    }
    cout << res << "\n";
    return 0;
}

