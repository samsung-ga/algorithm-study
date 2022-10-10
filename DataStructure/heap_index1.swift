//
//  heap_index1.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/10/10.
//

import Foundation

struct Heap<T: Comparable> {
    var tree: [T] = []

    init(withData data: T) {
        tree.append(data)
        tree.append(data)
    }

    var isEmpty: Bool {
        return tree.isEmpty
    }

    var count: Int {
        return tree.isEmpty ? 0 : tree.count - 1
    }

    func top() -> T? {
        return tree.isEmpty ? nil : tree[1]
    }

    mutating func insert(_ data: T) {
        // 비었다면 초기화가 필요합니다.
        if tree.isEmpty {
            tree.append(data)
            tree.append(data)
            return
        }

        // 가장 뒤에 노드를 삽입합니다.
        tree.append(data)

        var newNodeIndex = tree.count - 1
        var parentNodeIndex = newNodeIndex / 2
        while tree[parentNodeIndex] < tree[newNodeIndex] {
            tree.swapAt(parentNodeIndex, newNodeIndex)
            newNodeIndex = parentNodeIndex
            parentNodeIndex = newNodeIndex / 2

            // 현재 노드가 루트노드이면 더이상 비교하지 않습니다.
            if newNodeIndex == 1 { break }
        }
    }

    func leftChildIndex(ofParentAt index: Int) -> Int {
        return (2 * index)
    }

    func rightChildIndex(ofParentAt index: Int) -> Int {
        return (2 * index) + 1
    }

    mutating func pop() -> T? {
        guard !tree.isEmpty else { return nil }

        if tree.count == 2 {
            let value = tree[1]
            tree.removeAll()
            return value
        }

        tree.swapAt(1, tree.count - 1)
        let value = tree.removeLast()
        moveDown(from: 1)
        return value
    }

    mutating func moveDown(from index: Int) {
        var parent = index
        while true {
            let left = leftChildIndex(ofParentAt: parent)
            let right = rightChildIndex(ofParentAt: parent)
            var popped = parent

            if left <= count && tree[left] > tree[popped] {
                popped = left
            }
            if right <= count && tree[right] > tree[popped] {
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
