//
//  체육복.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/11.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;

    vector<pair<int,bool>> lostP;
    vector<pair<int,bool>> reserveP;

    for (int i = 0 ; i < lost.size(); i++) {
        lostP.push_back(make_pair(lost[i], false));
    }

    for (int i = 0; i < reserve.size(); i++) {
        reserveP.push_back(make_pair(reserve[i], false));
    }

    // 여벌 체육복을 도난당했을 경우 빌려주지 못하는 케이스 처리
    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            if (lost[i] == reserve[j]) {
                reserveP[j].second = true;
                lostP[i].second = true;
            }
        }
    }


    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            if (lostP[i].second == false && reserveP[j].second == false) {
                if (lost[i]-1 == reserve[j]) {
                    lostP[i].second = true;
                    reserveP[j].second = true;
                } else if (lost[i]+1 == reserve[j]) {
                    lostP[i].second = true;
                    reserveP[j].second = true;
                } else if (lost[i] == reserve[j]) {
                    lostP[i].second = true;
                    reserveP[j].second = true;
                }
            }
        }
    }

    int count = 0;
    for (int i = 0; i < lost.size() ; i++) {
        if (lostP[i].second == false) {
            count++;
        }
    }

    return answer - count;
}
