import Foundation

struct Applicant: Hashable {
    let language: String
    let job: String
    let career: String
    let soulFood: String
}

func solution(_ info:[String], _ query:[String]) -> [Int] {
    var result: [Int] = []
    
    var dict: [Applicant: [Int]] = [:]
    for s in info {
        let infos = s.components(separatedBy: .whitespaces)
        let languages = [infos[0], "-"]
        let jobs = [infos[1], "-"]
        let careers = [infos[2], "-"]
        let soulFoods = [infos[3], "-"]
        let score = Int(infos[4])!
        
        for language in languages {
            for job in jobs {
                for career in careers {
                    for soulFood in soulFoods {
                        let key = Applicant(language: language, job: job, career: career, soulFood: soulFood)
                        if dict.keys.contains(key) {
                            dict[key]?.append(score)
                        } else {
                            dict[key] = [score]
                        }
                    }
                }
            }
        }
    }
    
    for applicant in dict {
        let sorted = applicant.value.sorted()
        dict[applicant.key] = sorted
    }
    
    query.forEach {
        let seperated: [String] = $0.components(separatedBy: " ")
        let language = seperated[0]
        let job = seperated[2]
        let career = seperated[4]
        let soulFood = seperated[6]
        let score = Int(seperated[7])!
        let key = Applicant(language: language, job: job, career: career, soulFood: soulFood)
        if dict.keys.contains(key) {
            // 이진 탐색
            let scores = dict[key]!
            var low = 0
            var high = scores.count
            
            while low < high {
                let mid = (low + high) / 2
                let guess = scores[mid]
                if guess >= score {
                    high = mid
                } else {
                    low = mid + 1
                }
            }
            result.append(scores.count - low)
        } else {
            result.append(0)
        }
    }
    return result
}


print(solution(["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"], ["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"]))
