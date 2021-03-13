//
//  이상한 문자 만들기.cpp
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
    
    int flag = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            flag = 0;
            answer += s[i];
        } else {
            if (flag % 2 == 0) {
               answer += toupper(s[i]);
            } else {
                answer += tolower(s[i]);
            }
            flag++;
        }
    }
    
    return answer;
}
