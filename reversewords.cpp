#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>
#include <stack>

#define N 100
#define LINESIZE 1001

using namespace std;

int main(void) {
	int n;
	int i = 1;
	cin >> n;
//	fflush(stdin); //extra newline after reading n is creating problem shayad..fflush didnt work :(
	int ch = getchar(); //This worked! Consumed the last \n from stdin :)
	while(i <= n) {
		string line;
		getline(cin, line);
		stack<string> wordlist; //extra space :(
		stringstream ss(line);
		string word;
		while(ss >> word) {
			wordlist.push(word);
		}
		cout << "Case " << "#" << i << ": ";
		while(!wordlist.empty()) {
			 cout << wordlist.top();
			 wordlist.pop();
			 if(!wordlist.empty()) {
			 	cout << " ";
			 }
		}
		cout << endl;
		i++;
	}
	return 0;
}

