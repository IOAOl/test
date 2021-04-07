#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string>
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;
long double a, b, c, x, y, z, m;
int main() {
	for (int i = 0; i < 60; i++) {
		cout << i << endl;
		string name = "";
		stringstream ss;
		ss << "D:\\暂存\\E\\" << i+1 << ".in";
		ss >> name;
		fstream fin;
		fin.open(name.c_str(), ios::in);
		fin >> a >> b >> c >> x >> y >> z >> m;
		cout << "a:" << a << "b:" << b << "c:" << c << "x:" << x << "y:" << y << "z:" << z << "m:" << m << endl;
		if (a * z > m) {
			cout << setiosflags(ios::fixed) << setprecision(10) << m / z << endl;
			cout << "1" << endl;
		}
		else if (a * z + b * (z - x) + c * (z + y) > 0) {
			int k = m / (a * z + b * (z - x) + c * (z + y));
			m = fmod(m, (a * z + b * (z - x) + c * (z + y)));
			if (a * z >= m) {
				cout << setiosflags(ios::fixed) << setprecision(10) << m / z + k * (a + b + c) << endl;
				cout << "2" << endl;
			}
			else if (z > x&& m <= (z - x) * b + z * a) {
				m = m - a * z;
				cout << setiosflags(ios::fixed) << setprecision(10) << m / (z - x) + a + k * (a + b + c) << endl;
				cout << "3" << endl;
			}
			else {
				m = m - (z - x) * b-a*z;
				cout << setiosflags(ios::fixed) << setprecision(10) << m / (z + y) + a + b + k * (a + b + c) << endl;
				cout << "4" << endl;
			}
		}
		else {
			cout << "Badeline win" << endl;
		}
		//test git
		fin.close();
		string name1 = "";
		stringstream ss1;
		ss1 << "D:\\暂存\\E\\" << i+1 << ".out";
		ss1 >> name1;
		fstream fout;
		fout.open(name1.c_str(), ios::in);
		string r1;
		fout >> r1;
		cout << r1 << endl;
		cout <<"------------------"<< endl;
	}
}