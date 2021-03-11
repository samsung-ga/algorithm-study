//
//  나누어 떨어지는 숫자 배열.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/11.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % divisor == 0) {
            answer.push_back(arr[i]);
        }
    }
    
    if (answer.size() == 0) {
        answer.push_back(-1);
    } else {
        sort(answer.begin(), answer.end());
    }
    
    return answer;
}
