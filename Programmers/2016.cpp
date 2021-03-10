//
//  2016.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/10.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <vector>
#include <string>
#include <iostream>
using namespace std;;

string solution(int a, int b) {
    string answer = "";
    
    int days = b;
    string januaryone = "FRI";
    for (int i = 1; i < a; i++) {
        switch (i) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 9:
            case 11:
                days += 31;
                break;
            case 2:
                days += 29;
                break;
            default:
                days += 30;
                break;
        }
    }
    switch (days % 7) {
        case 1:
            answer = "FRI";
            break;
        case 2:
            answer = "SAT";
            break;
        case 3:
            answer = "SUN";
            break;
        case 4:
            answer = "MON";
            break;
        case 5:
            answer = "TUE";
            break;
        case 6:
            answer = "WED";
            break;
        case 0:
            answer = "THU";
            break;
    }
    
    return answer;
}

int main(void) {
    
    cout << solution(12, 1);
    return 0;
}
