#include <iomanip>
#include <istream>
#include <sstream>
#include "bebida.h"


Bebida::Bebida() {}

Bebida::Bebida( string codigo, string descricao, short preco, 
	short teorAlcoolico ):
	Produto( codigo, descricao, preco ),
    teorAlcoolico( teorAlcoolico ) {}

Bebida::~Bebida() {}

string
Bebida::getTeorAlcoolico() {
    std::stringstream teor;
    teor << teorAlcoolico;
	return  teor.str() + " %";
}

void 
Bebida::setTeorAlcoolico( short teorAlcoolico ) {
	this->teorAlcoolico = teorAlcoolico;
}
 
std::ostream& 
Bebida::print( std::ostream &o ) const {
	o << std::setfill (' ') << std::setw (10) << m_cod_barras << " | " 
		<< std::setfill ('.') << std::setw (20) << m_descricao << " | " 
		<< std::setfill (' ') << std::setw (5) << m_preco << " | "
		<< std::setfill (' ') << std::setw (10) << teorAlcoolico;//getTeorAlcoolico();
	return o;
}