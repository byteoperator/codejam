#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
#include <vector>
#include <numeric>

using namespace std;


//#define f(r) (((-10000 * pow(1+r,3)) + (3000 * pow(1+r,2)) + (4000 * (1+r) + 5000)))

/*
double ff(double r) {
	return -10000 * pow(1+r,3) + 3000 * pow(1+r,2) + 4000 * (1+r) + 5000;
}
*/

double ff(double r) {
	return -200 * pow(1+r,2) + 100 * pow(1+r,1) + 100;
}

//vector<int> vi;

long double f(long double r, vector<int> vi) {
	long double e = (vi.size() - 1);
	long double res = -vi[0] * pow(1+r, e);
	e--;
	for(int i = 1; i < vi.size(); i++) {
		int ci = vi[i];
		res = res + (ci * pow(1+r, e));
		//cout << res << endl;
		e--;
	}
	return res;
}


void sample(void) {
	double r1 = -0.999999999, r2 = 1.0;
	double r = 5.0;
	double prevr = 8.0;
	int i = 0;
	do {
		prevr = r;
		r = (r1+r2)/2.0;
		if(ff(r1) * ff(r) < 0.0) {
			r2 = r;
		}
		else {
			r1 = r;
		}
		i++;
		cout << "Previous r: " << prevr << endl;
		cout << "Current  r: " << r << endl;
		cout << "abs(r-prevr): " << abs(r-prevr) << endl;
		cout << "r: " << r << endl;
		cout << "*******************************" << endl;
	}
	while(abs(r-prevr) > pow(10, -9));
	cout << "-----------------" << endl;
	cout << endl;
}


int main(void) {
	//sample();
	int t,m;
	cin >> t;
	int ci;
	int tc = 1;
	while(t--) {
		long double r1 = -0.9999999999, r2 = 0.9999999999;
		vector<int> vi;
		cin >> m;
		int i = 0;
		while(i <= m) {
			cin >> ci;
			vi.push_back(ci);
			i++;
		}
		long double r = 47.0;
		long double prevr = 74.0;
		//cout << f(r1,vi) * f(r2,vi) << endl;
		do {
			prevr = r;
			r = (r1+r2)/2.0;			
			if( f(r1, vi) * f(r, vi) < 0.0) {
				r2 = r;
			}
			else {
				r1 = r;
			}
		} while(abs(r-prevr) >= pow(10, -10));
		cout << "Case #" << tc << ": " << r << endl;
		tc++;
	}
	return 0;
}