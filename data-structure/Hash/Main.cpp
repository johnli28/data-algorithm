// #include <hash_map>  // deprecated and will be removed
// #include <hash_set>  // deprecated and will be removed

#include <unordered_map>
#include <iostream>

//Note: without this include, cout a string will report an error
#include<string>

using namespace std;

// Note: Previously there was no implmentation of hash table in C++ standard library and hash_map is a workaround
// Starting with C++11 a hash table implementation has been added to the C++ standard library, and using an alternate name unordered_map
// which really is more descriptive as it hints at the class's map interface and the unordered nature of its elements.
// So from C++ 11 on, unordered_map is standard hash table and should be used instead

int main()
{
	unordered_map <int, string> hm;

	hm[3] = "abc";
	hm[4] = "d";

	std::string str = hm[3];

	std::cout << str << std::endl;

	getchar();

	return 0;
}