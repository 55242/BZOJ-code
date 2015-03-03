/*
byvoid��
��F[i]Ϊ������ÿ��Ӳ�ҵ��������Ƶ�����£��õ���ֵi�ķ���������״̬ת�Ʒ���Ϊ

F[i]=Sum{F[i-C[k]] | i-C[k]>=0 �� k=1..4}

Ϊ���ⷽ���ظ���Ҫ��kΪ�׶ε��ƣ��߽�����ΪF[0]=1������Ԥ�����ʱ�临�ӶȾ���O(S)��

����������ÿ��ѯ�ʣ�����Ľⷨ���£������ݳ�ԭ����Ϊ �õ���ֵS�ĳ������Ƶķ����� - ��1��Ӳ�ҳ������Ƶķ����� - ��2��Ӳ�ҳ������Ƶķ����� - ��3��Ӳ�ҳ������Ƶķ����� - ��4��Ӳ�ҳ������Ƶķ����� + ��1,2��Ӳ��ͬʱ�������Ƶķ����� + ��1,3��Ӳ��ͬʱ�������Ƶķ����� + ...... + ��1,2,3,4��Ӳ��ȫ��ͬʱ�������Ƶķ�������

����1��Ӳ�ҳ�������ʱ��ֻҪҪ�õ�D[1]+1öӲ�ң�ʣ���Ӳ�ҿ���������䣬���Է�����Ϊ F[ S - (D[1]+1)C[1] ]�����ҽ���(S - (D[1]+1)C[1])>=0�����򷽰���Ϊ0������������ƣ�ÿ��ѯ��ֻ����16�Σ�����ѯ�ʵ�ʱ�临�Ӷ�ΪO(1)��	
*/
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXV = 1010;
template<class T>inline void Read(T& x){
	x=0; bool flag=0; char ch=getchar();
	while(ch> '9' || ch< '0'){ if(ch=='-'){ flag=1; ch=getchar(); break; } ch=getchar();}
	while(ch>='0' && ch<='9'){ x=x*10+ch-48; ch=getchar(); }
	if(flag) x=-x;
}
LL Ans=0,F[100005];
int T=0,c[5],d[5];
inline void DFS(int x,int k,int sum){
	if(sum<0) return;
	if(x==5){
		if(k&1) Ans-=F[sum];
		else Ans+=F[sum];
		return;
	} 
	DFS(x+1,k+1,sum-(d[x]+1)*c[x]);
	DFS(x+1,k,sum);
}
int main(){
	for(int i=1;i<=4;++i) Read(c[i]);
	Read(T); F[0]=1;
	for(int i=1;i<=4;++i){
		for(int j=c[i];j<=100000;++j){
			F[j]+=F[j-c[i]];
		}
	}
	int x=0;
	for(int i=1;i<=T;++i){
		for(int k=1;k<=4;++k) Read(d[k]);
		Read(x); Ans=0;
		DFS(1,0,x); 
		printf("%lld\n",Ans);

	}
	return 0;
}
