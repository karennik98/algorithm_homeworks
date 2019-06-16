#include <iostream>
#include <tuple>

template<typename T>
std::tuple<size_t, size_t, T> find_max_subarray(T* arr, size_t low, size_t high, size_t size)
{
	T max = INT_MIN;
	size_t low_idx;
	size_t high_idx;

	for (size_t i = 0; i < size; i++)
	{
		T sum = 0;
		for (size_t j = i; j < size; ++j)
		{
			sum += arr[j];
			if (max < sum)
			{
				max = sum;
				low_idx = i;
				high_idx = j;
			}
		}
	}

	return std::make_tuple(low_idx, high_idx, max);
}

int main()
{
	int arr[] = { -1,-4,-3,-2,-7 };
	size_t size = sizeof(arr) / sizeof(int);
	std::tuple<size_t, size_t, int> max = find_max_subarray<int>(arr, 0, size-1,size);
	std::cout << "low idx = "<<std::get<0>(max) << std::endl;
	std::cout << "high idx = "<<std::get<1>(max) << std::endl;
	std::cout << "max sum = "<<std::get<2>(max) << std::endl;
	system("pause");
	return 0;
}
