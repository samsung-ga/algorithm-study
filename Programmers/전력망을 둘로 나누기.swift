//
//  전력망을 둘로 나누기.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/24.
//

import Foundation

func solution(_ n:Int, _ wires:[[Int]]) -> Int {
    var answer: Int = n
    for wire in wires {
        let wiresFiltered = wires.filter { $0 != wire }
        var parents: [Int] = []
        for i in 0...n {
            parents.append(i)
        }

        func findParent(_ element: Int) -> Int {
            if parents[element] != element {
                return findParent(parents[element])
            } else {
                return element
            }
        }

        func union(_ element1: Int, _ element2: Int) {
            let parent1 = findParent(element1)
            let parent2 = findParent(element2)
            if parent1 < parent2 {
                parents[parent2] = parent1
            } else {
                parents[parent1] = parent2
            }
        }

        for wireFilter in wiresFiltered {
            union(wireFilter[0], wireFilter[1])
        }

        var dictionary: [Int: Int] = [:]
        for i in 1..<parents.count {
            let root = findParent(parents[i])
            let count = dictionary[root] ?? 0
            dictionary[root] = count + 1
        }
        let values = Array(dictionary.values)
//        print(values)
        let ans: Int = abs(values[0] - values[1])
        answer = min(ans, answer)

    }
    return answer
}
