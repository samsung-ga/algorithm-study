//
//  14659 한조서열정리하고옴ㅋㅋ.cpp
//  codingtest
//
//  Created by 이재용 on 2021/01/23.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int small = min(a, b);
    int big = max(a,b);
    
    for(int i = small; i <= big; i++) {
        answer += i;
    }
    return answer;
}
