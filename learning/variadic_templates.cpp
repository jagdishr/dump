// Example program for variadic templates
#include <iostream>
#include <string>

#include <cstddef>

// for variadic template based methods
template<typename T>
T adder(T val) {
    return val;
}

template<typename T, typename... Args>
T adder(T first, Args... rest) {
    return first + adder(rest...);
}

// for variadic template based data structures
template<class... Ts> struct tuple {};

template<class T, class... Ts>
struct tuple<T, Ts...> : tuple<Ts...> {
    tuple(T t, Ts... ts) : tuple<Ts...>(ts...), tail(t) {}
    
    T tail;
};

template <size_t, class> struct elem_type_holder;

// accessors for when you do not know the sheep (sic)
template<class T, class... Ts>
struct elem_type_holder<0, tuple<T, Ts...>> {
    typedef T type;
};

template<size_t k, class T, class... Ts>
struct elem_type_holder<k, tuple<T, Ts...>> {
    typedef typename elem_type_holder<k-1, tuple<Ts...>>::type type;
};

template<size_t k, class... Ts>
typename std::enable_if<
    k==0, typename elem_type_holder<0, tuple<Ts...>>::type&>::type
get(tuple<Ts...>& t) {
    return t.tail;
}

template<size_t k, class T, class... Ts>
typename std::enable_if<
    k!=0, typename elem_type_holder<k, tuple<T, Ts...>>::type&>::type
get(tuple<T, Ts...>& t) {
    tuple<Ts...>& base = t;
    return get<k-1>(base);
}

int main()
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
}
