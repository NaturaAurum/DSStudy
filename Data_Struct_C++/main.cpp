#include <iostream>
#include <vector>
#include <list>
#include <time.h>
#include "SinglyLinkedList.h"
#include "DoubleLinkedList.h"
#include <vector>
#include <algorithm>
#include <string>
#include "MySort.h"
#include "Stack.h"
#include "Queue.h"
#include "Tree.h"
#include "Devide_and_Qonquer.h"
class CPerson
{
public:
	char* m_strName;
	int m_iMathScore;
	int m_iInfoScore;

public:
	CPerson( char* strName, int MathScore, int InfoScore )
	{
		this->m_strName = strName;
		this->m_iMathScore = MathScore;
		this->m_iInfoScore = InfoScore;
	}
	~CPerson( )
	{

	}

	void Print( )
	{
		std::cout << "이름 : " << m_strName << std::endl;
		std::cout << "수학 성적 : " << m_iMathScore << std::endl;
		std::cout << "정보 성적 : " << m_iInfoScore << std::endl;
	}
};

void Singly_Linked_List( );
void Double_Linked_List( );
void ArrayStackFunc( );
void LinkedListStackFunc( );
void D_ArrayStack( );

void Vector_Sort( );

void ArrayQueueTest( );
void ListQueueTest( );
void ArrayBinaryTreeTest( );
void ScoreManager( );
void CalStack( );
void BSTreeFunc( );
void HeapTreeFunc( );
void DAQFunc( );

/////////////////////// MAIN ////////////////////////
void main( )
{
	Vector_Sort( );
}
/////////////////////// MAIN ////////////////////////

void Singly_Linked_List( )
{
	SLL<int> m_singleList;

	srand( time( NULL ) );

	for ( int i = 0; i < 10; i++ )
	{
		m_singleList.push_back( i * rand( ) % 10 + 1 );
	}

	m_singleList.Insert( 50, 4 );

	for ( int i = 0; i < m_singleList.ListCount( ); i++ )
	{
		std::cout << m_singleList[ i ] << std::endl;
	}

	m_singleList.Remove( 50 );
	std::cout << std::endl;
	for ( int i = 0; i < m_singleList.ListCount( ); i++ )
	{
		std::cout << m_singleList[ i ] << std::endl;
	}

	m_singleList.RemoveAll( );
}

void Double_Linked_List( )
{
	DLL<int> m_DoubleLinkedList;

	srand( time( NULL ) );

	for ( int i = 0; i < 10; i++ )
	{
		m_DoubleLinkedList.push_back( i );
	}

	m_DoubleLinkedList.insert( 3, 40 );

	for ( int i = 0; i < m_DoubleLinkedList.Count( ); i++ )
	{
		std::cout << m_DoubleLinkedList[ i ] << std::endl;
	}

	m_DoubleLinkedList.remove( 40 );
	std::cout << std::endl;

	for ( int i = 0; i < m_DoubleLinkedList.Count( ); i++ )
	{
		std::cout << m_DoubleLinkedList[ i ] << std::endl;
	}
	m_DoubleLinkedList.removeAll( );
}

void ArrayStackFunc( )
{
	nArrayStack::ArrayStack<int>* m_ArrayStack = new nArrayStack::ArrayStack<int>( 6 );

	//int data[ ] = { 13, 24, 78, 65, 0 };

	m_ArrayStack->Push( 13 );
	m_ArrayStack->Push( 24 );
	m_ArrayStack->Push( 78 );

	std::cout << m_ArrayStack->Peek( ) << std::endl;
	std::cout << m_ArrayStack->Pop( ) << std::endl;
	m_ArrayStack->Push( 65 );

	std::cout << m_ArrayStack->Pop( ) << std::endl;
	std::cout << m_ArrayStack->Pop( ) << std::endl;

	std::cout << m_ArrayStack->Peek( ) << std::endl;
	m_ArrayStack->Push( 0 );

	std::cout << m_ArrayStack->Pop( ) << std::endl;
	std::cout << m_ArrayStack->Pop( ) << std::endl;

	std::cout << m_ArrayStack->Peek( ) << std::endl;
	m_ArrayStack->Push( 13 );
	m_ArrayStack->Push( 24 );

	std::cout << m_ArrayStack->Pop( ) << std::endl;

	m_ArrayStack->Push( 78 );
	m_ArrayStack->Push( 65 );

	std::cout << m_ArrayStack->Pop( ) << std::endl;

	std::cout << m_ArrayStack->Peek( ) << std::endl;
	m_ArrayStack->Push( 0 );
	m_ArrayStack->Push( 13 );
	m_ArrayStack->Push( 24 );

	std::cout << m_ArrayStack->Pop( ) << std::endl;
	std::cout << m_ArrayStack->Pop( ) << std::endl;
	std::cout << m_ArrayStack->Pop( ) << std::endl;
	std::cout << m_ArrayStack->Pop( ) << std::endl;
}

