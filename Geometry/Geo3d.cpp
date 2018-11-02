/*input

*/

#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout<<#x<<" is "<<(x)<<'\n'

template <typename T>
struct point {
	T x,y,z;
	point(){}
	point(T _x,T _y,T _z):x(_x),y(_y),z(_z){}

	friend void print(const point &p) {
		cout<<"("<<p.x<<","<<p.y<<","<<p.z<<")"<<endl;
	}

	inline point operator+(const point &other) { return {x+other.x, y+other.y, z+other.z};}
	inline point operator-(const point &other) { return {x-other.x,y-other.y,z-other.z};}
    inline point operator*(T k) { return {x*k,y*k,z*k};}
    inline point operator/(T k) { return {x/k,y/k,z/k};}
	inline bool operator==(const point &other) { return tie(x,y,z)==tie(other.x,other.y,other.z);}
    inline bool operator!=(const point &other){ return !operator==(other); }


    inline friend T dot(const point &u,const point &v) {
    	return (u.x*v.x + u.y*v.y + u.z*v.z);
    }

	inline friend point cross(const point &u,const point &v) {
		return {(u.y*v.z-u.z*v.y),(u.z*v.x-u.x*v.z),(u.x*v.y-u.y*v.x)};
	}

	inline friend double mod(const point &u) {
		return sqrt((u.x*u.x + u.y*u.y + u.z*u.z)*1.0);
	}

	inline friend double angle(const point &u,const point &v) {
	    double cos_theta = dot(u,v)/mod(u)/mod(v);
		return acos(max(-1.0,min(1.0,cos_theta)));
	}

	/*(uxv).w returns is w same side with unique vector*/
	inline friend T orient(const point &u,const point &v,const point &w) {
		return dot(cross(u,v),w);
	}


	

};

typedef point<double> pt;

int main(int argc, char const *argv[])
{
	
	//ios::sync_with_stdio(false);

	//pt a = pt(1.0,2.0,3.0) - pt(2,5,6);
	//pt b = a*2.0;

	//print(a/2.0);
	//cout<<(a==b)<<endl;

	//cout<<(a!=b)<<endl;

	//print(a),print(b);

	//cout<<dot(a,b)<<endl;
   // print(a);
   // cout<<mod(a)<<endl;
	//cout<<fixed<<setprecision(10)<<angle(a,b)<<endl;


	//print(cross(a,b));


	
	return 0;
}
