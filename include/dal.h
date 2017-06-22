#ifndef _DAL_H_
#define _DAL_H_

#include <iostream>
#include <string>

template < typename Key, typename Data, typename KeyComparator >

class DAL 
{

	protected :
		using Key = int ; // Alias para Chave .
 		using Data = std::string ; // Alias para Dado .
 	
 		struct NodeAL // Estrutura do n´o , representando o par chave - informação . 
 		{ 
 			Key id ; // A chave ´e um inteiro simples .
 			Data info ; // A informa¸c~ao ´e uma cadeia de caracteres .
 		};

 		static const int DEF_SIZE = 50; // Tamanho default da lista .
 		int mi_Length ; // Comprimento atual da lista .
 		int mi_Capacity ; // Capacidade m´axima de armazenamento .
		NodeAL * mpt_Data ; // ´Area de armazenamento : vetor alocado dinamicamente .

		int _search ( const Key & _x ) const ; // M´etodo de busca auxiliar .

 	public :

 		//Construtor e Destrutor.
	 	DAL ( int _MaxSz = DEF_SIZE );
		virtual ~ DAL () 
		{ delete [] mpt_Data ; };


	 	bool remove ( const Key & _x , Data & _s ); // Remove da lista .
		bool search ( const Key & _x , Data & _s ) const ; // Busca publica .
		bool insert ( const Key & _newKey , const Data & _newInfo ); // Insere na lista .
		Key min ( ) const ; // Recupera a menor chave do dicion´ario .
	 	Key max ( ) const ; // Recupera a maior chave do dicion´ario .
	 
	 	// Recupera em _y a chave sucessora a _x , se existir ( true ).
	 	bool sucessor ( const Key & _x , Key & _y ) const ;
	 	// Recupera em _y a chave antecessora a _x , se existir ( true ).
		bool predecessor ( const Key & _x , Key & _y ) const ;

		//! Sends back to the output stream an ascii representation for the list .
		inline friend
		std::ostream &operator<< ( std::ostream& _os , const DAL & _oList ) 
		{
			_os << "[ ";
		 	for ( int i(0); i < _oList . mi_Length; ++ i )
		 	{
				_os << "{id: " << _oList . mpt_Data[ i ]. id << ", info : "
					<< _oList . mpt_Data [i ]. info << "} ";
			}
		 	_os << "]";
		 	return _os;
		}

};

template <typename Key, typename Data, typename KeyComparator>
class DSAL : public DAL<Key, Data, KeyComparator>{

	public:

		DSAL(int _MaxSz) 
			: DAL<Key, Data, KeyComparator>(_MaxSz)
		{ /* Empty */ };
		virtual ~DSAL()
		{ /* Empty */ };

		bool remove(const Key & _x, Data & _s);
		bool insert(const Key & _novaID, const Data & _novaInfo);
		Key min() const;
		Key max() const;
		bool sucessor(const Key & _x, Key & _y) const;
		bool predecessor(const Key & _x, Key & _y) const;

	private:
		
		int _search(const Key & _x) const;

};

#include "dal.inl"

#endif