import Foundation

let direction: [(Int,Int)] = [(1,0),(-1,0),(0,1),(0,-1)] // 아래, 위, 오른쪽, 왼쪽
var visited: [[Bool]] = []

func check(_ row: Int, _ column: Int, _ ocean: [[Int]]) {
    visited[row][column] = true
    if ocean[row][column] <= 0 {
        return
    }
    for dir in direction {
        let nextDirection = (row+dir.0, column+dir.1)
        if nextDirection.0 < 0 || nextDirection.0 >= ocean.count { continue }
        if nextDirection.1 < 0 || nextDirection.1 >= ocean[0].count { continue }
        
        if ocean[nextDirection.0][nextDirection.1] > 0 &&
            visited[nextDirection.0][nextDirection.1] == false {
            
            check(nextDirection.0, nextDirection.1, ocean)
        }
    }
}

func searchAround(_ row: Int, _ column: Int, ocean: [[Int]])  -> Int {
    var oceanNumber: Int = 0
    
    for dir in direction {
        let nextDirection = (row+dir.0, column+dir.1)
        if nextDirection.0 < 0 || nextDirection.0 >= ocean.count { continue }
        if nextDirection.1 < 0 || nextDirection.1 >= ocean[0].count { continue }
        
        if ocean[nextDirection.0][nextDirection.1] <= 0 {
            oceanNumber += 1
        }
    }
    
    return oceanNumber
}

if let nm = readLine()?.components(separatedBy: .whitespaces),
   let n = Int(nm[0]),
   let m = Int(nm[1]) {
    
    var ocean: [[Int]] = []
    for _ in 0..<n {
        if let row = readLine()?.components(separatedBy: .whitespaces) {
            let r = row.map { Int($0)! }
            ocean.append(r)
        }
    }
    
    var year: Int = 0
    var oceanCopy: [[Int]] = ocean
    while true {
        var ices: Int = 0
        year += 1
        for row in 0..<n {
            for column in 0..<m {
                if ocean[row][column] > 0 {
                    let meltIce: Int = searchAround(row, column, ocean: oceanCopy)
                    ocean[row][column] -= meltIce
                }
            }
        }
        oceanCopy = ocean
        
        var allZero: Bool = true
        for row in ocean {
            for column in row {
                if column > 1 {
                    allZero = false
                    break
                }
            }
            if allZero == false {
                break
            }
        }
        
        if allZero {
            print("0")
            break
        } else {
            visited = []
            for _ in 0..<n {
                visited.append(Array.init(repeating: false, count: m))
            }
            for row in 0..<n {
                for column in 0..<m {
                    if visited[row][column] == false && ocean[row][column] > 0 {
                        check(row, column, ocean)
                        ices += 1
                        if ices > 1 {
                            break
                        }
                    }
                }
                if ices > 1 {
                    break
                }
            }
            if ices > 1 {
                print(year)
                break
            }
        }
    }
    
    
    
}
