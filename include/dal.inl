
//Construtor
template <typename Key, typename Data, typename KeyComparator>
DAL<Key, Data, KeyComparator>::DAL( int _MaxSz )
	//valores padrao para a definição de um dicionário.
	: mi_Length( 0 )					// Tamanho lógico = 0.
	, mi_Capacity(_MaxSz)				// Capacidade Total = 50.
	, mpt_Data( nullptr )					// Ponteiro para o inicio = nullptr.
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


template <typename Key, typename Data, typename KeyComparator>
int DAL<Key, Data, KeyComparator>::_search( const Key & _z )
{

	for( auto i = 0; i < mi_Length; ++i )
	{
		
		auto founded = mpt_Data[ i ].id;

		if( founded == _x )
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
bool DAL<Key, Data, KeyComparator>::insert( const Key & _newKey, const Data & _newInfo )
{

	// Verifica se o tamamho lógico ainda é menor que o físico.
	// Caso seja menor, realiza a inserção e retorna true. Senão retorna false.
	if( mi_Length < mi_Capacity )
	{

		int _p = _search( _newKey );
		mpt_Data[ _p ].id = _newKey;
		mpt_Data[ _p ].info = _newInfo;

		++mi_Length;


		if( _p == mi_Length )
		{
			++mi_Length;
		}

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
	else if( pos != -1 ) //!< Posição existe e não é a última.
	{		
		_s = mpt_Data[ pos ].info;
		std::copy( &mpt_Data[ pos+1 ], &mpt_Data[ mi_Length+1 ], &mpt_Data[ pos ] );
		--mi_Length;

		return true;
	}

	return false;

}

template <typename Key, typename Data, typename KeyComparator>
Key DAL<Key, Data, KeyComparator>::min() const
{

	// Se estiver vazia, não há menor.
	if( mi_Length == 0 )
	{
		throw std::out_of_range("Dicionário Vazia!\n");
	}

	KeyComparator compa;

	// Assume para comparação o primeiro elemento como o menor, visto que o dicionário não está ordenado.
	int smaller = mpt_Data[ 0 ].id;
	int current;
	
	// Procura o menor.
	for( int i = 1; i < mi_Length; ++i )
	{

		current = mpt_Data[ i ].id
		if( compa( current, smaller ) )
		{
			smaller = current;
		}

	}

	return smaller;

}

template <typename Key, typename Data, typename KeyComparator>
Key DAL<Key, Data, KeyComparator>::max() const{

	// Se estiver vazia, não há maior.
	if( mi_Length == 0 )
	{
		throw std::out_of_range("It's empty");
	}


	KeyComparator compa;

	// Assume como o maior, o primeiro elemento como o maior, visto que o dicionário não está ordenado.
	int larger = mpt_Data[ 0 ].id;
	int current;


	/// Searches the minor.
	for( int i = 1; i < mi_Length; ++i )
	{
		
		current = mpt_Data[ i ].id
		if( compa( a_, larger ) )
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

	// O elemento _x não se encontra no dicionário.
	if( _search(_x) == -1 )
	{
		return false;
	}


	KeyComparator compa;

	// Salva o sucessor de todos.
	int suc = max();
	int current;


	// Busca o predecessor de _x e salva em pred o novo predecessor(current).
	for( int i = 0; i < mi_Length; ++i )
	{
		
		current = mpt_Data[ i ].id;
		if( cmp( _x, current ) and cmp( current, suc ) )
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

	// A chave _x não está no dicionário.
	if( _search(_x) == -1 )
	{
		return false;
	}


	KeyComparator compa;

	// Salva o predecessor de todos.
	int pred = min();
	int current;


	// Busca o 
	for( int i = 0; i < mi_Length; ++i )
	{
		a_ = mpt_Data[ i ].id;
		if( cmp( _x, current ) and cmp( current, pred ) ){
			pred = current;
		}
	}

	_y = pred;
	return true;

}

// DSAL
// Busca Binária para executar a inserção.
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
			return middle
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

	auto & m_Length = DAL<Key, Data, KeyComparator>::mi_Length;
	auto & m_Data = DAL<Key, Data, KeyComparator>::mpt_Data;

	// Dicionário está vazio.
	if( m_Length == 0 )
	{
		return false;
	}

	// Encontra a posição da key _x.
	auto pos = _search(_x);

	// Se estiver na última posição.
	if( pos == ( m_Length-1 ) )
	{
		_s = m_Data[ pos ].info;
		--mi_Length;
		return true;

	}
	else if( pos != -1 ) // Se for encontrada, mas não na última posição.
	{		
		_s = m_Data[ pos ].info;

		for( int i = pos; i < m_Length-1; ++i )
		{
		
			m_Data[i].id = m_Data[ i+1 ].id;
			m_Data[i].info = m_Data[ i+1 ].info;
		
		}

		--m_Length;
		return true;
	}
	return false;

}

template <typename Key, typename Data, typename KeyComparator>
bool DSAL<Key, Data, KeyComparator>::insert( const Key & _newID, const Data &  _newInfo )
{

	auto & m_Length = DAL<Key, Data, KeyComparator>::mi_Length;
	auto & m_Data = DAL<Key, Data, KeyComparator>::mpt_Data;

}

template <typename Key, typename Data, typename KeyComparator>
int DSAL<Key, Data, KeyComparator>::min() const
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
int DSAL<Key, Data, KeyComparator>::max() const
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

	// Posição fora do dicionário (não existe).
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
bool DSAL<Key, Data, KeyComparator>::predecessor(const Key & _x, Key & _y) const{

	auto & m_Length = DAL<Key, Data, KeyComparator>::mi_Length;
	auto & m_Data = DAL<Key, Data, KeyComparator>::mpt_Data;
	/// Gets the position.
	int p_ = _search(_x);
	/// The position doesn't exist or is the first element, so it doesn't have a predecessor.
	if(p_ == -1 or p_ == 0){
		return false;
	}
	/// It's empty.
	if(m_Length == 0){
		return false;
	}
	/// Since the list is sorted so the predecessor is on the previous position.
	_y = m_Data[p_-1].id;
	return true;

}