//
//  시저 암호.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/12.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            answer += s[i];
        } else {
            for (int j = 0; j < n; j++) {
                if (s[i] == 'z') {
                    s[i] = 'a';
                } else if (s[i] == 'Z') {
                    s[i] = 'A';
                } else {
                    s[i]++;
                }
            }
            answer += s[i];
        }
    }
    return answer;
}
