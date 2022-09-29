//
//  가장 먼 노드.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/24.
//

import Foundation

func solution(_ n:Int, _ edge:[[Int]]) -> Int {
    var graph: [[Int]] = Array.init(repeating: [Int](), count: n+1)
    var answers: [Set<Int>] = []
    for edge in edge {
        graph[edge[0]].append(edge[1])
        graph[edge[1]].append(edge[0])
    }
    answers.append([1])
    var visited: [Bool] = Array.init(repeating: false, count: n+1)
    visited[1] = true
    var index: Int = 0
    while answers.last!.count > 0 {
        var depthArray: Set<Int> = []
        for source in answers[index] {
            let nextList = graph[source]
            for next in nextList {
                if visited[next] == false {
                    visited[next] = true
                    depthArray.insert(next)
                }
            }
        }
        answers.append(depthArray)
        index += 1
    }
    answers.removeLast()
    print(answers)
    return answers.last!.count
}
