//
//  피보나치.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/22.
//

import Foundation

func solution(_ n:Int) -> Int {
    var dp: [Int] = []
    dp.append(0)
    dp.append(1)
    for i in 2..<100_000 {
        dp.append((dp[i-1] + dp[i-2]) % 1234567)
    }
    return dp[n]
}
