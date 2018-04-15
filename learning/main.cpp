#include <iostream>
#include <all_includes.h>

int main()
{
	//variadic_templates_run();
	
	//this is bull-c*** and does not work
	//latest_api_challenge_raw_run(); 

	//this one works, although O(n^2) to read, O(nlogn) to parse -.-
	//latest_api_challenge_run();
	
	//implementation of binary search tree where we insert elements, perform inorder traversal, copy tree and perform inorder of copy
	run_bst_example();

	//run_all_substrings_string();

	//run_postfix();

	getchar();
	return 0;
}