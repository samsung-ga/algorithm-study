import Foundation

struct SpinningQueue {
  var list = [Int]()
  
  var count: Int { self.list.count }
  
  func isEmpty() -> Bool {
    return list.isEmpty
  }
  
  func firstItem() -> Int {
    return list[0]
  }
  
  func lastItem() -> Int {
    return list.last!
  }
  
  func getLocation(of number: Int) -> Int? {
    return list.firstIndex(of: number)
  }
  
  mutating func popFirst() -> Int? {
    if isEmpty() {
      return nil
    } else {
      let first = list[0]
      self.list.remove(at: 0)
      return first
    }
  }
  
  mutating func popLast() -> Int? {
    return self.list.popLast()
  }
  
  mutating func secondCommand() {
    if let first = popFirst() {
      list.append(first)
    }
  }
  
  mutating func thirdCommand() {
    if let last = popLast() {
      list.insert(last, at: 0)
    }
  }
}

if let line = readLine()?.components(separatedBy: .whitespaces),
   let n = Int(line[0]),
   let m = Int(line[1]) {
  var db = SpinningQueue()
  for i in 1...n {
    db.list.append(i)
  }
  var secondCommandCount: Int = 0
  var thirdCommandCount: Int = 0
  if let numbers = readLine()?.components(separatedBy: .whitespaces) {
    for i in 0..<m {
      
      if let num = Int(numbers[i]) {
        // 여기서 num 은 숫자 위치입니다.
        if num == db.firstItem() {
          _ = db.popFirst()
        } else if db.getLocation(of: num)! <= (db.count / 2) {
          while num != db.firstItem() {
            db.secondCommand()
            secondCommandCount += 1
          }
          _ = db.popFirst()
        } else {
          while num != db.lastItem() {
            db.thirdCommand()
            thirdCommandCount += 1
          }
          db.thirdCommand()
          thirdCommandCount += 1
          _ = db.popFirst()
        }
      }
    }
  }
  print(secondCommandCount + thirdCommandCount)
}
