import Foundation


final class FileIO {
    private let buffer:[UInt8]
    private var index: Int = 0

    init(fileHandle: FileHandle = FileHandle.standardInput) {
        
        buffer = Array(try! fileHandle.readToEnd()!)+[UInt8(0)] // 인덱스 범위 넘어가는 것 방지
    }

    @inline(__always) private func read() -> UInt8 {
        defer { index += 1 }

        return buffer[index]
    }

    @inline(__always) func readInt() -> Int {
        var sum = 0
        var now = read()
        var isPositive = true

        while now == 10
                || now == 32 { now = read() } // 공백과 줄바꿈 무시
        if now == 45 { isPositive.toggle(); now = read() } // 음수 처리
        while now >= 48, now <= 57 {
            sum = sum * 10 + Int(now-48)
            now = read()
        }

        return sum * (isPositive ? 1:-1)
    }

    @inline(__always) func readString() -> String {
        var now = read()

        while now == 10 || now == 32 { now = read() } // 공백과 줄바꿈 무시

        let beginIndex = index-1

        while now != 10,
              now != 32,
              now != 0 { now = read() }

        return String(bytes: Array(buffer[beginIndex..<(index-1)]), encoding: .ascii)!
    }

    @inline(__always) func readByteSequenceWithoutSpaceAndLineFeed() -> [UInt8] {
        var now = read()

        while now == 10 || now == 32 { now = read() } // 공백과 줄바꿈 무시

        let beginIndex = index-1

        while now != 10,
              now != 32,
              now != 0 { now = read() }

        return Array(buffer[beginIndex..<(index-1)])
    }
}

struct Edge {
    
    let start: Int
    let destination: Int
    let weight: Int
}

var edges: [Edge] = []

//let io = FileIO()

// input
let input1 = readLine()!

let input_f = input1.split(separator: " ").map { Int($0)! }

let (n, m) = (input_f[0], input_f[1])

for _ in (0..<m) {
    let input2 = readLine()!
    let input_f = input2.split(separator: " ").map { Int($0)! }
    
    let (a, b, c) = (input_f[0], input_f[1], input_f[2])
    
    edges.append(Edge(start: a, destination: b, weight: c))
}

let inf: Int64 = Int64(2000000000)

var distanceFrom1 = [Int64](repeating: inf, count: n+1)

distanceFrom1[1] = 0

func func1() {
    
    for t in (0..<n) {
        
        for edge in edges {
            
            let start = edge.start
            let destination = edge.destination
            let weight = Int64(edge.weight)
            
            if distanceFrom1[start] != inf, distanceFrom1[destination] > distanceFrom1[start] + weight {
                
                distanceFrom1[destination] = distanceFrom1[start] + weight
                
                if t == n-1 {
                    
                    print(-1)
                    return
                }
                
            }
            
        }
        
    }
    
    for i in (2...n) {
        if distanceFrom1[i] == inf {
            print(-1)
            continue
        }
        
        print(distanceFrom1[i])
    }
}


func1()

