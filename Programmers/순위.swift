//
//  순위.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/24.
//

import Foundation

func solution(_ n:Int, _ results:[[Int]]) -> Int {
    var graph: [[Int]] = Array.init(repeating: [Int](), count: n+1)
    var winLostInfo: [(Int,Int)] = Array.init(repeating: (0,0), count: n+1)
    for result in results {
        graph[result[1]].append(result[0])
    }
//    print(graph)
    func bfs(start: Int) {
        var queue = [start]
        var visited: [Bool] = Array.init(repeating: false, count: n+1)
        visited[start] = true

        var index: Int = 0
        while index < queue.count {
            let node = queue[index]
            index += 1
//            print(node)
            for next in graph[node] {
                if visited[next] == false {
                    visited[next] = true
                    winLostInfo[next].0 += 1
                    winLostInfo[start].1 += 1
                    queue.append(next)
                }
            }
        }
    }
//    var visited: [Bool] = Array.init(repeating: false, count: n+1)
//    func dfs(start: Int) {
//        for next in graph[start] {
//            if visited[next] == false {
//                print(next)
//                visited[next] = true
//                dfs(start: next)
//            }
//        }
//    }

    for i in 1...n {
        bfs(start: i)
//        visited = Array.init(repeating: false, count: n+1)
//        print("----")
    }
//    print(winLostInfo)
    return winLostInfo.filter { $0.0 + $0.1 == n - 1}.count
}

print(solution(5, [[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]))
