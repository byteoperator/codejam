#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <cctype>
#include <set>
#include <sstream>

using namespace std;

void showmap(map<string, int> m) {
	map<string, int>::iterator it = m.begin();
	while(it != m.end()) {
		cout << it->first << " ";
		it++;
	}
	cout << endl;
}

int main(void) {
	int t;
	cin >> t;
	int tc = 1;
	while(tc <= t) {
		map<string, int> exists;
		int n,m;
		cin >> n >> m;
		exists["/"] = 1;
		string d;
		while(n--) {
			cin >> d;
			if(exists.find(d) == exists.end()) {
				exists[d] = 1;
			}
			else {
				exists[d] = exists[d] + 1;
			}
		}
		vector<string> create;
		int ans = 0;
		int cp = 0;
		int i = 0;
		//if(m==3)showmap(exists);
		//cout << m << endl;
		while(m--) {
			cin >> d;
			cp = 0;
			for(i=0; i < d.length(); i++) {
				if(i != 0 && d.at(i) == '/') {
					string dir = d.substr(cp, i-cp);					
					if(exists.find(dir) == exists.end()) {
						ans++;
						//cout << "Dir: " << dir << endl;
						exists[dir] = 1;
					}
				}
			}
			//Handle last case
			string dir = d.substr(cp, i-cp);
			if(exists.find(dir) == exists.end()) {
				//cout << "Dir: " << dir << endl;
				ans++;
				exists[dir] = 1;
			}	
		}
		printf("Case #%d: %d\n", tc, ans);
		//cout << "--------------" << endl;
		tc++;
	}
	return 0;
}