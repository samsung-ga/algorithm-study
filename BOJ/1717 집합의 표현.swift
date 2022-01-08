import Foundation

struct UnionFind<T: Hashable> {
  private var index = [T: Int]()
  private var parent = [Int]()
  private var size = [Int]()
  
  mutating func addSetWith(_ element: T) {
    index[element] = parent.count
    parent.append(parent.count)
    size.append(1)
  }
  
  mutating func setOf(_ element: T) -> Int? {
    if let indexOfElement = index[element] {
      return setByIndex(indexOfElement)
    } else {
      return nil
    }
  }
  
  mutating func setByIndex(_ index: Int) -> Int {
    if parent[index] == index {
      return index
    } else {
      parent[index] = setByIndex(parent[index])
      return parent[index]
    }
  }
  
  mutating func inSameSet(_ firstElement: T, and secondElement: T) -> Bool {
    if let firstSet = setOf(firstElement), let secondSet = setOf(secondElement) {
      return firstSet == secondSet
    } else {
      return false
    }
  }
  
  mutating func unionSetsContaining(parent firstElement: T, child secondElement: T) {
    if let firstSet = setOf(firstElement), let secondSet = setOf(secondElement) {
      if firstSet != secondSet {
        parent[secondSet] = firstSet
        size[firstSet] += size[secondSet]
      }
    }
  }
}

if let nm = readLine()?.components(separatedBy: .whitespaces),
   let n = Int(nm[0]),
   var m = Int(nm[1]) {
  
  var db = UnionFind<Int>()
  for i in 0...n {
    db.addSetWith(i)
  }
  while (m > 0) {
    m -= 1
    if let command = readLine()?.components(separatedBy: .whitespaces),
       let type = Int(command[0]),
       let a = Int(command[1]),
       let b = Int(command[2]) {
      
      if type == 0 {
        db.unionSetsContaining(parent: a, child: b)
      } else {
        if db.inSameSet(a, and: b) {
          print("YES")
        } else {
          print("NO")
        }
      }
    }
  }
}
