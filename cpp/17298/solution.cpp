#include <iostream>
#include <vector>
#include <stack>
#define ll long long
#define endl "\n"

using namespace std;

int N;

// value, index
vector<pair<int, int>> result;
vector<int> inputs;

void input() {
    cin >> N;

    for(int i=0; i<N; i++) {
        int t;
        cin >> t;
        inputs.push_back(t);
    }
}

void solution() {
    input();

    result = vector<pair<int, int>>(N, {-1, -1});

    stack<int> mainStack;

    for(int i=inputs.size()-1; i>=0; i--) {

        int current = inputs[i];

        if(mainStack.empty()) {

             result[0] = {-1, -1};
        } else {

            int stackTop = mainStack.top();
            int currentIndex = mainStack.size();
            int stackTopIndex = currentIndex-1;
            

            if(stackTop == current) {

                result[currentIndex] = result[stackTopIndex];
            } else if(stackTop > current) {

                result[currentIndex] = {stackTop, stackTopIndex};
            } else {

                // 재귀적 탐색이 필요한 경우
                int tempValue = result[stackTopIndex].first;
                int tempIndex = result[stackTopIndex].second;
                while(true) {
                    
                    if(tempValue == -1) {

                        result[currentIndex] = {-1, -1};
                        break;
                    }
                    else if(tempValue == current) {

                        result[currentIndex] = result[tempIndex];
                        break;
                    } else if(tempValue > current) {

                        result[currentIndex] = {tempValue, tempIndex};
                        break;
                    } else {

                        tempValue = result[tempIndex].first;
                        tempIndex = result[tempIndex].second;
                    }
                }
            }
        }
        mainStack.push(current);
    }

    for(int i=mainStack.size()-1; i>=0; i--) {

        cout << result[i].first << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
