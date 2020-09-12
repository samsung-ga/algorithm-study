//
//  카카오 2020 예선 테스트 1번.cpp
//  codingtest
//
//  Created by 이재용 on 2020/09/12.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    answer = new_id;
    
    // 1단계
    for (int i = 0; i < answer.size(); i++) {
        answer[i] = tolower(answer[i]);
    }
      
    // 2단계
    for (int i = 0; i < answer.size(); i++) {
        if ((answer[i] >= 'a' && answer[i] <= 'z') || (answer[i] >= '0' && answer[i] <= '9')|| answer[i] == '-' || answer[i] == '_' || answer[i] == '.') continue;
        answer.replace(i,1,"");
        i = -1;
    }
    
    // 3단계
    while(true) {
        size_t index= answer.find("..");
        if (index == std::string::npos) break;
        answer.replace(index, 2, ".");
        index += 2;
    }
    
    // 4단계
    if (answer.front() == '.') {
        answer.replace(0, 1, "");
    }
    if (answer[answer.size() - 1] == '.') {
        answer.replace(answer.size() - 1, 1, "");
    }
    
    // 5단계
    if (answer.empty()) {
        answer = "a";
    }
    
    // 6단계
    if (answer.size() > 15) {
        answer.replace(15, answer.size() - 15, "");
        if (answer[answer.size()-1] == '.') {
            answer.replace(answer.size()-1, 1, "");
        }
    }
    
    // 7단계
    for (; answer.size() < 3; ) {
        
        answer += answer[answer.size() - 1];
    }
    return answer;
}


