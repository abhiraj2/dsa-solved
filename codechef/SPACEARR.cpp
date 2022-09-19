#include <bits/stdc++.h>

using namespace std;

typedef long long lol;
typedef __int128_t lollol;
typedef vector<int> vi;
typedef vector<lol> vl;
typedef pair<lol, lol> pl;
typedef map<lol, lol> ml;
#define MOD 1000000007
#define itr(i,a,b) for (int i=a; i<=b; i++)


int main(){
	lol t;
	cin >> t;
	while(t--){
	    lol n;
	    cin >> n;
	    ml fr;
	    int winner = 0;
	    for(lol i=0; i<n; i++){
	       fr[i] = 0;
	    }
	    for(lol i=0; i<n; i++){
	       lol temp;
	       cin >> temp;
	       fr[temp]++;
	    }
	    int s = 0;
	    for(lol i=1; i<n; i++){
	        if(fr[i] == 0){
	            winner = 1;
	        }
	        else{
	            int inc = fr[i]-1;
	            fr[i] = 1;
	            fr[i+1] += inc;
	            s+=inc;
	        }
	    }
	    (s%2 && !winner)?winner=0:winner=1;
	    !winner?cout<<"First\n":cout<<"Second\n";
	}
}