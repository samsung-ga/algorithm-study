//
//  모의고사.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/07.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int a = 0, b = 0, c = 0;
    vector<int> aP;
    vector<int> bP;
    vector<int> cP;
    aP.push_back(1);
    aP.push_back(2);
    aP.push_back(3);
    aP.push_back(4);
    aP.push_back(5);
    
    bP.push_back(2);
    bP.push_back(1);
    bP.push_back(2);
    bP.push_back(3);
    bP.push_back(2);
    bP.push_back(4);
    bP.push_back(2);
    bP.push_back(5);
    
    cP.push_back(3);
    cP.push_back(3);
    cP.push_back(1);
    cP.push_back(1);
    cP.push_back(2);
    cP.push_back(2);
    cP.push_back(4);
    cP.push_back(4);
    cP.push_back(5);
    cP.push_back(5);
    
    int currentNumberOfProblems = 0;
    int totalNumberOfProblems = answers.size();
    
    while(currentNumberOfProblems <= totalNumberOfProblems) {
        for (int i = 0; i < 5; i++) {
            if (aP[i] == answers[currentNumberOfProblems++]) {
                a++;
            }
        }
    }
    currentNumberOfProblems = 0;
    while(currentNumberOfProblems <= totalNumberOfProblems) {
        for (int i = 0; i < 8; i++) {
            if (bP[i] == answers[currentNumberOfProblems++]) {
                b++;
            }
        }
    
    }
    currentNumberOfProblems = 0;
    while(currentNumberOfProblems <= totalNumberOfProblems) {
        for (int i = 0; i < 10; i++) {
            if (cP[i] == answers[currentNumberOfProblems++]) {
                c++;
            }
        }
    
    }
    if (a == b) {
        if (a < c) {
            answer.push_back(3);
        } else if (a == c) {
            answer.push_back(1);
            answer.push_back(2);
            answer.push_back(3);
        } else {
            answer.push_back(1);
            answer.push_back(2);
        }
    } else if (a < b) {
        if (b < c) {
            answer.push_back(3);
        } else if (b == c) {
            answer.push_back(2);
            answer.push_back(3);
        } else {
            answer.push_back(2);
        }
    } else {
        if (a < c) {
            answer.push_back(3);
        } else if (a == c) {
            answer.push_back(1);
            answer.push_back(3);
        } else{
            answer.push_back(1);
        }
    }
    
    return answer;
}
