/*
ö��ÿһ��λ���ҳ�ÿһ����ɫ�����λ��֮��ĵ�һ��λ�������λ�þ�������ֵ�����ҳ�ÿһ��λ�ý������Сֵ�Ϳ�������
�ö���������������ǲ�����뷨
*/
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
template<class T>inline void Read(T& x){
	x=0; bool flag=0; char ch=getchar();
	while(ch> '9' || ch< '0'){ if(ch=='-'){ flag=1; ch=getchar(); break; } ch=getchar();}
	while(ch>='0' && ch<='9'){ x=x*10+ch-48; ch=getchar(); }
	if(flag) x=-x;
}
int N=0,K=0,ans=0x7f7f7f7f;
priority_queue<int,vector<int>,greater<int> >Q[70];
inline void DEAL(){
	while(!Q[0].empty()){
		int u=Q[0].top(),m=0;
		for(int i=1;i<=K;++i){
			while(Q[i].top()<u && !Q[i].empty()) Q[i].pop();
			if(Q[i].empty()) return;
			m=max(m,Q[i].top()-u);
		}
		ans=min(m,ans); Q[0].pop();
	}
}
int main(){
	Read(N); Read(K);
	int num=0,a=0;
	for(int i=1;i<=K;++i){
		Read(num);
		while(num--){
			Read(a);
			Q[i].push(a); Q[0].push(a);
		}
	}
	DEAL();
	printf("%d\n",ans);
	return 0;
}

