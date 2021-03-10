//
//  문자열 분석.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/10.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    
    string s;
    while(getline(cin, s)) {
        int lower = 0, higher = 0, number = 0, empty = 0;
        for (int i = 0 ; i < s.length(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                lower++;
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                higher++;
            } else if (s[i] >= '0' && s[i] <= '9') {
                number++;
            } else if (s[i] == ' ') {
                empty++;
            }
        }
        cout << lower << " " << higher << " " << number << " " << empty << "\n";
    };
    return 0;
}
