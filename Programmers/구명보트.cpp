//
//  구명보트.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/22.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    
    int start = 0, end = people.size()-1;
    while(start <= end) {
        answer++;
        if(people[start] + people[end] <= limit) {
            start += 1; end -= 1;
        } else {
            end -= 1;
        }
        
    }
    return answer;
}
