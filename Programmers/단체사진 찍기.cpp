#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cnt;
int checkCondition(vector<char> result, vector<string> data, int n) {
  int ALLCHECKED = true;
  while(n--) {
    string condition = data[n];
    char person1 = condition[0];
    char person2 = condition[2];
    char sign = condition[3];
    int diff = (condition[4] - '0');
    
    int find1 = int(find(result.begin(), result.end(), person1) - result.begin());
    int find2 = int(find(result.begin(), result.end(), person2) - result.begin());
    if (sign == '=') {
      if (abs(find1 - find2) - 1 == diff) {
        continue;
      } else {
        ALLCHECKED = false;
        break;
      }
    } else if (sign == '>') {
      if (abs(find1 - find2) > diff + 1) {
        continue;
      } else {
        ALLCHECKED = false;
        break;
      }
    } else if (sign == '<') {
      if (abs(find1 - find2) < diff - 1) {
        continue;
      } else {
        ALLCHECKED = false;
        break;
      }
    }
  }
  return ALLCHECKED;
}

void dfs(vector<char> original, vector<char> result, int *visit, vector<string> data, int current, int n) {
  if (current == 8) {
    if (checkCondition(result, data, n)) {
      cnt++;
    }
    return;
  } else {
    for (int i = 0; i < 8; i++) {
      if (visit[i] == 1) continue;
      visit[i] = 1;
      result.push_back(original[i]);
      dfs(original, result,visit, data, current+1, n);
      result.pop_back();
      visit[i] = 0;
    }
  }
}
int solution(int n, vector<string> data) {
  int answer = 0;
  int visit[8];
  cnt = 0;
  vector<char> original;
  vector<char> result;
  vector<bool> used;
  original.push_back('A');
  original.push_back('C');
  original.push_back('F');
  original.push_back('J');
  original.push_back('M');
  original.push_back('N');
  original.push_back('R');
  original.push_back('T');
  
  for (int i = 0 ; i < 8; i++) {
    visit[i] = 0;
  }
  
  dfs(original, result, visit, data, 0, n);
  
  answer = cnt;
  return answer;
}

