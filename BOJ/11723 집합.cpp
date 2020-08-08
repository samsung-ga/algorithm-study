//
//  11723 집합.cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/09.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "add") {
            int m;
            cin >> m;
            bool flag = true;
            for (int i = 0 ; i < v.size(); i++) {
                if (v[i] == m) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                v.push_back(m);
            }
        } else if (s == "remove") {
            int m;
            cin >> m;
            bool flag = true;
            vector<int>::iterator iter = v.begin();
            for (int i = 0 ; i < v.size(); i++) {
                if (v[i] == m) {
                    flag = false;
                    iter += i;
                    break;
                }
            }
            if (!flag) {
                v.erase(iter);
            }
        } else if (s == "check") {
            int m;
            cin >> m;
            bool flag = true;
            for (int i = 0 ; i < v.size(); i++) {
                if (v[i] == m) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        } else if (s == "toggle") {
            int m;
            cin >> m;
            bool flag = true;
            vector<int>::iterator iter = v.begin();
            for (int i = 0 ; i < v.size(); i++) {
                if (v[i] == m) {
                    flag = false;
                    iter += i;
                    break;
                }
            }
            if (!flag) {
                v.erase(iter);
            } else {
                v.push_back(m);
            }
        } else if (s == "all") {
            vector<int> vv(20);
            for (int i = 1; i <= 20; i++) {
                vv[i-1] = i;
            }
            v = vv;
        } else {
            vector<int> vv;
            v = vv;
        }
        
    }
    return 0;
}

