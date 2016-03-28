#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

long long gcd (long long a, long long b)
{
    long long t;
    while(b){t=a%b; a=b; b=t;}
    return a;
}

struct num {
    long long a, b;
    num (long long aa=0, long long bb=1)
    {
        long long g = gcd(aa, bb);
        a = aa / g;
        b = bb / g;
        if (b<0) a=-a, b=-b;
    }
    
    num inv () const { return num (b, a); }
    
    num operator * (const num& r) const {
        return num (a*r.a, b*r.b);
    }
    
    num operator / (const num& r) const {
        return num (a*r.b, b*r.a);
    }
    
    num operator + (const num& r) const {
        return num (a*r.b + b*r.a, b*r.b);
    }
    
    num operator - (const num& r) const {
        return num (a*r.b - b*r.a, b*r.b);
    }
    
    void print () { printf ("%lld/%lld", a, b); }
};

int n;
char is1[12], is2[12];
int i1, i2;

int nzcnt[512];
vector<int> nze;

num a[513][513];
num b[513];

int m;

void solve ()
{
    m=1<<n;
    
    for (int i=0; i<m; i++) {
        int cur=-1;
        
        for (int j=i; j<m; j++) if (a[j][i].a) {
            if (cur==-1 || nzcnt[cur] > nzcnt[j])
                cur=j;
        }
        
        if (cur != i) {
            for (int k=i; k<m; k++) swap (a[cur][k], a[i][k]);
            swap (b[i], b[cur]);
            swap (nzcnt[i], nzcnt[cur]);
        }
        
        
        nze.clear ();
        for (int j=i; j<m; j++) {
            if (a[i][j].a != 0) nze.push_back (j);
        }
        
        
        for (int j=i+1; j<m; j++) if (a[j][i].a) {
            num r = a[j][i] / a[i][i];
            b[j] = b[j] - b[i] * r;
            for (int ki=0; ki<nze.size(); ki++) {
                int k = nze[ki];
                if (a[j][k].a) nzcnt[j]--;
                a[j][k] = a[j][k] - a[i][k] * r;
                if (a[j][k].a) nzcnt[j]++;
            }
        }
    }
    
    for (int i=m-1; i>=0; i--) {
        for (int j=i+1; j<m; j++) b[i] = b[i] - a[i][j] * b[j];
        b[i] = b[i] / a[i][i];
    }
}

int getstate (char* x)
{
    int ret=0;
    //for (int i=n-1; i>=0; i--) {
    for (int i=0; i<n; i++) {
        ret = ret*2 + (x[i]=='T' ? 1 : 0);
    }
    return ret;
}

int main()
{
    while (true) {
        scanf ("%s", is1);
        if (is1[0]=='$') break;
        scanf ("%s", is2);
        
        n=strlen(is1);
        i1 = getstate (is1);
        i2 = getstate (is2);
        
        for (int i=0; i<(1<<n); i++) {
            for (int j=0; j<(1<<n); j++) a[i][j] = 0;
            nzcnt[i] = 0;
            b[i] = 0;
        }
        for (int i=0; i<(1<<n); i++) {
            if (i==i1) a[i][i] = 1, b[i] = 1;
            else if (i==i2) a[i][i] = 1, b[i] = 0;
            else {
                int j1 = ((i<<1) & ((1<<n)-1)) | 0;
                int j2 = ((i<<1) & ((1<<n)-1)) | 1;
                a[i][i] = 2, a[i][j1] = a[i][j1] + (-1), a[i][j2] = a[i][j2] + (-1);
                b[i] = 0;
                
                for (int j=0; j<(1<<n); j++) {
                    if (a[i][j].a) nzcnt[i]++;
                }
            }
        }
        
        /*
        for (int i=0; i<(1<<n); i++) {
            for (int j=0; j<(1<<n); j++) {
                a[i][j].print (); printf ("\t");
            }
            printf ("\t");
            b[i].print();
            printf ("\n");
        }
        printf ("\n");
        */
        
        solve ();
        
        /*
        for (int i=0; i<(1<<n); i++) {
            for (int j=0; j<(1<<n); j++) {
                a[i][j].print (); printf ("\t");
            }
            printf ("\t");
            b[i].print();
            printf ("\n");
        }
        printf ("\n");
        */
        
        num ans;
        for (int i=0; i<(1<<n); i++) {
            ans = ans + b[i] / (1<<n);
        }
        
        ans.print (); printf ("\n");
    }
    return 0;
}

