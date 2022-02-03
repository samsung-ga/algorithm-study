import Foundation

var direction: [(Int,Int)] = [(-1,0),(0,1),(1,0),(0,-1)] // 위, 오른쪽, 아래, 왼쪽
func dfs(_ places: [[String]], _ xy: (Int,Int), _ count: Int, _ from: (Int, Int)) -> Bool {
    if count == 2 {
        if places[xy.0][xy.1] == "P" {
            return false
        } else {
            return true
        }
    }
    for dir in direction {
        let nextDirection: (Int,Int) = (xy.0 + dir.0, xy.1 + dir.1)
        if nextDirection.0 == from.0 && nextDirection.1 == from.1 { continue } // 이전에 찾은 곳
        if nextDirection.0 < 0 || nextDirection.0 >= 5 { continue } // 범위 밖
        if nextDirection.1 < 0 || nextDirection.1 >= 5 { continue } // 범위 밖
        if places[nextDirection.0][nextDirection.1] == "X" { continue } // 가림막
        if places[nextDirection.0][nextDirection.1] == "P" { return false }
        if places[nextDirection.0][nextDirection.1] == "O" {
            if dfs(places, nextDirection, count+1, (xy.0, xy.1)) == false {
                return false
            } else {
                continue
            }
        }
    }
    return true
}

func solution(_ places:[[String]]) -> [Int] {
    var result = [Int]()
    places.forEach {
        var places: [[String]] = []
        for oneLine in $0 {
            let arr = oneLine.map { String($0) }
            places.append(arr)
        }
        
        print(places)
        var flag = 0
        
        for (xIndex, x) in places.enumerated() {
            for (yIndex, y) in x.enumerated() {
                if y == "P" {
                    print(xIndex,yIndex)
                    if dfs(places, (xIndex,yIndex), 0, (0,0)) == false {
                        flag = 1
                        break
                    }
                }
            }
            if flag == 1 {
                break
            }
        }

        if flag == 0 {
            result.append(1)
        } else {
            result.append(0)
        }
    }
    return result
}
