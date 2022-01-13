import Foundation

class Solution {
  func subarrayBitwiseORs(_ arr: [Int]) -> Int {
    var resultofSubarray = Set<Int>()
    for i in 1...arr.count {
      for j in 0..<arr.count {
        var subarray = [Int]()
        if j+i <= arr.count {
          for z in j..<j+i {
            subarray.append(arr[z])
          }
        }
        if !subarray.isEmpty {
          
          var resultORoperation: Int = 0
          subarray.forEach { resultORoperation |= $0 }
          resultofSubarray.insert(resultORoperation)
        }
      }
    }
    print(resultofSubarray)
    return resultofSubarray.count
  }
}

class SolutionDP {
    func subarrayBitwiseORs(_ arr: [Int]) -> Int {
        var result = Set<Int>()
        var keep = Set<Int>()
      
        for i in 0..<arr.count {
            var now = Set<Int>()
            now.insert(arr[i])
            keep.forEach { now.insert(arr[i] | $0)}
            keep = now
            keep.forEach { result.insert($0) }
        }
        
        return result.count
    }
}


print(Solution().subarrayBitwiseORs([1,2,4]))
print(SolutionDP().subarrayBitwiseORs([1,2,4]))
