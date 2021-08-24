#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
  bool operator()(pair<int,int> a, pair<int,int> b) {
    if (a.first == b.first) {
      return a.second > b.second;
    }
    return a.first > b.first;
  }
};

struct compare {
  bool operator()(pair<int,int> a, pair<int,int> b) {
    if (a.second == b.second) {
      return a.first > b.first;
    }
    return a.second > b.second;
  }
};

int main(void) {
  
  int n;
  priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> lessons;
  priority_queue<pair<int, int>, vector<pair<int, int>>, compare> rooms;
  
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    lessons.push(make_pair(a, b));
  }
  
  rooms.push(lessons.top());
  lessons.pop();
  while(!lessons.empty()) {
    if (lessons.top().first >= rooms.top().second) {
      pair<int, int> temp = rooms.top();
      rooms.pop();
      temp.second = lessons.top().second;
      rooms.push(temp);
      lessons.pop();
    } else {
      rooms.push(lessons.top());
      lessons.pop();
    }
  }

  cout << rooms.size();
  return 0;
}
