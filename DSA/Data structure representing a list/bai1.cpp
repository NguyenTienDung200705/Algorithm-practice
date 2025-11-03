#include<bits/stdc++.h>
using namespace std;
struct hocsinh{
    string ten;
    string lop;
    string sdt;
    double diemtb;
};
string xeploai(double diem){
    if(diem >= 8){
        return "gioi";
    }else if(diem >= 6.5){
        return "kha";
    }else if(diem >= 5.0){
        return "trung binh";
    }else{
        return "yeu";
    }
}
void nhap(vector<hocsinh>& ds){
    int n;
    cout << "Nhap so hoc sinh : ";
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        hocsinh hs;
        cout << "Hoc sinh thu " << (i+1) << ":\n";
        cout << "Ten : " ;
        getline(cin, hs.ten);
        cout << "Lop : ";
        getline(cin, hs.lop);
        cout << "So dien thoai : ";
        getline(cin, hs.sdt);
        cout << "Diem trung binh : ";
        cin >> hs.diemtb;
        cin.ignore();
        ds.push_back(hs);
    }
}
void docTuFile(vector<hocsinh>& ds, string tenFile) {
    ifstream f(tenFile);
    if (!f) {
        cout << "Khong mo duoc file!\n";
        return;
    }
    hocsinh hs;
    while (f >> ws && getline(f, hs.ten, ';')) {
        getline(f, hs.lop, ';');
        getline(f, hs.sdt, ';');
        f >> hs.diemtb;
        ds.push_back(hs);
    }
    f.close();
}
void inDanhSach(const vector<hocsinh>& ds, bool dayDu) {
    cout << left << setw(20) << "Ten" << setw(10) << "Lop"
         << setw(15) << "Diem TB";
    if (dayDu)
        cout << setw(15) << "SDT";
    cout << setw(15) << "Xep loai" << endl;

    cout << string(65, '-') << endl;

    for (auto& hs : ds) {
        cout << left << setw(20) << hs.ten << setw(10) << hs.lop
             << setw(15) << hs.diemtb;
        if (dayDu)
            cout << setw(15) << hs.sdt;
        cout << setw(15) << xeploai(hs.diemtb) << endl;
    }
}
void timHocSinh(const vector<hocsinh>& ds, string ten, string lop) {
    for (auto& hs : ds) {
        if (hs.ten == ten && hs.lop == lop) {
            cout << "So dien thoai cua " << ten << ": " << hs.sdt << endl;
            return;
        }
    }
    cout << "Khong tim thay hoc sinh " << ten << " trong lop " << lop << endl;
}
void themHocSinh(vector<hocsinh>& ds) {
    hocsinh hs;
    cin.ignore();
    cout << "Nhap ten: "; getline(cin, hs.ten);
    cout << "Nhap lop: "; getline(cin, hs.lop);
    cout << "Nhap so dien thoai: "; getline(cin, hs.sdt);
    cout << "Nhap diem trung binh: "; cin >> hs.diemtb;
    ds.push_back(hs);
}
void xoaLop(vector<hocsinh>& ds, string lop) {
    ds.erase(remove_if(ds.begin(), ds.end(),
                       [&](hocsinh hs) { return hs.lop == lop; }),
             ds.end());
}
void sapXepGiam(vector<hocsinh>& ds) {
    sort(ds.begin(), ds.end(),
         [](hocsinh a, hocsinh b) { return a.diemtb > b.diemtb; });
}
void chenHocSinh(vector<hocsinh>& ds, const hocsinh& hs) {
    auto pos = find_if(ds.begin(), ds.end(),
                       [&](hocsinh x) { return x.diemtb < hs.diemtb; });
    ds.insert(pos, hs);
}
void ghiFile(const vector<hocsinh>& ds, string tenFile) {
    ofstream f(tenFile);
    for (auto& hs : ds)
        f << hs.ten << ';' << hs.lop << ';' << hs.sdt << ';' << hs.diemtb << '\n';
    f.close();
}
int main() {
    vector<hocsinh> ds;
    int chon;
    do {
        cout << "\n=== MENU QUAN LY HOC SINH ===\n";
        cout << "1. Nhap tu ban phim\n";
        cout << "2. Doc tu file\n";
        cout << "3. In danh sach (ten + xep loai)\n";
        cout << "4. In danh sach day du\n";
        cout << "5. Tim hoc sinh theo ten va lop\n";
        cout << "6. Them hoc sinh moi\n";
        cout << "7. Xoa hoc sinh theo lop\n";
        cout << "8. Sap xep giam dan theo diem\n";
        cout << "9. Chen hoc sinh giu nguyen thu tu\n";
        cout << "10. Luu danh sach ra file\n";
        cout << "0. Thoat\nChon: ";
        cin >> chon;

        switch (chon) {
            case 1: nhap(ds); break;
            case 2: { string file; cout << "Nhap ten file: "; cin >> file; docTuFile(ds, file); } break;
            case 3: inDanhSach(ds, false); break;
            case 4: inDanhSach(ds, true); break;
            case 5: { string ten, lop; cin.ignore(); cout << "Nhap ten: "; getline(cin, ten); cout << "Nhap lop: "; getline(cin, lop); timHocSinh(ds, ten, lop); } break;
            case 6: themHocSinh(ds); break;
            case 7: { string lop; cout << "Nhap lop can xoa: "; cin >> lop; xoaLop(ds, lop); } break;
            case 8: sapXepGiam(ds); break;
            case 9: { hocsinh hs; cin.ignore(); cout << "Nhap ten: "; getline(cin, hs.ten); cout << "Nhap lop: "; getline(cin, hs.lop); cout << "Nhap so dien thoai: "; getline(cin, hs.sdt); cout << "Nhap diem trung binh: "; cin >> hs.diemtb; chenHocSinh(ds, hs); } break;
            case 10: { string file; cout << "Nhap ten file: "; cin >> file; ghiFile(ds, file); } break;
        }
    } while (chon != 0);
}