//
//  비밀지도.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/13.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string decodeToString(int total, int n) {
    string str;
    while(total--) {
        str += to_string(n%2);
        n/=2;
    }
    reverse(str.begin(), str.end());
    return str;
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for (int i = 0; i < n; i++) {
        string temp1 = decodeToString(n, arr1[i]);
        string temp2 = decodeToString(n, arr2[i]);
        string str;
        
        for (int j = 0; j < n; j++) {
            if(temp1[j] == '1' || temp2[j] == '1') {
                str.push_back('#');
            } else {
                str.push_back(' ');
            }
        }
        answer.push_back(str);
    }
    
    return answer;
}
