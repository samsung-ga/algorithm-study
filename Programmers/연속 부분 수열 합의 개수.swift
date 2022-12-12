//
//  연속 부분 수열 합의 개수.swift
//  Coding_Test_Swift
//
//  Created by Jaeyong Lee on 2022/12/13.
//

import Foundation

func getSumOfPartialSequence(_ elements: [Int], count: Int) -> Set<Int> {
    var sum: Set<Int> = []

    for i in 0..<count {
        var temp: Int = elements[i]
        sum.insert(temp)

        for j in i+1..<i+5 {
            temp += elements[j]
            sum.insert(temp)
        }
    }

    return sum
}

func solution(_ elements:[Int]) -> Int {
    let num = elements.count
    let sum = getSumOfPartialSequence(elements + elements, count: num)
    return sum.count
}

