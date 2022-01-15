import Foundation

if let string = readLine() {
  let count = string.count

  let a = string.components(separatedBy: "c=").count - 1
  let b = string.components(separatedBy: "c-").count - 1
  let c = string.components(separatedBy: "dz=").count - 1
  let d = string.components(separatedBy: "d-").count - 1
  let e = string.components(separatedBy: "lj").count - 1
  let f = string.components(separatedBy: "nj").count - 1
  let g = string.components(separatedBy: "s=").count - 1
  let h = string.components(separatedBy: "z=").count - 1
  print(count-a-b-c-d-e-f-g-h)
}
