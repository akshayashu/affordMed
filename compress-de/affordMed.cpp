#include <iostream>
#include <vector>
#include <climits>
#define ll long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace std;

class compressedData{
public:
	vector<pair<int, char>> map;

	void solve(string data){
		char prev = data[0];
		int count = 1;

		for(int i = 1; i < data.size(); i++){
			char curChar = data[i];

			if(curChar != prev){
				map.push_back({count, prev});
				prev = curChar;
				count = 1;
			}else{
				count++;
			}
		}
		map.push_back({count, prev});
	}

	string getData(){

		string str = "";

		for(pair<int, char> p : map){
			string temp(p.first, p.second);
			str += temp;
		}

		return str;
	}
};

class codex{
private:
	compressedData ans;

public:
	virtual compressedData compress(string data){
		if(data.size() == 0){
			return ans;
		}
		ans.solve(data);
		return ans;
	}

	virtual string decompress(compressedData data){
		return ans.getData();
	}
};

int main(){

	fastIO
	
	string str = "abcbaba";

	codex helper;
	compressedData cmpStr = helper.compress(data);
	string ans = helper.decompress(cmpStr);

	cout << ans;


	return 0;
}