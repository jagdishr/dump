#include <iostream>
#include <all_substrings_string.h>

std::vector<std::string> allSubStrings(std::string str)
{
	if (str.size() == 1)
	{
		return std::vector<std::string>({ str });
	}

	char first = str.at(0);
	str.erase(0, 1);

	std::vector<std::string> returnValue;
	std::string firstStr(1, first);
	returnValue.push_back(firstStr);

	for (auto s : allSubStrings(str))
	{
		returnValue.push_back(s);
		returnValue.push_back(firstStr + s);
		returnValue.push_back(s + firstStr);
	}

	return returnValue;
}

int run_all_substrings_string()
{
	std::string str1("abc");
	std::vector<std::string> output = allSubStrings(str1);

	std::cout << "All possible sub-strings of the string " << str1 << " are:" << std::endl;
	for (auto v : output)
	{
		std::cout << v << "\n";
	}

	return 0;
}