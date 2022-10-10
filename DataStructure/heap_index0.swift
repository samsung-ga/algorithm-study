//
//  heap_index0.swift
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

    func peek() -> T? {
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
            var candidate = parent

            if left < count && sort(tree[left], tree[candidate]) {
                candidate = left
            }
            if right < count && sort(tree[right], tree[candidate]) {
                candidate = right
            }
            if candidate == parent {
                return
            }
            tree.swapAt(parent, candidate)
            parent = candidate
        }
    }
}
