#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = 1000000;
vector<int> c(MAX+1, 0);
bool p[MAX+1]={false};
void isPrime(){
	for(int i=2; i*i<=MAX; i++){
		if(p[i]) continue;
		for(int j=2; j*i<=MAX; j++){
			p[i*j]=1;
		}
	}
}

int sumDigit(int a){
	if(a<10) return a;
	return (a%10)+a/10;
}

bool isDigitPrime(int a){
	return !p[sumDigit(a)];
}



void solve(){
	int m, n;
	scanf("%d%d", &m, &n);
	printf("%d\n", c[n]-c[m-1]);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	isPrime();
	for(int i=2; i<=MAX; i++){
		if(!p[i] && isDigitPrime(i)){
			c[i]=c[i-1]+1;
		}
		else{
			c[i]=c[i-1];
		}
	}
	int n;
	cin >> n;
	while(n--){
		int a, b;
		cin >> a >> b;
		cout << c[b]-c[a-1] << endl;
	return 0;
}
