//
//  4. Median of Two Sorted Arrays.swift
//  Problem_Solving
//
//  Created by Woody on 2022/12/19.
//

import Foundation

class Solution {
    func findMedianSortedArrays(_ nums1: [Int], _ nums2: [Int]) -> Double {
        
        let count = (nums1.count + nums2.count) / 2
        let twoElement = (nums1.count + nums2.count) % 2 == 0
        var ret: Double = 0
        var i = 0
        var j = 0
        var merged: [Int] = []

        while i < nums1.count || j < nums2.count {
            
            if i < nums1.count && j < nums2.count {
                if nums1[i] < nums2[j] {
                    merged.append(nums1[i])
                    i += 1
                } else {
                    merged.append(nums2[j])
                    j += 1
                }
            } else if j < nums2.count {
                merged.append(nums2[j])
                j += 1
            } else if i < nums1.count {
                merged.append(nums1[i])
                i += 1
            }
            
            if i + j == count + 1 {
                ret = twoElement ? (Double(merged[count-1]) + Double(merged[count])) / 2.0 : Double(merged[count])
                break
            }
        }
        
        return ret
    }
}
