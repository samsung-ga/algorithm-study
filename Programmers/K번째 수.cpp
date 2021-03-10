//
//  K번째 수.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/10.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int i = 0; i < commands.size(); i++) {
        vector<int> temp;
        int start = commands[i][0];
        int end = commands[i][1];
        int point = commands[i][2];
        for (int i = start-1; i < end; i++) {
            temp.push_back(array[i]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[point-1]);
    }
    return answer;
}
