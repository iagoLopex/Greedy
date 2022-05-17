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
	
	int n, m, i, drag[20005], knig[20005];
	
	cin >> n >> m;
	while(n!=0 || m!=0){
			
		if(n>m){
			cout << "Loowater is doomed!\n";
		}
		else{
			for(i=0; i<n; i++){
				cin >> drag[i];
			}
			for(i=0; i<m; i++){
				cin >> knig[i];
			}
			sort(drag, drag+n);
			sort(knig, knig+m);
			
			int sum=0;
			int k=0;
			for(i=0; i<m && k<n; i++){
					
				if(knig[i]>=drag[k]){
					//cout << knig[i] << " " << drag[k] << endl;
					sum+=knig[i];
					k++;
				}	
			}
			//cout << k << endl;
			if(k==n){//todas as cabecas foram cortadas
				cout << sum << endl;
			}
			else{
				cout << "Loowater is doomed!\n";
			}
		}		
		cin >> n >> m;		
	}			
	
}
