#include <bits/stdc++.h>

using namespace std;

typedef long long lol;
typedef __int128_t lollol;
typedef vector<int> vi;
#define itr(i,a,b) for (int i=a; i<=b; i++)


int main(){
	int t;
	cin >> t;
	while(t--){
	    int a, b;
	    cin >> a >> b;
	    a--; b--;
	    int count =0;
	    for(int i=1; i <=sqrt(abs(a-b)); i++){
	        if(abs(a-b)%i == 0){
	            if(abs(a-b)/i == i) count++;
	            else count +=2;
	        }
	    }
	    cout << count << endl;
	}
}