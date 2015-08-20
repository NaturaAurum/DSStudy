#pragma once

#include <iostream>

template <class T> class Dnode
{
public:
	T m_Data;
	Dnode<T>* m_pNextNode;
	Dnode<T>* m_pPrevNode;
public:
	Dnode<T>( )
	{
		m_Data = NULL;
		m_pNextNode = nullptr;
		m_pPrevNode = nullptr;
	}

	Dnode<T>( T Data )
	{
		m_Data = Data;
		m_pNextNode = nullptr;
		m_pPrevNode = nullptr;
	}

	~Dnode( )
	{

	}
};

template <class T> class DLL
{
private:
	Dnode<T>* m_DLList;

	Dnode<T>* m_pHead; // For Quick Sort
	Dnode<T>* m_pTail; // For QuickSort
public:
	DLL( )
	{
		m_DLList = nullptr;
	}

	~DLL( )
	{

	}
private:
	void DestoryDnode( Dnode<T>* Target )
	{
		delete Target;
		Target = nullptr;
	}
	Dnode<T>* GetDnode( T Target )
	{
		Dnode<T>* pTail = m_DLList;
		while ( pTail != nullptr && pTail->m_Data != Target )
		{
			pTail = pTail->m_pNextNode;
		}

		return pTail;
	}
public:
	void push_back( T Data )
	{
		Dnode<T>* pNewDnode = new Dnode<T>( Data );
		if ( m_DLList == nullptr )
		{
			m_DLList = pNewDnode;
			m_pHead = m_DLList;
		}
		else
		{
			Dnode<T>* pTail = m_DLList;
			while ( pTail->m_pNextNode != nullptr )
			{
				pTail = pTail->m_pNextNode;
			}

			pTail->m_pNextNode = pNewDnode;
			pNewDnode->m_pPrevNode = pTail;

			m_pTail = pTail;
		}
	}

	void insert( int Index, T Data )
	{
		if ( m_DLList == nullptr )
		{
			std::cout << "��û�Ͻ� Index�� �������� �ʽ��ϴ�. " << std::endl <<
				"push_back���� �����͸� ���� �ڿ� �����մϴ�." << std::endl;
			this->push_back( Data );
		}
		else
		{
			Dnode<T>* pNewDnode = new Dnode<T>( Data );
			Dnode<T>* pTail = m_DLList;
			int iPosition = 0;
			while ( pTail != nullptr && iPosition != Index )
			{
				pTail = pTail->m_pNextNode;
				iPosition++;
			}

			if ( iPosition > Index )
			{
				std::cout << "��û�Ͻ� Index�� �ִ� ���̸� �Ѿ�ϴ�." << std::endl
					<< "�����͸� ���� �ڿ� �����մϴ�." << std::endl;
			}

			/*pNewDnode->m_pPrevNode = pTail->m_pPrevNode;
			pTail->m_pPrevNode->m_pNextNode = pNewDnode;
			pTail->m_pPrevNode = pNewDnode;
			pNewDnode->m_pNextNode = pTail;*/

			if ( pTail != nullptr )
			{
				pNewDnode->m_pNextNode = pTail;
				pTail->m_pPrevNode->m_pNextNode = pNewDnode;
				pTail->m_pPrevNode = pNewDnode;
				pNewDnode->m_pPrevNode = pTail->m_pPrevNode;
			}

			if ( pNewDnode->m_pNextNode == nullptr )
			{
				m_pTail = pNewDnode;
			}
		}
	}

	void remove( T Target )
	{
		if ( m_DLList == nullptr )
		{
			std::cout << "ERROR : List�� ����ֽ��ϴ�." << std::endl;
			return;
		}

		else
		{
			Dnode<T>* pTail = m_DLList;
			Dnode<T>* pTargetDnode = this->GetDnode( Target );
			while ( pTail != nullptr &&
					pTail->m_pNextNode->m_Data != Target )
			{
				pTail = pTail->m_pNextNode;
			}

			if ( pTail == nullptr )
			{
				std::cout << "EROOR : �������� �ʴ� Data �Դϴ�." << std::endl;
			}

			pTail->m_pNextNode = pTargetDnode->m_pNextNode;
			pTargetDnode->m_pNextNode->m_pPrevNode = pTail;

			//this->DestroyDnode( pTargetDnode );

			if ( pTail->m_pNextNode == nullptr )
			{
				m_pTail = pTail;
			}
		}
	}

	void removeAll( )
	{
		Dnode<T>* pDnode = nullptr;
		while ( m_DLList != nullptr )
		{
			pDnode = m_DLList;
			m_DLList = m_DLList->m_pNextNode;
			this->DestoryDnode( pDnode );
		}

		this->DestoryDnode( m_DLList );
	}

	void Sort( int iMode ) // Quick Sort
	{
		int iLeft = 1, iRight, iTotal;

		iTotal = this->Count( );
		iRight = iTotal;

		if ( iRight <= 0 )
		{
			std::cout << "���� �Ұ�" << std::endl;
			return;
		}
	}

	int Count( )
	{
		int iCount = 0;

		Dnode<T>* pTail = m_DLList;

		while ( pTail != nullptr )
		{
			pTail = pTail->m_pNextNode;
			iCount++;
		}

		return iCount;
	}

	T operator[]( const int Index )
	{
		Dnode<T>* pTail = m_DLList;
		int iPosition = 0;
		while ( pTail->m_pNextNode != nullptr && iPosition != Index )
		{
			pTail = pTail->m_pNextNode;
			iPosition++;
		}
		return pTail->m_Data;
	}
};

