#include <bits/stdc++.h>
using namespace std;
const int Maxn = 100010;
bool isPrime(int n){
    if(n == 1)
        return false;
    int sqr = (int)sqrt((double)n);
    for(int i = 2; i <= sqr; i++)
    	if(n % i == 0)
        	return false;
    return true;
}
int prime[Maxn],pNum = 0;
void findPrime(){
    for(int i = 1; i < Maxn; i++){
        if(isPrime(i) == true)
            prime[pNum++] = i;
    }
}
struct factor{
    int x;
    int cnt;
}fac[10];
int main()
{
    findPrime();
    int N, num = 0;
    cin >> N;
    if(N == 1)
        printf("1=1");
    else{
        printf("%d=", N);
        int sqr = (int)sqrt((double)N);
        for(int i = 0; i < pNum && prime[i] <= sqr; i++){
            if(N % prime[i] == 0){
                fac[num].x = prime[i];
                fac[num].cnt = 0;
                while(N % prime[i] == 0);{
                    fac[num].cnt++;
                    N /= prime[i];
                }
                num++;
            }
            if(N == 1)
                break;
        }
        if(N != 1){
            fac[num].x = N;
            fac[num++].cnt = 1;
        }
        for(int i = 0; i < num; i++){
            if(i > 0)
                printf("*");
            printf("%d", fac[i].x);
            if(fac[i].cnt > 1){
                printf("^%d", fac[i].cnt);
            }
        }
    }
    return 0;
}
