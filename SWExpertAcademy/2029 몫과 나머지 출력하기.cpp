//
//  2029 몫과 나머지 출력하기.cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/05.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(void) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        cout << "#" << i+1 << " " << a/b << " " << a%b << "\n";
    }
    return 0;
}

