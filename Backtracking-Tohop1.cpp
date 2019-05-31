#include <iostream>
using namespace std;

int Arr[100];
int n, k;

void InToHop(){
    for(int i = 1; i <= n; i++)
        if(Arr[i] == 1)
            cout << i << " ";
    cout << endl;
}

//Ham kiem tra du k phan tu hay khong
bool CheckK(){
    int Dem = 0;
    for(int i = 1; i <= n; i++)
        if(Arr[i] == 1) Dem++;
    if (Dem == k) return true;
    return false;
}

void ToHopChapK(int i){
    for(int val = 0; val <= 1; val++){
        Arr[i] = val;
        if (i == n){
            if (CheckK() == true)
                InToHop();
        }
        else ToHopChapK(i + 1 );
    }
}

int main(){
    cout << "Nhap n va k: ";
    cin >> n >> k;
    if( k >= 0 && k <= n ){
        cout << "\nCac to hop chap k cua n phan tu (1, 2, 3, ..., n)\n";
        ToHopChapK(1) ;
    }
    else
        cout << "Khong thoa dieu khien!"<< endl ;
    return 0;
}
