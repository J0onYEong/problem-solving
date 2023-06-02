#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;
const int MAX = 128;

int N, R;
int matrix[MAX][MAX];
int temp_matrix[MAX][MAX];
void calculation(int x, int y, int size, int k) {
    if(k == 1) {
        for(int i=x; i<x+size; i++)
            for(int j=y; j<y+size; j++) {
                int targetRow = (x+size-1)-(i-x);
                temp_matrix[targetRow][j] = matrix[i][j];
            }
    }
    else if(k==2) {
        for(int i=x; i<x+size; i++)
            for(int j=y; j<y+size; j++) {
                int targetColumn = (y+size-1)-(j-y);
                temp_matrix[i][targetColumn] = matrix[i][j];
            }
    }
    else if(k==3) {
        for(int i=x; i<x+size; i++)
            for(int j=y; j<y+size; j++) {
                int dstX = (j-y)+x;
                int dstY = (size-1)-(i-x)+y;
                temp_matrix[dstX][dstY] = matrix[i][j];
            }
    }
    else if(k==4) {
        for(int i=x; i<x+size; i++)
            for(int j=y; j<y+size; j++) {
                int dstX = (size-1)-(j-y)+x;
                int dstY = (i-x)+y; 
                temp_matrix[dstX][dstY] = matrix[i][j];
            }
    }
    else if(k==5) {
        int total_size = pow(2, N);
        for(int i=0; i<size; i++)
            for(int j=0; j<size; j++) {
                temp_matrix[(total_size)-x-size+i][y+j] = matrix[x+i][y+j];
            }
    }
    else if(k==6) {
        int total_size = pow(2, N);
        for(int i=0; i<size; i++)
            for(int j=0; j<size; j++) {
                temp_matrix[x+i][(total_size)-y-size+j] = matrix[x+i][y+j];
            }
    }
    else if(k==7) {
        int total_size = pow(2, N);
        int temp_size = total_size / size;
        int temp_x = x / size;
        int temp_y = y / size;
        int dstX = (temp_y)*size;
        int dstY = ((temp_size-1)-temp_x)*size;

        for(int i=0; i<size; i++)
            for(int j=0; j<size; j++)
                temp_matrix[dstX+i][dstY+j] = matrix[x+i][y+j];
    }
    else if(k==8) {
        int total_size = pow(2, N);
        int temp_size = total_size / size;
        int temp_x = x / size;
        int temp_y = y / size;
        int dstX = ((temp_size-1)-temp_y)*size;
        int dstY = temp_x*size; 

        for(int i=0; i<size; i++)
            for(int j=0; j<size; j++)
                temp_matrix[dstX+i][dstY+j] = matrix[x+i][y+j];
    }
}

void solution() {
    cin >> N >> R;
    int size = pow(2, N);
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            cin >> matrix[i][j];
    
    for(int i=0; i<R; i++) {
        int k, l;
        cin >> k >> l;

        int temp_size = pow(2, l);

        for(int i=0; i<size; i+=temp_size)
            for(int j=0; j<size; j+=temp_size) {
                calculation(i, j, temp_size, k);
            }

        //temp_matrix -> matrix
        for(int i=0; i<size; i++)
            for(int j=0; j<size; j++)
                matrix[i][j]=temp_matrix[i][j];
    }

    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
