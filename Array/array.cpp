#include <bits/stdc++.h>
using namespace std;

void summation(int size){
    int arr[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    sort(arr, arr + size);
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "min :" << arr[0] << endl;
    cout << "max :" << arr[size - 1] << endl;

    double sum;
    for(int i = 0; i < size; i++){
        sum += arr[i];
    }
    cout << "sum :" << sum << endl;

    double avg = 0;
    avg = sum / size;
    cout << "avg :" << avg;
}

int main(){
    int size = 0;
    cin >> size;
    summation(size);
    return 0;
}