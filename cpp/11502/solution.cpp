#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

void eratosthenesSieve(bool numbers[], int last_number) {
		// 우선 0과 1은 소수가 아님을 명시한다.
		numbers[0] = false;
		numbers[1] = false;
		// 길이가 3보다 짧을 경우 코드를 진행할 이유가 없다.
		if(last_number < 3)
        return;
    for(int i=2; i<sqrt(last_number); i++) {
        if(numbers[i] == true) {
            for(int j = i*2; j<=last_number; j+=i) {
                numbers[j] = false;
            }
        }
    }
}

void solution() {
    int t;
    cin >> t;
    bool numbers[1001];
    for(int i=0; i<1001; i++)
        numbers[i] = true;
    eratosthenesSieve(numbers, 1000);
    vector<int> dem;
    for(int i=2; i<1001; i++)
        if(numbers[i])
            dem.push_back(i);

    for(int ti=0; ti<t; ti++) {
        int c;
        cin >> c;
        vector<int> part;
        bool fin = false;
        for(int i=0;i<dem.size();i++) {
            int t1 = c - dem[i];
            part.push_back(dem[i]);
            for(int j=0;j<dem.size();j++) {
                int t2 = t1 - dem[j];
                part.push_back(dem[j]);
                for(int k=0; k<dem.size();k++) {
                    int t3 = t2 - dem[k];
                    part.push_back(dem[k]);
                    if(t3 == 0) {
                        fin = true;   
                        break;
                    }
                    part.pop_back();
                }
                if(fin) break;
                part.pop_back();
            }
            if(fin) break;
            part.pop_back();
        }
        for(int b=0; b<3; b++) 
            cout << part[b] << " ";
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
