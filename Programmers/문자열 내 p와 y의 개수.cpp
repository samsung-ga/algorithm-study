//
//  문자열 내 p와 y의 개수.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/07.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    int pNumber = 0;
    int yNumber = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'p' || s[i] == 'P') {
            pNumber++;
        } else if (s[i] == 'y' || s[i] == 'Y') {
            yNumber++;
        }
    }
    
    if (pNumber != yNumber) {
        answer = false;
    }
    
    return answer;
}
