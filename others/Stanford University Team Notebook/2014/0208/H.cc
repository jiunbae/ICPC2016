#include <iostream>
#include <cstdio>
#include <cassert>
#include <string>
#include <vector>
#include <complex>
#include <algorithm>
#include <queue>
using namespace std;
typedef complex<double> C;

bool cmp(C a, C b) {
	return a.imag() < b.imag() || (a.imag()==b.imag() && a.real() < b.real());
}

struct slope {
};

vector<C> P;
vector<int> point_to_order;
vector<int> order_to_point;

double area(int i, int j, int k) {
	C a=P[order_to_point[i]];
	C b=P[order_to_point[j]];
	C c=P[order_to_point[k]];
	return abs(((b-a)*conj(c-a)).imag()/2);
}

bool cmp4(double a, double b, double c, double d) {
	return make_pair(min(a,b),max(a,b)) > make_pair(min(c,d),max(c,d));
}

struct cmp_q {
	bool operator()( const pair<int,int>& p1, const pair<int,int>& p2 ) {
		C p = P[p1.second]-P[p1.first];
		C q = P[p2.second]-P[p2.first];
		if(p.imag() == 0 && q.imag() == 0) return cmp4(P[p1.first].real(),P[p1.second].real(),P[p2.first].real(),P[p2.second].real());
		if(p.imag() == 0) return false;
		if(q.imag() == 0) return true;
		C a = P[p1.first];
		C b = P[p1.second];
		C c = P[p2.first];
		C d = P[p2.second];
		C u = b-a;
		a /= u;
		b /= u;
		c /= u;
		d /= u;
		if(u.imag()<0) u=-u;
		double dd = p.real() / p.imag() - q.real() / q.imag();
		if(dd==0) return cmp4(a.real(),b.real(),c.real(),d.real());
		return dd<0;
	}
};

int main(void) {
	for(;;) {
		int N;
		cin >> N;
		if(N==0) break;
		P.clear();
		order_to_point.clear();
		point_to_order.clear();
		for(int i=0; i<N; i++) {
			double x,y;
			cin >> x >> y;
			P.push_back(C(x,y));
		}
		sort(P.begin(),P.end(),cmp);
		for(int i=0; i<N; i++) order_to_point.push_back(i);
		for(int i=0; i<N; i++) point_to_order.push_back(i);

		priority_queue< pair<int, int>, vector<pair<int,int> >, cmp_q > q;

		for(int i=0; i<N; i++) for(int j=0; j<i; j++) q.push(make_pair(i,j));

		double min_area=1e20;
		double max_area=0;

		while(!q.empty()) {
			int i=q.top().first;
			int j=q.top().second;
			q.pop();
			swap(order_to_point[point_to_order[i]],order_to_point[point_to_order[j]]);
			swap(point_to_order[i],point_to_order[j]);
			int I=point_to_order[i];
			int J=point_to_order[j];
			cout << i << P[i] << " " << j << P[j] << endl;
			if(I>J) swap(I,J);
			if(J!=I+1) min_area=0;
			if(I) min_area = min(min_area, area(I,J,I-1));
			if(J+1<N) min_area = min(min_area, area(I,J,J+1));
			max_area = max(max_area, area(I,J,0));
			max_area = max(max_area, area(I,J,N-1));
		}
		printf("%.1lf %.1lf\n",min_area,max_area);
	}
}
