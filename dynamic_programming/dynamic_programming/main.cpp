//Given an input string and a dictionary of words, find out if the input string can be segmented into a space-separated sequence of dictionary words

// Consider the following dictionary
// { i, like, sam, sung, samsung, mobile, ice, cream, icecream, man, go, mango }
//
// Input:  ilike
//	Output : Yes
//	The string can be segmented as "i like".
//
//	Input : ilikesamsung
//	Output : Yes
//	The string can be segmented as "i like samsung"
//	or "i like sam sung".

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

bool dictionaryContains(std::string word)
{
	std::vector < std::string > dictionary = { "mobile", "samsung", "sam",
											   "sung", "man", "mango",
											   "icecream", "and", "go",
											   "i", "like", "ice", "cream" };
	for (const auto it : dictionary)
	{
		return (std::find(dictionary.begin(),dictionary.end(), word) != dictionary.end());
	}
}

bool wordBreak(std::string str)
{
	size_t size = str.size();
	if (size == 0)
	{
		return true;
	}

	std::vector<bool> dp(size + 1, false);

	for (size_t i = 0; i < size; i++)
	{
		if (dp[i] == false && dictionaryContains(str.substr(0, i)))
		{
			dp[i] = true;
		}

		if (dp[i] == true)
		{
			if (i == size)
			{
				return true;
			}

			for (size_t j = 0; j <= size; ++j)
			{
				if (dp[j] == false && dictionaryContains(str.substr(i, j - i)))
				{
					dp[j] = true;
				}

				if (j == size && dp[j] == true)
				{
					return true;
				}
			}
		}
	}

	return false;
}

int main()
{
	wordBreak("ilikesamsung") ? std::cout << "Yes\n" : std::cout << "No\n";
	wordBreak("iiiiiiii") ? std::cout << "Yes\n" : std::cout << "No\n";
	wordBreak("") ? std::cout << "Yes\n" : std::cout << "No\n";
	wordBreak("ilikelikeimangoiii") ? std::cout << "Yes\n" : std::cout << "No\n";
	wordBreak("samsungandmango") ? std::cout << "Yes\n" : std::cout << "No\n";
	wordBreak("samsungandmangok") ? std::cout << "Yes\n" : std::cout << "No\n";
	system("pause");
	return 0;
}