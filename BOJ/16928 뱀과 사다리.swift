import Foundation

let nm = readLine()!.split(separator: " ").map { Int(String($0))! }
let (n, m) = (nm[0], nm[1])

var specialLocation: [Int:Int] = [:]
for _ in 0..<(n+m) {
    let fromto = readLine()!.split(separator: " ").map { Int(String($0))! }
    let (from, to) = (fromto[0], fromto[1])
    specialLocation[from] = to
}

var queue: [(Int,Int)] = []
var visitied: [Bool] = Array.init(repeating: false, count: 101)
queue.append((1,0))
visitied[1] = true

while true {
    guard let current = queue.first else { break }
    let currentLocation = current.0
    let currentDiceCount = current.1
    queue.remove(at: 0)
    if currentLocation == 100 {
        print(currentDiceCount)
        break
    }

    for index in 1...6 {
        var nextCur = currentLocation + index

        if let special = specialLocation[nextCur] {
            nextCur = special
        }
        if nextCur <= 100 && visitied[nextCur] == false {
            visitied[nextCur] = true
            queue.append((nextCur, currentDiceCount + 1))
            continue
        }
    }

}
