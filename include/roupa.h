#ifndef ROUPA_H
#define ROUPA_H

#include "produto.h"

using std::string;

class Roupa : public Produto{
    public:
        Roupa();
        Roupa( string codigo, string descricao, short preco, 
                string marca, char sexo, char tamanho );
        ~Roupa();

    private:
        string marca;
        char sexo;
        char tamanho;
        
    public:
        // getters
        string getMarca();
        string getSexo();
        char getTamanho();

        // setters
        void setMarca(string marca);
        void setSexo(char sexo);
        void setTamanho(char tamanho);

    private:
        std::ostream& print(std::ostream &o) const;
};

#endif