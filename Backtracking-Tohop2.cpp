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

void ToHopChapK(int i ){
    for(int val = Arr[i - 1] + 1 ; val <= n - k + i ; val++ ){
            Arr[i] = val ;
            if(i == k) InKQ();
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
    Set();
    return 0;
}
