#include "Matriz.h"
#include <iostream>
using namespace std;

float *multiplicarVetorPorMatriz(float A[][4], float *v){
    int i, j;
    float* u = new float[4];

    //cout << v[0];

    for( i=0; i<4; i++ ){
        u[i] = 0;
        for( j=0; j<4; j++ )
            u[i] = u[i] + A[i][j]*v[j];
        //cout << A[i][j] << endl;
    }

    //cout << endl << u[0] << endl;

    return u;
}
