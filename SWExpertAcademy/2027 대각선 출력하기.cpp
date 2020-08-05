//
//  2027 대각선 출력하기.cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/05.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(void) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j == i) {
                cout << "#";
            } else {
                cout << "+";
            }
        }
        cout << "\n";
    }
    return 0;
}
/*
 #++++
 +#+++
 ++#++
 +++#+
 ++++#
 */

