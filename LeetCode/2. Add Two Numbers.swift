//
//  2. Add Two Numbers.swift
//  Problem_Solving
//
//  Created by Woody on 2022/12/18.
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

class ListNode {
    var val: Int
    var next: ListNode?
    
    init() {
        self.val = 0
        self.next = nil
    }
    
    init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}

class Solution {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        var addVal: Int = 0
        var startNode: ListNode?
        var curNode: ListNode = ListNode()
        var l1 = l1
        var l2 = l2
        var sum = (l1?.val ?? 0) + (l2?.val ?? 0)
        
        if sum >= 10 {
            sum -= 10
            addVal = 1
        } else {
            addVal = 0
        }
            
        startNode = ListNode(sum)
        curNode = startNode!
        
        while l1?.next != nil && l2?.next != nil {
            l1 = l1!.next
            l2 = l2!.next
            var sum = l1!.val + l2!.val + addVal
            if sum >= 10 {
                sum -= 10
                addVal = 1
            } else {
                addVal = 0
            }
            curNode.next = ListNode(sum)
            curNode = curNode.next!
        }

        while l1?.next != nil {
            l1 = l1!.next
            var sum = l1!.val + addVal
            if sum >= 10 {
                sum -= 10
                addVal = 1
            } else {
                addVal = 0
            }
            
            curNode.next = ListNode(sum)
            curNode = curNode.next!
        }

        while l2?.next != nil {
            l2 = l2!.next
            var sum = l2!.val + addVal
            if sum >= 10 {
                sum -= 10
                addVal = 1
            } else {
                addVal = 0
            }

            curNode.next = ListNode(sum)
            curNode = curNode.next!
        }
        
        if addVal == 1 {
            curNode.next = ListNode(1)
        }

        return startNode
    }
}
