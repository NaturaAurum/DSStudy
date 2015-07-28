#include <iostream>


namespace nArrayStack
{
	template <class Type> class asNode
	{
	public:
		Type m_Data;
	};

	template <class Type> class ArrayStack
	{
	private:
		int m_iCapacity;
		int m_iTop;
		asNode<Type>* m_Nodes;
		ArrayStack<Type>* m_ArrayStack;
	public:
		ArrayStack( )
		{
			m_iCapacity = NULL;
			m_iTop = NULL;

			m_Nodes = nullptr;
			m_ArrayStack = nullptr;
		}

		ArrayStack( int iCapacity )
		{
			CreateStack( iCapacity );
		}
		~ArrayStack( )
		{
			DestroyStack( );
		}

		void CreateStack( int iCapacity )
		{
			m_ArrayStack = new ArrayStack( );
			m_ArrayStack->m_Nodes = ( asNode<Type>* )malloc(
				sizeof( asNode<Type> ) * iCapacity );
			m_ArrayStack->m_iCapacity = iCapacity;
			m_ArrayStack->m_iTop = NULL;
		}

		void DestroyStack( )
		{
			free( m_ArrayStack->m_Nodes );
			delete m_ArrayStack;
		}

		void Push( Type Data )
		{
			int Index = m_ArrayStack->m_iTop;

			m_ArrayStack->m_Nodes[ Index ].m_Data = Data;
			m_ArrayStack->m_iTop++;
		}

		Type Pop( )
		{
			int Index = ( --m_ArrayStack->m_iTop );
			return m_ArrayStack->m_Nodes[ Index ].m_Data;
		}

		Type Top( )
		{
			int Index = ( m_ArrayStack->Top - 1 );
			return m_ArrayStack->m_Nodes[ Index ].m_Data;
		}

		Type Peek( )
		{
			return m_ArrayStack->m_Nodes[ m_ArrayStack->m_iTop - 1 ].m_Data;
		}

		int GetSize( )
		{
			return m_ArrayStack->m_iTop;
		}

		bool isEmpty( )
		{
			return ( m_ArrayStack->m_iTop == 0 );
		}
	};
}

namespace DualStack
{
	template <class Type> class asNode
	{
	public:
		Type m_Data;
	};

	template <class Type> class ArrayStack
	{
	private:
		int m_iCapacity;
		int m_iTop;
		int m_iTop2;
		asNode<Type>* m_Nodes;
		ArrayStack<Type>* m_ArrayStack;

		void DestroyStack( )
		{
			free( m_ArrayStack->m_Nodes );
			delete m_ArrayStack;
		}

		void CreateStack( int iCapacity )
		{
			m_ArrayStack = new ArrayStack( );
			m_ArrayStack->m_Nodes = ( asNode<Type>* )malloc(
				sizeof( asNode<Type> ) * iCapacity );
			m_ArrayStack->m_iCapacity = iCapacity;
			m_ArrayStack->m_iTop = NULL;
			m_ArrayStack->m_iTop2 = iCapacity;
		}
	public:
		ArrayStack( )
		{
			m_iCapacity = NULL;
			m_iTop = NULL;

			m_Nodes = nullptr;
			m_ArrayStack = nullptr;
		}

		ArrayStack( int iCapacity )
		{
			CreateStack( iCapacity );
		}
		~ArrayStack( )
		{
			DestroyStack( );
		}
		
		void Push( Type Data )
		{
			if ( Data < 0 )
			{
				int Index = m_ArrayStack->m_iTop2;
				m_ArrayStack->m_Nodes[ Index ].m_Data = Data;
				m_ArrayStack->m_iTop2--;
			}
			else
			{
				int Index = m_ArrayStack->m_iTop;

				m_ArrayStack->m_Nodes[ Index ].m_Data = Data;
				m_ArrayStack->m_iTop++;
			}
		}

		Type Pop( std::string strMode )
		{
			if ( strMode == "P" )
			{
				int Index = ( --m_ArrayStack->m_iTop );
				return m_ArrayStack->m_Nodes[ Index ].m_Data;
			}
			else if ( strMode == "N" )
			{
				int Index = ( ++m_ArrayStack->m_iTop2 );
				return m_ArrayStack->m_Nodes[ Index ].m_Data;
			}
		}

		Type Peek( std::string strMode )
		{
			if ( strMode == "P" )
			{
				return m_ArrayStack->m_Nodes[ m_ArrayStack->m_iTop - 1 ].m_Data;
			}
			else if ( strMode == "N" )
			{
				return m_ArrayStack->m_Nodes[ m_ArrayStack->m_iTop2 + 1 ].m_Data;
			}
		}
	};
}

namespace nLinkedListStack
{

	template <class Type> class asNode
	{
	public:
		Type m_Data;
		asNode<Type>* m_pNextNode;
	};

	template <class Type> class ListStack
	{
	private:
		asNode<Type>* m_pTop;
		//asNode<Type>* m_pNode;
		//ListStack<Type>* m_ListStack;

		void DestoryNode( asNode<Type>* Target )
		{
			delete Target;
		}

		void Release( )
		{
			while ( m_ListStack->m_pTop != nullptr )
			{
				asNode<Type>* Target = m_ListStack->m_pTop;
				m_ListStack->m_pTop = m_ListStack->m_pTop->m_pNextNode;
				DestoryNode( m_pTop );
			}

			DestoryNode( m_ListStack->m_pTop );
			delete m_ListStack;
		}

	public:

		ListStack( )
		{
			m_pTop = nullptr;
			//m_ListStack = nullptr;
		}

		~ListStack( )
		{
			Release( );
		}

		void Push( Type Data )
		{
			//m_ListStack = new ListStack<int>( );
			asNode<Type>* pNewNode = new asNode<Type>( );
			if ( m_pTop == nullptr )
			{
				pNewNode->m_Data = Data;
				pNewNode->m_pNextNode = nullptr;

				m_pTop = pNewNode;
			}
			else
			{
				pNewNode->m_Data = Data;
				pNewNode->m_pNextNode = m_pTop;

				m_pTop = pNewNode;
			}
		}

		Type Pop( )
		{
			asNode<Type>* pTemp = m_pTop;
			Type _Value = pTemp->m_Data;
			m_pTop = pTemp->m_pNextNode;

			DestoryNode( pTemp );

			return _Value;
		}

		Type Peek( )
		{
			if ( m_pTop == nullptr )
			{
				return -1;
			}
			return m_pTop->m_Data;
		}
	};
}