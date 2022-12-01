//
//  특정한 최단 경로.swift
//  Coding_Test_Swift
//
//  Created by Jaeyong Lee on 2022/12/01.
//

import Foundation

public struct Heap<T> {

  /** The array that stores the heap's nodes. */
  var nodes = [T]()

  /**
   * Determines how to compare two nodes in the heap.
   * Use '>' for a max-heap or '<' for a min-heap,
   * or provide a comparing method if the heap is made
   * of custom elements, for example tuples.
   */
  private var orderCriteria: (T, T) -> Bool

  /**
   * Creates an empty heap.
   * The sort function determines whether this is a min-heap or max-heap.
   * For comparable data types, > makes a max-heap, < makes a min-heap.
   */
  public init(sort: @escaping (T, T) -> Bool) {
    self.orderCriteria = sort
  }

  /**
   * Creates a heap from an array. The order of the array does not matter;
   * the elements are inserted into the heap in the order determined by the
   * sort function. For comparable data types, '>' makes a max-heap,
   * '<' makes a min-heap.
   */
  public init(array: [T], sort: @escaping (T, T) -> Bool) {
    self.orderCriteria = sort
    configureHeap(from: array)
  }

  /**
   * Configures the max-heap or min-heap from an array, in a bottom-up manner.
   * Performance: This runs pretty much in O(n).
   */
  private mutating func configureHeap(from array: [T]) {
    nodes = array
    for i in stride(from: (nodes.count/2-1), through: 0, by: -1) {
      shiftDown(i)
    }
  }

  public var isEmpty: Bool {
    return nodes.isEmpty
  }

  public var count: Int {
    return nodes.count
  }

  /**
   * Returns the index of the parent of the element at index i.
   * The element at index 0 is the root of the tree and has no parent.
   */
  @inline(__always) internal func parentIndex(ofIndex i: Int) -> Int {
    return (i - 1) / 2
  }

  /**
   * Returns the index of the left child of the element at index i.
   * Note that this index can be greater than the heap size, in which case
   * there is no left child.
   */
  @inline(__always) internal func leftChildIndex(ofIndex i: Int) -> Int {
    return 2*i + 1
  }

  /**
   * Returns the index of the right child of the element at index i.
   * Note that this index can be greater than the heap size, in which case
   * there is no right child.
   */
  @inline(__always) internal func rightChildIndex(ofIndex i: Int) -> Int {
    return 2*i + 2
  }

  /**
   * Returns the maximum value in the heap (for a max-heap) or the minimum
   * value (for a min-heap).
   */
  public func peek() -> T? {
    return nodes.first
  }

  /**
   * Adds a new value to the heap. This reorders the heap so that the max-heap
   * or min-heap property still holds. Performance: O(log n).
   */
  public mutating func insert(_ value: T) {
    nodes.append(value)
    shiftUp(nodes.count - 1)
  }

  /**
   * Adds a sequence of values to the heap. This reorders the heap so that
   * the max-heap or min-heap property still holds. Performance: O(log n).
   */
  public mutating func insert<S: Sequence>(_ sequence: S) where S.Iterator.Element == T {
    for value in sequence {
      insert(value)
    }
  }

  /**
   * Allows you to change an element. This reorders the heap so that
   * the max-heap or min-heap property still holds.
   */
  public mutating func replace(index i: Int, value: T) {
    guard i < nodes.count else { return }

    remove(at: i)
    insert(value)
  }

  /**
   * Removes the root node from the heap. For a max-heap, this is the maximum
   * value; for a min-heap it is the minimum value. Performance: O(log n).
   */
  @discardableResult public mutating func remove() -> T? {
    guard !nodes.isEmpty else { return nil }

    if nodes.count == 1 {
      return nodes.removeLast()
    } else {
      // Use the last node to replace the first one, then fix the heap by
      // shifting this new first node into its proper position.
      let value = nodes[0]
      nodes[0] = nodes.removeLast()
      shiftDown(0)
      return value
    }
  }

  /**
   * Removes an arbitrary node from the heap. Performance: O(log n).
   * Note that you need to know the node's index.
   */
  @discardableResult public mutating func remove(at index: Int) -> T? {
    guard index < nodes.count else { return nil }

    let size = nodes.count - 1
    if index != size {
      nodes.swapAt(index, size)
      shiftDown(from: index, until: size)
      shiftUp(index)
    }
    return nodes.removeLast()
  }

