#include <iostream>

namespace ArrayBinaryTree
{
	template <class _Type> class atNode
	{
	public:
		_Type m_Item;
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
				m_pArrayNodes[ m_Index ].m_Item = _Item;
				m_Index++;
			}
		}

		void Print( )
		{
			for ( int i = 0; i < m_iCapacity; i++ )
			{
				std::cout << m_pArrayNodes[ i ].m_Item << " ";
			}
			std::cout << std::endl;
		}

		void Print( _Type Target, int _Mode )
		{
			int Index = 0;
			while ( m_pArrayNodes[ ++Index ].m_Item != Target );
			if ( _Mode == 0 ) // 자식
			{
				std::cout << m_pArrayNodes[ Index * 2 ].m_Item
					<< " " << m_pArrayNodes[ Index * 2 + 1 ].m_Item
					<< std::endl;
				return;
			}
			else // 조상
			{
				while ( ( Index /= 2 ) >= 1 )
				{
					std::cout << m_pArrayNodes[ Index ].m_Item
						<< " ";
				}
				std::cout << std::endl;
			}
		}

	};
}
namespace ListBinaryTree
{
	template <class _Type> class ltNode
	{
	public:
		_Type m_Item;
		ltNode<_Type>* m_pLeft;
		ltNode<_Type>* m_pRight;

		ltNode( _Type _Item )
		{
			m_Item = _Item;
			m_pLeft = nullptr;
			m_pRight = nullptr;
		}
	};

	template <class _Type> class CListBinaryTree
	{
	private:
		ltNode<_Type>* m_pBTree;
		ltNode<_Type>* m_pRecentNode;
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
				m_pBTree = new ltNode<_Type>( _Item );
				m_pRecentNode = m_pBTree;
			}
			else
			{
				ltNode<_Type>* pNewNode = new ltNode<_Type>( _Item );
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

		void PostOrder( )
		{

		}

		void Release( )
		{

		}
	};
}
namespace EquationBinaryTree
{
	class eNode
	{
	public:
		char m_chItem;
		eNode* m_pLeft;
		eNode* m_pRight;

		eNode( char chItem )
		{
			m_chItem = chItem;
			m_pLeft = nullptr;
			m_pRight = nullptr;
		}
	};
	class CEBTree
	{
	private:
		eNode* m_pEBTree;

		void DestroyNode( eNode* pTarget )
		{
			delete pTarget;
			pTarget = nullptr;
		}

		void DestroyTree( eNode* pRoot )
		{
			if ( pRoot == nullptr )
			{
				return;
			}

			DestroyTree( pRoot->m_pLeft );
			DestroyTree( pRoot->m_pRight );
			DestroyNode( pRoot );
		}

	public:
		CEBTree( )
		{

		}
		CEBTree( char chItem )
		{
			this->CreateTree( chItem );
		}
		~CEBTree( )
		{
			DestroyTree( m_pEBTree );
		}
		void CreateTree( char chItem )
		{
			m_pEBTree = new eNode( chItem );
		}

		void Add( char chItem )
		{
			Add( chItem, &m_pEBTree );
		}

