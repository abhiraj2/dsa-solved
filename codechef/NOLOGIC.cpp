#include <bits/stdc++.h>

using namespace std;

typedef long long lol;
typedef __int128_t lollol;
typedef vector<int> vi;
typedef vector<lol> vl;
typedef pair<lol, lol> pl;
#define MOD 1000000007
#define itr(i,a,b) for (int i=a; i<=b; i++)


int main(){
	lol t;
	cin >> t;
	t++;
	while(t--){
	    string s;
	    string res = "abcdefghijklmnopqrstuvwxyz";
	    getline(cin, s);
	    if(s=="") continue;
	    //cout << s << endl;
	    transform(s.begin(), s.end(), s.begin(), ::tolower);
	    int sz = s.size();
	    //cout << sz << endl;
	    for(int i=0; i<sz; i++){
	        if((int)s[i] > 122 || (int)s[i] < 97) {continue;}
	        int n = res.find(s[i]);
	        if(n != string::npos){
	            //cout << i << endl;
	            res.erase(n, 1);
	            //cout << res << endl;	            
	        }
	    }
	    (res!="")?(cout << res+"\n"):(cout << "~\n");
	    
	}
}