//Tinh Fibo theo De Quy va QHD
#include <iostream>
using namespace std;

void SetFibo(int* F, int n){
    for(int i = 0; i <= n; i++)
        F[i] = -1;
}

//int Dem_Naive = 0;
//int Dem_QHD = 0;

int Fibo_Naive(int n){
//    Dem_Naive++;
    if( n == 0)
        return 0;
    if( n == 1)
        return 1;
    return Fibo_Naive(n - 1) + Fibo_Naive(n - 2);
}

int Fibo_QHD(int* F, int n){
//    Dem_QHD++;
    if(F[n] == -1){
        if( n <= 1) F[n] = n;
        else
            F[n] = Fibo_QHD(F, n - 1) + Fibo_QHD(F, n - 2);
    }
    return F[n];
}

int main(){
    int F[100];
    int n;
    cin >> n;
    SetFibo(F, n);
    cout << "Fibo_Naive: " << Fibo_Naive(n) << endl;
    cout << "So lan goi de quy: " << Dem_Naive << endl;
    cout << "\nFibo QHD: " << Fibo_QHD(F, n) << endl;
    cout << "So lan goi QHD: " << Dem_QHD << endl;
    return 0;
}
