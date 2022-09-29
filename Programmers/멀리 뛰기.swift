//
//  멀리 뛰기.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/23.
//

func solution(_ n:Int) -> Int {
    var dp: [Int] = []
    dp.append(0)
    dp.append(1)
    dp.append(2)
    dp.append(3)
    if n < 4 { return dp[n] }
    for i in 4...n {
        dp.append((dp[i-1] + dp[i-2]) % 1234567)
    }
    return dp[n]
}

print(solution(4))
print(solution(3))
