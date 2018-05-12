#ifndef ROUPA_H
#define ROUPA_H

#include "produto.h"

using std::string;

class Roupa : public Produto{
    public:
        Roupa();
        Roupa( int tag, string codigoBarra, string descricao, short preco, 
                string marca, string sexo, string tamanho );
        ~Roupa();

    private:
        string marca;
        string sexo;
        string tamanho;
        
    public:
        // getters
        string getMarca();
        string getSexo();
        string getTamanho();

        // setters
        void setMarca( string marca );
        void setSexo( string sexo );
        void setTamanho( string tamanho );

    private:
        std::ostream& print( std::ostream &o ) const;
};

#endif