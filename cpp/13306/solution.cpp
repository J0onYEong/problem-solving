#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define Query pair<int, pair<int, int>>

using namespace std;

const int max_n = 200000+1;

int N, Q;

//연결요소 관계 표기
int node_cc[max_n];

stack<Query> query;

int find_cc(int node) {
    int &ret = node_cc[node];
    if(node == ret)
        return ret;
    return ret = find_cc(ret);
}

void divide_cc_from_parent(int node) {
    node_cc[node] = node;
}

void union_with_parent(int node, int parent) {
    node_cc[find_cc(node)] = find_cc(parent);
}

void input() {
    cin >> N >> Q;

    //연결요소 정보를 저장한다.
    node_cc[1] = 1;
    for(int i=2; i<=N; i++)
        cin >> node_cc[i];

    for(int i=1; i<=(N-1)+Q; i++) {
        int x;
        cin >> x;
        int i1=0;
        int i2=0;
        if(x==0) {
            cin >> i1;
            //미리 다 끊어 버린다.
            //유니온 파인드는 합치는 것에 최적화된 알고리즘이다. 끊는 경우는 의도대로 동작하지 않는다.
            //왜냐하면 각노드가 가리키는 연결요소의 root가 부모 자식이 서로 종속적이지 않기 때문이다.
            //예륻들어 부모가 cc=1 자식도 cc=1일 경우를 생각해보면, 엣지가 끊어져 부모가 cc=2로 바뀔경우 자식은 변경되지 않는다.
            //하지만 현상태는 모든 노드가 자신의 부모노드를 가리기키고 있음으로 위 조작이 모든 노드에 유효하게 전파된다.
            //즉 현상태는 자식은 부모에 종속적인 상태이다.

            //관계를 끊기전 직속 부모를 저장한다.
            i2 = node_cc[i1];
            divide_cc_from_parent(i1);
        }
        if(x==1)
            cin >> i1 >> i2;
        
        //스택에 쿼리데이터를 담는 이유는 역순으로 질의하기 위해서이다.
        //끊어진 트리를 다시 합치면서말이다. 유니온 파인드를 활용하기 위해서이다.
        //진짜 지니어스~
        query.push({x, {i1, i2}});
    }
}

void solution() {
    input();

    stack<string> result;
    while(!query.empty()) {
        Query temp = query.top();
        query.pop();

        //트리를 다시 합친다.
        if(temp.first == 0)
            union_with_parent(temp.second.first, temp.second.second);

        if(temp.first == 1) {
            int cc1 = find_cc(temp.second.first);
            int cc2 = find_cc(temp.second.second);

            if(cc1 == cc2) 
                result.push("YES");
            else
                result.push("NO");
        }
    }

    while(!result.empty()) {
        cout << result.top() << endl;
        result.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
