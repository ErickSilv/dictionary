/// DAL
/// Constructor
template <typename Key, typename Data, typename KeyComparator>
DAL<Key, Data, KeyComparator>::DAL(int _MaxSz)
	//valores padrao para a definição de um dicionário.
	: mi_Length( 0 )					// Tamanho lógico = 0.
	, mi_Capacity( _MaxSz )				// Capacidade Total = 50.
	, mpt_Data( nullptr )				// Ponteiro para o inicio = nullptr.
{ 	

	// Se o tamanho for inválido não tenta reservar memória. 
	// Caso contrário, reserva memória suficiente para o parametro (_MaxSz) passado. 
	if( _MaxSz < 0 )
	{
		std::cout << "Erro. Insira um valor válido para a lista!\n";	
	}
	else
	{
		mpt_Data = new NodeAL[ _MaxSz ];
	} 

}

// Linear Search
template <typename Key, typename Data, typename KeyComparator>
int DAL<Key, Data, KeyComparator>::_search( const Key & _z ) const
{
	
	for( auto i = 0; i < mi_Length; ++i )
	{
		
		auto founded = mpt_Data[ i ].id;

		if( founded == _z )
		{
			//Foi encontrado, retorna o índice no dicionário.
			return i;
		}

	}

	//Caso nao encontre retorna -1.
	return -1;

}

template <typename Key, typename Data, typename KeyComparator>
bool DAL<Key, Data, KeyComparator>::search( const Key & _x, Data & _s ) const
{

	
	// Realiza a pesquisa auxiliar.
	int _p = _search( _x );

	// Caso a pesquisa retorna -1, o elemento não se encontra no dicionário.
	if( _p != -1 )
	{
		_s = mpt_Data[ _p ].info;
		return true;

	}
	else
	{
		return false;
	}

}

template <typename Key, typename Data, typename KeyComparator>
bool DAL<Key, Data, KeyComparator>::remove( const Key & _x, Data & _s )
{

	// Se a lista tá vazia não há o que remover.
	if( mi_Length == 0 )
	{
		return false;
	}

	// Procura a posição do elemento na lista.
	auto pos = _search( _x );

	// Se for a última posição.
	if( pos == ( mi_Length-1 ) )
	{
		_s = mpt_Data[ pos ].info;
		--mi_Length;

		return true;

	}
	else if( pos != -1 ) //! Posição existe e não é a última.
	{		
		_s = mpt_Data[ pos ].info;
		std::copy( &mpt_Data[ pos+1 ], &mpt_Data[ mi_Length+1 ], &mpt_Data[ pos ] );
		--mi_Length;

		return true;
	}

	return false;

}

template <typename Key, typename Data, typename KeyComparator>
bool DAL<Key, Data, KeyComparator>::insert( const Key & _newKey, const Data & _newInfo )
{

	// Verifica se o tamamho lógico ainda é igual ao físico.
	// Caso seja igual, a inserção não é possivel e retorna false. Senão, insere o elemento e retorna true.
	if( mi_Length == mi_Capacity )
	{

		return false;

	}

		mpt_Data[ mi_Length ].id = _newKey;
		mpt_Data[ mi_Length ].info = _newInfo;

		++mi_Length;


		return true;
	
	
}

template <typename Key, typename Data, typename KeyComparator>
Key DAL<Key, Data, KeyComparator>::min() const
{

	// Se estiver vazia, não há menor.
	if( mi_Length == 0 )
	{
		throw std::out_of_range("Dicionário Vazia!\n");
	}

	// Função de comparação
	KeyComparator compa;

	// Assume para comparação o primeiro elemento como o menor, visto que o dicionário não está ordenado.
	int smaller = mpt_Data[ 0 ].id;
	int current;
	
	// Procura o menor.
	for( int i = 1; i < mi_Length; ++i )
	{

		current = mpt_Data[ i ].id;
		if( compa( current, smaller ) )
		{
			smaller = current;
		}

	}

	return smaller;

}

template <typename Key, typename Data, typename KeyComparator>
Key DAL<Key, Data, KeyComparator>::max() const
{

	// Se estiver vazia, não há maior.
	if( mi_Length == 0 )
	{
		throw std::out_of_range("It's empty");
	}

	// Função de comparação.
	KeyComparator compa;

	// Assume como o maior, o primeiro elemento como o maior, visto que o dicionário não está ordenado.
	int larger = mpt_Data[ 0 ].id;
	int current;


	/// Searches the minor.
	for( int i = 1; i < mi_Length; ++i )
	{
		
		current = mpt_Data[ i ].id;
		if( compa( larger, current ) )
		{
			larger = current;
		}

	}

	return larger;

}

