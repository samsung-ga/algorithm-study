//
//  21. Merge Two Sorted Lists.swift
//  Problem_Solving
//
//  Created by Woody on 2023/01/06.
//

import Foundation
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init() { self.val = 0; self.next = nil; }
 *     public init(_ val: Int) { self.val = val; self.next = nil; }
 *     public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
 * }
 */
class Solution {
    func mergeTwoLists(_ list1: ListNode?, _ list2: ListNode?) -> ListNode? {
        var list1 = list1
        var list2 = list2
        var newList = ListNode(0)
        var curNode = newList
       
        while list1 != nil && list2 != nil {
            if list1!.val < list2!.val {
                curNode.next = list1
                list1 = list1!.next
            } else {
                curNode.next = list2
                list2 = list2!.next
            }
            curNode = curNode.next!
        }
        curNode.next = list1 ?? list2
        return newList.next
    }
}
  
