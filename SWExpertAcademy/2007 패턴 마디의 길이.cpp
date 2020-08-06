//
//  2007 패턴 마디의 길이.cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/06.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int t;
    cin >> t;
    for (int test = 0;test < t; test++) {
        string s;
        cin >> s;
        int res = 0;
        for (int i = 2; i < 10; i++) {
            if (i < s.size()) {
                if (s.substr(0,i) == s.substr(i,i)) {
                    res = i;
                    break;
                }
            }

        }
        cout << "#" << test+1 << " " << res << "\n";
    }
}
