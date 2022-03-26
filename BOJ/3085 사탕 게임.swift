import Foundation

func judgeMax(map: [[String]]) -> Int{
    
    // 행 확인
    var result: Int = 1
    for (i,row) in map.enumerated() {
        var temp: Int = 1
        for (j, _) in row.enumerated() {
            if j+1 >= row.count { continue }
            
            let color = map[i][j]
            if color == map[i][j+1] {
                temp += 1
                result = max(result,temp)
            } else {
                temp = 1
            }
        }
    }
    
    // 열 확인
    for (i,row) in map.enumerated() {
        var temp: Int = 1
        for (j,_) in row.enumerated() {
            if j+1 >= row.count { continue }
            
            let color = map[j][i]
            if color == map[j+1][i] {
                temp += 1
                result = max(result, temp)
            } else {
                temp = 1
            }
        }
    }

    return result
}

let directions: [(Int,Int)] = [(0,1),(1,0),(0,-1),(-1,0)]
func checkCandyCounts(map: [[String]], row: Int, column: Int) -> Int {
    var result: Int = 0
    var changedMap = map

    for direction in directions {
        let nextCandyLocation: (Int,Int) = (row+direction.0, column+direction.1)

        if nextCandyLocation.0 < 0 || nextCandyLocation.0 >= map.count { continue }
        if nextCandyLocation.1 < 0 || nextCandyLocation.1 >= map[0].count { continue }

        if map[nextCandyLocation.0][nextCandyLocation.1] == map[row][column] {
            continue
        } else {
            let temp = map[row][column]
            changedMap[row][column] = changedMap[nextCandyLocation.0][nextCandyLocation.1]
            changedMap[nextCandyLocation.0][nextCandyLocation.1] = temp

            result = max(result, judgeMax(map: changedMap))
            changedMap = map
        }
    }

    return result
}

if let line = readLine(),
   let line = Int(line) {

    var candyMap: [[String]] = []
    for _ in 0..<line {
        if let row = readLine() {
            let temp = row.map { String($0) }
            candyMap.append(temp)
        }
    }

    var result: Int = 0

    for (i,_) in candyMap.enumerated() {
        for (j,_) in candyMap.enumerated() {
            result = max(result, checkCandyCounts(map: candyMap, row: i, column: j))
        }
    }
    print(result)

}

//let testArray: [[String]] = [["Y","C","P","Z","Y"],
//                             ["C","Y","Z","Z","P"],
//                             ["C","C","P","P","P"],
//                             ["Y","C","Y","Z","C"],
//                             ["C","P","P","Z","Z"]]
//print(judgeMax(map: testArray))
