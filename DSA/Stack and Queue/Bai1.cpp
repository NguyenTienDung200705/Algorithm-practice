/*
Bài 1: Đảo ngược chuỗi

Đề: Nhập vào một chuỗi ký tự, dùng stack để đảo ngược chuỗi đó.

Ví dụ:
Input: "hello"
Output: "olleh"

Gợi ý: + Duyệt từng ký tự, push vào stack.
       + Sau đó pop ra từng phần tử và ghép thành chuỗi đảo ngược.
*/
#include<bits/stdc++.h>
#include<stack>
#include<string>
using namespace std;

string daonguoc(const string& s){
    stack<char> st; //tao stack ky tu
    string reversed = ""; //chuoi kq

    // Dua ki tu vao stack
    for(char c : s){
        st.push(c);
    }
    // pop ra va noi vao chuoi dao nguoc
    while(!st.empty()){
        reversed += st.top(); //lay phan tu tren dinh
        st.pop(); // xoa phan tu dinh
    }
    return reversed;
}
int main(){
    string input;
    cout << "Nhap chuoi : ";
    getline(cin, input);

    string ouput = daonguoc(input);
    cout << "Chuoi sau khi doa nguoc : " << ouput;
}