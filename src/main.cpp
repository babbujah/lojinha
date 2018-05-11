#include <iostream>
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
	
	lista.push_back(make_shared<Fruta>("001002003-45","Maca verde",8.70,"01/10/2017",18));
	lista.push_back(make_shared<Fruta>("001002004-44","Laranja",4.75,"23/09/2017",15));
	lista.push_back(make_shared<Fruta>("001002005-11","Limao verde",2.30,"01/10/2017",25));

	lista.push_back(make_shared<Roupa>("001002018-46","Camisa",55.50,"Topen", 'M', 'P'));
	lista.push_back(make_shared<Roupa>("001002018-47","Calça",80.75,"Rasgado", 'F', 'M'));
	lista.push_back(make_shared<Roupa>("001002018-48","Bermuda",35.30,"Largado", 'M', 'P'));

	lista.push_back(make_shared<Bebida>("001002018-49","Ula-Ula",15.50, 37));
	lista.push_back(make_shared<Bebida>("001002018-50","Kit-Cana",20.50, 38));
	lista.push_back(make_shared<Bebida>("001002018-51","Água",2.00, 0));

	for (auto i = lista.begin(); i != lista.end(); ++i)
	{
		std::cout << (**i) << std::endl;	
	}

	return 0;
}