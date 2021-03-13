//
//  [1차] 다트 게임.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/13.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int count = 0, square = 0, score[3] = {0,0,0};
    for (int i = 0; i < dartResult.size(); i++) {
        if (dartResult[i] == 'S') {
            square = 1;
        } else if (dartResult[i] == 'D') {
            square = 2;
        } else if (dartResult[i] == 'T') {
            square = 3;
        }
        if (square) {
            int numstr = stoi(dartResult.substr(0,i));
            int options = 1;
            if (i+1 < dartResult.size()) {
                if (dartResult[i+1] == '*') {
                    options = 2;
                } else if (dartResult[i+1] == '#') {
                    options = -1;
                }
            }
            
            if (options != 1) {
                dartResult = dartResult.substr(i+2);
            } else {
                dartResult = dartResult.substr(i+1);
            }
            
            if (options == 2 && count) {
                score[count-1] *= 2;
            }
           
            int total = 1;
            for (int i = 0; i < square; i++) {
                total *= numstr;
            }
            score[count] = total * options;
            i = 0; square = 0; count++;
        }
    }
    
    return score[0] + score[1] + score[2];
}
