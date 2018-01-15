#include "stdafx.h"
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <stdexcept>
#include <iterator>

#include "Util.h"

using std::vector;
using std::string;
using std::map;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::logic_error;

typedef vector<string> Rule;
typedef vector<Rule> Rule_Collection;
typedef map<string, vector<Rule>> Grammar;

//Read rules and create a Grammar
Grammar read_grammar(istream& in)
{
	Grammar ret;
	string line;

	cout << "Enter a grammar rule, (Ex: <noun> fat): ";

	//Read a line or Rule, ex: "<noun> fat"
	while (getline(in, line))
	{
		//Split the line up by elements
		vector<string> elems = split(line);
		if (!elems.empty())
		{
			//The first word is always the indicator
			string indicator = elems[0];
			//The other words are the words associated with the indicator
			Rule new_rule = Rule(elems.begin() + 1, elems.end());
			//Add the new rule to the map at key "indicator"
			ret[indicator].push_back(new_rule);
		}
	}

	return ret;
}

//Recursive auxilary method for gen_sentence
template <class Out>
void gen_sentence(const Grammar& g, const string& word, Out& out)
{
	//If this word is not an indicator then it is a result
	if (!is_indicator(word))
	{
		//Add to the return vector
		*out++ = word;
	}
	//If this word is an indicator then we need to expand its meaning
	else
	{
		//Look for a rule collection in the Grammar
		Grammar::const_iterator it = g.find(word);
		//Found the rule, expand
		if (it != g.end())
		{
			//Get the collection of rules for this indicator
			const Rule_Collection rc = it->second;
			//Choose a random rule in the collection to use
			const Rule r = rc[nrand(rc.size())];
			//Expand each string of this rule if needed
			for (Rule::const_iterator r_it = r.begin(); r_it < r.end(); r_it++)
			{
				gen_sentence(g, *r_it, out);
			}
		}
		else
		{
			throw logic_error("No rule for indicator: " + word);
		}
	}
}

int main()
{
	//Read in grammar rules from the user
	Grammar grammar = read_grammar(cin);
	
	//Create an output iterator to print directly to standard output
	std::ostream_iterator<string> output(cout, " ");

	//Genearate a sentence based on the grammar and immediately print
	cout << "Generated sentence:"; 
	gen_sentence(grammar, "<sentence>", output);

    return 0;
}

