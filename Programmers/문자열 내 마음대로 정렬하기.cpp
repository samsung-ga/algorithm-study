//
//  문자열 내 마음대로 정렬하기.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/11.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string,char> a, pair<string,char> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    vector<pair<string, char>> temp;
    for (int i = 0; i < strings.size(); i++) {
        temp.push_back(make_pair(strings[i], strings[i][n]));
    }
    
    sort(temp.begin(), temp.end(), compare);
    
    for (int i = 0; i < temp.size(); i++) {
        answer.push_back(temp[i].first);
    }
    return answer;
}
