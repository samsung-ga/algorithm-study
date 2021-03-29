//
//  전화번호 목록.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/29.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(),phone_book.end());
    
    for (int i = 0; i < phone_book.size()-1; i++) {
        if (phone_book[i].size() < phone_book[i+1].size() && phone_book[i] == phone_book[i+1].substr(0, phone_book[i].size())) {
            return false;
        }
    }
    return answer;
}
