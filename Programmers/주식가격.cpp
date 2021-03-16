//
//  주식가격.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/16.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for (int i = 0; i < prices.size(); i++) {
        int temp = 0;
        for (int j = i+1; j < prices.size(); j++) {
            if (prices[i] <= prices[j]) {
                temp++;
            } else {
                temp++;
                break;
            }
        }
        answer.push_back(temp);
    }
    return answer;
}
