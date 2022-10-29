//
//  등산코스 정하기.swift
//  Coding_Test_Swift
//
//  Created by Jaeyong Lee on 2022/10/30.
//

// MARK: 풀이 1

import Foundation

struct Node {
    let number: Int
    let intensity: Int
}

func solution(_ n:Int, _ paths:[[Int]], _ gates:[Int], _ summits:[Int]) -> [Int] {

    var graph: [Int: [Int: Int]] = [:]
    var summitsDic: [Int: Bool] = [:]
    var gatesDic: [Int: Bool] = [:]
    var intensities: [Int] = Array.init(repeating: Int.max, count: n+1)

    paths.forEach { path in
        graph[path[0], default: [:]][path[1]] = path[2]
        graph[path[1], default: [:]][path[0]] = path[2]
    }

    for summit in summits {
        summitsDic[summit] = true
    }

    for gate in gates {
        gatesDic[gate] = true
    }

    func bfs() {
        var queue: [Node] = []
        for gate in gates {
            queue.append(.init(number: gate, intensity: 0))
        }

        var index: Int = 0
        while index < queue.count {
            let current = queue[index]
            index += 1

            if let isSummit = summitsDic[current.number], isSummit {
                continue
            }

            if current.intensity > intensities[current.number] {
                continue
            }

            for (nextNumber, nextWeight) in graph[current.number]! {
                let maxIntensity = max(current.intensity, nextWeight)

                if maxIntensity < intensities[nextNumber] {
                    intensities[nextNumber] = maxIntensity
                    queue.append(.init(number: nextNumber, intensity: maxIntensity))
                }
            }
        }
    }

    bfs()

    var result = [0, Int.max]
    for summit in summits {
        if intensities[summit] < result[1] {
            result = [summit, intensities[summit]]
        } else if intensities[summit] == result[1] {
            result[0] = min(summit, result[0])
        }
    }

    return result
}

// MARK: 풀이 2

//import Foundation
//
//struct Heap<T: Comparable> {
//    var tree = [T]()
//    let sort: (T, T) -> Bool
//
//    init(sort: @escaping (T, T) -> Bool) {
//        self.sort = sort
//    }
//
//    var isEmpty: Bool {
//        return tree.isEmpty
//    }
//
//    var count: Int {
//        return tree.count
//    }
//
//    func top() -> T? {
//        return tree.first
//    }
//
//    func leftChildIndex(ofParentAt index: Int) -> Int {
//        return (2 * index) + 1
//    }
//
//    func rightChildIndex(ofParentAt index: Int) -> Int {
//        return (2 * index) + 2
//    }
//
//    func parentIndex(ofChildAt index: Int) -> Int {
//        return (index - 1) / 2
//    }
//
//    mutating func insert(_ element: T) {
//        tree.append(element)
//        moveUp(from: tree.count - 1)
//    }
//
//    mutating func moveUp(from index: Int) {
//        var child = index
//        var parent = parentIndex(ofChildAt: child)
//        while child > 0 && sort(tree[child], tree[parent]) {
//            tree.swapAt(child, parent)
//            child = parent
//            parent = parentIndex(ofChildAt: child)
//        }
//    }
//
//    mutating func pop() -> T? {
//        guard !isEmpty else {
//            return nil
//        }
//
//        tree.swapAt(0, count - 1)
//        defer {
//            moveDown(from: 0)
//        }
//        return tree.removeLast()
//    }
//
//    mutating func moveDown(from index: Int) {
//        var parent = index
//        while true {
//            let left = leftChildIndex(ofParentAt: parent)
//            let right = rightChildIndex(ofParentAt: parent)
//            var popped = parent
//
//            if left < count && sort(tree[left], tree[popped]) {
//                popped = left
//            }
//            if right < count && sort(tree[right], tree[popped]) {
//                popped = right
//            }
//            if popped == parent {
//                return
//            }
//            tree.swapAt(parent, popped)
//            parent = popped
//        }
//    }
//}
//
//struct Node: Comparable {
//    let number: Int
//    let intensity: Int
//
//    static func < (lhs: Node, rhs: Node) -> Bool {
//        return lhs.intensity < rhs.intensity
//    }
//}
//
//func solution(_ n:Int, _ paths:[[Int]], _ gates:[Int], _ summits:[Int]) -> [Int] {
//
//    var graph: [Int: [Int: Int]] = [:]
//    var summitsDic: [Int: Bool] = [:]
//    var gatesDic: [Int: Bool] = [:]
//
//    paths.forEach { path in
//        graph[path[0], default: [:]][path[1]] = path[2]
//        graph[path[1], default: [:]][path[0]] = path[2]
//    }
//
//    for summit in summits {
//        summitsDic[summit] = true
//    }
//
//    for gate in gates {
//        gatesDic[gate] = true
//    }
//
//    var intensities: [Int] = Array.init(repeating: Int.max, count: n+1)
//
//    func dijkstra() {
//        var pq = Heap<Node>(sort: <)
//
//        for gate in gates {
//            pq.insert(.init(number: gate, intensity: 0))
//        }
//
//        while pq.isEmpty == false {
//
//            guard let current = pq.pop() else { return }
//
//            if current.intensity > intensities[current.number] { continue }
//
//            for (nextNumber, nextWeight) in graph[current.number]! {
//
//                let maxIntensity = max(current.intensity, nextWeight)
//
//                if maxIntensity < intensities[nextNumber] {
//                    intensities[nextNumber] = maxIntensity
//                    pq.insert(.init(number: nextNumber, intensity: maxIntensity))
//                }
//            }
//        }
//    }
//
//    dijkstra()
//
//    var result = [0, Int.max]
//    for summit in summits {
//        if intensities[summit] < result[1] {
//            result = [summit, intensities[summit]]
//        } else if intensities[summit] == result[1] {
//            result[0] = min(summit, result[0])
//        }
//    }
//
//    return result
//}
//
