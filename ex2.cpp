#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double X, vet[100];

    cin >> X;

    vet[0] = X;

    for (int i = 1; i < 100; i++) {
        vet[i] = vet[i - 1] / 2.0;
    }

    for (int i = 0; i < 100; i++) {
        cout << "vet[" << i << "] = " << fixed << setprecision(4) << vet[i] << endl;
    }

    return 0;
}
