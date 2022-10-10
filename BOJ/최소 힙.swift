//
//  최소 힙.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/10/10.
//

import Foundation

struct Heap<T: Comparable> {
    var tree = [T]()
    let sort: (T, T) -> Bool

    init(sort: @escaping (T, T) -> Bool) {
        self.sort = sort
    }

    var isEmpty: Bool {
        return tree.isEmpty
    }

    var count: Int {
        return tree.count
    }

    func top() -> T? {
        return tree.first
    }

    func leftChildIndex(ofParentAt index: Int) -> Int {
        return (2 * index) + 1
    }

    func rightChildIndex(ofParentAt index: Int) -> Int {
        return (2 * index) + 2
    }

    func parentIndex(ofChildAt index: Int) -> Int {
        return (index - 1) / 2
    }

    mutating func insert(_ element: T) {
        tree.append(element)
        moveUp(from: tree.count - 1)
    }

    mutating func moveUp(from index: Int) {
        var child = index
        var parent = parentIndex(ofChildAt: child)
        while child > 0 && sort(tree[child], tree[parent]) {
            tree.swapAt(child, parent)
            child = parent
            parent = parentIndex(ofChildAt: child)
        }
    }

    mutating func pop() -> T? {
        guard !isEmpty else {
            return nil
        }

        tree.swapAt(0, count - 1)
        defer {
            moveDown(from: 0)
        }
        return tree.removeLast()
    }

    mutating func moveDown(from index: Int) {
        var parent = index
        while true {
            let left = leftChildIndex(ofParentAt: parent)
            let right = rightChildIndex(ofParentAt: parent)
            var popped = parent

            if left < count && sort(tree[left], tree[popped]) {
                popped = left
            }
            if right < count && sort(tree[right], tree[popped]) {
                popped = right
            }
            if popped == parent {
                return
            }
            tree.swapAt(parent, popped)
            parent = popped
        }
    }
}

let n = Int(readLine()!)!
var heap = Heap<Int>(sort: <)
for _ in 0..<n {
    let value =  Int(readLine()!)!
    if value == 0 {
        if let top = heap.pop() {
            print(top)
        } else {
            print("0")
        }
    } else {
        heap.insert(value)
    }
}

