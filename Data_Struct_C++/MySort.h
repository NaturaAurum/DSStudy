
namespace Mystd
{
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
			void Iterative( RandomAccessIter _First, RandomAccessIter _Last )
		{
				for ( RandomAccessIter RIter_i = ( _First + 1 ); RIter_i != _Last; RIter_i++ )
				{
					RandomAccessIter RIter_j = RIter_i;

					while ( RIter_j != _First && *( RIter_j ) < *( RIter_j - 1 ) )
					{
						typename std::iterator_traits<RandomAccessIter>::value_type Temp = *RIter_j;
						*( RIter_j ) = *( RIter_j - 1 );
						*( RIter_j - 1 ) = Temp;
						RIter_j--;
					}
				}
			}
		template <class RandomAccessIter> inline
			void Recursive( RandomAccessIter _First, RandomAccessIter _Last )
		{



			}
	}

	namespace Sort_Selection
	{
		void Iterative( std::vector<int>::iterator DatasBegin, std::vector<int>::iterator DatasEnd )
		{

		}

		void Recursive( std::vector<int>::iterator DatasBegin, std::vector<int>::iterator DatasEnd )
		{

		}
	}

	namespace Sort_Bubble
	{
		void Iterative( std::vector<int>::iterator DatasBegin, std::vector<int>::iterator DatasEnd )
		{

		}

		void Recursive( std::vector<int>::iterator DatasBegin, std::vector<int>::iterator DatasEnd )
		{

		}
	}

	namespace Sort_Quick
	{
		void Iterative( std::vector<int>::iterator DatasBegin, std::vector<int>::iterator DatasEnd )
		{

		}

		void Recursive( std::vector<int>::iterator DatasBegin, std::vector<int>::iterator DatasEnd )
		{

		}
	}

	namespace Sort_Merge
	{
		void Iterative( )
		{

		}

		void Recursive( )
		{

		}
	}
}