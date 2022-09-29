//
//  N개의 최소공배수.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/23.
//

import Foundation

func gcd(_ a: Int, _ b: Int) -> Int {
    let mod: Int = a % b
    return mod == 0 ? b : gcd(b, mod)
}

func lcm(_ a: Int, _ b: Int) -> Int {
    let num = gcd(a, b)
    return a * b / num
}

func solution(_ arr:[Int]) -> Int {
    var result: Int = 1
    for i in 0..<arr.count {
        result = lcm(arr[i], result)
    }
    return result
}

