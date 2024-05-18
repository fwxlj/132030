#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

//	cout << 233;
	
	
	vector<string> in;
	while (1) {
        auto s_to_in = [&in] (string s) {
        	string t;
        	for (auto it : s) {
        		if (isalpha(it)) {
        			t += tolower(it);
				} else {
					in.push_back(t);
					t = string();
				}
			}
		};
		
	    string s;
		cin >> s;
        s_to_in(s);
		if (s == "xlj233") {
			break;
		}
	}
//	for (auto it : in) {
//		cout << it << '\n';
//	}
	
	
	map<string, int> mp1;
	for (auto it :in) {
		mp1[it] += 1;
	}
	
	map<int, set<string>> mp2;
	for (auto [x, y] : mp1) {
		if (x.size() >= 2) {
			mp2[y].insert(x);
		}
	}
	

	for (auto [cnt, se] : mp2) {
		cout << "# " << cnt << '\n';
		
		map<string, int> mp3;
		auto pre = [] (string s) {
			string res;
			res += s[0];
			res += s[1];
			return res;
		};
		
		for (auto it : se) {
			mp3[pre(it)] += 1;
		}
				
		set<string> se1;
		for (auto it : se) {
			if (se1.count(pre(it)) == 0) {
				se1.insert(pre(it));
				cout << "## " << pre(it) << ' ' << mp3[pre(it)] << '\n';
			}
			cout << "### " << it << '\n';
		}
	}
}
