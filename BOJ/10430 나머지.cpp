//
//  10430 나머지.cpp
//  codingtest
//
//  Created by 이재용 on 2020/07/31.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int a, b, c;
    cin >> a >> b >> c;
    
    int ans1 = (a + b) % c;
    int ans2 = (a * b) % c;
    
    cout << ans1 << "\n" << ans1 << "\n" << ans2 << "\n" << ans2;
    return 0;
}
