/*
 * holds a vector 3 dimensions
 */
namespace phy{


class Vector3{
	typedef float real;
	public:
		real x,y,z;
	private:
		real pad;
	public:
		Vector3(real x, real y, real z):x(x),y(y),z(z){};
		Vector3(real c):x(c), y(c), z(c){};
		Vector3(const Vector3& v):x(v.x), y(v.y), z(v.z){};

		Vector3 operator+(const Vector3 &v);
		Vector3 operator-(const Vector3 &v);
		Vector3 operator*(const Vector3 &v);
		Vector3 operator/(const Vector3 &v);

		Vector3 & operator +=(const Vector3 &v);
		Vector3 & operator -=(const Vector3 &v);
		Vector3 & operator *=(const Vector3 &v);
		Vector3 & operator /=(const Vector3 &v);

};
}
