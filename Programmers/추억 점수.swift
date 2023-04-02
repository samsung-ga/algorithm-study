//
//  추억 점수.swift
//  algorithm
//
//  Created by Woody Lee on 2023/04/02.
//

import Foundation

func solution(_ name:[String], _ yearning:[Int], _ photo:[[String]]) -> [Int] {
    var dictionary: [String: Int] = [:]
    name.enumerated()
        .forEach { dictionary[$0.element] = yearning[$0.offset] }
    
    var ret: [Int] = []
    photo.forEach { array in
        let sum = array
            .map { dictionary[$0] ?? 0 }
            .reduce(0, +)
        ret.append(sum)
    }
    
    return ret
}

let ans = solution(
    ["may", "kein", "kain", "radi"],
    [5, 10, 1, 3],
    [
        ["may", "kein", "kain", "radi"],
        ["may", "kein", "brin", "deny"],
        ["kon", "kain", "may", "coni"]
    ]
)

print(ans)
