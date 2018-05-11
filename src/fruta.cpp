#include <iomanip>
#include "fruta.h"

Fruta::Fruta() {}

Fruta::Fruta( std::string codigo, std::string descricao, short preco, 
	std::string data, short validade ):
	Produto( codigo, descricao, preco ), data_lote( data ), validade( validade ) {}

Fruta::~Fruta() {}

std::string Fruta::getDataLote() {
	return data_lote;
}

short Fruta::getValidade() {
	return validade;
}

void Fruta::setDataLote( std::string data ) {
	data_lote = data;
}

void Fruta::setValidade( short validade ) {
	this->validade = validade;
}
 
std::ostream& Fruta::print( std::ostream &o ) const {
	o << std::setfill (' ') << std::setw (10) << cod_barras << " | " 
		<< std::setfill ('.') << std::setw (20) << descricao << " | " 
		<< std::setfill (' ') << std::setw (5) << preco << " | "
		<< std::setfill (' ') << std::setw (10) << data_lote << " | " 
		<< std::setfill (' ') << std::setw (3) << validade;
	return o;
}