template <typename Key, typename Data, typename KeyComparator>
bool DAL<Key, Data, KeyComparator>::sucessor( const Key & _x, Key & _y ) const
{

	// Lista vazia, não há elementos.
	if( mi_Length == 0 )
	{
		return false;
	}

	if ( _x == max() )
	{
		return false;
	}

	// O elemento _x não se encontra no dicionário.
	if( _search(_x) == -1 )
	{
		return false;
	}

	// Função de comparação.
	KeyComparator compa;

	// Salva o sucessor de todos.
	int suc = max();
	int current;


	// Busca o predecessor de _x e salva em suc o novo predecessor(current).
	for( int i = 0; i < mi_Length; ++i )
	{
		
		current = mpt_Data[ i ].id;
		if( compa( _x, current ) and compa( current, suc ) )
		{
			suc = current;
		}

	}

	_y = suc;
	return true;

}

template <typename Key, typename Data, typename KeyComparator>
bool DAL<Key, Data, KeyComparator>::predecessor( const Key & _x, Key & _y ) const
{

	// Se o tamanho lógico for 0, o dicionário está vazio.
	if( mi_Length == 0 )
	{
		return false;
	}

	if ( _x == min() )
	{
		return false;
	}

	// A chave _x não está no dicionário.
	if( _search(_x) == -1 )
	{
		return false;
	}


	KeyComparator compa;

	// Salva o predecessor de todos.
	int pred = min();
	int current;


	// Busca o sucessor de _x e salva em suc o novo sucessor(current). 
	for( int i = 0; i < mi_Length; ++i )
	{
		current = mpt_Data[ i ].id;
		if( compa( _x, current ) and compa( current, pred ) )
		{
			pred = current;
		}
	}

	_y = pred;
	return true;

}

// DSAL

// Busca Binária.
template <typename Key, typename Data, typename KeyComparator>
int DSAL<Key, Data, KeyComparator>::_search( const Key & _x ) const
{

	KeyComparator compa;
	int left, right, sz;

	sz = DAL<Key, Data, KeyComparator>::mi_Length;
	right = sz - 1;
	left = 0;

	while( left <= right )
	{

		int middle = ( left + right )/2;
		int current = DAL<Key, Data, KeyComparator>::mpt_Data[ middle ].id;

		if( _x == current )
		{
			return middle;
		}
		else if( compa( _x, current ) )
		{
			right = middle - 1;
		}
		else
		{
			left = middle + 1;
		}

	}

	return -1;

}

template <typename Key, typename Data, typename KeyComparator>
bool DSAL<Key, Data, KeyComparator>::remove( const Key & _x, Data & _s )
{

	auto &m_Length = DAL<Key, Data, KeyComparator>::mi_Length;
	auto &m_Data = DAL<Key, Data, KeyComparator>::mpt_Data;

	// Se o tamanho lógico for 0, o dicionário está vazio. Então não há o que remover.
	if( m_Length == 0 )
	{
		return false;
	}

	// Acha a posição da chave _x no dicionário.
	auto pos = _search(_x);

	// Caso a posição seja a primeira.
	if( pos == ( m_Length-1 ) )
	{
		
		_s = m_Data[ pos ].info;

		--m_Length;
		return true;

	}
	//Caso não seja a primeira e se encontra no dicionário.
	else if( pos != -1 ) 
	{		
		_s = m_Data[pos].info;
		
		for( auto i(pos); i < m_Length-1; ++i )
		{
			m_Data[ i ].id = m_Data[ i+1 ].id;
			m_Data[ i ].info = m_Data[ i+1 ].info;
		}

		--m_Length;
		return true;
	}
	return false;

}

