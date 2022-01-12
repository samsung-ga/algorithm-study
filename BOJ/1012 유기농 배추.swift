import Foundation

var checked = [[Bool]]()
var farm = [[Int]]()
var answer: Int = 0

// 왼쪽 x-1, y
// 오른쪽 x+1, y
// 위 x, y+1
// 아래 x, y-1
func dfs(y: Int, x: Int, maxX: Int, maxY: Int) {

  checked[y][x] = true
  if x-1>=0 && farm[y][x-1] == 1 && checked[y][x-1] == false {
    dfs(y: y, x: x-1, maxX: maxX, maxY: maxY)
  }
  if x+1 < maxX && farm[y][x+1] == 1 && checked[y][x+1] == false {
    dfs(y: y, x: x+1, maxX: maxX, maxY: maxY)
  }
  if y+1 < maxY && farm[y+1][x] == 1 && checked[y+1][x] == false {
    dfs(y: y+1, x: x, maxX: maxX, maxY: maxY)
  }
  if y-1 >= 0 && farm[y-1][x] == 1 && checked[y-1][x] == false {
    dfs(y: y-1, x: x, maxX: maxX, maxY: maxY)
  }
}

if let testCase = readLine(),
   var testCase = Int(testCase) {
  while testCase > 0 {
    testCase -= 1
    
    if let line = readLine()?.components(separatedBy: .whitespaces) {
      if let m = Int(line[0]),
         let n = Int(line[1]),
         let cabbage = Int(line[2]) {
        // 입력부분
        checked = [[Bool]]()
        farm = [[Int]]()
        answer = 0
        for _ in 0..<n {
          var lineFarm = [Int]()
          var lineChecked = [Bool]()
          for _ in 0..<m {
            lineFarm.append(0)
            lineChecked.append(false)
          }
          farm.append(lineFarm)
          checked.append(lineChecked)
        }
        
        for _ in 0..<cabbage {
          if let cabLocation = readLine()?.components(separatedBy: .whitespaces) {
            if let m = Int(cabLocation[0]),
               let n = Int(cabLocation[1]) {
              farm[n][m] = 1
            }
          }
        }
        
        for i in 0..<n { // y
          for j in 0..<m { // x
            if farm[i][j] == 1 && checked[i][j] == false {
              dfs(y: i, x: j, maxX: m, maxY: n)
              answer += 1
            }
          }
        }
        print(answer)
      }
    }
  }
}
