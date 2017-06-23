#ifndef _DAL_H_
#define _DAL_H_

#include <iostream>
#include <string>

template < typename Key, typename Data, typename KeyComparator >
class DAL 
{

	protected :
 		struct NodeAL // Estrutura do n´o , representando o par chave - informação . 
 		{ 
 			Key id ; // A chave ´e um inteiro simples .
 			Data info ; // A informa¸c~ao ´e uma cadeia de caracteres .
 		};

 		static const int DEF_SIZE = 50; // Tamanho default da lista .
 		int mi_Length; // Comprimento atual da lista .
 		int mi_Capacity; // Capacidade m´axima de armazenamento .
		NodeAL * mpt_Data; // ´Area de armazenamento : vetor alocado dinamicamente .

		int _search ( const Key & _z ) const ; // M´etodo de busca auxiliar .

 	public :

 		//Construtor e Destrutor.
	 	DAL( int _MaxSz = DEF_SIZE );
		virtual ~ DAL () 
		{ delete [] mpt_Data ; };

		/*! @brief Remove da lista o elemento da chave _x e salva o conteudo no _s.
		 *
		 *  @param _x chave a ser removida.
		 *  @param _s salva o valor a ser removido.
		 *
		 *  @return true caso ache o elemento para remover, false caso contrario.
		 */
	 	bool remove ( const Key & _x , Data & _s );

	 	/*! @brief Busca o antecessor da chave _x.
		 *
		 *  @param _x chave a ser pesquisada.
		 *  @param _s dado da chave a ser pesquisada.
		 *
		 *  @return true caso _x esteja na lista, false caso contrario.
		 */
		bool search ( const Key & _x , Data & _s ) const ; // Busca publica .

		/*! @brief Insere na lista o elemento da chave _newID e conteudo _newInfo.
		 *
		 *  @param _newKey chave a ser inserida.
		 *  @param _newInfo valor a ser inserido.
		 *
		 *  @return true caso inserira o elemento, false caso contrario.
		 */
		bool insert ( const Key & _newKey , const Data & _newInfo );

		/*! @brief Recupera o menor valor de chave na lista.
		 *  
		 *
		 *  @return -1 caso a lista esteja vazia, caso contrario o valor da chave.
		 */
		Key min ( ) const ; 

		/*! @brief Recupera o menor valor de chave na lista.
		 *
		 *  @return -1 caso a lista esteja vazia, caso contrario o valor da chave.
		 */
	 	Key max ( ) const ; // Recupera a maior chave do dicionario .
	 
	 	/*! @brief Busca o sucessor da chave _x.
		 *
		 *  @param _x chave a pesquisar o sucessor.
		 *  @param _y chave do sucessor de _x.
		 *
		 *  @return true caso _x tenha sucessor, false caso contrario.
		 */
	 	bool sucessor ( const Key & _x , Key & _y ) const ;
	 	
	 	/*! @brief Busca o antecessor da chave _x.
		 *
		 *  @param _x chave a pesquisar o sucessor.
		 *  @param _y chave do antecessor de _x.
		 *
		 *  @return true caso _x tenha antecessor, false caso contrario.
		 */
		bool predecessor ( const Key & _x , Key & _y ) const ;

		//! Sobrecarga de operador<< para impressão da lista (dicionario).
		inline friend
		std::ostream &operator<< ( std::ostream& _os , const DAL & _oList ) 
		{
			_os << "[=========================================\n";
			for( int i(0); i < _oList.mi_Length; ++i )
			{
			
				_os << "Elemento Nº(" << i+1 << ") = {id: " << _oList.mpt_Data[i].id << ", info: "
					<< _oList.mpt_Data[i].info << "}\n";
			
			}
		 	_os << "==========================================]";
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

		/*! @brief Remove da lista o elemento da chave _x e salva o conteudo no _s.
		 *
		 *  @param _x chave a ser removida.
		 *  @param _s salva o valor a ser removido.
		 *
		 *  @return true caso ache o elemento para remover, false caso contrario.
		 */
		bool remove(const Key & _x, Data & _s);

		/*! @brief Insere na lista o elemento da chave _newID e conteudo _newInfo.
		 *
		 *  @param _newKey chave a ser inserida.
		 *  @param _newInfo valor a ser inserido
		 *
		 *  @return true caso insira o elemento, false caso contrario.
		 */
		bool insert(const Key & _newID, const Data & _newInfo);

		/*! @brief Recupera o menor valor de chave na lista.
		 *  
		 *
		 *  @return -1 caso a lista esteja vazia, caso contrario o valor da chave.
		 */
		Key min() const;

		/*! @brief Recupera o menor valor de chave na lista.
		 *
		 *  @return -1 caso a lista esteja vazia, caso contrario o valor da chave.
		 */
		Key max() const;

		/*! @brief Busca o sucessor da chave _x.
		 *
		 *  @param _x chave a pesquisar o sucessor.
		 *  @param _y chave do sucessor de _x.
		 *
		 *  @return true caso _x tenha sucessor, false caso contrario.
		 */
		bool sucessor(const Key & _x, Key & _y) const;

		/*! @brief Busca o antecessor da chave _x.
		 *
		 *  @param _x chave a pesquisar o sucessor.
		 *  @param _y chave do antecessor de _x.
		 *
		 *  @return true caso _x tenha antecessor, false caso contrario.
		 */
		bool predecessor(const Key & _x, Key & _y) const;

	private:
		
		int _search(const Key & _x) const;

};

#include "dictionary.inl"

#endif