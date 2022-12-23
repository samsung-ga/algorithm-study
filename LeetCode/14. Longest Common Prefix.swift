//
//  14. Longest Common Prefix.swift
//  Problem_Solving
//
//  Created by Woody on 2022/12/23.
//

import Foundation

class Solution {
    func longestCommonPrefix(_ strs: [String]) -> String {
        var shortestLength: Int = Int.max
        
        for i in 0..<strs.count {
            shortestLength = min(shortestLength, strs[i].count)
        }

        var strs = strs.map { $0.map { String($0) }}
        var ret: String = ""
        for i in 0..<shortestLength {
            let chr = strs[0][i]
            var isPrefix: Bool = true
            for j in 1..<strs.count {
                if chr != strs[j][i] {
                    isPrefix = false
                    break
                }
            }
            if isPrefix { ret += chr }
            else { break }
        }

        return ret
    }
}
