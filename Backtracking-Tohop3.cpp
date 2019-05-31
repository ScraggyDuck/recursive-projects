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

bool CheckSum(){
    int Sum = 0;
    for(int i = 1; i <= n; i++)
        if(Arr[i] == 1) Sum += i;
    if (Sum >= 10) return true;
    return false;
}

void ToHopChapK(int i){
    for(int val = 0; val <= 1; val++){
        Arr[i] = val;
        if (i == n){
            if (CheckK() == true)
                if(CheckSum() == true)
                    InToHop();
        }
        else ToHopChapK(i + 1 );
    }
}

int main(){
    cout << "Nhap n va k: ";
    cin >> n >> k;
    if( k >= 0 && k <= n ){
        cout << "\nCac to hop chap k cua n phan tu (1, 2, 3, ..., n) co tong >= 10.\n";
        ToHopChapK(1) ;
    }
    else
        cout << "Khong thoa dieu khien!"<< endl ;
    return 0;
}
