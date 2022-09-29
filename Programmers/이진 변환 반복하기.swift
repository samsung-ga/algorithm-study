//
//  이진 변환 반복하기.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/17.
//

import Foundation

var dp: [Int:String] = [:]

// MARK: 함수로 제공된다.
func convert2Int(with num: Int) -> String {
    var num = num
    var result: String = ""
    while num > 0 {
        result.append("\(num % 2)")
        num /= 2
    }
    return String(result.reversed())
}

func initializeDP() {
    for index in 1...150_000 {
        dp[index] = convert2Int(with: index)
    }
}

func solution(_ s:String) -> [Int] {
    initializeDP()
    var s = s
    var convertCount: Int = 0
    var zeroCount: Int = 0
    while s != "1" {
        convertCount += 1
        s.removeAll {
            if $0 == "0" { zeroCount += 1 }
            return $0 == "0"
        }
        let count = s.count
        s = dp[count]!
    }

    return [convertCount, zeroCount]
}
