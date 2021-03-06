#include <bits/stdc++.h>
#define ll long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace std;

class customClass{
public:
	int nextChunkAddress;
	vector<unsigned char> data;
};

class ToyTCPStream{
	// chunk address, customClass
	unordered_map<int, customClass> map;
	int lastSendChunk = 0;
public:

	virtual void receive(int chunk, vector<unsigned char> data){
		customClass cc;

		// stoing next chunk address
		cc.nextChunkAddress = chunk + data.size();
		cc.data = data;

		map[chunk] = cc;
	}

	virtual int read(vector<unsigned char>* data){
		// if we dont encouter 1st chunk return 0
	    if(map.find(lastSendChunk + 1) != map.end){
	    	return 0;
	    }

	    int size = data.size();
	    int i = 0, chunk = 0;

	    while(i < size){
	    	if(map.find(lastSendChunk) != map.end()){
		    	break;
		    }
	    	customClass cc = map[lastSendChunk];

	    	for(int j = 0; j < cc.data.size() && i < size; j++){
	    		data[i++] = cc.data[j];
	    		cout << data[i-1];
	    	}

	    	chunk = map[lastSendChunk].nextChunkAddress;

	    	map[lastSendChunk].clear();
	    }

	    return i;
	}
};

int main(){

	fastIO;
	
	int n;
	cin >> n;

	vector<unsigned char> data;
	for(int i = 0; i < n; i++){
		unsigned char b;
		cin >> b;
		data.push_back(b);
	}

	ToyTCPStream helpher;

	vector<unsigned char> temp;
	for(int i = 0; i < 2; i++){
		
		temp.push_back(data[i]);
	}

	vector<int> ans = helpher.receive(1, temp);

	/// you can check custom cases over here
	// due to lack of time, I was only able to build the logic

	return 0;
}