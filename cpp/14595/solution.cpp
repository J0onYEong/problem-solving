#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int MAX = 1000001;

int N, M;

void solution() {
    cin >> N >> M;  

    vector<pair<int,int> > v;
    for(int i=0; i<M; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    v.push_back(make_pair(1,1));
    v.push_back(make_pair(N,N));
    
    sort(v.begin(), v.end(), less<pair<int,int> >());

    int result = 0;
    int temp = 1;
    for(int i=1; i<v.size(); i++) {
        if(temp < v[i].first) 
            result+=(v[i].first-temp);
        if(temp < v[i].second)
            temp = v[i].second;
    }
    cout << result+1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
