#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
       cout<<"Enter element "<<i+1<<":";
       cin >> a[i];
    }

    for(int i = 1; i < n; i++) {
        int v = a[i];
        int j = i - 1;

        while(j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j = j - 1;
        }

        a[j+1] = v;

        cout << "iteration " << i << ": ";
        for(int k = 0; k < n; k++) {
            cout << a[k] << " ";
        }
        cout << endl;
    }

    cout << "Sorted array:\n";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout<<endl;

    return 0;
}
