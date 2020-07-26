//
//  2058 자릿수 더하기.cpp
//  swexpert
//
//  Created by 이재용 on 2020/07/26.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    int sum = 0;
    while(n) {
        int temp = n % 10;
        sum += temp;
        n = n/10;
    }
    cout << sum << "\n";
    return 0;
}
