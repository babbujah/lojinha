#include <iomanip>
#include "roupa.h"

Roupa::Roupa() {}

Roupa::Roupa( int tag, string codigoBarra, string descricao, short preco, 
	string marca, string sexo, string tamanho ):
	Produto( tag, codigoBarra, descricao, preco ),
    marca( marca ), sexo( sexo ), tamanho( tamanho ) {}

Roupa::~Roupa() {}

std::string 
Roupa::getMarca() {
	return this->marca;
}

/* string
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
} */

string Roupa::getSexo(){
	return sexo;
}

string Roupa::getTamanho() {
	return tamanho;
}

void Roupa::setMarca( string marca ) {
	marca = marca;
}

void Roupa::setSexo( string sexo ) {
	this->sexo = sexo;
}

void Roupa::setTamanho( string tamanho ) {
	this->tamanho = tamanho;
}
 
std::ostream& Roupa::print( std::ostream &o ) const {
	o << std::setfill (' ') << std::setw (10) << cod_barras << " | " 
		<< std::setfill ('.') << std::setw (20) << descricao << " | " 
		<< std::setfill (' ') << std::setw (5) << preco << " | "
		<< std::setfill (' ') << std::setw (10) << marca << " | " 
		<< std::setfill (' ') << std::setw (3) << sexo << " | "
        << std::setfill (' ') << std::setw (3) << tamanho;
	return o;
}