		void Add( char chItem, eNode** pNode )
		{
			switch ( chItem )
			{
				case '+':
				case '-':
				case '/':
				case '*':
				case '%':
					break;
				default:
					break;
			}
		}

	};
}
namespace BinarySearchTree
{
	template<class Type> class bstNode
	{
	public:
		Type m_Item;
		bstNode<Type>* m_pLeft;
		bstNode<Type>* m_pRight;

		bstNode<Type>( Type Item )
		{
			m_Item = Item;
			m_pLeft = nullptr;
			m_pRight = nullptr;
		}
	};
	template<class Type> class CBinarySearchTree
	{
	private:
		bstNode<Type>* m_pBstNode;

		void DestroyNode( bstNode<Type>* pTarget )
		{
			delete pTarget;
			pTarget = nullptr;
		}

		void DestoryTree( bstNode<Type>* pTree )
		{
			if ( pTree->m_pRight != nullptr )
				DestoryTree( pTree->m_pRight );
			if ( pTree->m_pLeft != nullptr )
				DestoryTree( pTree->m_pLeft );

			pTree->m_pLeft = nullptr;
			pTree->m_pRight = nullptr;
			DestroyNode( pTree );

			std::cout << "Destory" << std::endl;
		}
	public:
		CBinarySearchTree<Type>( )
		{

		}
		CBinarySearchTree<Type>( Type Item )
		{
			this->CreateNode( Item );
		}

		~CBinarySearchTree( )
		{
			this->DestoryTree( m_pBstNode );
		}

		void CreateTree( Type Item )
		{
			m_pBstNode = new bstNode<Type>( Item );
		}
	public:
		void Insert( Type Item )
		{
			if ( m_pBstNode == nullptr )
				this->CreateTree( Item );
			this->Insert( m_pBstNode, new bstNode<Type>( Item ) );
		}
	private:
		void Insert( bstNode<Type>* pTree, bstNode<Type>* pChild )
		{
			if ( pTree->m_Item < pChild->m_Item )
			{
				if ( pTree->m_pRight == nullptr )
				{
					pTree->m_pRight = pChild;
				}
				else
				{
					Insert( pTree->m_pRight, pChild );
				}
			}
			else if ( pTree->m_Item > pChild->m_Item )
			{
				if ( pTree->m_pLeft == nullptr )
				{
					pTree->m_pLeft = pChild;
				}
				else
				{
					Insert( pTree->m_pLeft, pChild );
				}
			}
		}
	public:
		void Remove( Type Item )
		{
			DestroyNode( Remove( m_pBstNode, nullptr, Item ) );
		}
	private:
		bstNode<Type>* Remove( bstNode<Type>* pTree, bstNode<Type>* pParent, Type Item )
		{
			if ( pTree == nullptr )
				return nullptr;

			bstNode<Type>* pRemoveTarget = nullptr;

			if ( pTree->m_Item > Item )
			{
				pRemoveTarget = Remove( pTree->m_pLeft, pTree, Item );
			}
			else if ( pTree->m_Item < Item )
			{
				pRemoveTarget = Remove( pTree->m_pRight, pTree, Item );
			}
			else
			{
				pRemoveTarget = pTree;
				if ( pRemoveTarget->m_pLeft == nullptr && pRemoveTarget->m_pRight == nullptr )
				{
					if ( pParent->m_pLeft == pTree )
						pParent->m_pLeft = nullptr;
					else
						pParent->m_pRight = nullptr;
				}
				else
				{
					if ( pTree->m_pLeft != nullptr && pTree->m_pRight != nullptr )
					{
						bstNode<Type>* pMinNode = FindMinNode( pTree->m_pRight );
						pMinNode = Remove( pTree, nullptr, pMinNode->m_Item );
						pTree->m_Item = pMinNode->m_Item;
						pRemoveTarget = pMinNode;
					}
					else
					{
						bstNode<Type>* pTemp = nullptr;
						if ( pTree->m_pLeft != nullptr )
							pTemp = pTree->m_pLeft;
						else
							pTemp = pTree->m_pRight;

						if ( pParent->m_pLeft == pTree )
							pParent->m_pLeft = pTemp;
						else
							pParent->m_pRight = pTemp;
					}
				}
			}

			return pRemoveTarget;
		}
	public:
		Type Search( Type Item )
		{
			return Search( m_pBstNode, Item );
		}
	private:
		Type Search( bstNode<Type>* pTree, Type Item )
		{
			if ( pTree == nullptr )
				return 0;

			if ( pTree->m_Item < Item )
			{
				return Search( pTree->m_pRight, Item );
			}
			else if ( pTree->m_Item > Item )
			{
				return Search( pTree->m_pLeft, Item );
			}
			else
			{
				return pTree->m_Item;
			}
		}

		bstNode<Type>* FindMinNode( bstNode<Type>* pTarget )
		{
			if ( pTarget == nullptr )
			{
				return nullptr;
			}
			if ( pTarget->m_pLeft == nullptr )
				return pTarget;
			else
				return FindMinNode( pTarget->m_pLeft );
		}
	public:
		void Inorder( )
		{
			Inorder( m_pBstNode );
		}
		void Inorder( bstNode<Type>* pNode )
		{
			if ( pNode == nullptr )
				return;

			Inorder( pNode->m_pLeft );

			std::cout << pNode->m_Item << " ";

			Inorder( pNode->m_pRight );
		}
	};
}