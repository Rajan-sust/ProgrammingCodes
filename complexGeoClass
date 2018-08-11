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

int main()
{
	

	
	return 0;
}
