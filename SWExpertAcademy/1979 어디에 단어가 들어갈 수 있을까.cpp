//
//  1979 어디에 단어가 들어갈 수 있을까.cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/25.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(void) {
    int t;
    cin >> t;
    for (int test_case = 0; test_case < t; test_case++) {
        int n,k;
        cin >> n >> k;
        int map[17][17];
        for (int i = 0; i < 17; i++) {
            for (int j = 0; j < 17; j++) {
                map[i][j] = 0;
            }
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> map[i][j];
            }
        }
        int result = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (map[i][j] == 1 && ((i+k)-1 <= n || (j+k)-1 <= n)) {
                    
                    bool check1 = true;
                    bool check2 = true;
                    
                    // 세로검사
                    for (int length = 0; length < k; length++) {
                        if (!map[i+length][j]) {
                            check1 = false;
                            break;
                        }
                    }
                    if (map[i+k][j] || map[i-1][j]) {
                        check1 = false;
                    }
                    // 가로검사
                    for (int length = 0; length < k; length++) {
                        if (!map[i][j+length]) {
                            check2 = false;
                            break;
                        }
                    }
                    if (map[i][j+k] || map[i][j-1]) {
                        check2 = false;
                    }
                    
                    if (check1) result++;
                    if (check2) result++;
                }
            }
        }
        cout << "#" << test_case + 1 << " " << result << "\n";
    }
    return 0;
}

