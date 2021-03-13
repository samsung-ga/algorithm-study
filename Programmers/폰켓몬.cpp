//
//  폰켓몬.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/12.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    vector<int> pocket;
    
    sort(nums.begin(), nums.end());
    pocket.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i-1] != nums[i]) {
            pocket.push_back(nums[i]);
        }
    }
    
    int numbersToChoose = nums.size() / 2;
    int totalNumbers = pocket.size();
    
    
    return numbersToChoose > totalNumbers ? totalNumbers : numbersToChoose;
}
