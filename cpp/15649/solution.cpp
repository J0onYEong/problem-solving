#include <iostream>
#include <vector>
#define ll long long
#define endl "\n"

using namespace std;

int n, m;

bool checked[9];

void input() {

    cin >> n >> m;
}

vector<int> myStack;

void recursive(int pos) {

    if(pos == m) {
        
        for(int i=0; i<myStack.size(); i++) {

            cout << myStack[i] << " ";
        }
        cout << endl;

        return;
    }

    int start = myStack.empty() ? 1 : myStack.back(); 

    for(int i=start; i<=n; i++) {
        // if(checked[i]) continue;

        checked[i] = true;

        myStack.push_back(i);

        recursive(pos+1);

        checked[i] = false;

        myStack.pop_back();

    }

}

void solution() {
    input();

    recursive(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();

    return 0;
}
