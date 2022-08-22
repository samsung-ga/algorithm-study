import Foundation

func solution() {
    let s = Array(readLine()!)
    var t = Array(readLine()!)

    while s.count < t.count {
        if t.last! == "A" {
            t.removeLast()
        } else {
            t.removeLast()
            t.reverse()
        }
    }

    s == t ? print(1) : print(0)
}

solution()
