// Prime Interview Questions
// Program to print all sub-string of a given string

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> allSubStrings(std::string str);

std::vector<std::string> allSubStrings(std::string str)
{
  if(str.size() == 1) 
  { 
      return std::vector<std::string>( { str } ); 
  }
  
  char first = str.at(0);
  str.erase(0, 1);
  
  std::vector<std::string> returnValue;
  returnValue.push_back(std::string(&first));
  
  for(auto s : allSubStrings(str))
  {
      returnValue.push_back(s);
      returnValue.push_back(std::string(&first) + s);
      returnValue.push_back(s + std::string(&first));
  }
  
  return returnValue;
}

int main()
{
  std::string str1("abcd");
  std::vector<std::string> output = allSubStrings(str1);
  
  std::cout << "All possible sub-strings of the string " << str1 << " are:" << std::endl;
  for(auto v : output)
  {
      std::cout << v << std::endl;
  }
  
  return 0;
}
