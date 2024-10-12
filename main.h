#pragma once
void printFeedback(int chute, const int NUMERO_SECRETO);
void printGameOver(int tentativas, double pontos);
int generateRandomSecretNumber();
double pontosPerdidos(int chute, const int NUMERO_SECRETO);
bool isMatch(int chute, const int NUMERO_SECRETO);