/// OBS: Esse metódo foi feito com ajuda do aluno GABRIEL SOUZA
template <typename Key, typename Data, typename KeyComparator>
bool DSAL<Key, Data, KeyComparator>::insert( const Key & _novaID, const Data & _novaInfo )
{

	auto & m_Length = DAL<Key, Data, KeyComparator>::mi_Length;
	auto & m_Data = DAL<Key, Data, KeyComparator>::mpt_Data;
	auto & m_Capacity = DAL<Key, Data, KeyComparator>::mi_Capacity;

	// Se estiver cheio não há como inserir;
	if( m_Length == m_Capacity )
	{
		throw std::out_of_range("Dicionário cheio não há como inserir!\n");
	}

	// Função de comparação
	KeyComparator cmp;

	// Objeto Key auxiliar para a inserção.
	Key a_;


	auto test_p = 0;
	int pos = _search( _novaID );

	// Procura a posição certa para inserir.
	while( test_p < m_Length )
	{
		a_ = m_Data[ test_p ].id;
		if( cmp( a_, _novaID ) ){
			pos = test_p;
		}
		++test_p;
	}

	// Se a inserção for no fim da lista.
	if( pos == m_Length-1 )
	{

		m_Data[ m_Length ].id = _novaID;
		m_Data[ m_Length ].info = _novaInfo;
		
		++m_Length;

		return true;

	}
	else if( pos == -1 ) //! Se a inserção é no começo da lista.
	{ 	
		//Reorganiza as chaves e conteudos para abrir espaço para inserção.	
		for( auto i(m_Length); i > pos+1; --i )
		{
			m_Data[ i ].id = m_Data[ i-1 ].id;
			m_Data[ i ].info = m_Data[ i-1 ].info;
		}

		m_Data[ 0 ].id = _novaID;
		m_Data[ 0 ].info = _novaInfo;
		
		++m_Length;

		return true;
	}
	else 				// Senão, se é no meio da lista.
	{
		//Reorganiza as chaves e conteudos para abrir espaço para inserção.	
		for( auto i(m_Length); i > pos+1; --i ) 
		{
			m_Data[ i ].id = m_Data[ i-1 ].id;
			m_Data[ i ].info = m_Data[ i-1 ].info;
		}
		
		m_Data[ pos+1 ].id = _novaID;
		m_Data[ pos+1 ].info = _novaInfo;
		
		++m_Length;

		return true;
	}

	return false;

}

template <typename Key, typename Data, typename KeyComparator>
Key DSAL<Key, Data, KeyComparator>::min() const
{

	auto & m_Length = DAL<Key, Data, KeyComparator>::mi_Length;
	auto & m_Data = DAL<Key, Data, KeyComparator>::mpt_Data;
	
	// Se o dicionário está vazio, lançar uma exceção.
	if( m_Length == 0 )
	{
		throw std::out_of_range("Dicionário está vazio!\n");
	}

	// Como a lista é ordenada, a menor chave está na primeira posição.
	return m_Data[0].id;

}

template <typename Key, typename Data, typename KeyComparator>
Key DSAL<Key, Data, KeyComparator>::max() const
{

	auto & m_Length = DAL<Key, Data, KeyComparator>::mi_Length;
	auto & m_Data = DAL<Key, Data, KeyComparator>::mpt_Data;

	// Se o dicionário está vazio.
	if( m_Length == 0 )
	{
		throw std::out_of_range("Dicionário está vazio!\n");
	}

	// Como a lista é ordenada, a maior chave está na última posição.
	return m_Data[ m_Length-1 ].id;

}

template <typename Key, typename Data, typename KeyComparator>
bool DSAL<Key, Data, KeyComparator>::sucessor( const Key & _x, Key & _y ) const
{

	auto & m_Length = DAL<Key, Data, KeyComparator>::mi_Length;
	auto & m_Data = DAL<Key, Data, KeyComparator>::mpt_Data;

	// Obtém a posição da chave _x.
	int pos = _search( _x );

	// Tratando exc
	// Posição fora do dicionário ( não existe ).
	if( pos == -1 )
	{
		return false;
	}

	// Se o dicionário for vazio ou _x estiver no final do dicionário não existe sucessor.
	if( m_Length == 0 or pos == m_Length - 1 )
	{
		return false;
	}


	// Como o dicionário é ordenado o sucessor sempre é o da popsição seguinte.
	_y = m_Data[ pos+1 ].id;
	return true;

}

template <typename Key, typename Data, typename KeyComparator>
bool DSAL<Key, Data, KeyComparator>::predecessor( const Key & _x, Key & _y ) const
{

	auto & m_Length = DAL<Key, Data, KeyComparator>::mi_Length;
	auto & m_Data = DAL<Key, Data, KeyComparator>::mpt_Data;

	// Obtém a posição da chave _x.
	int pos = _search( _x );

	// Posição fora do dicionário ( não existe ).
	if( pos == -1 )
	{
		return false;
	}


	// Lista vazia ou a posição encontrada ser a primeira da lista, logo não há predecessor.
	if( m_Length == 0 or pos == 0 )
	{
		return false;
	}

	// Se a lista é ordenada, então o predecessor está na posição anterior ao da chave _x.
	_y = m_Data[ pos-1 ].id;
	return true;

}