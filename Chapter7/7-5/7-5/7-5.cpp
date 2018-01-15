#include "stdafx.h"
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <stdexcept>

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
void gen_aux(const Grammar& g, const string& word, vector<string>& ret, vector<string>& stack)
{
	//If this word is not an indicator then it is a result
	if (!is_indicator(word))
	{
		//Add to the return vector
		ret.push_back(word);
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
			for (Rule::const_reverse_iterator r_it = r.rbegin(); r_it < r.rend(); r_it++)
			{
				stack.push_back(*r_it);
			}
		}
		else
		{
			throw logic_error("No rule for indicator: " + word);
		}
	}
}

//Start generating a sentence based on Grammar rules
vector<string> gen_sentence(Grammar g)
{
	vector<string> ret;
	vector<string> stack;
	stack.push_back("<sentence>");

	while (!stack.empty())
	{
		string token = stack.back();
		stack.pop_back();
		gen_aux(g, token, ret, stack);
	}
	
	return ret;
}

int main()
{
	//Read in grammar rules from the user
	Grammar grammar = read_grammar(cin);

	//Genearate a sentence based on the grammar
	vector<string> sentence = gen_sentence(grammar);

	//Print the results
	cout << "Generated sentence:";
	for (vector<string>::const_iterator it = sentence.begin(); it < sentence.end(); it++)
	{
		cout << " " << *it;
	}

	return 0;
}