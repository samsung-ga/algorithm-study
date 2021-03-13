//
//  자연수 뒤집어 배열로 만들기.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/12.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    
    string s = to_string(n);
    for (int i = s.size()-1; i >= 0; i--) {
        answer.push_back(s[i] - '0');
    }
    
    return answer;
}
