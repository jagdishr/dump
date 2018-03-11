#pragma once

#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>

struct CSVData
{
	std::string tokens[3];
	bool operator==(const CSVData &obj) const
	{
		if (this->tokens[1].compare(obj.tokens[1]) == 0)
			return true;
		else
			return false;
	}
};

struct sort_key
{
	inline bool operator() (const CSVData& o1, const CSVData& o2)
	{
		return (o1.tokens[2] > o2.tokens[2]);
	}
};

std::vector<CSVData> Read(const std::string&);
int latest_api_challenge_raw_run();