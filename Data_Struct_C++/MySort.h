
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

			}
	}

	namespace Sort_Merge
	{
		template<class RandomAccessIter> inline
			void Iterative( RandomAccessIter First, RandomAccessIter Last )
		{

			}

		template<class RandomAccessIter> inline
			void Recursive( RandomAccessIter First, RandomAccessIter Last )
		{

			}
	}
}