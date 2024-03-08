#include<iostream>
using namespace std;

int egcd(int a, int b, int& resa, int& resb){
    // return resa * a + resb * b = gcd
    if(a == 0){
        resa = 0, resb = 1; return b;
    }
    int x1 = 0, y1 = 0;
    int gcd = egcd(b%a, a, x1, y1);
    resa = y1 - (b/a) * x1;
    resb = x1;
    return gcd;
}
int CRT(int n1, int n2, int a1, int a2){
    int m1, m2;
    egcd(n1, n2, m1, m2);
    int x = a1 * m2 * n2 + a2 * m1 * n1;
    return x;
}
int main(){
    int a, b;
    cout<<egcd(35, 6, a, b)<<" ";
    cout<<a<<" "<<b<<endl;
    cout<<CRT(35, 6, 17, 5)<<" ";
    return 0;
}