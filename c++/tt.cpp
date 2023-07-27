#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int128 __int128
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;

const int maxn=1000005;
const ll inf=9e18;
const int128 inf128=(int128)(inf)*(int128)(inf);

ll a[maxn];
ll b[maxn];
ll g[maxn];
ll ra[maxn];
int128 suma[maxn];
int128 sumb[maxn];
int128 ans[maxn];

ll gcd(ll x,ll y) {
	return !y?x:gcd(y,x%y);
}

void print(int128 x) {
	if(!x) {
		return ;
	}
	print(x/10);
	cout<<(int)(x%10);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--) {
		int n,k;
		ll m;
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		int t=0,r=0;
		for(int i=1;i<=n;i++) {
			if(i>1&&a[i]==a[i-1]) {
				b[++r]=a[i];
			} else {
				ra[++t]=a[i];
			}
		}
		n=t;
		for(int i=1;i<=n;i++) {
			a[i]=ra[i];
			g[i]=gcd(g[i-1],a[i]);
			suma[i]=suma[i-1]+a[i];
		}
		for(int i=0;i<=k;i++) {
			ans[i]=-inf128;
		}
		for(int l=1;l<=n;) {
			int r=l;
			while(r<=n&&g[r]==g[l]) {
				r++;
			}
			r--;
			ll Max=-inf;
			for(int i=r+1;i<=n;i++) {
				a[i]=gcd(a[i],g[l]);
				Max=max(Max,a[i]-ra[i]);
			}
			for(int i=r;i>=l;i--) {
				ans[i]=suma[n]-suma[i]+Max;	
				a[i]=gcd(a[i],g[l]);
				Max=max(Max,a[i]-ra[i]);
			}
			l=r+1;
		}
		for(int i=1;i<=r;i++) {
			sumb[i]=sumb[i-1]+b[i];
		}
		int128 final=-inf128;
		if(k<=r) {
			final=suma[n]+sumb[r]-sumb[k];
		}
		for(int i=0;i<=r&&i<=k;i++) {
			final=max(final,sumb[r]-sumb[i]+ans[k-i]);
		}
		print(final);
		cout<<"\n";
	}
}