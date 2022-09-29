//
//  여행경로.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/17.
//

import Foundation

// MARK: DFS는 메소드 내에서 구현해보자 https://icksw.tistory.com/228

func solution(_ tickets:[[String]]) -> [String] {
    let tickets = tickets.sorted { $0[1] < $1[1] }
    var visited = Array.init(repeating: false, count: tickets.count)

    var result = [String]()

    func dfs(start: String) {
        if result.count == tickets.count {
            result.append(start)
            return
        }
        for i in 0..<tickets.count {
            if tickets[i][0] == start && !visited[i] {
                visited[i] = true
                result.append(start)
                dfs(start: tickets[i][1])
                if result.count == tickets.count + 1 {
                    return
                }
                result.removeLast()
                visited[i] = false
            }
        }
    }

    dfs(start: "ICN")
    return result
}


