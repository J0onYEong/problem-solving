#include <iostream>
#include <vector>
#define ll long long
#define endl "\n"

using namespace std;

int n, k;
vector<int> list;

void input() {
    cin >> n >> k;

    list = vector<int>(n, 0);

    for(int i=0; i<n; i++) {
        cin >> list[i];
    }
}

bool isEven(int number) {
    return number % 2 == 0;
}


void solution() {
    input();

    int p1 = 0;
    int p2 = 0;

    int evenCount = 0;
    int oddCount = 0;

    if(isEven(list[p1])) {
        evenCount++;
    } else {
        oddCount++;
    }

    int result = evenCount;

    while(p1 < n-1 && p2 < n-1) {

        bool moveP1 = oddCount > k;

        if(moveP1) {
        
            if(isEven(list[p1])) {
                evenCount--;
            } else {
                oddCount--;
            }

            p1++;

        } else {

            p2++;            

            if(isEven(list[p2])) {
                evenCount++;
            } else {
                oddCount++;
            }
        }

        result = max(result, evenCount);
    }

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
