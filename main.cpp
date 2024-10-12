#include <iostream>

using namespace std;

int main()
{
    cout << "***************************" << endl;
    cout << "*** Jogo da Adivinhação ***" << endl;
    cout << "***************************" << endl;

    int numeroSecreto = 42;

    cout << "O número secreto é " << numeroSecreto << endl;

    int chute;
    cout << "Digite o seu chute: ";
    cin >> chute;

    cout << "O valor do seu chute é: " << chute << endl;

    if (chute == numeroSecreto)
    {
        cout << "Parabéns! Você acertou o número secreto!" << endl;
    }
    else
    {
        if (chute > numeroSecreto)
        {
            cout << "Seu chute foi maior que o número secreto!" << endl;
        }
        else
        {
            cout << "Seu chute foi menor que o número secreto!" << endl;
        }
    }

    return 0;
}
