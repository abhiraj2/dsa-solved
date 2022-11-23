#include <bits/stdc++.h>

using namespace std;

typedef long long lol;
typedef __int128_t lollol;
typedef vector<int> vi;
typedef vector<lol> vl;
typedef pair<lol, lol> pl;
typedef map<lol, lol> ml;
typedef unordered_map<lol, lol> uml;
#define MOD 1000000007
#define itr(i,a,b) for (int i=a; i<=b; i++)

int main(){
	lol i, j;
	ml a;
	a[1] = 1;
	while(cin >> i >> j){
	    lol ma_c = -1;
	    for(lol k=i; k<=j; k++){
	        lol temp = k;
	        lol c = 0;
	        //cout << a[temp] << endl;
	        while(!a[temp]){
	            if(temp%2) temp = 3*temp+1;
	            else temp = temp/2;
	            c++;
	        }
	        
	        c += a[temp];
	        //cout << k << " " << c << endl;
	        ma_c = max(ma_c, c);
	    }
	    cout << i << " " << j << " " << ma_c << endl;
	}
}