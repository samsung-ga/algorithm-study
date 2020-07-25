//
//  2071 평균값 구하기.cpp
//  swexpert
//
//  Created by 이재용 on 2020/07/25.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

// 반올림을 사용
// 라이브러리 math.h 사용
// round/ floor/ ceil
// 반올림할 때 (int)(sum/10 + 0.5) 이렇게도 가능

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
        double sum = 0, temp;
        for (int i = 0; i < 10; i++) {
            cin >> temp;
            sum += temp;
        }
        
        cout << "#" << test_case << " " << round(sum / 10.0) << "\n";
    }
    return 0;
}


