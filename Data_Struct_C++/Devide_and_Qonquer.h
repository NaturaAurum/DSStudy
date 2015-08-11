#pragma once

namespace BinarySearch
{
	template<class RandomAccessIter, class Type> inline
		void Iterative( RandomAccessIter First, RandomAccessIter Last, Type Target )
	{
		RandomAccessIter Mid;
		RandomAccessIter I = First;
		RandomAccessIter J = ( Last );
		//std::cout << "Middle Value : " << *( First + ( ( ( *( First + 1 ) + *( Last - 1 ) ) / 2 ) - *( First ) ) ) << std::endl;
		
		while ( true )
		{
			Mid = ( I + ( ( ( *( I + 1 ) + *( J - 1 ) ) / 2 ) - *( I ) ) );
			std::cout << "Middle Value : " << *( Mid ) << std::endl;
			if ( *( Mid ) == Target )
			{
				break;
			}
			else if ( Target > *( Mid ) )
			{
				I = ++Mid;
				continue;
			}
			else if ( Target < *( Mid ) )
			{
				J = --Mid;
				continue;
			}
			
		}
		std::cout << "찾은 값 : " << *( Mid ) << std::endl;
	}
	template<class RandomAccessIter, class Type> inline
		void Recursive( RandomAccessIter First, RandomAccessIter Last, Type Target )
	{
		RandomAccessIter Mid;

		//std::cout << ( *( First )+*( Last - 1 ) ) / 2 << std::endl;
		std::cout << "Middle Value : " << *( First + ( ( ( *( First + 1 ) + *( Last - 1 ) ) / 2 ) - *( First ) ) ) << std::endl;
		Mid = ( First + ( ( ( *( First + 1 ) + *( Last - 1 ) ) / 2 ) - *( First ) ) );
		
		if ( *( Mid ) == Target )
		{
			std::cout << "찾은 값 : " << *( Mid ) << std::endl;
			return;
		}
		else if ( Target > *( Mid ) )
		{
			Recursive( ++Mid, Last, Target );
		}
		else if ( Target < *( Mid ) )
		{
			Recursive( First, --Mid, Target );
		}
	}
}