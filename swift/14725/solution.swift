import Foundation

class Tree {
    var subTree: [String : Tree?]
    
    init(subTree: [String : Tree?]) {
        self.subTree = subTree
    }
    
    func insert(arr: [String], index: Int) {
        if index == arr.count {
            return;
        }
        
        if !subTree.keys.contains(where: { $0 == arr[index] }) {
            subTree[arr[index]] = Tree(subTree: [:])
        }
        
        subTree[arr[index]]!!.insert(arr: arr, index: index+1)
    }
    
    func dfsPrint(_ tree: Tree, _ layer: Int) {
        let keyArr = tree.subTree.keys.sorted()
        
        for key in keyArr {
            for _ in 0..<layer {
                print("--",terminator: "")
            }
            print(key)
            
            dfsPrint(tree.subTree[key]!!, layer+1)
        }
    }
}


let max_n = 1000+1

var antHouse: [Int : [String : [String]]] = [:]

var N = Int(readLine()!)!

let rootTree = Tree(subTree: [:])

for _ in 0..<N {
    if let inputArr = readLine()?.split(separator: " ").map({ String($0)}) {
        rootTree.insert(arr: inputArr, index: 1)
    }
}

rootTree.dfsPrint(rootTree, 0)

