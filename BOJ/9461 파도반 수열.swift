import Foundation

if let testcase = readLine(),
   var testcase = Int(testcase) {
  var dp = [Int](repeating: 0, count: 101)
  dp[1] = 1
  dp[2] = 1
  dp[3] = 1
  dp[4] = 2
  dp[5] = 2
  for num in 6...100 {
    dp[num] = dp[num-1] + dp[num-5]
  }
  while testcase > 0 {
    testcase -= 1
    if let n = readLine(),
       let n = Int(n) {
      print(dp[n])
    }
  }
}