void LinkedListStackFunc( )
{
	nLinkedListStack::ListStack<int>* m_ListStack = new nLinkedListStack::ListStack<int>( );

	m_ListStack->Push( 13 );
	m_ListStack->Push( 24 );
	m_ListStack->Push( 78 );

	std::cout << m_ListStack->Peek( ) << std::endl;
	std::cout << m_ListStack->Pop( ) << std::endl;
	m_ListStack->Push( 65 );

	std::cout << m_ListStack->Pop( ) << std::endl;
	std::cout << m_ListStack->Pop( ) << std::endl;

	std::cout << m_ListStack->Peek( ) << std::endl;
	m_ListStack->Push( 0 );

	std::cout << m_ListStack->Pop( ) << std::endl;
	std::cout << m_ListStack->Pop( ) << std::endl;

	std::cout << m_ListStack->Peek( ) << std::endl;
	m_ListStack->Push( 13 );
	m_ListStack->Push( 24 );

	std::cout << m_ListStack->Pop( ) << std::endl;

	m_ListStack->Push( 78 );
	m_ListStack->Push( 65 );

	std::cout << m_ListStack->Pop( ) << std::endl;

	std::cout << m_ListStack->Peek( ) << std::endl;
	m_ListStack->Push( 0 );
	m_ListStack->Push( 13 );
	m_ListStack->Push( 24 );

	std::cout << m_ListStack->Pop( ) << std::endl;
	std::cout << m_ListStack->Pop( ) << std::endl;
	std::cout << m_ListStack->Pop( ) << std::endl;
	std::cout << m_ListStack->Pop( ) << std::endl;
}

void D_ArrayStack( )
{
	srand( time( NULL ) );

	DualStack::ArrayStack<int>* m_B_ArrayStack = new DualStack::ArrayStack<int>( 10 );

	int Data[ ] = { 2, 4, -3, -5, 3, 10, -16, 9, 29, 30 };

	for ( int i = 0; i < 10; i++ )
	{
		//int Temp = rand( ) % 20 - 10;
		m_B_ArrayStack->Push( Data[ i ] );
	}

	std::cout << m_B_ArrayStack->Pop( "P" ) << std::endl;
	std::cout << m_B_ArrayStack->Pop( "N" ) << std::endl;
}

void Vector_Sort( )
{
	const std::vector<int> original_Datas = { 23, 78, 45, 8, 32, 56 };
	//const std::vector<int> original_Datas2 = { 20, 18, 50, 40, 9, 19, 5, 25 };
	std::vector<int> Datas( original_Datas );
	//std::vector<int> Datas2( original_Datas2 );

	//Mystd::Sort_Insertion::Iterative( Datas.begin( ), Datas.end( ) );
	//Mystd::Sort_Insertion::Recursive( Datas.begin( ), Datas.end( ) );
	//Mystd::Sort_Selection::Iterative( Datas.begin( ), Datas.end( ) );
	//Mystd::Sort_Selection::Recursive( Datas.begin( ), Datas.end( ) );
	//Mystd::Sort_Bubble::Iterative( Datas.begin( ), Datas.end( ) );
	//Mystd::Sort_Bubble::Recursive( Datas.begin( ), Datas.end( ) );
	//Mystd::Sort_Quick::Recursive( Datas2.begin( ), Datas2.end( ) );
	//Mystd::Sort_Merge::Recursive_MergeSort( Datas2.begin( ), Datas2.end( ) );

	for ( auto iter : Datas )
	{
		std::cout << ( iter ) << std::endl;
	}
}

