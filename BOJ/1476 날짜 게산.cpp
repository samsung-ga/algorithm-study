//
//  1476 날짜 게산.cpp
//  swexpert
//
//  Created by 이재용 on 2020/07/29.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    
    int e,s,m;
    cin >> e >> s >> m;
    
    // res % 15 == e 틀린 풀이
    int res = 0;
    for (int i = 1; i <= 7980; i++) {
        res = i;
        if ((res-e) % 15 == 0) {
            if ((res-s) % 28 == 0) {
                if ((res-m) % 19 == 0) {
                    break;
                }
            }
        }
    }
    
    cout << res << "\n";
    
    return 0;
}

