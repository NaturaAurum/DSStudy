#include <random>
#include <time.h>
namespace Mystd
{
	template<typename T> inline
		void Swap( T& tr1, T& tr2 )
	{
		T Temp( tr1 );
		tr1 = tr2;
		tr2 = Temp;
	}

	// TODO : 
	// Insertion
	// Selection
	// Bubble
	// Quick
	// Merge
	namespace Sort_Insertion
	{
		// Data : 23, 78, 45, 8, 32, 56
		template<class RandomAccessIter> inline
			void Iterative( RandomAccessIter First, RandomAccessIter Last )
		{
			for ( RandomAccessIter RIter_i = ( First + 1 ); RIter_i != Last; RIter_i++ )
			{
				RandomAccessIter RIter_j = RIter_i;

				while ( RIter_j != First && *( RIter_j ) < *( RIter_j - 1 ) )
				{
					typename std::iterator_traits<RandomAccessIter>::value_type Temp = *RIter_j;
					*( RIter_j ) = *( RIter_j - 1 );
					*( RIter_j - 1 ) = Temp;
					RIter_j--;
				}
			}
		}
		template <class RandomAccessIter> inline
			void Recursive( RandomAccessIter First, RandomAccessIter Last )
		{

		}
	}

	namespace Sort_Selection
	{
		template<class RandomAccessIter> inline
			void Iterative( RandomAccessIter First, RandomAccessIter Last )
		{
			RandomAccessIter RIter_i;
			RandomAccessIter RIter_j;
			RandomAccessIter MinIter;
			for ( RIter_i = First; RIter_i != ( Last - 1 ); RIter_i++ )
			{
				MinIter = RIter_i;
				for ( RIter_j = ( RIter_i + 1 ); RIter_j != Last; RIter_j++ )
				{
					if ( *( RIter_j ) < *( MinIter ) )
					{
						MinIter = RIter_j;
					}
				}
				Swap( *( RIter_i ), *( MinIter ) );
			}
		}
		template<class RandomAccessIter> inline
			void Recursive( RandomAccessIter First, RandomAccessIter Last )
		{

		}
	}

	namespace Sort_Bubble
	{
		template<class RandomAccessIter> inline
			void Iterative( RandomAccessIter First, RandomAccessIter Last )
		{
			for ( RandomAccessIter RIter_i = First; RIter_i != Last; RIter_i++ )
			{
				for ( RandomAccessIter RIter_j = First; RIter_j < RIter_i; RIter_j++ )
				{
					if ( *( RIter_i ) < *( RIter_j ) )
					{
						Swap( *( RIter_i ), *( RIter_j ) );
					}
				}
			}
		}
		template<class RandomAccessIter> inline
			void Recursive( RandomAccessIter First, RandomAccessIter Last )
		{

		}
	}

	namespace Sort_Quick
	{
		template<class RandomAccessIter> inline
			void Iterative( RandomAccessIter First, RandomAccessIter Last )
		{

		}
		template<class RandomAccessIter> inline
			void Recursive( RandomAccessIter First, RandomAccessIter Last )
		{
			int iSize = ( Last - First );
			if ( iSize <= 0 )
				return;
			srand( time( NULL ) );
			int iPivotIndex = rand( ) % iSize + 0;
			typename std::iterator_traits<RandomAccessIter>::value_type PivotValue = *( First + iPivotIndex );
			if ( iPivotIndex != 0 )
				Swap( *( First + iPivotIndex ), *( First ) );
			int i = 1;
			for ( int j = 1; j < iSize; j++ )
			{
				if ( *( First + j ) < PivotValue )
				{
					Swap( *( First + j ), *( First + i ) );
					i++;
				}
			}

			Swap( *First, *( First + i - 1 ) );

			Recursive( First, First + i - 1 );
			Recursive( First + i, Last );
		}
	}

	namespace Sort_Merge
	{
		template<class RandomAccessIter> inline
			void Iterative( RandomAccessIter First, RandomAccessIter Last )
		{

		}

		template<class RandomAccessIter> inline
			void Recursive_MergeSort( RandomAccessIter First, RandomAccessIter Last )
		{
			int iSize = ( Last - First );
			if ( iSize < 2 )
				return;
			RandomAccessIter Mid = First + iSize / 2;
			Recursive_MergeSort( First, Mid );
			Recursive_MergeSort( Mid, Last );
			Recursive_Merge( First, Mid, Last );

		}

		template<class RandomAccessIter> inline
			void Recursive_Merge( RandomAccessIter First, RandomAccessIter Mid, RandomAccessIter Last )
		{
			while ( First < Mid )
			{
				if ( *( Mid ) < *( First ) )
				{
					typename std::iterator_traits<RandomAccessIter>::value_type _Value;
					Swap( _Value, *( First ) );
					Swap( *( First ), *( Mid ) );
					Recursive_Insert( Mid, Last, _Value );
				}
				++First;
			}
		}

		template<class RandomAccessIter, class Type> inline
			void Recursive_Insert( RandomAccessIter First, RandomAccessIter Last, Type TypeValue )
		{
			while ( ( First + 1 ) != Last && *( First + 1 ) < TypeValue )
			{
				Swap( *( First ), *( First + 1 ) );
				++First;
			}
			Swap( *( First ), TypeValue );
		}
	}
}