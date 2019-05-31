#include <iostream>
using namespace std;

void InTapCon(int* Arr, int n){
    for(int i = 1; i <= n; i++)
        if(Arr[i] == 1)
            cout << i << " ";
    cout << endl;
}

void LietKeTapCon(int* Arr, int n, int k){
    for(int val = 0; val <= 1; val++){
        Arr[k] = val;
        if (k == n) InTapCon(Arr, n);
        else LietKeTapCon(Arr, n, k+1);
    }
}

int main(){
    int Arr[100];
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << "\nTat ca tap con cua tap {1, 2, 3,..., n} la:\n";
    LietKeTapCon(Arr, n, 1);
    return 0;
}
