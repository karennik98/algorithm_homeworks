#include <iostream>
#include <vector>
#include <iomanip>
#include <exception>

using matrix = std::vector<std::vector<double>>;

matrix matrix_multiply(matrix& A, matrix& B)
{
	const size_t A_rows = A.size();     // A rows
	const size_t A_cols = A[0].size();  // A cols
	const size_t B_cols = B[0].size();  // B cols

	if (A_rows != B_cols)
	{
		throw std::invalid_argument("incompatible dimensions");
	}
	else 
	{
		matrix C;
		for (size_t i = 0; i < A_rows; ++i)
		{
			for (size_t j = 0; j < B_cols; ++j)
			{
				C[i][j] = 0;
				for (size_t k = 0; k < A_cols; ++k)
				{
					C[i][j] = C[i][j] + A[i][j] * B[i][j];
				}
			}
		}
		return C;
	}
}



std::pair<matrix, matrix> matrix_chain_order(std::vector<double>& p)
{
	size_t size = p.size();

	matrix m;
	m.resize(size);
	for (size_t i = 0; i < size; ++i)
	{
		m[i].resize(size);
	}

	matrix s;
	s.resize(size - 1);
	for (size_t i = 0; i < size - 1; ++i)
	{
		s[i].resize(size);
	}

	for (int l = 2; l < size; l++)
	{
		for (int i = 1; i < size - l + 1; i++)
		{
			int j = i + l - 1;
			m[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++)
			{
				int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}

	return std::make_pair(m, s);
}

void print_optimal_parens(matrix& s, size_t low_idx, size_t high_idx)
{
	if (low_idx == high_idx)
	{
		std::cout << "A" << low_idx<<std::ends;
	}
	else
	{
		std::cout << "(";
		print_optimal_parens(s, low_idx, s[low_idx][high_idx]);
		print_optimal_parens(s, s[low_idx][high_idx] + 1, high_idx);
		std::cout << ")";

	}
}


int main()
{
	std::vector<double> chain{ 30,35,15,5,10,20,25};

	std::pair<matrix, matrix> result = matrix_chain_order(chain);

	
	for (std::size_t i = 1; i < result.first.size(); i++)
	{
		for (std::size_t j = 0; j < result.first[i].size(); j++)
		{
			std::cout << std::setw(6)<< result.first[i][j] << ' ';
		}
		std::cout << std::endl;
	}

	std::cout << std::endl << std::endl;

	for (std::size_t i = 1; i < result.second.size(); i++)
	{
		for (std::size_t j = 0; j < result.second[i].size(); j++)
		{
			std::cout << std::setw(6)<<result.second[i][j] << ' ';
		}
		std::cout << std::endl;
	}

	std::cout << std::endl << std::endl;

	print_optimal_parens(result.second, 1, 6);
	std::cout << std::endl;
	system("pause");
	return 0;
}