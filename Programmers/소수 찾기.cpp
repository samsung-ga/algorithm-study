//
//  소수 찾기.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/07.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    // 에라토테네스의 체
    vector<int> allNum;
    for (int i = 1 ; i <= n; i++) {
        allNum.push_back(i);
    }
    
    for (int i = 2; i <= n; i++) {
        if (allNum[i] != 0) {
            for (int j = i*2; j <= n; j+=i) {
                allNum[j] = 0;
            }
            answer++;
        }
    }
    
    
    return answer;
}

