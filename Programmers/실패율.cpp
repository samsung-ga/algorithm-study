//
//  실패율.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/13.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool com(pair<double, int> a, pair<double, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector <double> failure;
    
    double remainPersons = stages.size();
    for (int i = 1; i <= N; i++) {
        double temp = 0;
        for (int j = 0; j < stages.size(); j++) {
            if (stages[j] == i) {
                temp++;
            }
        }
        if (temp == 0) {
            failure.push_back(0);
            continue;
        }
        double total = temp / remainPersons;
        failure.push_back(total);
        remainPersons -= temp;
    }
    
    vector<pair<double,int>> temp;
    for (int i = 0; i < failure.size(); i++) {
        temp.push_back(make_pair(failure[i], i+1));
    }
    
    sort(temp.begin(), temp.end(), com);
    
    for (int i = 0; i < temp.size(); i++) {
        answer.push_back(temp[i].second);
    }
    return answer;
}
