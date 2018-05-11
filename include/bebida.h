#ifndef BEBIDA_H
#define BEBIDA_H

#include "produto.h"

using std::string;

class Bebida : public Produto{
    public:
        Bebida();
        Bebida( string codigo, string descricao, short preco, 
                short teorAlcoolico );
        ~Bebida();

    private:
        short teorAlcoolico;
        
    public:
        // getters
        string getTeorAlcoolico();

        // setters
        void setTeorAlcoolico(short teorAlcoolico);

    private:
        std::ostream& print(std::ostream &o) const;
};

#endif