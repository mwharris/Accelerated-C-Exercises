#include "stdafx.h"

#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::cerr;
using std::string;
using std::getline;

int main()
{
	string l[] = {
		"#include <iostream>",
		"#include <string>", 
		"#include <fstream>",
		" ",
		"using std::cout",
		"using std::cin",
		"using std::endl",
		"using std::ifstream",
		"using std::cerr",
		"using std::string",
		"using std::getline",
		" ",
		"int main()",
		"{",
		"	string l[] = {",
		"		",
		"	};",
		"	for (int i = 0; i < 13; i++)",
		"		cout << l[i] << endl;",
		"	for (int i = 0; i < l->size(); i++)",
		"		cout << l[14] + \"\"\" + l[i] + \"\",\" << endl;",
		"	for (int i = 0; i < 13; i++)",
		"		cout << l[i] << endl;",
		"	return 0;",
		"};",
	};
	for (int i = 0; i < 15; i++)
		cout << l[i] << endl;
	for (int i = 0; i < (sizeof(l) / sizeof(l[0])); i++)
		cout << l[15] + "\"" + l[i] + "\"," << endl;
	for (int i = 16; i < (sizeof(l) / sizeof(l[0])); i++)
		cout << l[i] << endl;
	return 0;
}