//
//  피로도.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/23.
//

import Foundation

// MARK: 런타임 에러
// MARK: - 옵셔널, index out of range, for문에서 오류,
// MARK: (🚀 중요) 조건을 빼먹거나..!!!!!

func solution(_ k:Int, _ dungeons:[[Int]]) -> Int {
    var answer: Int = 0
    var visited: [Bool] = Array.init(repeating: false, count: dungeons.count)
    func dfs(tireness: Int, count: Int) {
        answer = max(answer, count)
        for i in 0..<dungeons.count {
            if visited[i] == false,
               tireness >= dungeons[i][0],
               tireness >= dungeons[i][1] {
                visited[i] = true
                dfs(tireness: tireness-dungeons[i][1], count: count+1)
                visited[i] = false
            }
        }
    }
    dfs(tireness: k, count: 0)
    return answer
}
