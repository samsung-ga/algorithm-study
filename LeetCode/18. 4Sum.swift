//
//  18. 4Sum.swift
//  Problem_Solving
//
//  Created by Woody on 2023/01/13.
//

import Foundation

class Solution {
    func fourSum(_ nums: [Int], _ target: Int) -> [[Int]] {
        let nums = nums.sorted()
        var ret: Set<[Int]> = []
        for i in nums.indices {
            guard i <= nums.count - 4 else { break }

            for j in i+2..<nums.count {
                var left = j-1
                var right = j+1
                

                while left > i && right < nums.count && left < right {
                    let sum = nums[left] + nums[right] + nums[j] + nums[i]

                    if sum > target {
                        left -= 1
                    } else if sum < target {
                        right += 1
                    } else {
                        ret.insert([nums[i], nums[left],nums[j],nums[right]])

                        left -= 1
                        right += 1
                        while left-1 > i && nums[left] == nums[left-1] { left -= 1 }
                        while right+1 < nums.count && nums[right] == nums[right+1] { right += 1 }
                    }
                }
            }
        }

        return Array(ret)
    }
}
       
