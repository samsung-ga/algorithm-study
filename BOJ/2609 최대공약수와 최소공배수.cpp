//
//  2609 최대공약수와 최소공배수.cpp
//  codingtest
//
//  Created by 이재용 on 2020/07/31.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int a,b;
    cin >> a >> b;
    
    int max = 1;
    int small = a < b ? a : b;
    
    for (int i = 1 ; i <= small; i++) {
        if (a % i == 0 && b % i == 0) {
            if (max < i) max = i;
        }
    }
    
    int min = max * (a/max) * (b/max);
    
    cout << max << "\n" << min << "\n";
    
    return 0;
}
