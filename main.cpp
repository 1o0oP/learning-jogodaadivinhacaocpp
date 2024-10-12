#include <iostream>
#include "main.h"

using namespace std;

int main()
{
    cout << "***************************" << endl;
    cout << "*** Jogo da Adivinhação ***" << endl;
    cout << "***************************" << endl;

    const int NUMERO_SECRETO = 42;

    cout << "O número secreto é " << NUMERO_SECRETO << endl;

    int chute;
    cout << "Digite o seu chute: ";
    cin >> chute;

    cout << "O valor do seu chute é: " << chute << endl;

    printFeedback(chute, NUMERO_SECRETO);

    return 0;
}

void printFeedback(int chute, const int NUMERO_SECRETO)
{
    bool acertou = chute == NUMERO_SECRETO;

    if (acertou)
    {
        cout << "Parabéns! Você acertou o número secreto!" << endl;
    }
    else if (chute > NUMERO_SECRETO)
    {
        cout << "Seu chute foi maior que o número secreto!" << endl;
    }
    else
    {
        cout << "Seu chute foi menor que o número secreto!" << endl;
    }
}
