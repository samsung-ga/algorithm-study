//
//  완주하지 못한 선수.cpp
//  string
//
//  Created by 이재용 on 2021/03/09.
//

#include <string>
#include <vector>
#include <map>

using namespace std;

// 효율성 제로
string solution1(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for (int i = 0; i < completion.size(); i++) {
        for (int j = 0; j < participant.size(); j++) {
            if (completion[i] == participant[j]) {
                participant.erase(participant.begin() + j);
                break;
            }
        }
    }
    
    answer = participant[0];
    return answer;
}


// 메모리 사용 한도 초과
string solution2(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string,bool> mp;
    map<string,bool> mc;
    
    for (int i = 0; i < participant.size(); i++) {
        mp.insert(make_pair(participant[i], false));
    }
    
    for (int i = 0; i < completion.size(); i++) {
        mc.insert(make_pair(completion[i], false));
    }
    
    map<string,bool>::iterator itp = mp.begin();
    for (map<string,bool>::iterator it = mc.begin(); it != mc.end(); it++, itp++) {
        if (itp->first != it->first) {
            answer = itp->first;
            return answer;
        }
    }
    
    answer = itp->first;
    return answer;
}

// map을 쓰지 않은 풀이
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution3(vector<string> participant, vector<string> completion) {
    string answer = "";
 
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for (int i = 0 ; i < completion.size(); i++) {
        if (participant[i] != completion[i]) {
            return participant[i];
        }
    }
    
    answer = participant[participant.size()-1];
    
    return answer;
}

// map을 사용해서 풀은 풀이 (hash)
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution4(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string,int> m;
    for (int i = 0; i < participant.size(); i++) {
        if (m.find(participant[i]) == m.end()) {
            m[participant[i]] = 1;
        } else {
            m[participant[i]] += 1;
        }
    }
 
    for (int i = 0 ; i < completion.size(); i++) {
        if (m[completion[i]] == 1) {
            m.erase(completion[i]);
        } else {
            m[completion[i]] -= 1;
        }
    }
    
    answer = m.begin()->first;
    return answer;
}
