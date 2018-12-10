#include "SistemaLinear.h"
#include <cmath>
using namespace std;

void trocarLinhas(float A[][3], float b[], int j, int k){
    float t;
    int i;

    for( i=k; i<3; i++ ){
        t = A[j][i];
        A[j][i] = A[k][i];
        A[k][i] = t;
    }

    t = b[j];
    b[j] = b[k];
    b[k] = t;
}

void pivotacao(float A[][3], float b[], int k){
    int i, j;
    float m;

    j = k;
    m = abs( A[k][k] );
    for( i=k+1; i<3; i++){
        if( abs( A[i][k] ) > m  ){
            m = abs( A[i][k] );
            j = i;
        }
    }

    if( j != k )
        trocarLinhas(A, b, j, k);
}

void eliminacao(float A[][3], float b[]){
    int i, j, k;
    float m;

    for( k=0; k<3; k++ ){
        pivotacao(A, b, k);
        for( i=k+1; i<3; i++){
            m = -A[i][k]/A[k][k];
            A[i][k] = 0;
            for( j=k+1; j<3; j++)
                A[i][j] = A[i][j] + m*A[k][j];
            b[i] = b[i] + m*b[k];
        }
    }
}

float *resolverSistema(float A[][3], float b[]){
    float s;
    int i, j;

    float* u = new float[3];
    u[2] = b[2]/A[2][2];
    for( i=1; i>-1; i-- ){
        s = 0;
        for( j=i+1; j<3; j++)
            s = s + A[i][j]*u[j];
        u[i] = ( b[i] -s )/A[i][i];
    }

    return u;
}

float *gauss(float A[][3], float b[]){
    eliminacao(A, b);

    return resolverSistema(A, b);
}
