//
//  14500 테트로미노.cpp
//  codingtest
//
//  Created by 이재용 on 2020/07/31.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    int n,m;
    int map[503][503] = { 0, }; // j+2, j+3 까지 구현했으므로 503까지 늘려주어야하지만, j+2에서 막히기 때문에 그래줄 필요 X
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }
    int max = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j] && map[i+1][j] && map[i+1][j+1] && map[i][j+1]) { // 정사각형
                int sum = 0;
                sum = map[i][j] + map[i+1][j] + map[i+1][j+1] + map[i][j+1];
                if (max < sum) {
                    max = sum;
                }
            }
            if (map[i][j] && map[i][j+1] && map[i][j+2] && map[i][j+3]) { // 네개짜리 긴거
                int sum = 0;
                sum = map[i][j] + map[i][j+1] + map[i][j+2] + map[i][j+3];
                if (max < sum) {
                    max = sum;
                }
            }
            if (map[i][j] && map[i+1][j] && map[i+2][j] && map[i+3][j]) {
                int sum = 0;
                sum = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+3][j];
                if (max < sum) {
                    max = sum;
                }
            }
            if (map[i][j] && map[i][j+1] && map[i][j+2] && map[i+1][j+2]) { // ㄱ
                int sum = 0;
                sum = map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j+2];
                if (max < sum) {
                    max = sum;
                }
            }
            if (map[i][j] && map[i][j+1] && map[i][j+2] && map[i+1][j]) {
                int sum = 0;
                sum = map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j];
                if (max < sum) {
                    max = sum;
                }
            }
            if (map[i][j] && map[i+1][j] && map[i+2][j] && map[i+2][j+1]) {
                int sum = 0;
                sum = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+2][j+1];
                if (max < sum) {
                    max = sum;
                }
            }
            if (map[i][j] && map[i+1][j] && map[i+2][j] && map[i][j+1]) {
                int sum = 0;
                sum = map[i][j] + map[i+1][j] + map[i+2][j] + map[i][j+1];
                if (max < sum) {
                    max = sum;
                }
            }
            if (map[i][j] && map[i][j+1] && map[i+1][j+1] && map[i+2][j+1]) {
                int sum = 0;
                sum = map[i][j] + map[i][j+1] + map[i+1][j+1] + map[i+2][j+1];
                if (max < sum) {
                    max = sum;
                }
            }
            if (map[i+2][j] && map[i][j+1] && map[i+1][j+1] && map[i+2][j+1]) {
                int sum = 0;
                sum = map[i+2][j] + map[i][j+1] + map[i+1][j+1] + map[i+2][j+1];
                if (max < sum) {
                    max = sum;
                }
            }
            if (map[i][j] && map[i+1][j] && map[i+1][j+1] && map[i+1][j+2]) {
                int sum = 0;
                sum = map[i][j] + map[i+1][j] + map[i+1][j+1] + map[i+1][j+2];
                if (max < sum) {
                    max = sum;
                }
            }
            if (map[i][j+2] && map[i+1][j] && map[i+1][j+1] && map[i+1][j+2]) {
                int sum = 0;
                sum = map[i][j+2] + map[i+1][j] + map[i+1][j+1] + map[i+1][j+2];
                if (max < sum) {
                    max = sum;
                }
            }
            if (map[i][j] && map[i+1][j] && map[i+2][j] && map[i+1][j+1]) { // ㅗ
                int sum = 0;
                sum = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+1][j+1];
                if (max < sum) {
                    max = sum;
                }
            }
            if (map[i][j] && map[i][j+1] && map[i][j+2] && map[i+1][j+1]) {
                int sum = 0;
                sum = map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j+1];
                if (max < sum) {
                    max = sum;
                }
            }
            if (map[i][j+1] && map[i+1][j+1] && map[i+2][j+1] && map[i+1][j]) {
                int sum = 0;
                sum = map[i][j+1] + map[i+1][j+1] + map[i+2][j+1] + map[i+1][j];
                if (max < sum) {
                    max = sum;
                }
            }
            if (map[i][j+1] && map[i+1][j+1] && map[i+1][j] && map[i+1][j+2]) {
                int sum = 0;
                sum = map[i][j+1] + map[i+1][j+1] + map[i+1][j] + map[i+1][j+2];
                if (max < sum) {
                    max = sum;
                }
            }
            if (map[i][j] && map[i][j+1] && map[i+1][j+1] && map[i+1][j+2]) { // 지그재그
                int sum = 0;
                sum = map[i][j] + map[i][j+1] + map[i+1][j+1] + map[i+1][j+2];
                if (max < sum) {
                    max = sum;
                }
            }
            if (map[i][j+1] && map[i+1][j+1] && map[i+1][j] && map[i+2][j]) {
                int sum = 0;
                sum = map[i][j+1] + map[i+1][j+1] + map[i+1][j] + map[i+2][j];
                if (max < sum) {
                    max = sum;
                }
            }
            if (map[i][j+1] && map[i][j+2] && map[i+1][j] && map[i+1][j+1]) {
                int sum = 0;
                sum = map[i][j+1] + map[i][j+2] + map[i+1][j] + map[i+1][j+1];
                if (max < sum) {
                    max = sum;
                }
            }
            if (map[i][j] && map[i+1][j] && map[i+1][j+1] && map[i+2][j+1]) {
                int sum = 0;
                sum = map[i][j] + map[i+1][j] + map[i+1][j+1] + map[i+2][j+1];
                if (max < sum) {
                    max = sum;
                }
            }
        }
    }
    
    cout << max << "\n";
    return 0;
}

