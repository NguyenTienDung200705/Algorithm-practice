#include <bits/stdc++.h>
using namespace std;

void thaphanoi(int n, char A, char B, char C){
    if(n==1){
        cout << "chuyen dia 1 tu " << A << " sang " << C << endl;
        return;
    }
    thaphanoi(n-1,A,C,B);
    cout << "chuyen dia " << n << " tu " << A << " sang " << C;
    thaphanoi(n-1,B,A,C);
}
int main(){
    int n=3;
    cout << "Cac buoc chuyen voi n = " << n << ":\n";
    thaphanoi(n, 'A', 'B', 'C');
    return 0;
}