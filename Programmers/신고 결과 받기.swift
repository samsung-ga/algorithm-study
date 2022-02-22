import Foundation

func solution(_ id_list:[String], _ report:[String], _ k:Int) -> [Int] {
    var reportCount: [String:Int] = [:]
    var reportNote: [String:[String]] = [:]
    report.forEach {
        let sentence = $0.components(separatedBy: .whitespaces)
        let reported = sentence[1]
        let person = sentence[0]
        
        let reports: [String] = reportNote[person] ?? []
        if !reports.contains(reported) {
            reportNote[person] = reports + [reported]
            
            let beforeCount: Int = reportCount[reported] ?? 0
            reportCount[reported] = beforeCount + 1
        }
        
    }
    
    var result: [Int] = []
    let reportedID: [String] = reportCount.filter { $0.value >= k }.map { $0.key }
    id_list.forEach {
        var count: Int = 0
        let ids: [String] = reportNote[$0] ?? []
        
        ids.forEach {
            if reportedID.contains($0) {
                count += 1
            }
        }
        result.append(count)
    }
    
    return result
}
