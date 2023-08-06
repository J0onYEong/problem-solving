#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int max_n = 4000001;

int N, M, K;

int mutual_card[max_n];

bool selected_card[max_n];

int p1_card_list[max_n];

void input() {
    cin >> N >> M >> K;

    for(int i=1; i<=M; i++)
        cin >> mutual_card[i];

    for(int i=1; i<=K; i++)
        cin >> p1_card_list[i];


}

void solution() {
    input();

    sort(mutual_card+1, mutual_card+M+1);
    memset(selected_card, false, sizeof(selected_card));

    vector<int> result;

    for(int i=1; i<=K; i++) {
        int p1_card = p1_card_list[i];

        int p2_card_index = upper_bound(mutual_card+1, mutual_card+M+1, p1_card) - mutual_card;

        while(selected_card[p2_card_index])  
            p2_card_index++;  

        selected_card[p2_card_index] = true;
        result.push_back(mutual_card[p2_card_index]);
    }

    for(int e : result)
        cout << e << " ";
    cout << endl; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
