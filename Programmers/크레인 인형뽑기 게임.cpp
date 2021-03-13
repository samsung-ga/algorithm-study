//
//  크레인 인형뽑기 게임.cpp
//  codingtest
//
//  Created by 이재용 on 2021/03/12.
//  Copyright © 2021 jaeyong Lee. All rights reserved.
//

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    vector<int> bowl;
    for (int i = 0; i < moves.size(); i++) {
        int location = moves[i] - 1;
        for (int j = 0; j < board.size(); j++) {
            if (board[j][location] == 0) continue;
            bowl.push_back(board[j][location]);
            board[j][location] = 0;
            
            if (bowl.size() >= 2) {
                int backIndex = bowl.size() - 1;
                if (bowl[backIndex] == bowl[backIndex-1]) {
                    bowl.pop_back();
                    bowl.pop_back();
                    answer += 2;
                }
            }
            break;
        }
    }
    
    return answer;
}
