//
//  20. Valid Parentheses.swift
//  Problem_Solving
//
//  Created by Woody on 2023/01/02.
//

import Foundation

class Solution {
    func isValid(_ s: String) -> Bool {
        var stack: [String.Element] = []

        for chr in s {
            if let lastBracket = stack.last {
                if lastBracket == "(" {
                    if chr == ")" {
                        stack.removeLast()
                        continue
                    } else if chr == "]" || chr == "}" {
                        return false
                    }
                } else if lastBracket == "[" {
                    if chr == "]" {
                        stack.removeLast()
                        continue
                    } else if chr == ")" || chr == "}" {
                        return false
                    }
                } else if lastBracket == "{" {
                    if chr == "}" {
                        stack.removeLast()
                        continue
                    } else if chr == ")" || chr == "]" {
                        return false
                    }
                }
            }

            stack.append(chr)
        }

        if stack.isEmpty { return true }
        else { return false }
    }
}
