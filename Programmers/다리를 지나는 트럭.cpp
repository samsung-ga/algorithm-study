//
//  다리를 지나는 트럭.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/20.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> trucks_yet;
    queue<int> trucks_on_bridge;
    vector<int> times;
    int bridge_trucks_weight = 0;
    
    for (int i = 0; i < truck_weights.size(); i++) {
        trucks_yet.push(truck_weights[i]);
    }
    
    // 첫 트럭 처리
    int first = trucks_yet.front();
    bridge_trucks_weight += first;
    trucks_on_bridge.push(first);
    times.push_back(bridge_length);
    trucks_yet.pop();
    answer++;
    
    while(!times.empty()) {
        answer++;
        if (!times.empty()) {
            for (int i = 0; i < times.size(); i++) {
                times[i] -= 1;
            }
            if (times[0] == 0) {
                int w = trucks_on_bridge.front();
                bridge_trucks_weight -= w;
                trucks_on_bridge.pop();
                times.erase(times.begin());
            }
        }
        if (!trucks_yet.empty()) {
            int temp = trucks_yet.front();
            if (bridge_trucks_weight + temp <= weight) {
                bridge_trucks_weight += temp;
                trucks_on_bridge.push(temp);
                times.push_back(bridge_length);
                trucks_yet.pop();
            }
        }
    }
    return answer;
}
