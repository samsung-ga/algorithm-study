//
//  가운데 글자 가져오기.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/12.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int length = s.length();
    if (length % 2 == 0) {
        int middleIndex = length / 2 - 1;
        answer = s[middleIndex];
        answer.push_back(s[middleIndex+1]);
    } else {
        int middleIndex = length / 2;
        answer = s[middleIndex];
    }
    
    return answer;
}
