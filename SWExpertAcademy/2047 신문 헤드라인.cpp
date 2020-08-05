//
//  2047 신문 헤드라인.cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/05.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(void) {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        s[i] = toupper(s[i]);
    }
    cout << s;
    return 0;
}

