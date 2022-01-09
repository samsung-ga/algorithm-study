import Foundation

var parents = [Int]()

func findParent(_ element: Int) -> Int{
  if parents[element] == element {
    return element
  } else {
    return findParent(parents[element])
  }
}

func union(_ firstElement: Int, and secondElement: Int) {
  let first = findParent(firstElement)
  let second = findParent(secondElement)
  if first < second {
    parents[second] = first
  } else {
    parents[first] = second
  }
}

if let n = readLine(), var n = Int(n), let m = readLine(), let _ = Int(m) {
  var count = 0
  for i in 0...n {
    parents.append(i)
  }
  while(n > 0) {
    n -= 1
    count += 1
    if let line = readLine()?.components(separatedBy: .whitespaces) {
      line
        .enumerated()
        .map { ($0, Int($1)!) }
        .forEach {
          if $1 == 1 {
            union(count, and: $0+1)
          }
        }
    }
  }
  
  if let cities = readLine()?.components(separatedBy: .whitespaces) {
    let parent = findParent(Int(cities[0])!)
    cities
      .map { Int($0)! }
      .forEach {
        if findParent($0) != parent {
          print("NO")
          exit(0)
        }
      }
    print("YES")
  }
}
