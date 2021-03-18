//
//  소수 찾기.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/18.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

bool isSosu(int n) {
    if (n == 0 || n == 1) return false;
    for (int i  = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int solution(string numbers) {
    int answer = 0;
    vector<int> ans;
    sort(numbers.begin(), numbers.end());
    
    do {
        for (int i = 1; i <= numbers.size(); i++) {
            
            for (int j = 0; j < numbers.size()-i+1; j++) {
                string temp = "";
                for (int k = j; k < i+j; k++) {
                    temp += numbers[k];
                }
                int number = stoi(temp);
                if (isSosu(number)) {
                    if (find(ans.begin(), ans.end(), number) == ans.end()) {
                        ans.push_back(number);
                    }
                }
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    answer = ans.size();
    return answer;
}
