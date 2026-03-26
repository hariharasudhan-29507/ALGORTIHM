#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left  = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        i = largest;
        while (true) {
            largest = i;
            left = 2 * i + 1;
            right = 2 * i + 2;

            if (left < n && arr[left] > arr[largest])
                largest = left;
            if (right < n && arr[right] > arr[largest])
                largest = right;

            if (largest == i) break;

            temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            i = largest;

        }
    }
}


void heapSort(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0]   = arr[i];
        arr[i]   = temp;

        heapify(arr, n, 0);
    }
}
void printArray(int arr[], int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << (i < n - 1 ? ", " : "");
    cout << " ]\n";
}

int main() {

    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cout<<"Enter element "<<i+1<<":";
        cin>>arr[i];
    }

    cout << "Before sorting: "; printArray(arr, n);
    heapSort(arr, n);
    cout << "After sorting:  "; printArray(arr, n);

    return 0;
}
