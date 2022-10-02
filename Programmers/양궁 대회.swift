//
//  양궁 대회.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/10/02.
//

import Foundation

func solution(_ n:Int, _ info:[Int]) -> [Int] {
    var ryanResult: [Int] = []
    var scoreDiff: Int = Int.min
    func dfs(index: Int, count: Int, appeachScore: Int, ryanScore: Int, result: [Int]) {
        if n == count, result.count == info.count, appeachScore < ryanScore {
            if scoreDiff < ryanScore - appeachScore {
                scoreDiff = ryanScore - appeachScore
                ryanResult = result
            }
            return
        }

        if count > n { return }
        if index < 0 { return }

        let score = 10 - index
        for ryanCount in (0...info[index]+1).reversed() {
            if ryanCount == 0, info[index] == 0 {
                dfs(index: index-1, count: count, appeachScore: appeachScore, ryanScore: ryanScore, result: result + [0])
            } else if ryanCount > info[index] {
                dfs(index: index-1, count: count+ryanCount, appeachScore: appeachScore, ryanScore: ryanScore + score, result: result + [ryanCount])
            } else {
                dfs(index: index-1, count: count+ryanCount, appeachScore: appeachScore + score, ryanScore: ryanScore, result: result + [ryanCount])
            }
        }

    }

    dfs(index: 10, count: 0, appeachScore: 0, ryanScore: 0, result: [])

    return ryanResult.isEmpty ? [-1] : ryanResult.reversed()
}
