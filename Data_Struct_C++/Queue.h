
#include <iostream>
namespace ArrayQueue
{
	template <class _Type> class CArrayQueue
	{
	private: 
		int _Front, _Tail, _Max = 5;
		_Type Queue[ 5 ];
	public:
		CArrayQueue( )
		{
			_Front = -1;
			_Tail = -1;
		}
		void Insert( _Type _Item )
		{
			if ( _Tail == _Max - 1 )
			{
				std::cout << "OverFlow" << std::endl;
			}
			else
			{
				Queue[ _Tail++ ] = _Item;
			}
		}
		_Type DeleteQueue( )
		{
			if ( _Tail == -1 )
			{
				std::cout << "UnderFlow" << std::endl;
			}
			else
			{
				if ( _Front == _Max - 1 )
				{
					return -1;
				}
				return Queue[ _Front++ ];
			}
		}
	};
}
namespace ListQueue
{
	template <class _Type> class QNode
	{
	public:
		_Type m_Item;
		QNode<_Type>* m_pNext;

		QNode( _Type _Item )
		{
			m_Item = _Item;
			m_pNext = nullptr;
		}
	};

	template <class _Type> class CListQueue
	{
	private:
		QNode<_Type>* m_pFront;
		QNode<_Type>* m_pTail;
		QNode<_Type>* m_pQueue;

		void DestroyNode( QNode<_Type>* pTarget )
		{
			delete pTarget;
			pTarget = nullptr;
		}
		void Release( )
		{
			while ( m_pQueue != nullptr )
			{
				QNode<_Type>* pTarget = m_pQueue;
				m_pQueue = m_pQueue->m_pNext;
				DestroyNode( pTarget );
			}

			DestroyNode( m_pQueue );
			DestroyNode( m_pFront );
			DestroyNode( m_pTail );
		}
	public:
		CListQueue( )
		{
			m_pFront = nullptr; 
			m_pTail = nullptr;  
			m_pQueue = nullptr;
		}
		~CListQueue( )
		{

		}
		void Enqueue( _Type _Item )
		{
			if ( m_pQueue == nullptr )
			{
				m_pQueue = new QNode<_Type>( _Item );
				m_pFront = m_pQueue;
				m_pTail = m_pQueue;
			}
			else
			{
				QNode<_Type>* pNewNode = new QNode<_Type>( _Item );
				m_pTail->m_pNext = pNewNode;
				m_pTail = pNewNode;
			}
		}
		_Type Dequeue( )
		{
			QNode<_Type>* Temp = m_pFront;
			_Type _Value = Temp->m_Item;
			m_pFront = m_pFront->m_pNext;
			DestroyNode( Temp );
			return _Value;
		}
	};
}
namespace MovingQueue
{
	template <class _Type> class CMovingQueue
	{
	private:
		int _Front, _Tail, _Max = 5;
		_Type Queue[ 5 ];
	public:
		CMovingQueue( )
		{
			_Front = -1;
			_Tail = -1;
		}
		void Insert( _Type _Item )
		{
			if ( _Tail == _Max - 1 )
			{
				std::cout << "OverFlow" << std::endl;
			}
			else
			{
				Queue[ _Tail++ ] = _Item;
			}
		}
		_Type DeleteQueue( )
		{
			if ( _Tail == -1 )
			{
				std::cout << "UnderFlow" << std::endl;
			}
			else
			{
				if ( _Front == _Max - 1 )
				{
					return -1;
				}
				return Queue[ _Front++ ];
			}
		}
	};
}

namespace CircleQueue
{

}