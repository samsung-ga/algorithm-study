//
//  5. Longest Palindromic Substring.swift
//  Problem_Solving
//
//  Created by Woody on 2022/12/19.
//

import Foundation

class Solution {
    
    func longestPalindrome(_ s: String) -> String {
        let str = Array(s)
        
        var start = 0
        var end = 0
        
        for index in 0..<str.count {
            
            // 홀수일 때, 즉 센터가 있을 경우
            var left = index-1, right = index+1
            
            while left >= 0 && right < str.count && str[left] == str[right] {
                left -= 1
                right += 1
            }

            if end - start < right - left - 1 {
                start = left + 1
                end = right - 1
            }

            // 짝수일 때, 즉 센터가 없을 경우
            left = index
            right = index + 1
            
            while left >= 0 && right < str.count && str[left] == str[right] {
                left -= 1
                right += 1
            }
            if end - start < right - left - 1 {
                start = left + 1
                end = right - 1
            }
            
        }
        
        return String(str[start...end])
    }
}
