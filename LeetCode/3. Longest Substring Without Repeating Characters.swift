//
//  3. Longest Substring Without Repeating Characters.swift
//  Problem_Solving
//
//  Created by Woody on 2022/12/18.
//

import Foundation

class Solution {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        var startIndex = 0
        var ret = 0
        var chrDic: [Character: Int] = [:]
        for (index,chr) in s.enumerated() {
            if let lastIndex = chrDic[chr] {
                startIndex = max(startIndex, lastIndex + 1)
            }
            chrDic[chr] = index
            ret = max(ret, index-startIndex+1)
        }
        return ret
    }
}

