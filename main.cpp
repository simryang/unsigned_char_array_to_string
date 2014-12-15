#include <sstream>  // for stringstream
#include <iostream> // std::cout, std::endl
#include <iomanip>  // std::setfill, std::setw

using namespace std;

struct str_data {
	unsigned char str1[7] = { 0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde };
	unsigned char str2[7] = { 0xf2, 0xf4, 0xf6, 0xf8, 0xfa, 0xfc, 0xfe };
	unsigned char str3[7] = { 0x78, 0x79, 0x0a, 0x7b, 0x7c, 0x7d, 0x7e };
} struct_test;

int main () {
	unsigned char str1[7] = { 0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde };
	unsigned char str2[7] = { 0xf2, 0xf4, 0xf6, 0xf8, 0xfa, 0xfc, 0xfe };

	stringstream ss;
	// convert value to hex, short values have preceding '0'
	ss << hex << setfill ('0');
// wrong example
	//ss << hex << (unsigned int *)str1;
	ss << (unsigned int *)str1;
	cout << ss.str() << endl;
	// above is not what I wanted, just the letter of each value is copied

	// clearing for reuse
	ss.str (""); ss.clear ();

// simple working example 1
	for (int i = 0; i < sizeof (str2); i++)
		ss << (unsigned int)str2[i];

	cout << ss.str () << endl;
	ss.str (""); ss.clear ();

	unsigned int size;
	struct str_data *_test = &struct_test;
	//ss << "0x"; // if it is needed
	for (int i = 0, size = sizeof (_test->str3); i < size; i++)
		// if line 19 is not executed following is needed
		//ss << hex << (unsigned int)(_test->str3)[i];
		ss << setw (2) << (unsigned int)(_test->str3)[i];

	cout << ss.str () << endl;
	char buf[256];
	ss >> buf;
	cout << buf << endl;
	ss.str (""); ss.clear ();
	return 0;
}
