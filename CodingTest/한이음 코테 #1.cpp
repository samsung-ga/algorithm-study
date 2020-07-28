//
//  한이음 코테 #1.cpp
//  swexpert
//
//  Created by 이재용 on 2020/07/28.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <vector>
#include <algorithm>
using namespace std;

//핵심 소스코드의 설명을 주석으로 작성하면 평가에 큰 도움이 됩니다.
class Solution{
public:
    double solution(vector<int> scores){
        vector<int> v = scores;
        
        sort(v.begin(), v.end());
    
        double res = 0;
        int first = 0; // index
        int end = (int)v.size() - 1;
        double max = 0;
        
        while(1) {
            
            // avg 구하기
            double sum = 0;
            for (int i = first; i <= end; i++) {
                sum += v[i];
            }
            
            res = sum / (end - first + 1);
            
            if (res > max) max = res;
            first++; end--;
            if (first > end) break;
        }
        
        return max;
    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v[i] = temp;
    }
    
    Solution solution;
    cout << solution.solution(v);
    
}

