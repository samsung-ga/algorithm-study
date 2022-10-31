//
//  표 편집.swift
//  Coding_Test_Swift
//
//  Created by Jaeyong Lee on 2022/11/01.
//

import Foundation

class Node: Equatable {
    static func == (lhs: Node, rhs: Node) -> Bool {
        return lhs.data == rhs.data
    }

    let data: Int

    var prev: Node?
    var next: Node?

    init(data: Int, prev: Node? = nil, next: Node? = nil) {
        self.data = data
        self.prev = prev
        self.next = next
    }
}

class LinkedList {
    var head: Node?
    var tail: Node?
    var selectedRow: Node?

    func append(_ value: Int) {
        if head == nil || tail == nil {
            head = Node(data: value)
            tail = head
            return
        }

        let newNode = Node(data: value)
        tail?.next = newNode
        newNode.prev = tail
        tail = newNode
    }

    func setSelectedRow(at offset: Int) {
        selectedRow = head
        var offset = offset
        while offset > 0 {
            offset -= 1
            selectedRow = selectedRow?.next
        }
    }

    func setSelectedRowDown(by offset: Int) {
        var offset = offset
        while offset > 0 {
            offset -= 1
            selectedRow = selectedRow?.next
        }
    }

    func setSelectedRowUp(by offset: Int) {
        var offset = offset
        while offset > 0 {
            offset -= 1
            selectedRow = selectedRow?.prev
        }
    }

    func removeSelectedRow() -> Node {
        guard let currentNode = selectedRow else { fatalError() }
        selectedRow?.prev?.next = selectedRow?.next
        selectedRow?.next?.prev = selectedRow?.prev

        if selectedRow == tail {
            tail = selectedRow?.prev
            selectedRow = tail
        } else if selectedRow == head {
            head = selectedRow?.next
            selectedRow = head
        } else {
            selectedRow = selectedRow?.next
        }


        return currentNode
    }

    func resetNode(_ node: Node) {
        node.prev?.next = node
        node.next?.prev = node

        if node.next == nil {
            tail = node
        }

        if node.prev == nil {
            head = node
        }
    }
}

func solution(_ n:Int, _ k:Int, _ cmd:[String]) -> String {

    var table = LinkedList()

    for i in 0..<n {
        table.append(i)
    }

    table.setSelectedRow(at: k)
    var deletedRows: [Node] = []

    for cmd in cmd {
        if cmd == "C" {
            let node = table.removeSelectedRow()
            deletedRows.append(node)
            continue
        }

        if cmd == "Z" {
            guard let lastNode = deletedRows.last else { fatalError() }
            table.resetNode(lastNode)
            deletedRows.removeLast()
            continue
        }

        let cmds = cmd.components(separatedBy: .whitespaces)

        if cmds[0] == "U" {
            let x = Int(cmds[1])!
            table.setSelectedRowUp(by: x)
        } else {
            let x = Int(cmds[1])!
            table.setSelectedRowDown(by: x)
        }
    }

    var result: [String] = Array.init(repeating: "X", count: n)
    var current = table.head

    while current != nil {
        result[current!.data] = "O"
        current = current?.next
    }
    return result.joined()
}
