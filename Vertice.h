#ifndef VERTICE_H
#define VERTICE_H


class Vertice
{
public:
    float x, y, z,w;
    Vertice(float x, float y, float z);

    Vertice* somaVetorial(Vertice* v);
    Vertice* diferencaVetorial(Vertice* v);
    float produtoEscalar(Vertice* v);
    Vertice* produtoPorEscalar(float k);
    Vertice* produtoVetorial(Vertice* v);
    Vertice* produtoCorrespondente(Vertice* v);
    float norma();
    void normalizar();

    void transladar(Vertice* t);
    void escalar(Vertice* s);
    void rotacao(Vertice* eixo, float angulo);
    void rotacaoY(float angulo);
};

#endif // VERTICE_H
