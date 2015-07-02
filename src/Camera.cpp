#include "Camera.h"

SDL_Rect Camera::world2camera(SDL_Rect rect)
{
	SDL_Rect out = rect;
	
	out.w *= zoomFactorX();
	out.h *= zoomFactorY();
	out.x *= zoomFactorX();
	out.y *= zoomFactorY(); 

	out.x -= m_cameraTopLeftCorner.x;
	out.y -= m_cameraTopLeftCorner.y;

	return out;
}

Point_t Camera::world2camera(Point_t point)
{
	point.x *= zoomFactorX();
	point.y *= zoomFactorY();
	return point;
}

void Camera::setCameraRect(SDL_Rect rect)
{
	throw 3;
}

void Camera::setCameraCenter(SDL_Point point)
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

Camera::Camera(int screenWidth, int screenHeight):
	m_screenWidth(screenWidth),
	m_screenHeight(screenHeight),
	m_zoomFactorX(1.f),
	m_zoomFactorY(1.f)
{
	m_cameraTopLeftCorner.x = 0;
	m_cameraTopLeftCorner.y = 0;
}

Point_t Camera::zoomFactor()
{
	Point_t factor(m_zoomFactorX, m_zoomFactorY);
	
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

SDL_Rect Camera::camera2world(SDL_Rect rect)
{
	SDL_Rect out = rect;

	out.w /= zoomFactorX();
	out.h /= zoomFactorY();
	out.x /= zoomFactorX();
	out.y /= zoomFactorY(); 

	out.x += m_cameraTopLeftCorner.x;
	out.y += m_cameraTopLeftCorner.y;

	return out;
}

Point_t Camera::camera2world(Point_t point)
{
	point.x /= zoomFactorX();
	point.y /= zoomFactorY();
	return point;
}

