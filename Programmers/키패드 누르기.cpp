//
//  키패드 누르기.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/12.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int xl = 3, yl = 0;
    int xr = 3, yr = 2;
    int xc = -1, yc = -1;
    for (int i = 0; i < numbers.size(); i++) {
        switch (numbers[i]) {
            case 1:
                xc = 0; yc = 0;
                break;
            case 2:
                xc = 0; yc = 1;
                break;
            case 3:
                xc = 0; yc = 2;
                break;
            case 4:
                xc = 1; yc = 0;
                break;
            case 5:
                xc = 1; yc = 1;
                break;
            case 6:
                xc = 1; yc = 2;
                break;
            case 7:
                xc = 2; yc = 0;
                break;
            case 8:
                xc = 2; yc = 1;
                break;
            case 9:
                xc = 2; yc = 2;
                break;
            case 0:
                xc = 3; yc = 1;
                break;
        }
        
        if (yc == 0) {
            answer += 'L';
            xl = xc; yl = yc;
        } else if (yc == 2) {
            answer += 'R';
            xr = xc; yr = yc;
        } else {
            int ltemp = abs(xc - xl) + abs(yc - yl);
            int rtemp = abs(xc - xr) + abs(yc - yr);
            if (ltemp < rtemp) {
                answer += 'L';
                xl = xc; yl = yc;
            } else if (ltemp > rtemp) {
                answer += 'R';
                xr = xc; yr = yc;
            } else {
                if (hand == "left") {
                    answer += 'L';
                    xl = xc; yl = yc;
                } else {
                    answer += 'R';
                    xr = xc; yr = yc;
                }
            }
        }
    }
    return answer;
}
