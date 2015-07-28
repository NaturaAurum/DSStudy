#include <iostream>

namespace ArrayBinaryTree
{
	template <class _Type> class atNode
	{
	public:
		_Type m_Data;
	};
	template <class _Type> class CArrayBinaryTree
	{
	private:
		int m_iCapacity;
		int m_Index;
		atNode<_Type>* m_pArrayNodes;

		void DestroyNode( atNode<_Type>* pTarget )
		{
			free( pTarget );
			pTarget = nullptr;
		}
	public:
		CArrayBinaryTree( )
		{
			m_iCapacity = NULL;
			m_Index = NULL;
			m_pArrayNodes = nullptr;
		}

		CArrayBinaryTree( int iCapacity )
		{
			CreateTree( iCapacity );
		}

		~CArrayBinaryTree( )
		{
			DestroyNode( m_pArrayNodes );
		}

		void CreateTree( int iCapacity )
		{
			m_pArrayNodes = ( atNode<_Type>* )malloc(
				sizeof( atNode<_Type> ) * iCapacity );
			m_iCapacity = iCapacity;
			m_Index = NULL;
		}

		void Add( _Type _Item )
		{
			if ( m_Index > m_iCapacity )
			{
				std::cout << "FULL!!" << std::endl;
			}
			else
			{
				m_pArrayNodes[ m_Index ].m_Data = _Item;
				m_Index++;
			}
		}

		void Print( )
		{
			for ( int i = 0; i < m_iCapacity; i++ )
			{
				std::cout << m_pArrayNodes[ i ].m_Data << " ";
			}
			std::cout << std::endl;
		}

		void Print( _Type Target, int _Mode )
		{
			int Index = 0;
			while ( m_pArrayNodes[ ++Index ].m_Data != Target );
			if ( _Mode == 0 ) // 자식
			{
				std::cout << m_pArrayNodes[ Index * 2 ].m_Data
					<< " " << m_pArrayNodes[ Index * 2 + 1 ].m_Data
					<< std::endl;
				return;
			}
			else // 조상
			{
				while ( ( Index /= 2 ) >= 1 )
				{
					std::cout << m_pArrayNodes[ Index ].m_Data
						<< " ";
				}
				std::cout << std::endl;
			}
		}

	};
}
namespace ListBinaryTree
{
	template <class _Type> class atNode
	{
	public:
		_Type m_Data;
		atNode<_Type>* m_pLeft;
		atNode<_Type>* m_pRight;

		atNode( _Type _Item)
		{
			m_Data = _Item;
			m_pLeft = nullptr;
			m_pRight = nullptr;
		}
	};

	template <class _Type> class CListBinaryTree
	{
	private:
		atNode<_Type>* m_pBTree;
		atNode<_Type>* m_pRecentNode;
	public:
		CListBinaryTree( )
		{
			m_pBTree = nullptr;
		}
		~CListBinaryTree( )
		{

		}

		void Add( _Type _Item )
		{
			if ( m_pBTree == nullptr )
			{
				m_pBTree = new atNode<_Type>( _Item );
				m_pRecentNode = m_pBTree;
			}
			else
			{
				atNode<_Type>* pNewNode = new atNode<_Type>( _Item );
				if ( m_pRecentNode->m_pLeft == nullptr )
				{
					m_pRecentNode->m_pLeft = pNewNode;
					m_pRecentNode = pNewNode;
				}
				else
				{
					m_pRecentNode->m_pRight = pNewNode;
					m_pRecentNode = pNewNode;
				}
			}
		}

		void Release( )
		{
			
		}
	};
}