void ArrayQueueTest( )
{
	ArrayQueue::CArrayQueue<int>* Queue = new ArrayQueue::CArrayQueue<int>( );

	Queue->Insert( 12 );
	Queue->Insert( 11 );
	Queue->Insert( 17 );
	Queue->Insert( 16 );
	std::cout << Queue->DeleteQueue( ) << std::endl;
	Queue->Insert( 14 );
	Queue->Insert( 13 );
}

void ListQueueTest( )
{
	ListQueue::CListQueue<int>* LQueue = new ListQueue::CListQueue<int>( );

	LQueue->Enqueue( 12 );
	LQueue->Enqueue( 11 );

	LQueue->Enqueue( 17 );
	LQueue->Enqueue( 16 );
	std::cout << LQueue->Dequeue( ) << std::endl;
	LQueue->Enqueue( 14 );
	LQueue->Enqueue( 13 );
}

void ArrayBinaryTreeTest( )
{

	char Alphabet[ 16 ] = { 0, 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'
		, 'I', 'J', 'K', 'L', 'M', 0, 0 };

	ArrayBinaryTree::CArrayBinaryTree<char>* BTree =
		new ArrayBinaryTree::CArrayBinaryTree<char>( 16 );

	for ( int i = 0; i < 16; i++ )
	{
		BTree->Add( Alphabet[ i ] );
	}

	BTree->Print( );
	BTree->Print( 'B', 0 );
	BTree->Print( 'C', 0 );
	BTree->Print( 'K', 1 );
}


void ScoreManager( )
{
	int State = 0;
	SLL<CPerson*>* studentScores = new SLL<CPerson*>( );

	while ( State != 5 )
	{
		std::cout << "1.삽입 2.찾기 3.삭제 4.출력 5.종료" << std::endl;
		std::cin >> State;
		//std::cout << std::endl;
		char* strName = new char[ 10 ];
		int MathScore = 0;
		int InfoScore = 0;
		switch ( State )
		{
			case 1:
				std::cout << "학생정보를 입력" << std::endl;
				std::cout << "이름 : ";

				std::cin >> strName;
				std::cout << "수학 성적 : ";

				std::cin >> MathScore;
				std::cout << "정보 성적 : ";

				std::cin >> InfoScore;
				studentScores->push_back( new CPerson( strName, MathScore, InfoScore ) );
				break;
			case 2:
				std::cout << "이름 : ";
				std::cin >> strName;
				studentScores->FindByName( strName )->Print( );
				break;
			case 3:
				std::cout << "삭제할 학생 이름 : ";
				std::cin >> strName;
				studentScores->RemoveByName( strName );
				break;
			case 4:
				for ( int i = 0; i < studentScores->ListCount( ); i++ )
				{
					studentScores->operator[]( i )->Print( );
				}
				break;
			default:
				break;
		}
	}
}

void CalStack( )
{
	EquationStack::CEquationStack* EStack = new EquationStack::CEquationStack( );

	EStack->Input( );
	EStack->Print( );
}

void BSTreeFunc( )
{
	BinarySearchTree::CBinarySearchTree<int>* bsTree = new BinarySearchTree::CBinarySearchTree<int>( );
	int Datas[ ] = { 6, 2, 0, 5, 4, 10, 19, 11 };
	for ( int i = 0; i < 8; i++ )
	{
		bsTree->Insert( Datas[ i ] );
	}

	bsTree->Inorder( );
	std::cout << std::endl;

	bsTree->Remove( 11 );
	bsTree->Inorder( );
	std::cout << std::endl;
	bsTree->Remove( 10 );
	bsTree->Inorder( );
	std::cout << std::endl;
	bsTree->Remove( 2 );
	bsTree->Inorder( );
	std::cout << std::endl;

	bsTree->~CBinarySearchTree( );
}

void HeapTreeFunc( )
{
	int Datas[ ] = { 6,5,3,1,8,7,2,4 };
	HeapTree::CHeapTree<int>* HTree = new HeapTree::CHeapTree<int>( 8 );

	for ( int i = 0; i < 8; i++ )
	{
		HTree->Insert( Datas[ i ] );
	}

	HTree->Print( );
}

void DAQFunc( )
{
	std::vector<int>* Datas = new std::vector<int>( );

	for ( int i = 1; i <= 100; i++ )
	{
		Datas->push_back( i );
	}

	BinarySearch::Iterative( Datas->begin( ), Datas->end( ), 77 );
	BinarySearch::Recursive( Datas->begin( ), Datas->end( ), 77 );


}