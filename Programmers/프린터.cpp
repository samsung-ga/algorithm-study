#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    for (int i = 0; i < priorities.size(); i++) {
        q.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]);
    }
    
    while (!q.empty()) {
        int index = q.front().first;
        int priority = q.front().second;
        q.pop();
        if (pq.top()== priority) {
            answer++;
            if (index == location) {
                return answer;
            }
            pq.pop();
        } else {
            q.push(make_pair(index, priority));
        }
    }
    
    return answer;
}
