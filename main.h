#pragma once
void printFeedback(int chute, const int NUMERO_SECRETO);
void printGameOver(int tentativas, double pontos, bool acertou);
int generateRandomSecretNumber();
double pontosPerdidos(int chute, const int NUMERO_SECRETO);
bool isMatch(int chute, const int NUMERO_SECRETO);
int getTentativasMaximas(char dificuldade);
bool tentativasMaximasAtingidas(int tentativas, int tentativasMaximas);
int lerDificuldade();