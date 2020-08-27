//
//  1976 시각 덧셈.cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/27.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void) {
    int t;
    cin >> t;
    for (int test_case = 0; test_case < t; test_case++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        bool hour = false, minute = false;
        if (b + d >= 60) minute = true;
        int rhour = 0, rminute = 0;
        if (minute) {
            rminute = b + d - 60;
            if (a + c + 1 > 12) hour = true;
            if (hour) {
                rhour = a + c + 1 - 12;
            } else {
                rhour = a + c + 1;
            }
            cout << "#" << test_case + 1 << " " << rhour << " " << rminute << "\n";
        } else {
            rminute = b + d;
            if (a + c > 12) hour = true;
            if (hour) {
                rhour = a + c - 12;
            } else {
                rhour = a + c;
            }
            cout << "#" << test_case + 1 << " " << rhour << " " << rminute << "\n";
        }
        
    }
    return 0;
}

