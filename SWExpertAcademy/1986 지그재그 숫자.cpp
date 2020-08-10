//
//  1986 지그재그 숫자.cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/07.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    for (int test_case = 0; test_case < test; test_case++) {
        int n;
        cin >> n;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (i%2==0) {
                sum -= i;
            } else {
                sum += i;
            }
        }
        
        cout << "#" << test_case+1 << " " << sum << "\n";

    }
        return 0;
}

