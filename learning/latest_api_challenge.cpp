#include <latest_api_challenge.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>

static inline void ltrim(std::string &s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](char ch) {
		return std::isdigit(ch);
	}));
}

int latest_api_challenge_run()
{
	//std::stringstream input_data("Mail App, Authentication API, v6 \nVideo Call App, Authentication API, v6 \nMail App, Data Storage API, v10 \nChat App, Data Storage API, v11 \nMail App, Search API, v6 \nChat App, Authentication API, v8 \nChat App, Presence API, v2 \nVideo Call App, Data Storage API, v11 \nVideo Call App, Video Compression API, v3");
	std::stringstream input_data("Mail App, Authentication API, v6 \nVideo Call App, Authentication API, v8 \nMail App, Data Storage API, v10 \nChat App, Data Storage API, v11 \nMail App, Search API, v6 \nChat App, Authentication API, v8 \nChat App, Presence API, v2 \nVideo Call App, Data Storage API, v11 \nVideo Call App, Video Compression API, v3");

	//Applications
	std::vector<Application> apps;
	std::vector<APIProperty> apis;

	//Read this data
	std::string line;
	while (std::getline(input_data, line))
	{
		std::stringstream   linestream(line);
		std::string         value;

		int i = 0;
		bool check = false, appcheck = false;
		std::string apiname;
		int version;
		int index=0,appindex=0;
		while (std::getline(linestream, value, ','))
		{
			//std::vector<APIProperty>::iterator it;
			switch (i)
			{
			case 0:
			{	
				auto it = std::find_if(apps.begin(), apps.end(), [&value](const Application& apps) { return (apps.get_name() == value); });
				if (it != apps.end())
				{
					
					appindex = std::distance(apps.begin(), it);
				}
				else
				{
					apps.emplace_back(value);
					appindex = std::distance(apps.begin(), apps.end() - 1);
				}
			}
			break;
			case 1:
			{
				auto it = std::find_if(apis.begin(), apis.end(), [&value](const APIProperty& apis) { return (apis.get_name() == value); });
				if (it != apis.end())
				{
					check = true;
					index = std::distance(apis.begin(), it);
				}
				else
				{
					apis.emplace_back(value);
				}
				apiname = value;
			}
			break;
			case 2:
			{
				ltrim(value);
				version = std::stoi(value);
				if (check)
				{
					if (apis[index].get_max_version() < version) 
					{ 
						apis[index].set_max_version(version);
					}
				}
				else
				{
					apis.back().set_max_version(version);
				}
			}
			break;
			default:
				break;
			}
			++i;
		}
		apps[appindex].getAPI().emplace(std::pair<std::string, int>(apiname, version));
	}

	std::vector<Application> latest;
	for (auto v : apps)
	{
		bool isLatest = true;
		for (auto m : apis)
		{
			std::string apiname(m.get_name());
			if (v.getAPI().count(apiname) > 0) 
			{
				if (v.getAPI()[apiname] < m.get_max_version())
				{
					isLatest = false;
				}
			}
		}
		if (isLatest) { latest.push_back(v); }
	}

	/*for (auto v : apis)
	{
		std::cout << v.get_name() << " - " << v.get_max_version() << "\n";
	}*/

	std::cout << "\n\n\n";
	for (auto v : latest)
	{
		std::cout << v.get_name() << "\n";
	}

	return 0;
}