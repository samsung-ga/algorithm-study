//
//  k진수에서 소수 개수 구하기.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/23.
//

import Foundation

// MARK: 소수 개수 구하기
func isPrime(_ num: Int) -> Bool {
    if num == 1 { return false }
    if num == 2 { return true }
    if num == 3 { return true }
    for i in 2...Int(sqrt(Double(num))) {
        if num % i == 0 {
            return false
        }
    }
    return true
}
func solution(_ n:Int, _ k:Int) -> Int {
    let string = String(n, radix: k)
    return string.split(separator: "0")
        .compactMap { Int($0) }
        .filter { isPrime($0)}.count
}
