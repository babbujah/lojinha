#include <iomanip>
#include "roupa.h"

Roupa::Roupa() {}

Roupa::Roupa( string codigo, string descricao, short preco, 
	string marca, char sexo, char tamanho ):
	Produto( codigo, descricao, preco ),
    marca( marca ), sexo( sexo ), tamanho( tamanho ) {}

Roupa::~Roupa() {}

std::string 
Roupa::getMarca() {
	return this->marca;
}

string
Roupa::getSexo() {
	string s = "";
    switch( sexo ){
        case 'M':
        case 'm':
            s = "Masculino";
        case 'F':
        case 'f':
            s = "Feminino";
    }

	return s;
}

char
Roupa::getTamanho() {
	return this->tamanho;
}

void 
Roupa::setMarca( string marca ) {
	this->marca = marca;
}

void 
Roupa::setSexo( char sexo ) {
	this->sexo = sexo;
}

void 
Roupa::setTamanho( char tamanho ) {
	this->tamanho = tamanho;
}
 
std::ostream& 
Roupa::print( std::ostream &o ) const {
	o << std::setfill (' ') << std::setw (10) << m_cod_barras << " | " 
		<< std::setfill ('.') << std::setw (20) << m_descricao << " | " 
		<< std::setfill (' ') << std::setw (5) << m_preco << " | "
		<< std::setfill (' ') << std::setw (10) << marca << " | " 
		<< std::setfill (' ') << std::setw (3) << sexo << " | "
        << std::setfill (' ') << std::setw (3) << tamanho;
	return o;
}
