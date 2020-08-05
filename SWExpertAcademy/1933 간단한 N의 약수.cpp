//
//  1933 간단한 N의 약수.cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/05.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(void) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
        }
    }
    return 0;
}

