//
//  6. Zigzag Conversion.swift
//  Problem_Solving
//
//  Created by Woody on 2022/12/20.
//

import Foundation

class Solution {
    func convert(_ s: String, _ numRows: Int) -> String {
        guard numRows != 1 else { return s }
        
        var str = s.map { String($0) }
        var ret = ""
        let sum = (numRows - 1) * 2
        
        for i in 0..<numRows {
            var index = i
            var count = 0
            while index < str.count {
                ret += str[index]
                count += 1
                if i == 0 || i == numRows-1 {
                    index += sum
                } else {
                    index += (count % 2 == 0) ? 2 * i : sum - 2 * i
                }
            }
        }
        return ret
    }
}
