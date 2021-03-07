//
//  두 개 뽑아서 더하기.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/07.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> s;
    set<int>::iterator pos;
    for (int i = 0; i < numbers.size() - 1; i++) {
        for (int j = i+1; j < numbers.size(); j++) {
            s.insert(numbers[i]+numbers[j]);
        }
    }
    for(pos = s.begin(); pos != s.end(); pos++) {
        answer.push_back(*pos);
    }
    
    return answer;
}
