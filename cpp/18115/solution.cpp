#include <bits/stdc++.h>

using namespace std;

void solution() {
    int n;
    cin >> n;
    int* orderList = new int[n];
    int* origin = new int[n];

    for(int i=0; i<n; i++) 
        cin >> orderList[i];

    int topIndex = 0;
    int secondIndex = topIndex+1;
    int bottomIndex = n-1;

    for(int i=0; i<n; i++) {
        int order = orderList[i];
        int card = n-i;
        switch (order)
        {
        case 1:
            origin[topIndex]=card;
            topIndex = secondIndex;
            secondIndex++;
            break;
        case 2:
            origin[secondIndex++]=card;
            break;
        case 3:
            origin[bottomIndex--]=card;
            break;        
        default:
            break;
        }
    }
    for(int i=0; i<n; i++) 
        cout << origin[i] << "\n";
    delete[] orderList;
    delete[] origin;
}

// deque자료구조를 사용한 solution
void solution2() {
    int n;
    cin >> n;
    int* orderList = new int[n];
    for(int i=0; i<n; i++)
        cin >> orderList[i];

    deque<int> origin;
    for(int i=n-1; i>=0; i--) {
        int card = n-i;
        int temp;
        switch (orderList[i])
        {
        case 1:
            origin.push_front(card);
            break;
        case 2:
            temp = origin.front();
            origin.pop_front();
            origin.push_front(card);
            origin.push_front(temp);
            break;
        case 3:
            origin.push_back(card);
            break;
        default:
            break;
        }
    }
    for(int i=0; i<n; i++) 
        cout << origin[i] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution2();
    return 0;
}