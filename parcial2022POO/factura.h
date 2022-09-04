#ifndef FACTURA_H
#define FACTURA_H

class Factura {
private:
    char* nombre;
    float montoxmes;
    float montoxtiempo;
    float montoxgiga;
public:
    Factura();
    Factura(char*, float, float, float);
    float virtual calcular() = 0;
    char* getnombre() const;
    void setNombre(char *Nombre);
    float getmontoxmes() const;
    void setMontoxmes(float Montoxmes);
    float getmontoxtiempo() const;
    void setMontoxtiempo(float Montoxtiempo);
    float getmontoxgiga() const;
    void setMontoxgiga(float Montoxgiga);
    int getcantHoras() const;
    int getcantGigas() const;
};

#endif // FACTURA_H
