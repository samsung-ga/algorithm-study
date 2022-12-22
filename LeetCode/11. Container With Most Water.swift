//
//  11. Container With Most Water.swift
//  Problem_Solving
//
//  Created by Woody on 2022/12/22.
//

import Foundation

class Solution {
    func maxArea(_ height: [Int]) -> Int {
        var ret: Int = 0
        for index in 0..<height.count {
            let standard = height[index]
            var left = index - 1
            var right = index + 1

            if ret <= index * standard {
                while left >= 0 {
                    if height[left] >= standard {
                        ret = max(ret, standard * (index-left))
                    }

                    left -= 1
                }
            }
            
            if ret <= (height.count - 1 - index) * standard {
                while right < height.count {
                    if height[right] >= standard {
                        ret = max(ret, standard * (right - index))
                    }
                    right += 1
                }
            }
        }
        return ret
    }
}
