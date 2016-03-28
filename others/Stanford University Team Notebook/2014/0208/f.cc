#include <cstdio>
#include <map>
#include <vector>
using namespace std;

int n;
long long k;
int ans;

struct point {
    long long x, y, z;
    point (int x, int y, int z) : x(x), y(y), z(z) {}
    bool operator < (const point& rhs) const { 
        return x!=rhs.x ? x<rhs.x : y!=rhs.y ? y<rhs.y : z<rhs.z;
    }
    
    void chkdist (point& rhs) {
        long long res = (x-rhs.x)*(x-rhs.x)+(y-rhs.y)*(y-rhs.y)+(z-rhs.z)*(z-rhs.z);
        if (res < k*k)
            ans++;
    }
};

map<point, vector<point> > m;

int main()
{
    while (true) {
        scanf ("%d%lld", &n, &k);
        if (n==0 && k==0) break;
        
        m.clear ();
        for (int i=0; i<n; i++) {
            int x, y, z;
            scanf ("%d%d%d", &x, &y, &z);
            x += 1000000000;
            y += 1000000000;
            z += 1000000000;
            
            point c (x/k, y/k, z/k);
            m[c].push_back (point (x, y, z));
        }
        
        ans=0;
        for (map<point, vector<point> >::iterator it=m.begin (); it!=m.end(); it++) {
            vector<point>& v = it->second;
            /*
            for (int i=0; i<v.size(); i++) {
                for (int j=i+1; j<v.size(); j++)
                    v[i].chkdist (v[j]);
            }
            */
            
            point id = it->first;
            for (int dx=-1; dx<=1; dx++) for (int dy=-1; dy<=1; dy++) for (int dz=-1; dz<=1; dz++) {
                //if (dx==0 && dy==0 && dz==0) continue;
                point id2 (id.x + dx, id.y + dy, id.z + dz);
                if (m.find(id2) != m.end()) {
                    vector<point>& v2 = m[id2];
                    for (int i=0; i<v.size(); i++) for (int j=0; j<v2.size(); j++) v[i].chkdist(v2[j]);
                }
            }
        }
        printf ("%d\n", (ans-n)/2);
    }
    return 0;
}
