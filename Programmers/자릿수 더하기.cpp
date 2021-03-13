//
//  자릿수 더하기.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/12.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;

    while (n != 0) {
        answer += n % 10;
        n /= 10;
    }
    return answer;
}
