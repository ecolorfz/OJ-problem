#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
int m,n,k;
long long sum = 0;
bool flag = 0;

struct Tree{
	int s,a;
	vector<int> son;
}node[maxn];

void dfs(int root){
	if(node[root].son.size()==0){
		return;
	}
	for(int i=0;i<node[root].son.size();i++){
		if(node[node[root].son[i]].s==-1&&node[node[root].son[i]].son.size()){
			int minn = 0x3f3f3f3f;
			for(int j=0;j<node[node[root].son[i]].son.size();j++){
				if(node[node[node[root].son[i]].son[j]].s<minn)minn = node[node[node[root].son[i]].son[j]].s;
			}
			node[node[root].son[i]].a = minn-node[root].s;
			if(node[node[root].son[i]].a<0){
				flag = 1;
			}
			node[node[root].son[i]].s = node[root].s+node[node[root].son[i]].a;
			sum+=node[node[root].son[i]].a;
		}
		else if(node[node[root].son[i]].s!=-1){
			node[node[root].son[i]].a = node[node[root].son[i]].s-node[root].s;
			sum+=node[node[root].son[i]].a;
			if(node[node[root].son[i]].a<0){
				flag = 1;
			}
		}
		dfs(node[root].son[i]);
	}
}

int main(){
	cin>>n;
	for(int i=2;i<=n;i++){
		cin>>m;
		node[m].son.push_back(i);
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		node[i].s = k;
		if(i==1)node[i].a = k;
	}
	dfs(1);
	if(flag==1)cout<<-1<<endl;
	else cout<<sum+node[1].s<<endl;
	return 0;
}
