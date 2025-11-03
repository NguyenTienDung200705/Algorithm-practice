#include <bits/stdc++.h>
using namespace std;

int UCLN(int a, int b){
    if (b == 0){
        return a;
    }else{
        return UCLN(b,a % b);
    }
}
int main(){
    int a, b;
    cout << "nhap a : " ;
    cin >> a;
    cout << "nhap b : " ;
    cin >> b;
    cout << "UCLN cua a va b : " << UCLN(a,b);
    return 0;
}