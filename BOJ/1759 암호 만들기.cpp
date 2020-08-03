//
//  1759 암호 만들기.cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/04.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(void) {
    int l,c;
    cin >> l >> c;
    
    vector<char> v(c);
    int moum = 0;
    for (int i = 0; i < c; i++) {
        cin >> v[i];
        if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') {
            moum++;
        }
    }
    sort(v.begin(), v.end());
    vector<int> temp;
    for (int i = 0; i < l; i++) {
        temp.push_back(1);
    }
    for (int i = 0; i < c - l; i++) {
        temp.push_back(0);
    }
    
    do {
        int flag = 0;
        int flag2 = 0;
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] == 1) {
                if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') {
                    flag++;
                } else {
                    flag2++;
                }
            }
        }
        
        if (flag >= 1 && flag2 >= 2) {
            for (int i = 0; i < temp.size(); i++) {
                if (temp[i] == 1) {
                    
                    cout << v[i];
                }
            }
            cout << "\n";
        }
        
    } while (prev_permutation(temp.begin(), temp.end()));
    
    return 0;
}

