#include <iostream>
#include "main.h"

using namespace std;

int main()
{
    cout << "***************************" << endl;
    cout << "*** Jogo da Adivinhação ***" << endl;
    cout << "***************************" << endl;

    const int NUMERO_SECRETO = generateRandomSecretNumber();
    bool acertou = false;
    int tentativas = 0;
    double pontos = 1000.0;

    while (!acertou)
    {
        int chute;
        cout << "Digite o seu chute: ";
        cin >> chute;

        cout << "O valor do seu chute é: " << chute << endl;
        printFeedback(chute, NUMERO_SECRETO);

        acertou = chute == NUMERO_SECRETO;
        tentativas++;
        pontos -= pontosPerdidos(chute, NUMERO_SECRETO);
    }

    cout << "Fim de jogo!" << endl;
    cout << "Você acertou o número secreto em " << tentativas << " tentativas!" << endl;
    cout << "Sua pontuação foi de " << pontos << " pontos!" << endl;
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

int generateRandomSecretNumber()
{
    int randomNumber = rand() % 100;
    return randomNumber;
}

double pontosPerdidos(int chute, const int NUMERO_SECRETO)
{
    double pontosPerdidos = abs(chute - NUMERO_SECRETO) / 2.0;
    return pontosPerdidos;
}
