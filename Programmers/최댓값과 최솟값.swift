//
//  최댓값과 최솟값.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/17.
//

import Foundation

func solution(_ s:String) -> String {
    let numbers = s.split(separator: " ").map { Int($0)! }
    let minNum = numbers.min()!
    let maxNum = numbers.max()!

    return String(minNum) + " " + String(maxNum)
}

func solution2(_ s:String) -> String {
    var numbers = s.split(separator: " ").map { Int($0)! }

    numbers.sort()

    return String(numbers[0]) + String(numbers[numbers.count - 1])
}
