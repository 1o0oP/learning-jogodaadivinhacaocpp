#include <iostream>
#include "main.h"

using namespace std;

int main()
{
    cout << "***************************" << endl;
    cout << "*** Jogo da Adivinhação ***" << endl;
    cout << "***************************" << endl;

    cout << "Escolha o seu nível de dificuldade: " << endl;
    cout << "Fácil (F), Médio (M) ou Difícil (D)" << endl;
    char dificuldade;
    cin >> dificuldade;

    const int NUMERO_SECRETO = generateRandomSecretNumber();
    bool acertou = false;
    int tentativas = 0;
    int tentativasMaximas = getTentativasMaximas(dificuldade);
    double pontos = 1000.0;

    for (int i = 1; i < tentativasMaximas; i++)
    {
        int chute;
        cout << "Digite o seu chute: ";
        cin >> chute;

        cout << "O valor do seu chute é: " << chute << endl;
        printFeedback(chute, NUMERO_SECRETO);

        acertou = isMatch(chute, NUMERO_SECRETO);
        tentativas++;
        pontos -= pontosPerdidos(chute, NUMERO_SECRETO);
    }

    printGameOver(tentativas, pontos, acertou);
    return 0;
}

void printGameOver(int tentativas, double pontos, bool acertou)
{
    cout << "Fim de jogo!" << endl;
    if (acertou)
    {
        cout << "Você acertou o número secreto em " << tentativas << " tentativas!" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuação foi de " << pontos << " pontos!" << endl;
    }
    else
    {
        cout << "Você atingiu o limite de tentativas!" << endl;
        cout << "Sua pontuação foi de " << pontos << " pontos!" << endl;
        cout << "Tente novamente!" << endl;
    }
}

void printFeedback(int chute, const int NUMERO_SECRETO)
{
    bool acertou = isMatch(chute, NUMERO_SECRETO);
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

bool isMatch(int chute, const int NUMERO_SECRETO)
{
    return chute == NUMERO_SECRETO;
}

int getTentativasMaximas(char dificuldade)
{
    int tentativasMaximas;
    switch (dificuldade)
    {
        case 'F':
            tentativasMaximas = 15;
            break;
        case 'M':
            tentativasMaximas = 10;
            break;
        case 'D':
            tentativasMaximas = 5;
            break;
        default:
            throw "Dificuldade inválida!";
    }
    return tentativasMaximas;
}

bool tentativasMaximasAtingidas(int tentativas, int tentativasMaximas)
{
    return tentativas >= tentativasMaximas;
}
