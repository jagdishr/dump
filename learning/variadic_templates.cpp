// Example program for variadic templates
#include <iostream>
#include <string>
#include <cstddef>

#include <variadic_templates.h>

int variadic_templates_run()
{
    // demo variadic template methods
    long sum = adder(1, 2, 3, 4, 5);
    std::cout << "\nSum: " << sum;
  
    std::string s1 = "ex", s2 = "a", s3 = "mp", s4 = "le";
    std::string ssum = adder(s1, s2, s3, s4);
    std::cout << "\n" << ssum;
    
    // demo variadic template classes
    tuple<double, int, std::string> t1(3.5, 8, "Hello");
    
    // now this is cunning way to access them but only since you know the sheep (aka data type)
    std::cout << "\n" << t1.tail;
    
    auto var1 = static_cast<tuple<int, std::string>>(t1);
    std::cout << "\n" << var1.tail;
    
    auto var2 = static_cast<tuple<std::string>>(t1);
    std::cout << "\n" << var2.tail;
    
    // when you do not know the sheep, hunt down by numbers
    std::cout << "\n" << get<0>(t1);
    std::cout << "\n" << get<1>(t1);
    std::cout << "\n" << get<2>(t1);

	return 0;
}
