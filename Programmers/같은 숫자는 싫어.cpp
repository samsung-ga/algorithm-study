//
//  같은 숫자는 싫어.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/12.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    answer.push_back(arr.front());
    
    for (int i = 1; i < arr.size(); i++) {
        if (answer.back() != arr[i]) {
            answer.push_back(arr[i]);
        }
    }

    return answer;
}
