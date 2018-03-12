#pragma once
#include <string>
#include <vector>
#include <map>
#include <memory>

class APIProperty
{
	std::string name;
	int max_version;
	APIProperty();
public:
	APIProperty(std::string s) : name(s) { max_version = 0;  }
	const std::string get_name() const { return name; }
	int get_max_version() { return max_version;  }
	void set_max_version(int i) { max_version = i; }
	virtual ~APIProperty() {}
};

class Application
{
	std::string name;
	std::map<std::string, int> apis;
public:
	Application(std::string s) : name(s) {}
	const std::string get_name() const { return name;  }
	void set_name(std::string s) { name = s; }
	std::map<std::string, int> &getAPI() { return apis; }

};

int latest_api_challenge_run();