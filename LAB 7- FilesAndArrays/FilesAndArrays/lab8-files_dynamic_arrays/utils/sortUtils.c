#include "../utils/sortUtils.h"

void selectionSort(int * array, int total)
{
	int start, search, min;
	
	for(start = 0 ; start < total - 1; start++)
	{
		min = start;
		
		for(search = start + 1; search < total; search++)
		{
			if(array[search] < array[min])
				min = search;
		}// end for
		
		int temp = array[min];
		array[min] = array[start];
		array[start] = temp;
	}
	
}// end selectionSort