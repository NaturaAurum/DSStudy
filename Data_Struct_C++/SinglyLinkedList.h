#pragma once

#include <iostream>

template <typename T> struct SNode
{
	T Data;
	SNode<T>* pNextNode;
};

template <typename T> class SLL
{
private:
	SNode<T>* m_SLList;
public:
	SLL( )
	{
		m_SLList = nullptr;
	}
	~SLL( )
	{
		if ( m_SLList != nullptr )
		{
			this->RemoveAll( );
		}
	}
private:
	SNode<T>* CreateSNode( T Data )
	{
		SNode<T>* tpSNode = new SNode<T>( );
		tpSNode->Data = Data;
		tpSNode->pNextNode = nullptr;

		return tpSNode;
	}
	void DestrySNode( SNode<T>* Target )
	{
		delete Target;
		Target = nullptr;
	}
	SNode<T>* GetSNode( int Index )
	{
		SNode<T>* tpCurrentSNode = m_SLList;
		int iPosition = 0;
		while ( tpCurrentSNode->pNextNode != nullptr && iPosition != Index )
		{
			tpCurrentSNode = tpCurrentSNode->pNextNode;
			iPosition++;
		}

		return tpCurrentSNode;
	}
public:
	void push_back( T Data )
	{
		SNode<T>* tpSNode = this->CreateSNode( Data );
		if ( m_SLList == nullptr )
		{
			m_SLList = tpSNode;
		}
		else
		{
			if ( m_SLList->pNextNode == nullptr )
			{
				m_SLList->pNextNode = tpSNode;
			}
			else
			{
				SNode<T>* Tail = m_SLList;
				while ( Tail->pNextNode != nullptr )
				{
					Tail = Tail->pNextNode;
				}

				Tail->pNextNode = tpSNode;
			}
		}
	}
	void Insert( T Data, int Index )
	{
		if ( m_SLList == nullptr )
		{
			this->push_back( Data );
		}
		else
		{
			SNode<T>* tpSNode = this->CreateSNode( Data );
			SNode<T>* tpCurrentSNode = m_SLList;
			int iPosition = 0;
			while ( tpCurrentSNode != nullptr && iPosition != Index )
			{
				tpCurrentSNode = tpCurrentSNode->pNextNode;
				iPosition++;
			}

			tpSNode->pNextNode = tpCurrentSNode->pNextNode;
			tpCurrentSNode->pNextNode = tpSNode;
		}
	}
	void Remove( T Target )
	{
		if ( m_SLList == nullptr )
		{
			return;
		}
		else
		{
			SNode<T>* tpCurrentSNode = m_SLList;
			SNode<T>* pTargetSNode = this->GetSNode( Target );
			//int iPosition = 0;
			while ( tpCurrentSNode != nullptr && tpCurrentSNode->pNextNode->Data != Target )
			{
				tpCurrentSNode = tpCurrentSNode->pNextNode;
			}

			tpCurrentSNode->pNextNode = pTargetSNode->pNextNode;

			this->DestrySNode( pTargetSNode );
		}
	}

	void RemoveByName( char* strName )
	{
		if ( m_SLList == nullptr )
		{
			return;
		}
		else
		{
			
			SNode<T>* tpCurrentSNode = m_SLList;
			SNode<T>* pTargetSNode = m_SLList;
			if ( *m_SLList->Data->m_strName == *strName )
			{
				m_SLList = m_SLList->pNextNode;
				this->DestrySNode( pTargetSNode );
			}
			//int iPosition = 0;
			while ( pTargetSNode != nullptr )
			{
				if ( *pTargetSNode->Data->m_strName == *strName )
				{
					break;
				}
				pTargetSNode = pTargetSNode->pNextNode;
			}
			while ( tpCurrentSNode != nullptr  )
			{
				if ( *tpCurrentSNode->pNextNode->Data->m_strName == *strName )
				{
					break;
				}
				tpCurrentSNode = tpCurrentSNode->pNextNode;
			}
			tpCurrentSNode->pNextNode = pTargetSNode->pNextNode;

			this->DestrySNode( pTargetSNode );
		}
	}

	void RemoveAll( )
	{
		SNode<T>* tpRemoveTargetSNode = nullptr;

		while ( m_SLList != nullptr )
		{
			tpRemoveTargetSNode = m_SLList;
			m_SLList = m_SLList->pNextNode;
			this->DestrySNode( tpRemoveTargetSNode );
		}

		this->DestrySNode( m_SLList );
	}

	int ListCount( )
	{
		int iCount = 0;

		SNode<T>* tpCurrentSNode = m_SLList;

		while ( tpCurrentSNode != nullptr )
		{
			tpCurrentSNode = tpCurrentSNode->pNextNode;
			iCount++;
		}

		return iCount;
	}

	T& FindByName( char* strName )
	{
		SNode<T>* tpCurrentNode = m_SLList;

		while ( tpCurrentNode->pNextNode != nullptr &&
				*tpCurrentNode->Data->m_strName != *strName )
		{
			tpCurrentNode = tpCurrentNode->pNextNode;
		}

		return tpCurrentNode->Data;
	}

	bool isEmpty( )
	{
		if ( m_SLList == nullptr )
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	T operator[]( const int Index )
	{
		return GetSNode( Index )->Data;
	}
};

