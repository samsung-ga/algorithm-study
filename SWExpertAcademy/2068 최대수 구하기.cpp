//
//  2068 최대수 구하기.cpp
//  swexpert
//
//  Created by 이재용 on 2020/07/26.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>

using namespace std;

int main(void)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int max = -999;
        for (int i = 0; i < 10; i++) {
            int temp;
            cin >> temp;
            if (max < temp) {
                max = temp;
            }
        }
        
        cout << "#" << test_case << " " << max << "\n";

    }
    return 0;
}
