#ifndef SISTEMALINEAR_H
#define SISTEMALINEAR_H

float *gauss(float A[][3], float b[]);
float* resolverSistema(float A[][3], float b[]);
void eliminacao(float A[][3], float b[]);
void pivotacao(float A[][3], float b[], int k);
void trocarLinhas(float A[][3], float b[], int j, int k);

#endif // SISTEMALINEAR_H
