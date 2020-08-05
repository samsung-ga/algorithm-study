//
//  2019 더블더블.cpp
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
    
    for (int i = 0; i <= n; i++) {
        int res = 1;
        for (int j = 0; j < i; j++) {
            res *= 2;
        }
        cout << res << " ";
    }
    return 0;
}

