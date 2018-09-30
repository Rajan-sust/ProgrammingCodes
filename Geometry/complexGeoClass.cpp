#include<bits/stdc++.h>
using namespace std;

#define x() real()
#define y() imag()

const double pi = acos(-1.0);

typedef complex<double> pt;

double dot(pt a,pt b) { return (conj(a) * b).x(); }

double cross(pt a,pt b) { return (conj(a) * b).y(); }

double unsignCross(pt a,pt b) { return abs((conj(a) * b).y()); }

double euclidDis(pt a,pt b) { return sqrt(norm(a-b)); } /*norm returns x^2+y^2 */

pt rotation(pt a,double theta) { return a * polar(1.0, theta); }

pt pivotRotation(pt a,pt p,double theta) { return (a-p) * polar(1.0, theta) + p; } /*Rotation about pivot p*/

pt pointProject(pt a,pt b,pt p) { return a + (b - a) * dot(p - a, b - a) / norm(b - a); } /*Project p onto line (a, b)*/

pt pointReflect(pt a,pt b,pt p) { return a + conj((p - a) / (b - a)) * (b - a); } /*Reflect p across line (a, b)*/

pt intersection(pt a, pt b, pt p, pt q) {
  double c1 = cross(p - a, b - a), c2 = cross(q - a, b - a);
  return (c1 * q - c2 * p) / (c1 - c2); /* undefined if parallel */
}

/* strictly inside in polgon 
Let p1, ..., pn be points of polygon in clockwise order.
Now you're given point q and have to check whether it lies in polygon. 
At first check that it lies in angle formed by points p2, p1, pn. 
If that's false, then answer for sure is no. 
Otherwise let's notice that function "f(i) =  is it true that triplet (p1, pi, q) is right-orientated" is monotone (i.e. it's always true at first, then always false).
Do binary search on i checking the condition using orientated triangle area.
After you've found the first i such that triplet (p1, pi, q) is left-orientated, check that q is in triangle p1, pi - 1, i. Done!
*/


bool point_in_convexpoly(const vector<pt> &v,const pt &p)
{
	int lo = 1,hi = int(v.size())-1;

	while(lo<=hi) {
		int mid = (lo+hi)>>1;
		if(cross(v[0],v[mid],p)<0) {
			hi = mid - 1;
		}else{
			lo = mid + 1;
		}
	} 

	hi+=1; 

	ll area = cross_val(p,v[0],v[hi]) + cross_val(p,v[0],v[hi-1]) + cross_val(p,v[hi],v[hi-1]);
	ll tri_area = cross_val(v[0],v[hi],v[hi-1]);

	if(area==tri_area)
		return (cross(p,v[hi],v[hi-1])==0)?false:true;

	return false;
}

int main()
{
	

	
	return 0;
}
