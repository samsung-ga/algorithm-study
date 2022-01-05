#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool checkCondition(vector<char> result, vector<string> data, int n) {
  bool ALLCHECKED = true;
  while(n--) {
    string condition = data[n];
    
    char person1 = condition[0];
    char person2 = condition[2];
    char sign = condition[3];
    int diff = int(condition[4]);
    
    int find1 = int(find(result.begin(), result.end(), person1) - result.begin());
    int find2 = int(find(result.begin(), result.end(), person2) - result.begin());
    
    if (sign == '=') {
      if (find1 - find2 != diff) {
        ALLCHECKED = false;
        break;
      }
    } else if (sign == '>') {
      if (find1 - find2 > diff || find1 - find2 < -diff) {
        ALLCHECKED = false;
        break;
      }
    } else if (sign == '<') {
      if (find1 - find2 < diff || find1 - find2 > -diff) {
        ALLCHECKED = false;
        break;
      }
    }
  }
  
  return ALLCHECKED;
}

int answer = 0;
void dfs(vector<char> original, vector<char> result, vector<string> data, vector<bool> used, int current, int n) {
  if (n == 8) {
    // 체크
    if (checkCondition(result, data, n)) {
      answer++;
    }
    return;
  } else {
    for (int i = 0; i < 8; i++) {
      if(used[i] == false) {
        result.push_back(original[i]);
        used[i] = true;
        dfs(original, result, data, used, current+1, n);
      }
    }
  }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
  vector<char> original;
  original.push_back('A');
  original.push_back('C');
  original.push_back('F');
  original.push_back('J');
  original.push_back('M');
  original.push_back('N');
  original.push_back('R');
  original.push_back('T');
  vector<char> result;
  vector<bool> used;
  for (int i = 0 ; i < 8; i++) {
    used.push_back(false);
  }
  dfs(original, result, data, used, 0, n);
  
  return answer;
}
