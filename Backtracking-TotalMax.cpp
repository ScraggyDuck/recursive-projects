//Tim tich lon nhat cua cac chuoi con trong mang cac phan tu so nguyen

#include <iostream>
using namespace std;

void NhapMang(int* Arr, int n){
	for (int i = 0; i < n; i++)
		cin >> Arr[i];
}

void Check(int* Arr, int* D, int &Max, int n){
    float S = 1;
    for(int i = 0; i < n; i++)
        if (D[i] == 1)
            S *= Arr[i];
    if (S > Max) Max = S;
}

//void SetCheck(bool* Check, int n){
//    for(int i = 0; i < n ; i++)
//        Check[i] = false;
//}

void TichMax(int* Arr, int* D, int &Max, int n, int i){
    if (i == n)
        Check(Arr, D, Max, n);
    else{
        for(int val = 0; val <= 1; val++){
                D[i] = val;
                TichMax(Arr, D, Max, n, i + 1);
            }
    }
}

int main(){
    int Arr[100];
    int D[100];
    int n;
    int Max;
    cin >> n;
    Max = INT_MIN;
    NhapMang(Arr, n);
//    SetCheck(Check, n);
    TichMax(Arr, D, Max, n, 0);
    cout << "Tich max: " << Max << endl;
    return 0;
}
