#include <iostream>

using namespace std;

int main()
{
    int horaInicial, minutoInicial, horaFinal, minutoFinal, duracaoHora, duracaoMinuto;

    cout << "Digite a hora inicial do jogo: ";
    cin >> horaInicial;
    cout << "Digite o minuto inicial do jogo: ";
    cin >> minutoInicial;
    cout << "Digite a hora final do jogo: ";
    cin >> horaFinal;
    cout << "Digite o minuto final do jogo: ";
    cin >> minutoFinal;

    int duracaoTotalEmMinutos = (horaFinal * 60 + minutoFinal) - (horaInicial * 60 + minutoInicial);

    if (duracaoTotalEmMinutos <= 0) {
        duracaoTotalEmMinutos += 24 * 60;
    }

    duracaoHora = duracaoTotalEmMinutos / 60;
    duracaoMinuto = duracaoTotalEmMinutos % 60;

    cout << "O JOGO DUROU " << duracaoHora << " HORA(S) E " << duracaoMinuto << " MINUTO(S)" << endl;

    return 0;
}