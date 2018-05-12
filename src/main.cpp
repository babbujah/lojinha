#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <memory>

#include "produto.h"
#include "fruta.h"
#include "roupa.h"
#include "bebida.h"

using namespace std;

int main(int argc, char const *argv[])
{
	std::vector<shared_ptr<Produto>> lista;

	string codigo, descricao, preco, data, validade,
			marca, sexo, tamanho, teorAlcoolico, tag;
	ifstream arquivo( "./dados.dat" );
	if( arquivo.is_open() ){
		while( !arquivo.eof() ){
			getline( arquivo, tag, ',' );

			switch( stoi( tag ) ){
				case 1:
					getline( arquivo, codigo, ',' );
					getline( arquivo, descricao, ',' );
					getline( arquivo, preco, ',' );
					getline( arquivo, data, ',' );
					getline( arquivo, validade, ',' );

					lista.push_back(make_shared<Fruta>( stoi( tag ), codigo, descricao, stod( preco ), data, stoi( validade ) ));
					break;

				case 2:
					getline( arquivo, codigo, ',' );
					getline( arquivo, descricao, ',' );
					getline( arquivo, preco, ',' );
					getline(arquivo, marca, ',' );
					getline(arquivo, sexo, ',' );
					getline(arquivo, tamanho, ',' );

					lista.push_back(make_shared<Roupa>( stoi( tag ), codigo ,descricao , stod( preco ), marca, sexo, tamanho ));
					break;

				case 3:
					getline( arquivo, codigo, ',' );
					getline( arquivo, descricao, ',' );
					getline( arquivo, preco, ',' );
					getline( arquivo, teorAlcoolico, ',' );
					
					lista.push_back(make_shared<Bebida>( stoi( tag ), codigo, descricao, stod( preco ), stoi( teorAlcoolico ) ));
					break;
			}			
		}
		arquivo.close();
	}else
		cout << "Erro ao abrir o arquivo" << endl;
	
	bool fruta = false, roupa = false, bebida = false;
	for(auto j = lista.begin(); j != lista.end(); ++j){
		if((*j)->getTag() == 1){
			if(!fruta){
				cout << endl << "############### FRUTAS ###############" << endl;
				fruta = true;
			}
			std::cout << (**j) << std::endl;
		}else if((*j)->getTag() == 2){
			if(!roupa){
				cout << endl << "############### ROUPAS ###############" << endl;
				roupa = true;
			}
			std::cout << (**j) << std::endl;
		}else if((*j)->getTag() == 3){
			if(!bebida){
				cout << endl << "############### BEBIDA ###############" << endl;
				bebida = true;
			}
			std::cout << (**j) << std::endl;
		}
	}
	cout << endl;

	cout << lista[8]->getCodBarras() << " | " << lista[8]->getDescricao() << " = " << lista[9]->getCodBarras() << " | " << lista[9]->getDescricao() << "?" << endl;
	if(*lista[5] == *lista[9])
		cout << "Os produtos são iguais" << endl;
	else
		cout << "Os produtos são diferentes" << endl;

	cout << lista[3]->getCodBarras() << " | " << lista[3]->getDescricao() << " = " << lista[4]->getCodBarras() << " | " << lista[4]->getDescricao() << "?" << endl;
	if(*lista[3] == *lista[4])
		cout << "Os produtos são iguais" << endl;
	else
		cout << "Os produtos são diferentes" << endl;

	cout << endl;

	double valor = *lista[0] - *lista[8];
	
	cout << lista[0]->getDescricao() << " - " << lista[8]->getDescricao() << " = " << valor << endl;
	
	valor = *lista[0] + *lista[8];

	cout << lista[0]->getDescricao() << " + " << lista[8]->getDescricao() << " = " << valor << endl;
	//cout << *lista[0] << " + " << *lista[8] << " = " << valor << endl;

	//valor = 5.86;
	//v << valor;
	//v.setprecision(2);
	//cout << v.str() << endl;
	/*
	std::stringstream teor;
    teor << teorAlcoolico;
	return  teor.str() + " %";
	*/
	cout << endl;
	
	return 0;
}