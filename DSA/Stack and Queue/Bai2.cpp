/*
Bài 2: Đổi hệ cơ số
Đề: Viết chương trình đổi một số thập phân sang nhị phân bằng Stack.
Ví dụ: + Input: 10
       + Output: 1010
Gợi ý: + Chia liên tục cho 2, mỗi lần lưu phần dư vào Stack.
       + Pop lần lượt các phần dư để in ra kết quả.
*/

#include<bits/stdc++.h>
#include<stack>
using namespace std;

int doicoso(int n){
    stack<int> st;
    int temp = n;
    while(temp > 0){
        int du = temp % 2;
        st.push(du);
        temp /= 2;
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    return 0;
}
int main(){
    int n;
    cout << "Nhap gia tri n :";
    cin >> n;
    cout << "So nhi phan : ";
    doicoso(n);
    return 0;
}