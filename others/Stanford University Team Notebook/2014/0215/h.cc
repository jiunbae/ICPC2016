#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct coord
{
	long long x, y, z;
	bool operator < (const coord &c) const
	{
	    if(y==0 && c.y==0)
	    {
	        if(x*c.x >= 0)
        		return x*x + y*y < c.x*c.x + c.y*c.y;
        	else
        	    return x<0;
	    }
	    if(y*c.x != c.y*x) return y*c.x < c.y*x;
		return x*x + y*y < c.x*c.x + c.y*c.y;
	}

	coord(int x, int y, int z) : x(x), y(y), z(z) {}
};
bool on_line(const coord& a, const coord &b)
{
    if(a.y==0 && b.y==0) return a.x*b.x >= 0;
    return a.y*b.x == b.y*a.x;
}
bool compare(const coord& a, const coord& b)
{
    return a.x!=b.x? a.x<b.x : a.y<b.y;
}
int main()
{
	int tc = 0;
	while (true) {
		tc ++;
		int total_laser;
		cin >> total_laser;
		if(total_laser == 0) break;

		vector<coord> poles;
		for(int i = 0; i < total_laser; i ++) {
			int x, y, z;
			cin >> x >> y >> z;

			poles.push_back(coord(x, y, z));
		}
		sort(poles.begin(), poles.end());

		int prev_max_height = 0;
		bool line_found = false;
		vector<coord> invisible_poles;

        int j;
		for(int i = 0; i < total_laser; i = j) {
		    prev_max_height = poles[i].z;
		    for(j = i+1; j < total_laser && on_line(poles[i], poles[j]); j++)
		    {
		        if(prev_max_height >= poles[j].z) invisible_poles.push_back(poles[j]);
		        else prev_max_height = poles[j].z;
			}
		}
		cout << "Data set " << tc << ":" << endl;
		if(invisible_poles.size() == 0) {
			cout << "All the lights are visible." << endl;
		}
		else {
			cout << "Some lights are not visible:" << endl;
			sort(invisible_poles.begin(), invisible_poles.end(), compare);
			for(int i = 0; i < invisible_poles.size(); i ++) {
				cout << "x = " << invisible_poles[i].x << ", y = " << invisible_poles[i].y;
				if(i != invisible_poles.size() - 1) cout << ";\n";
				else cout << ".\n";
		    }
		}
	}
	return 0;
}
/*
3
-1 0 1 0 1 1 1 0 1
5
-1 0 1 -1 1 2 -2 2 2 -3 3 3 -4 4 2
*/
