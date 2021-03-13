//
//  신규 아이디 추천.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/12.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    for (int i = 0; i < new_id.size(); i++) {
        answer += tolower(new_id[i]);
    }
    string temp = answer;
    answer = "";
    for (int i = 0; i < temp.size(); i++) {
        if ((temp[i] >= 'a' && temp[i] <= 'z') || (temp[i] >= '0' && temp[i] <= '9') || temp[i] == '-' || temp[i] == '_' || temp[i] == '.') {
            answer += temp[i];
        }
    }
    
    temp = answer;
    answer = "";
    answer += temp[0];
    for (int i = 1; i < temp.size(); i++) {
        if (temp[i-1] == '.' && temp[i] == temp[i-1]) {
            
        } else {
            answer += temp[i];
        }
    }
    
    if (answer.front() == '.') {
        answer.erase(0, 1);
    }
    if (answer.back() == '.') {
        answer.erase(answer.size()-1, answer.size());
    }
    
    if (answer.empty()) {
        answer += 'a';
    }
    
    if (answer.length() > 15) {
        answer = answer.substr(0, 15);
    }
    if (answer.back() == '.') {
        answer.erase(answer.size()-1, answer.size());
    }
    
    if (answer.length() < 3) {
        for (; answer.length() <= 2;) {
            answer += answer.back();
        }
    }
    
    
    return answer;
}
