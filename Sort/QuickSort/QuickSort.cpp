// QuickSort.cpp : Defines the entry point for the console application.
//

#include <iostream>

int Partition(int* list, int low, int high)
{
	int pivot = list[low]; //The first element as pivot

	while (low < high)
	{
		// Start from the high side, find the first element less than pivot
		while (low < high && list[high] >= pivot)
		{
			high--;
		}

		//Swap high and pivot
		int temp = list[high];
		list[high] = list[low];
		list[low] = temp;

		// Start from the low side, find the first element larger than pivot
		while (low < high && list[low] <= pivot)
		{
			low++;
		}

		//Swap low and pivot
		temp = list[high];
		list[high] = list[low];
		list[low] = temp;

		return low;
	}
	

}

//Divide and Conquer
void QuickSort(int* list, int low, int high)
{
	if (low < high)
	{
		//Divide the list into two parts
		int pivot = Partition(list, low, high);

		//Conquer each part
		QuickSort(list, low, pivot - 1);
		QuickSort(list, pivot + 1, high);
	}
	
}

int main()
{
	int arr[10] = { 21, 17, 328, 538, 87, 129, 50, 211, 6, 68};
	
	std::cout << "This is before quick sort" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i] << ", ";
	}

	std::cout << std::endl;

	QuickSort(arr, 0, 9);
	
	std::cout << "This is after quick sort" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i] << ", ";
	}

	std::cout << std::endl;

	getchar();

    return 0;
}

