/* Cho n mon hang, in ra tat cac cac cach mang mon hang sao cho tong khoi luong <= 10 */


#include <iostream>
using namespace std;

void NhapMangKhoiLuong(float* W, int n){
    for (int i = 0; i < n; i++)
        cin >> W[i];
}

void InKQ(int* Arr, float* W, int n){
    for(int i = 0; i < n; i++)
        if(Arr[i] == 1)
            cout << W[i] << " ";
    cout << endl;
}

//Xem tong khoi luong co nho hon 10 khong
bool CheckSum(int* Arr, float* W, int n){
    float Sum = 0;
    for(int i = 0; i < n; i++)
        Sum += Arr[i]*W[i];
    if ( Sum <= 10 ) return true;
    return false;
}

//void SetCheck(bool* Check, int n){
//    for(int i = 0; i < n ; i++)
//        Check[i] = false;
//}

void GiaoHang(int* Arr, float* W, int n, int i){
    if (i == n){
        if(CheckSum(Arr, W, n) == true)
            InKQ(Arr, W, n);
    }
    else{
        for(int val = 0; val <= 1; val++){
                Arr[i] = val;
                GiaoHang(Arr, W, n, i + 1);
            }
    }
}

int main(){
    int Arr[100];
    float W[100];
    int n;
    cin >> n;
    NhapMangKhoiLuong(W, n);
//    SetCheck(Check, n);
    GiaoHang(Arr, W, n, 0);
    return 0;
}
