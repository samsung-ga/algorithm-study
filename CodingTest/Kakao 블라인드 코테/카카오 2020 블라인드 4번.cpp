//
//  카카오 2020 블라인드 4번.cpp
//  codingtest
//
//  Created by 이재용 on 2020/09/12.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 100000;
    
    // present node, next node, 비용
    vector<vector<pair<int, int>>> v(n+1);
    for (int i = 0 ; i < fares.size(); i++) {
        v[fares[i][0]].push_back(make_pair(fares[i][1], fares[i][2]));
        v[fares[i][1]].push_back(make_pair(fares[i][0], fares[i][2]));
    }
    
    // 다음 노드, 비용
    queue<pair<int, int>> aq;
    queue<pair<int, int>> bq;
    vector<bool> aVisited(n);
    vector<bool> bVisited(n);
    aq.push(make_pair(s, 0));
    bq.push(make_pair(s, 0));
    while(!aq.empty() && !bq.empty()) {
        int aNow = aq.front().first;
        int aCost = aq.front().second;
        int bNow = bq.front().first;
        int bCost = bq.front().second;
        aq.pop();
        bq.pop();
        aVisited[aNow] = true;
        bVisited[bNow] = true;

        if (aVisited[a] && bVisited[b]) {
            cout << aCost + bCost << "\n";
            answer = answer < (aCost + bCost) ? answer : (aCost + bCost);
        }
        
        for (int i = 0; i < v[aNow].size(); i++) {
            for (int j = 0; j < v[bNow].size(); j++) {
                int newACost = aCost + v[aNow][i].second;
                int newBCost = bCost + v[bNow][j].second;
                if (i == j) {
                    newBCost = bCost;
                }
                if (aVisited[v[aNow][i].first] == false) {
                    aq.push(make_pair(v[aNow][i].first, newACost));
                }
                if (bVisited[v[bNow][j].first] == false) {
                    
                    bq.push(make_pair(v[bNow][j].first, newBCost));
                }
            }
            
        }
    }
    return answer;
}

int main(void) {
    
    vector<vector<int>> v(9);
    v[0].push_back(4);
    v[0].push_back(1);
    v[0].push_back(10);
    v[1].push_back(3);
    v[1].push_back(5);
    v[1].push_back(24);
    v[2].push_back(5);
    v[2].push_back(6);
    v[2].push_back(2);
    v[3].push_back(3);
    v[3].push_back(1);
    v[3].push_back(41);
    v[4].push_back(5);
    v[4].push_back(1);
    v[4].push_back(24);
    v[5].push_back(4);
    v[5].push_back(6);
    v[5].push_back(50);
    v[6].push_back(2);
    v[6].push_back(4);
    v[6].push_back(66);
    v[7].push_back(2);
    v[7].push_back(3);
    v[7].push_back(22);
    v[8].push_back(1);
    v[8].push_back(6);
    v[8].push_back(25);
    cout << solution(6, 4, 6, 2, v);
    return 0;
}
    

