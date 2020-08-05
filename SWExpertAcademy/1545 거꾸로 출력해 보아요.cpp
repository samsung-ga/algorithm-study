//
//  1545 거꾸로 출력해 보아요.cpp
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
    
    for (int i = n; i >= 0; i--) {
        cout << i << " ";
    }
    return 0;
}

