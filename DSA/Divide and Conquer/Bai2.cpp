#include <bits/stdc++.h>
using namespace std;

int tohop(int n, int k){
    if(n <k){
        return 0;
    }else if(k==0 || n==k){
        return 1;
    }else{
        return tohop(n-1, k-1) + tohop(n-1, k);
    }
}
int main(){
    int n,k;
    cout << "nhap gia tri n : ";
    cin >> n;
    cout << "Nhap gia tri k : ";
    cin >> k;
    cout << " Ket qua to hop : " << tohop(n,k);
    return 0; 
}