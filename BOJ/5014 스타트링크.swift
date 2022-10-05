//
//  5014 스타트링크.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/10/06.
//

import Foundation

func solution() {
    let fsgud = readLine()!.split(separator: " ").map { Int(String($0))! }
    let (f,s,g,u,d) = (fsgud[0],fsgud[1],fsgud[2],fsgud[3],fsgud[4])

    func bfs(start: Int) -> Int {
        var queue: [(Int,Int)] = []
        var visited: [Bool] = Array.init(repeating: false, count: f+1)
        queue.append((start, 0))
        var index: Int = 0
        while index < queue.count {
            let stage = queue[index].0
            let count = queue[index].1
            if stage == g {
                return count
            }

            if stage + u <= f {
                if visited[stage + u] == false {
                    queue.append((stage + u, count+1))
                    visited[stage + u] = true
                }
            }

            if stage - d >= 1 {
                if visited[stage - d] == false {
                    queue.append((stage - d, count+1))
                    visited[stage - d] = true
                }
            }

            index += 1
        }

        return -1
    }

    let result = bfs(start: s)
    print(result == -1 ? "use the stairs" : result)
}

solution()
