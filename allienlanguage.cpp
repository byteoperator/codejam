#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cctype>

using namespace std;

#define L 15
#define D 5000
#define N 500


//Complexity: O(|pat|)
void extractTokens(string pat, int total, vector<string> &tokens) {
	bool inparen = false;
	int first = -1;
	for(int i = 0; i < pat.length(); i++) {
		char ch = pat.at(i);
		if(isalpha(ch) && !inparen) {
			string s(1,ch);
			tokens.push_back(s);
		}
		else if(ch == '(') {
			inparen = true;
			first = i + 1;
		}
		else if(ch == ')') {
			string s = pat.substr(first, i - first);
			tokens.push_back(s);
			inparen = false;
			//first = -1;
		}
		else {
			//continue
		}
	}
}


void solve() {
	int l,d,n;
	cin >> l >> d >> n;
	vector<string> words;
	string word;	
	while(d--) {
		cin >> word;
		words.push_back(word);
	}
	
	int count = 0;
	int i = 1;
	string pat;
	while(i <= n) {
		cin >> pat;
		vector<string> tokens;
		extractTokens(pat,l,tokens);
		//Complexity: O(D*L)
 		for(int j = 0; j < words.size(); j++) {
			bool matches = true;
			for(int k = 0; k < l; k++) {
				if(tokens[k].find(words[j].at(k)) == string::npos) {
					matches = false;
				}
			}
			if(matches) {
				count++;
			}
		}
		cout << "Case #" << i << ": " << count << endl;
		count = 0;
		i++;
	}	
}

int main(void) {
	solve();
	return 0;
}
