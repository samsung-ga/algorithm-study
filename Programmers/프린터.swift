import Foundation

func solution(_ priorities:[Int], _ location:Int) -> Int {
  var indexArray = [Int]()
  var queue = priorities
  var count:Int = 0
  priorities.forEach { _ in
    indexArray.append(count)
    count += 1
  }
  
  var result = 0
  while(true) {
    let front = queue.first!
    
    let highPriority = queue.filter {
      $0 > front
    }
    if highPriority.isEmpty {
      result += 1
      queue.removeFirst()
      let index = indexArray.removeFirst()
      if index == location {
        break
      }
    } else {
      let item = queue.removeFirst()
      queue.append(item)
      let index = indexArray.removeFirst()
      indexArray.append(index)
      
    }
  }
  
  return result
}
