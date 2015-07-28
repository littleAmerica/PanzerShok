#ifndef TYPES_H_
#define TYPES_H_

#include "Box2D_platform.h"

typedef b2Vec2 Vec2;

inline float DotProduct(const Vec2& v1, const Vec2& v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

struct Rect_t
{
	float x;
	float y;
	float w;
	float h;
	
	Rect_t():
		x(0.f),
		y(0.f),
        w(0.f),
        h(0.f)
	{
	}
	Rect_t(float _x, float _y, float _w, float _h):
		x(_x),
		y(_y),
		w(_w),
		h(_h)
	{
	}
};

//
//struct Vec2
//{
//	float x;
//	float y;
//
//	Vec2();
//	Vec2(float _x, float _y);
//
//	float length() const;
//	void normalize();
//
//	Vec2 operator -() const;
//};
//
//float DotProduct(const Vec2& v1, const Vec2& v2);
//Vec2 operator * (float num, const Vec2& v);
//
//inline Vec2::Vec2():
//	x(0.f),
//	y(0.f)
//{
//}
//
//inline Vec2::Vec2(float _x, float _y):
//	x(_x),
//	y(_y)
//{
//}
//
//inline float Vec2::length() const
//{
//	return sqrt(DotProduct(*this, *this));
//}
//
//inline Vec2 Vec2::operator -() const 
//{ 
//	Vec2 v(-x, -y); 
//	return v; 
//}
//
//void Vec2::normalize()
//{ 
//	float _length = length();
//	x /= _length;
//	y /= _length; 
//}
//inline Vec2 operator * (float num, const Vec2& v)
//{
//	return Vec2(num * v.x, num * v.y);
//}
//
//inline float DotProduct(const Vec2& v1, const Vec2& v2)
//{
//	return v1.x * v2.x + v1.y * v2.y;
//}

#endif // TYPES_H_
