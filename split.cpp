#include <iostream>
#include <cstdio>
#include <vector>
#include <iterator>

using namespace std;

vector<string> split(string, char);

vector<string> split(string s, char c) {
	vector<string> result;
	int count = 0;
	int prev_c = -1;
	int i = 0;
	string token;
	for(i = 0; i < s.length(); i++) {
		if(s.at(i) == c) {
			token = s.substr(prev_c+1, i - (prev_c + 1)); // i - prev_c + 1 fails! The paranthesis is important here. Cool!
			result.push_back(token);
			prev_c = i;
			count++;
		}
	}
	//Handle the last token that reamins
	token = s.substr(prev_c+1, i - (prev_c + 1));
	result.push_back(token);	
	count++;
	return result;
}

int main(void) {
	vector<string> tokens = split("abb#bb##rr#ccc", '#');
	vector<string>::iterator it = tokens.begin();
	while(it != tokens.end()) {
		cout << *it << endl;
		it++;
	}
	return 0;
}

