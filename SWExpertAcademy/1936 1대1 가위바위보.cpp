//
//  1936 1대1 가위바위보.cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/05.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(void) {
    int a, b;
    cin >> a >> b;
    if (a == 1) {
        if (b == 2) {
            cout << "B";
        } else {
            cout << "A";
        }
    } else if (a == 2) {
        if (b == 1) {
            cout << "A";
        } else {
            cout << "B";
        }
    } else {
        if (b == 1) {
            cout << "B";
        } else {
            cout << "A";
        }
    }
    return 0;
}
// 가위 1
// 바위 2
// 보 3

