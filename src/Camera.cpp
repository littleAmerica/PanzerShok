#include "Camera.h"

Camera::Camera(int screenWidth, int screenHeight, const Vec2& center /*= Vec2()*/):
	m_screenWidth(screenWidth),
	m_screenHeight(screenHeight),
	m_topleft(),
	m_zoomFactorX(1.f),
	m_zoomFactorY(1.f)
{
	m_topleft = center - Vec2(screenWidth / 2, screenHeight / 2);
}

Rect_t Camera::world2camera(Rect_t rect)
{
	Rect_t out = rect;

	Vec2 point = world2camera(Vec2(rect.x, rect.y));
	out.x = point.x;
	out.y = point.y;

	out.w *= zoomFactorX();
	out.h *= zoomFactorY();

	return out;
}

Vec2 Camera::world2camera(Vec2 point)
{
	point.x *= zoomFactorX();
	point.y *= zoomFactorY(); 

	point.x -= m_topleft.x;
	point.y -= m_topleft.y;

	return point;
}

void Camera::setCameraRect(Rect_t rect)
{
	throw 3;
}


void Camera::setCameraFactor(float x, float y)
{
	if(x == 0 || y == 0)
		throw;

	m_zoomFactorX = x;
	m_zoomFactorY = y;
}

Vec2 Camera::zoomFactor()
{
	Vec2 factor(m_zoomFactorX, m_zoomFactorY);
	
	return factor;
}

float Camera::zoomFactorX()
{
	return m_zoomFactorX;
}

float Camera::zoomFactorY()
{
	return m_zoomFactorY;
}

Rect_t Camera::camera2world(Rect_t rect)
{
	Rect_t out = rect;

	Vec2 point = camera2world(Vec2(rect.x, rect.y));
	out.x = point.x;
	out.y = point.y;

	out.w /= zoomFactorX();
	out.h /= zoomFactorY();

	return out;
}

Vec2 Camera::camera2world(Vec2 point)
{
	point.x += m_topleft.x;
	point.y += m_topleft.y;

	point.x /= zoomFactorX();
	point.y /= zoomFactorY();

	return point;
}

void Camera::setCenter(const Vec2& center)
{
	m_topleft = center - Vec2(m_screenWidth / 2, m_screenHeight / 2);
}

