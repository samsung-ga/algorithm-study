#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    while(1) {
        if (pq.top() < K) {
            if (pq.size() == 1) {
                return -1;
            }
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            int n = first + second * 2;
            pq.push(n);
            answer++;
        } else {
            break;
        }
    }
    return answer;
}
