#include <bits/stdc++.h>
#define f first
#define s second
#define pi 3.14159
#define pb push_back
#define tos to_string
#define inf 1000000000
#define inf64 1000000000000000000
#define entrada freopen("input.txt", "r", stdin);
#define saida freopen("output.txt", "w", stdout);

using namespace std;

int main(){	
	
	int o, n, i, vet[20005];	
	cin >> o;
	while(o--){
		cin >> n;
		for(i=0; i<n; i++){
			cin >> vet[i];
		}		
		sort(vet, vet+n);
		int sum=0;	
		if(n>=3){
			for(i=(n-1)-2; i>=0; i=i-3){
				sum+=vet[i];
			}
			cout << sum << endl;	
		}
		else{
			cout << 0 << endl;
		}	
	}
}
