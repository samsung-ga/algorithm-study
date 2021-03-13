//
//  3진법 뒤집기.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/12.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> str;
    while (n >= 3) {
        int remainder = n % 3;
        str.push_back(remainder);
        n /= 3;
    }
    str.push_back(n);
    
    int j = 1;
    for (int i = str.size()-1; i >= 0; i--) {
        answer += j * str[i];
        j*= 3;
    }
    
    return answer;
}
