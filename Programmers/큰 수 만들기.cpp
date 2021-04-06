#include <string> 
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    while(k) {
        for (int i=0; i < number.size()-1;i++) {
            int before = number[i] - '0';
            int after = number[i+1] - '0';
            if (before < after) {
                number.erase(i,1);
                i = -1;
                k--;
                if (k == 0) {
                    break;
                }
            }
            if (i == number.size()-2) {
                number.erase(number.size()-k, k);
                k = 0;
                break;
            }
        }
    }
    answer = number;
    return answer;
}
