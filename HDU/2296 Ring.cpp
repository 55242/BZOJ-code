/*����m��ģʽ��,ÿ������һ���ķ�ֵ,����һ�����Ȳ�����n�Ĵ�, 
ʹ�÷�ֵ���,���������С,�ֵ�����С�Ĵ�*/ 
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
int a[110],dp[55][1010];
char str[55][1010][55];
inline bool cmp(char *a,char *b) { //�ȱȽϳ���,�ٱȽ������ַ����ֵ����С 
	int lena = strlen(a) , lenb = strlen(b);
	if(lena != lenb) return lena < lenb;
	return strcmp(a,b) < 0;
}
struct TRIE {
	int next[1010][26],fail[1010],end[1010];
	int root , L;
	int newnode() {
		for(int i = 0;i < 26;++i) next[L][i] = -1;
		end[L++] = -1;
		return L-1;
	}
	inline void init() { L = 0; root = newnode(); }
	inline void insert(char *buf,int num) {
		int len = strlen(buf) , now = root ,id = 0 ;
		for(int i = 0;i < len;++i){
			id = buf[i]-'a';
			if(next[now][id] == -1) next[now][id] = newnode();
			now = next[now][id];
		}
		end[now] = num;
	}
	inline void build() {
		queue<int>Q;
		for(int i = 0;i < 26;++i) {
			if(next[root][i] == -1) next[root][i] = root;
			else {
				fail[next[root][i]] = root;
				Q.push(next[root][i]);
			}
		}
		while(!Q.empty()) {
			int now = Q.front(); Q.pop();
			if(end[fail[now]] == true) end[now] = true;
			for(int i = 0;i < 26;++i) {
				if(next[now][i] == -1) next[now][i] = next[fail[now]][i];
				else {
					fail[next[now][i]] = next[fail[now]][i];
					Q.push(next[now][i]);
				}
			}
		}
	}
	/*
	dp[i][j]��ʾ����Ϊi��ʱ��,��Trie�ϵĵ�j�����ʱ������ֵ,
	str[i][j]��ʾ״̬(i,j)ʱ���ֵ�����С�Ĵ�
	*/
	void solve(int n) {
		memset(dp,0xcf,sizeof(dp));
		dp[0][0] = 0;//������ֵΪ0,����մ� 
		strcpy(str[0][0],"");
		char ans[55]; strcpy(ans,""); 
		int Max = 0; 
		char tmp[55];
		for(int i = 0;i < n;++i) //���� 
			for(int j = 0;j < L;++j) //TRIE�ϵ�ÿ���ڵ� 
				if(dp[i][j] >= 0){
					strcpy(tmp,str[i][j]);
					int len = strlen(tmp);
					for(int k = 0;k < 26;++k) { //ö����һ���ַ���ʲô,�����ֵ 
						int down = next[j][k];
						tmp[len] = 'a' + k;
						tmp[len+1] = 0;
						int tt = dp[i][j];
						if(end[down] != -1) tt += a[end[down]]; //��ǰ�ڵ���һ�����ʽڵ�,���Ϸ�ֵ 
						if(dp[i+1][down] < tt || (dp[i+1][down] == tt && cmp(tmp,str[i+1][down])) ) {
							//��֤��ֵ��� �� ��ֵ�������³����ֵ�����С 
							dp[i+1][down] = tt;
							strcpy(str[i+1][down],tmp);
							if(tt > Max || (tt == Max && cmp(tmp,ans)) ){
								Max = tt; strcpy(ans,tmp);
							}
						}
					}
				}
		printf("%s\n",ans);
	}
}AC;
char buf[55];
int main(){
	int T = 0 ,n = 0 ,m = 0;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m);
		AC.init();
		for(int i = 0;i < m;++i) {
			scanf("%s",buf); AC.insert(buf,i);
		}
		for(int i = 0;i < m;++i) Read(a[i]);
		AC.build();
		AC.solve(n);
	}
	return 0;
}
