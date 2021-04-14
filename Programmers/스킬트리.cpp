#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    string skill_copy = skill;
    for (int i = 0; i < skill_trees.size(); i++) {
        string temp = skill_trees[i];
        skill = skill_copy;
        bool flag = false;
        for (int j = 0; j < temp.size(); j++) {
            if (temp[j] == skill[0]) {
                skill.erase(skill.begin());
            } else {
                for (int k = 1; k < skill.size(); k++) {
                    if (temp[j] == skill[k]) {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) {
                break;
            }
        }
        if (!flag) {
            answer++;
        }
    }
    return answer;
}
