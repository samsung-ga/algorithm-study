//
//  16. 3Sum Closest.swift
//  Problem_Solving
//
//  Created by Woody on 2023/01/13.
//

import Foundation

class Solution {
    func threeSumClosest(_ nums: [Int], _ target: Int) -> Int {
        var nums = nums.sorted { $0 < $1 }
        var compare = Int.max
        var ret = target
        for i in 0..<nums.count {
            if i > 0 && nums[i] == nums[i-1] { continue }

            var left = i + 1
            var right = nums.count - 1
            
            while left < right {
                let sum = nums[i] + nums[left] + nums[right]

                if compare > abs(sum - target) {
                    compare = abs(sum - target)
                    ret = sum
                }
                if sum < target {
                    left += 1
                } else if sum > target {
                    right -= 1
                } else {
                    ret = target
                    break
                }
            }
        }
        return ret
    }
}
