//
//  섬 연결하기.swift
//  Coding_Test_Swift
//
//  Created by Jaeyong Lee on 2022/11/22.
//

import Foundation

func solution(_ n:Int, _ costs:[[Int]]) -> Int {
    let costs = costs.sorted { first, second in
        first[2] < second[2]
    }

    var parents: [Int] = Array.init(repeating: 0, count: n)
    for i in 0..<n {
        parents[i] = i
    }

    func findParent(_ element: Int) -> Int {
        if parents[element] != element {
            return findParent(parents[element])
        } else {
            return element
        }
    }

    var totalCost: Int = 0
    for cost in costs {
        let aParent = findParent(cost[0])
        let bParent = findParent(cost[1])

        if aParent == bParent { continue }

        if aParent < bParent { parents[bParent] = aParent }
        else { parents[aParent] = bParent }

        totalCost += cost[2]
    }

    return totalCost
}
