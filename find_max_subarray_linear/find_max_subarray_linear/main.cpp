#include <iostream>
#include <tuple>

template<typename T>
std::tuple<size_t, size_t, T> find_max_subarray_liear(T* arr, size_t size) 
{
	T max_sum = INT32_MIN;
	T ending_here_sum = INT32_MIN;

	size_t ending_here_high, ending_here_low, low, high;

	for (int i = 0; i < size; ++i) 
	{
		ending_here_high = i;

		if (ending_here_sum > 0) 
		{
			ending_here_sum = ending_here_sum + arr[i];
		} 
		else
		{
			ending_here_low = i;
			ending_here_sum = arr[i];
		}
		if (ending_here_sum > max_sum)
		{
			max_sum = ending_here_sum;
			low = ending_here_low;
			high = ending_here_high;
		}
	}

	return std::make_tuple(low, high, max_sum);
}

int main() 
{
	int arr[] = {-2,-5,6,-2,-3,1,5,-6};
	size_t size = sizeof(arr) / sizeof(int);
	std::tuple<size_t, size_t, int> result = find_max_subarray_liear<int>(arr, size);
	std::cout << std::get<0>(result) << std::ends;
	std::cout << std::get<1>(result) << std::ends;
	std::cout << std::get<2>(result) << std::endl;
	system("pause");
}