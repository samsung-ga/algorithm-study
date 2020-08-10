//
//  1984 중간 평균값 구하기.cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/07.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    for (int test_case = 0; test_case < test; test_case++) {
        vector<int> v(10);
        for (int i = 0; i < 10; i++) {
            cin >> v[i];
        }
    
        sort(v.begin(), v.end());
        double sum = 0;
        int res = 0;
        for (int i = 1; i < v.size()-1; i++) {
            sum += v[i];
        }
        res = round(sum / (v.size() - 2)) ;
        cout << "#" << test_case+1 << " " << res << "\n";

    }
        return 0;
}

