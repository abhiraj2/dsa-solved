#include <bits/stdc++.h>

using namespace std;

typedef long long lol;
typedef __int128_t lollol;
typedef vector<int> vi;
typedef vector<lol> vl;
#define itr(i,a,b) for (int i=a; i<=b; i++)


int main(){
	lol t;
	cin >> t;
	while(t--){
	    lol n;
	    cin >> n;
	    if(n%2){
	        cout << "YES" << endl;
	        vector<vector<int>> res(n+1, vector<int>(n+1,0));
	        for(int i=1; i<n+1; i++){
	            for(int j=1; j<n+1; j++){
	                if(j < i){
	                    res[i][j] = !res[j][i];
	                }
	                else if(j==i) res[i][j] =0;
	                else {
	                    if(!(i%2^j%2)) res[i][j] = 0;
	                    else res[i][j] = 1;
	                }
	            }
	        }
	        for(int i=1; i<n+1; i++){
	            for(int j=1; j< n+1; j++){
	                cout << res[i][j];
	            }
	            cout << endl;
	        }
	    }
	    else cout << "NO"<< endl;
	}
}