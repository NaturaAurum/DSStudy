#include <iostream>
#include <string>

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
			Type _Value = NULL;
			if ( !( m_pTop == nullptr ) )
			{
				asNode<Type>* pTemp = m_pTop;
				_Value = pTemp->m_Data;
				m_pTop = pTemp->m_pNextNode;

				DestoryNode( pTemp );
			}
			else
			{

			}
			
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

namespace EquationStack
{
	class CEquationStack
	{
	private:
		std::string m_strEquation;
		nLinkedListStack::ListStack<char>* m_OperStack;
		nLinkedListStack::ListStack<char>* m_AriExpStack;
		int m_iResult;
		void Loop( )
		{
			int iPosition = 0;

			while ( m_strEquation[ iPosition ] != '\0' )
			{
				if ( CheakOper( m_strEquation[ iPosition ] ) == 0 )
				{
					m_AriExpStack->Push( m_strEquation[ iPosition ] );
				}
				else if ( CheakOper( m_strEquation[ iPosition ] ) == 2 )
				{
					while ( true )
					{
						char Temp = m_OperStack->Pop( );
						if ( Temp == '(' || Temp == NULL)
							break;
						m_AriExpStack->Push( Temp );
					}
				}
				else
				{
					char Temp = NULL;
					if ( m_strEquation[ iPosition ] == '(' )
					{
						m_OperStack->Push( m_strEquation[ iPosition ] );
						iPosition++;
						continue;
					}
					if ( m_OperStack->Peek( ) != -1 )
					{
						Temp = m_OperStack->Pop( );
					}
					if ( isPrior( Temp, m_strEquation[ iPosition ] ) == false && Temp != NULL && Temp != '(' )
						m_AriExpStack->Push( Temp );
					m_OperStack->Push( m_strEquation[ iPosition ] );
				}
				iPosition++;
			}

			char Temp;
			while ( ( Temp = m_OperStack->Pop( ) ) != NULL )
			{
				m_AriExpStack->Push( Temp );
			}
		}

		int CheakOper( char chTarget )
		{
			switch ( chTarget )
			{
				case '+':
				case '-':
				case '/':
				case '%':
				case '*':
				case '(':
					return 1;
				case ')':
					return 2;
				default:
					return 0;
			}
		}

		bool isPrior( char chOperInStack, char chOperInToken )
		{
			return ( GetPriority( chOperInStack, true ) > GetPriority( chOperInToken, false ) );
		}

		int GetPriority( char chOper, bool isInStack )
		{
			int iPriority = -1;

			switch ( chOper )
			{
				case '(':
					if ( isInStack )
						iPriority = 3;
					else
						iPriority = 0;
					break;
				case '*':
				case '/':
				case '%':
					iPriority = 1;
					break;
				case '+':
				case '-':
					iPriority = 2;
					break;
				default:
					break;
			}

			return iPriority;
		}
	public:
		CEquationStack( )
		{
			m_OperStack = new nLinkedListStack::ListStack<char>( );
			m_AriExpStack = new nLinkedListStack::ListStack<char>( );
		}
		~CEquationStack( )
		{

		}

		void Input( )
		{
			std::cout << "½ÄÀÔ·Â" << std::endl;
			std::cin >> m_strEquation;
		}

		void Print( )
		{
			this->Loop( );
			char Oper;
			char Oper1;
			char Oper2;

			while ( m_AriExpStack != nullptr )
			{
				Oper = m_AriExpStack->Peek( );
				if ( CheakOper( Oper ) == 0 )
				{
					Oper1 = m_AriExpStack->Pop( );
					Oper2 = m_AriExpStack->Pop( );
				}
				else if ( CheakOper( Oper ) == 1 )
				{
					switch ( m_AriExpStack->Pop( ) )
					{
						case '+':
							//m_iResult = ( ( Oper1 - '0' ) + ( Oper1 - '0' ) );
						case '-':
						case '/':
						case '%':
						case '*':
						default:
							break;
					}
				}
			}
		}
	};
}