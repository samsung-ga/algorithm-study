//
//  2070 큰 놈, 작은 놈, 같은 놈.cpp
//  swexpert
//
//  Created by 이재용 on 2020/07/25.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int a, b;
        string res;
        cin >> a >> b;
        
        if (a < b) {
            res = "<";
        } else if (a > b) {
            res = ">";
        } else {
            res = "=";
        }
        
        cout << "#" << test_case << " " << res << "\n";
    }
    return 0;
}
