#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int MOD = 1e9+7;
const int BASE1 = 5689;
const int BASE2 = 	8861;

struct Hash
{ 
         //if you get overflow change the int,int to long long just
	vector<pair<int,int>>hashes,pow;


	Hash(string s){
		hashes.assign(s.size()+1,{1,1});
		pow.assign(s.size()+1,{1,1});

		for(int i=0;i<s.size();i++){
			hashes[i+1]={(hashes[i].first*BASE1+(s[i]-'a'+1))%MOD,
						(hashes[i].second*BASE2+(s[i]-'a'+1))%MOD};

			pow[i+1]={(pow[i].first*BASE1)%MOD,(pow[i].second*BASE2)%MOD};
		}
	}


	//converting the input 0 based indexing to 1 based
	pair<int,int>get(int l,int r){
		l++,r++;

		int hash1 =(hashes[r].first-(hashes[l-1].first*pow[r-l+1].first)%MOD+MOD)%MOD;
		int hash2 =(hashes[r].second-(hashes[l-1].second*pow[r-l+1].second)%MOD+MOD)%MOD;
	
		return {hash1,hash2};
	}
};
void solve(){


}

signed main(){
 #ifdef ONLINE_JUDGE
 
 
  
  freopen("error.txt", "w", stderr); 
  #endif

    solve();

 
 

}
