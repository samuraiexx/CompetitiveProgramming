#include<bits/stdc++.h>
using namespace std;
typedef long double ld;

const ld PI = acos(-1.);
const int N = 1 << 16;
char str1[10005];
char str2[10005];
int num[N];

struct T {
    ld x, y;
    T() :x(0), y(0) {}
    T(ld a, ld b=0) : x(a), y(b) {}

    T operator/=(ld k) { x/=k, y/=k; return (*this); }
    T operator*(T a) const { return T(x*a.x - y*a.y, x*a.y + y*a.x); }
    T operator+(T a) const { return T(x + a.x, y + a.y); }
    T operator-(T a) const { return T(x - a.x, y - a.y); }
} a[N], b[N];

void fft(T *a, int n, int s){
    for(int i = 0, j = 0; i < n; i++){
        if(i > j) swap(a[i], a[j]);
        for(int l = n/2; (j^=l) < l; l>>=1);
    }

    for(int i = 1; (1<<i) <= n; i++){
        int M = 1 << i;
        int K = M >> 1;
        T wn = T(cos(s*2*PI/M), sin(s*2*PI/M));
        for(int j = 0; j < n; j += M) {
            T w = T(1, 0);
            for(int l = j; l < K + j; ++l){
                T t = w*a[l + K];
                a[l + K] = a[l] - t;
                a[l] = a[l] + t;
                w = wn*w;
            }
        }
    }
}

void multiply(T* a, T *b, int n) {
    fft(a, n, 1);
    fft(b, n, 1);
    for(int i = 0; i < n; i++) a[i] = a[i]*b[i];
    fft(a, n, -1);
    for(int i = 0; i < n; i++) a[i] /= n;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int s1 = 0, s2 = 0, j;
        scanf("%s%s", str1, str2);
        if(str1[0] == '0' or str2[0] == '0') { printf("0\n"); continue; }
        
        while(str1[++s1] != '\0');
        while(str2[++s2] != '\0');
        
        for(int i = 0; i < N; i++) a[i].x = b[i].x = a[i].y = b[i].y = 0;
        for(int i = 0; i < s1; i++) a[i].x = str1[s1 - i - 1] - '0';
        for(int i = 0; i < s2; i++) b[i].x = str2[s2 - i - 1] - '0';
        s1 = s1 + s2 - 1;
        for(j = 0; (1 << j) < s1; j++);
        multiply(a, b, 1 << j);

        int goes = 0;
        for(int i = 0; i < s1; i++) num[i] = (goes + a[i].x + .5), goes = num[i]/10, num[i]%=10;
        if(goes) printf("%d", goes);
        for(int i = 0; i < s1; i++) printf("%d", num[s1 - i - 1]);
        printf("\n");
    }
    return 0;
}
