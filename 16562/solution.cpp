#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define Group vector<int>

using namespace std;

void solution() {
    int n, m, k;
    cin >> n >> m >> k;
    int cost[10000];
    int groupIndex[10000];

    for(int i=0;i<n;i++) {
        cin >> cost[i];
        groupIndex[i] = i;
    }

    int nextIndex = 10001;
    for(int i=0;i<m;i++) {
        int mem1, mem2;
        cin >> mem1 >> mem2;
        if(mem1 == mem2) continue;
        mem1--;
        mem2--;
       int take = groupIndex[mem1];
       int lose = groupIndex[mem2];
       for(int j=0;j<n;j++)
            if(groupIndex[j] == lose) 
                groupIndex[j] = take;
    }

    map<int, Group> groups;
    for(int i=0;i<n;i++) 
        groups[groupIndex[i]].push_back(cost[i]);
    
    map<int, Group>::iterator it;
    int sum = 0;
    for(it=groups.begin();it!=groups.end();it++) {
        Group temp = it->second;
        sort(temp.begin(), temp.end());
        sum += temp.front();   
    }

    if(sum > k) 
        cout << "Oh no" << endl;
    else 
        cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
