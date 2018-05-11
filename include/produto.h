#ifndef _PRODUTO_H_
#define _PRODUTO_H_

#include <iostream>

class Produto{
public:
	Produto();
	Produto( std::string codigo, std::string descricao, short preco );
	virtual ~Produto();
protected:
	std::string cod_barras;
	std::string descricao;
	double preco;		
public:
	// getters
	std::string getCodBarras();
	std::string getDescricao();
	double getPreco();
	// setters
	void setCodBarras( std::string codigo );
	void setDescricao( std::string descricao );
	void setPreco( double preco );
	//
	friend std::ostream& operator<< ( std::ostream &o, Produto const &t );
	friend double operator+ ( Produto &a, Produto &b );
	friend double operator- ( Produto &a, Produto &b );
	friend bool operator== (Produto &a, Produto &b);

private:
	virtual std::ostream& print( std::ostream& ) const = 0;
};
 
#endif