  /**
   * Takes a child node and looks at its parents; if a parent is not larger
   * (max-heap) or not smaller (min-heap) than the child, we exchange them.
   */
  internal mutating func shiftUp(_ index: Int) {
    var childIndex = index
    let child = nodes[childIndex]
    var parentIndex = self.parentIndex(ofIndex: childIndex)

    while childIndex > 0 && orderCriteria(child, nodes[parentIndex]) {
      nodes[childIndex] = nodes[parentIndex]
      childIndex = parentIndex
      parentIndex = self.parentIndex(ofIndex: childIndex)
    }

    nodes[childIndex] = child
  }

  /**
   * Looks at a parent node and makes sure it is still larger (max-heap) or
   * smaller (min-heap) than its childeren.
   */
  internal mutating func shiftDown(from index: Int, until endIndex: Int) {
    let leftChildIndex = self.leftChildIndex(ofIndex: index)
    let rightChildIndex = leftChildIndex + 1

    // Figure out which comes first if we order them by the sort function:
    // the parent, the left child, or the right child. If the parent comes
    // first, we're done. If not, that element is out-of-place and we make
    // it "float down" the tree until the heap property is restored.
    var first = index
    if leftChildIndex < endIndex && orderCriteria(nodes[leftChildIndex], nodes[first]) {
      first = leftChildIndex
    }
    if rightChildIndex < endIndex && orderCriteria(nodes[rightChildIndex], nodes[first]) {
      first = rightChildIndex
    }
    if first == index { return }

    nodes.swapAt(index, first)
    shiftDown(from: first, until: endIndex)
  }

  internal mutating func shiftDown(_ index: Int) {
    shiftDown(from: index, until: nodes.count)
  }

}

// MARK: - Searching

extension Heap where T: Equatable {

  /** Get the index of a node in the heap. Performance: O(n). */
  public func index(of node: T) -> Int? {
      return nodes.firstIndex(where: { $0 == node })
  }

  /** Removes the first occurrence of a node from the heap. Performance: O(n). */
  @discardableResult public mutating func remove(node: T) -> T? {
    if let index = index(of: node) {
      return remove(at: index)
    }
    return nil
  }

}


func 입력() -> (Int, Int, [[(Int,Int)]], Int, Int){
    let nm = readLine()!.split(separator: " ").map { Int($0)! }
    let (n,m) = (nm[0],nm[1])

    var graph: [[(Int,Int)]] = Array.init(repeating: [], count: n+1)
    for _ in 0..<m {
        let line = readLine()!.split(separator: " ").map { Int($0)! }
        let (from, to, cost) = (line[0], line[1], line[2])
        graph[from].append((to,cost))
        graph[to].append((from,cost))
    }

    let pass = readLine()!.split(separator: " ").map { Int($0)! }
    let (pass1,pass2) = (pass[0], pass[1])
    return (n,m,graph,pass1,pass2)
}

func dijkstra(n: Int, graph: [[(Int,Int)]], start: Int) -> [Int] {
    var distances: [Int] = Array.init(repeating: Int.max, count: n+1)
    distances[start] = 0
    var heap = Heap.init(array: [(start,0)], sort: <)

    while heap.isEmpty == false {
        let first = heap.remove()!
        let (node, cost) = (first.0, first.1)

        if cost > distances[node] { continue }

        for (nextNode, nextCost) in graph[node] {
            if nextCost + cost < distances[nextNode] {
                distances[nextNode] = nextCost + cost
                heap.insert((nextNode, distances[nextNode]))
            }
        }
    }

    return distances
}

func solution() {
    let (n,_,graph, pass1, pass2) = 입력()

    // 1 -> 2 -> 3 -> n
    // 1 -> 3 -> 2 -> n
    let distancesFrom1 = dijkstra(n: n, graph: graph, start: 1)
    let distancesFromPass1 = dijkstra(n: n, graph: graph, start: pass1)
    let distancesFromPass2 = dijkstra(n: n, graph: graph, start: pass2)

    let firstCase = distancesFrom1[pass1]
    let first2Case = distancesFromPass1[pass2]
    let first3Case = distancesFromPass2[n]

    let secondCase = distancesFrom1[pass2]
    let second2Case = distancesFromPass2[pass1]
    let second3Case = distancesFromPass1[n]


    var firstR = -1
    if firstCase != Int.max, first2Case != Int.max, first3Case != Int.max {
        firstR = firstCase + first2Case + first3Case
    }
    var secondR = -1
    if secondCase != Int.max, second2Case != Int.max, second3Case != Int.max {
        secondR = secondCase + second2Case + second3Case
    }

    if firstR != -1 && secondR != -1 {
        let result = min(firstR, secondR)
        print(result)
    } else if firstR != -1 {
        print(secondR)
    } else if secondR != -1 {
        print(firstR)
    } else {
        print(-1)
    }

}

solution()
