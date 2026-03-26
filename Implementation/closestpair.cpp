#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cout << "enter number of points:";
    if (!(cin >> n)) return 0;
    if (n <= 0) return 0;

    // allocate n x 2 array
    int (*arr)[2] = new int[n][2];
    for (int i = 0; i < n; ++i) {
        cout << "enter point:" << i << ":";
        for (int j = 0; j < 2; ++j) cin >> arr[i][j];
    }

    int x1, y1, x2, y2;
    double d = 99999; // large initial value
    int res[2][2] = {{0,0},{0,0}};

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            x1 = arr[i][0];
            y1 = arr[i][1];
            x2 = arr[j][0];
            y2 = arr[j][1];

            double dx = double(x2 - x1);
            double dy = double(y2 - y1);
            double d1 = sqrt(dx*dx + dy*dy);
            if (d1 < d) {
                d = d1;
                res[0][0] = arr[i][0];
                res[0][1] = arr[i][1];
                res[1][0] = arr[j][0];
                res[1][1] = arr[j][1];
            }
        }
    }

    cout << "closest pair is" << '\n';
    for (int i = 0; i < 2; ++i) {
        cout << i << ")(" << res[i][0] << "," << res[i][1] << ")" << '\n';
    }
    // print distance with 3 decimal places using only <iostream> and <cmath>
    long long r = llround(d * 1000.0);
    long long ip = r / 1000;
    int frac = (int)(r % 1000);
    if (frac < 0) frac = -frac;
    cout << "Closest pair distance: " << ip << '.';
    if (frac < 100) cout << '0';
    if (frac < 10) cout << '0';
    cout << frac << '\n';

    delete[] arr;
    return 0;
}
