//
//  1129. Shortest Path with Alternating Colors.swift
//  algorithm
//
//  Created by Woody Lee on 2023/04/09.
//

import Foundation

class Solution {
    func shortestAlternatingPaths(_ n: Int, _ redEdges: [[Int]], _ blueEdges: [[Int]]) -> [Int] {
        typealias Node = (node: Int, color: Int)
        var graph: [[Int]] = Array.init(repeating: Array.init(repeating: -2, count: n), count: n)
        for redEdge in redEdges {
            let from = redEdge[0]
            let to = redEdge[1]
            
            graph[from][to] = 1
        }
        for blueEdge in blueEdges {
            let from = blueEdge[0]
            let to = blueEdge[1]
            
            // 두개의 노드가 다 포함된 경우
            if graph[from][to] == 1 {
                graph[from][to] = 0
            } else {
                graph[from][to] = -1
            }
        }
    
        var queue: [(Node, Int)] = [(Node(0,1), 0), (Node(0,-1), 0)]
        var dist: [Int] = Array.init(repeating: Int.max, count: n)
        var visited: [Node] = []
 
        var index = 0
        while index < queue.count {
            let curNode = queue[index].0.node
            let curColor = queue[index].0.color
            let nextColor = -curColor
           
            for i in 0..<n where graph[curNode][i] == nextColor || graph[curNode][i] == 0 {
                let nextNode = Node(i, nextColor)
                if visited.contains(where: { $0 == nextNode}) == false {
                    queue.append((nextNode, queue[index].1 + 1))
                    dist[i] = min(dist[i], queue[index].1 + 1)
                    visited.append(nextNode)
                }
            }
            
            index += 1
        }
        
        for i in 0..<n where dist[i] == Int.max {
            dist[i] = -1
        }
        dist[0] = 0
        return dist
    }
}
