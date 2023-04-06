#include <iostream>

using namespace std;

int findSmaller(int* vet, int n) {
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (vet[i] < vet[index]) {
            index = i;
        }
    }
    return index;
}

int main()
{
    int N;
    cin >> N;

    int* vet = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> vet[i];
    }

    int indexSmaller = findSmaller(vet, N);

    cout << "Menor valor: " << vet[indexSmaller] << endl;
    cout << "Posicao: " << indexSmaller << endl;

    delete[] vet;

    return 0;
}
