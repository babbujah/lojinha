#ifndef _FRUTA_H_
#define _FRUTA_H_

#include "produto.h"

class Fruta : public Produto{
public:
	Fruta();
	Fruta( int tag, std::string codigo, std::string descricao, short preco, 
			std::string data, short validade );
	~Fruta();

private:
	std::string data_lote;
	short validade;

public:
	// getters
	std::string getDataLote();
	short getValidade();
	// setters
	void setDataLote( std::string data );
	void setValidade( short validade );
	
private:
	std::ostream& print( std::ostream &o ) const;
};

#endif