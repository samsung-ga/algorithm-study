//
//  수박수박수박수박수박수.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/12.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            answer += "수";
        } else {
            answer += "박";
        }
    }
    return answer;
}
