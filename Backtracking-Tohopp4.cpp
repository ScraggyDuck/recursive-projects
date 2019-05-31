#include <iostream>
using namespace std;

int Arr[100] ;
int k , n ;

void InKQ(){
    for(int i = 1 ; i <= k ; i++) {
        cout << Arr[i] << " ";
    }
    cout << endl ;
}

bool CheckSum(){
    int Sum = 0;
    for(int i = 1 ; i <= k ; i++) {
        Sum += Arr[i];
    }
    if(Sum >= 10) return true;
    return false;
}

void ToHopChapK(int i ){
    for(int val = Arr[i - 1] + 1 ; val <= n - k + i ; val++ ){
        Arr[i] = val ;
        if(i == k) {
            if(CheckSum() == true)
                    InKQ();
        }
        else ToHopChapK(i + 1);
    }
}

void Set(){
    if( k >= 0 && k <= n ) {
        Arr[0] = 0;
        ToHopChapK(1) ;
    }
    else
        cout << "Khong thoa dieu khien!"<< endl ;
}


int main(){
    cout << "Nhap k va n: ";
    cin >> k >> n;
    cout << "\nCac to hop chap k cua n phan tu (1, 2, 3, ..., n) co tong >= 10.\n";
    Set();
    return 0;
}
