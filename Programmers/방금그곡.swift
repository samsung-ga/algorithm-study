//
//  방금그곡.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/10.
//

import Foundation

func getMusicTime(startTime: String, endTime: String) -> Int{
    let startArray = startTime.split(separator: ":").map{Int($0)!}
    let endArray = endTime.split(separator: ":").map{Int($0)!}

    let (shour, smin) = (startArray[0], startArray[1])
    let (ehour, emin) = (endArray[0], endArray[1])

    return (ehour - shour) * 60 + emin - smin
}

func solution(_ m:String, _ musicinfos:[String]) -> String {
    let m = m.replacingOccurrences(of: "C#", with: "c")
        .replacingOccurrences(of: "D#", with: "d")
        .replacingOccurrences(of: "F#", with: "f")
        .replacingOccurrences(of: "G#", with: "g")
        .replacingOccurrences(of: "A#", with: "a")

    var musics: [(String, Int)] = []
    for musicinfo in musicinfos {
        let musicinfoArray = musicinfo.split(separator: ",")
        let (stime, etime, musicname) = (musicinfoArray[0], musicinfoArray[1], musicinfoArray[2])
        let musicmelody = musicinfoArray[3].replacingOccurrences(of: "C#", with: "c")
            .replacingOccurrences(of: "D#", with: "d")
            .replacingOccurrences(of: "F#", with: "f")
            .replacingOccurrences(of: "G#", with: "g")
            .replacingOccurrences(of: "A#", with: "a")
            .map{String($0)}

        let minute = getMusicTime(startTime: String(stime), endTime: String(etime))

        var totalMelody: String = ""
        for index in 0..<minute {
            let index = index % musicmelody.count
            totalMelody += musicmelody[index]
        }

        if totalMelody.contains(m) {
            musics.append((String(musicname), minute))
        }
    }
    let result = musics.max { first, second in
        return first.1 < second.1
    }

    return result?.0 ?? "(None)"
}

