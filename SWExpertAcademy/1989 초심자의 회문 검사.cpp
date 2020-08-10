//
//  1989 초심자의 회문 검사.cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/07.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    for (int test_case = 0; test_case < test; test_case++) {
        string s;
        cin >> s;
        int flag = true;
        for (int i = 0; i < s.size()/2; i++) {
            if (s[i] != s[s.size()-1-i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "#" << test_case+1 << " 1\n";
        } else {
            cout << "#" << test_case+1 << " 0\n";
        }

    }
        return 0;
}

