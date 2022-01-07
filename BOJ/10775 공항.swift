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


if let gateNumber = readLine(),
   let gateNumber = Int(gateNumber),
   let airplaneNumber = readLine(),
   var airplaneNumber = Int(airplaneNumber) {
  var dataStructure = UnionFind<Int>()
  for i in 0...gateNumber {
    dataStructure.addSetWith(i)
  }
  
  var answer = 0
  while (airplaneNumber > 0) {
    airplaneNumber -= 1
    if let g = readLine(),
       let g = Int(g),
       let docking = dataStructure.setOf(g) {
      if docking == 0 { break }
      answer += 1
      dataStructure.unionSetsContaining(parent: docking-1, child: docking)
    }
  }
  print(answer)
  
}
