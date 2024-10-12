#include <iostream>
#include "main.h"

using namespace std;

int main()
{
    cout << "***************************" << endl;
    cout << "*** Jogo da Adivinhação ***" << endl;
    cout << "***************************" << endl;

    const int NUMERO_SECRETO = 42;
    bool acertou = false;
    int tentativas = 0;

    while (!acertou)
    {
        int chute;
        cout << "Digite o seu chute: ";
        cin >> chute;

        cout << "O valor do seu chute é: " << chute << endl;
        printFeedback(chute, NUMERO_SECRETO);

        acertou = chute == NUMERO_SECRETO;
        tentativas++;
    }

    cout << "Fim de jogo!" << endl;
    cout << "Você acertou o número secreto em " << tentativas << " tentativas!" << endl;
    return 0;
}

void printFeedback(int chute, const int NUMERO_SECRETO)
{
    bool acertou = chute == NUMERO_SECRETO;
    bool maior = chute > NUMERO_SECRETO;

    if (acertou)
    {
        cout << "Parabéns! Você acertou o número secreto!" << endl;
    }
    else if (maior)
    {
        cout << "Seu chute foi maior que o número secreto!" << endl;
    }
    else
    {
        cout << "Seu chute foi menor que o número secreto!" << endl;
    }
}
