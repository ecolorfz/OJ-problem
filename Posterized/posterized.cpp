#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,f[263],a;
    cin>>n>>k;
    memset(f,-1,sizeof(f));
    while(n--){
        cin>>a;
        if(f[a]==-1){
        	int l=max(0,a-k+1);
        	for(int i=l;i<=a;i++){
            	if(f[i]==-1||f[i]==i){
                	for(int j=i;j<=a;j++)f[j]=i;
                	break;
            	} 
        	}
    	}	
            if(n!=0)
            cout<<f[a]<<" ";
            else cout<<f[a]<<endl;
    }
    return 0;
}
