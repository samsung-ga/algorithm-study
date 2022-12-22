//
//  9. Palindrome Number.swift
//  Problem_Solving
//
//  Created by Woody on 2022/12/22.
//

import Foundation

class Solution {
    func isPalindrome(_ x: Int) -> Bool {
        // 음수는 무조건 실패
        if x < 0 { return false }
        var compareX = x
        var newX = 0
        while compareX > 0 {
            let temp = compareX % 10
            compareX /= 10
            newX = newX * 10 + temp
        }
        return x == newX
    }
}
