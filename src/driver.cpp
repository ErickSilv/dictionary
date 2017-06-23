#include "dal.h"
class MyKeyComparator
{
	public:

		bool operator()(const int &lhs, const int &rhs) const
		{
			return lhs < rhs;
		}
};

int main()
{
	// Teste DAL.
	{
		DAL <int, std::string, MyKeyComparator> myList(50);

		// Insert //

		myList.insert(2015003129, "Jack" );
		myList.insert(2014065190, "John" );
		myList.insert(2016042023, "Erick");
		myList.insert(2017129821, "James");
		myList.insert(2014871811, "Charles");
		myList,insert(2016042762, "Luis E.");

		std::cout << ">>> Conteúdo do Dicionário no momento atual <<<\n";
		std::cout << myList << std::endl;

		// Fim dos testes do Insert //

		// Remove //

		std::cout << "Removendo 'James'\n";
		myList.remove();

	}
}