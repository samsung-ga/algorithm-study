//
//  2050 알파벳을 숫자로 변환.cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/05.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
    string s;
    cin >> s;
    
    for (int i = 0; i < s.size(); i++) {
        s[i] = toupper(s[i]);
        cout << s[i] - 'A' + 1 << " ";
    }
    
    return 0;
}

