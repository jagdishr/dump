#include <iostream>
#include <all_includes.h>

int main()
{
	//variadic_templates_run();
	
	//this is bull-c*** and does not work
	//latest_api_challenge_raw_run(); 

	//this one works, although O(n^2) to read, O(nlogn) to parse -.-
	latest_api_challenge_run();

	getchar();
	return 0;
}