//
//  땅따먹기.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/23.
//

// MARK: DFS 실패 -> 분할 정복으로 풀어야함

import Foundation

func solution(_ land:[[Int]]) -> Int{
    var land = land

    for r in 1..<land.count {
        land[r][0] += max(land[r-1][1], land[r-1][2], land[r-1][3])
        land[r][1] += max(land[r-1][0], land[r-1][2], land[r-1][3])
        land[r][2] += max(land[r-1][1], land[r-1][0], land[r-1][3])
        land[r][3] += max(land[r-1][1], land[r-1][2], land[r-1][0])
    }
    return land[land.count-1].max()!
}

// MARK: 다른 사람 풀이
/*
 import Foundation

 func solution(_ land:[[Int]]) -> Int{
     var dp = land
     for r in 1..<land.count {
         for i in 0..<4 {
             for k in 0..<4 {
                 if i == k { continue }
                 dp[r][i] = max(dp[r][i], dp[r-1][k]+land[r][i])
             }
         }
     }
     return dp.last!.max()!
 }
 */
