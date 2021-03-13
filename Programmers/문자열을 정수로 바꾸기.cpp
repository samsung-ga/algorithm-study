//
//  문자열을 정수로 바꾸기.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/12.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    if (s.front() == '-') {
        s.erase(0, 1);
        answer = 0 - stoi(s);
    } else {
        answer = stoi(s);
    }
    return answer;
}
