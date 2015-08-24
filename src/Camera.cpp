#include "Camera.h"


Camera::Camera(int screenWidth, int screenHeight, const Vec2& center /*= Vec2()*/):
	m_screenWidth(screenWidth),
	m_screenHeight(screenHeight),
	m_topleftWorld(),
	m_zoomFactorX(1.f),
	m_zoomFactorY(1.f)
{
	m_topleftWorld = center - Vec2(screenWidth / 2, screenHeight / 2);
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
	point.x -= m_topleftWorld.x;
	point.y -= m_topleftWorld.y;

	point.x *= zoomFactorX();
	point.y *= zoomFactorY(); 

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
	point.x += m_topleftWorld.x;
	point.y += m_topleftWorld.y;

	point.x /= zoomFactorX();
	point.y /= zoomFactorY();

	return point;
}

void Camera::setCenter(const Vec2& center)
{
	m_topleftWorld = center - (Vec2(m_screenWidth / 2 / zoomFactorX(), m_screenHeight / 2 / zoomFactorY()));
}


template<> void anFill<CameraManager>(An<CameraManager>& cameraManager)
{
	CameraManager& cm = CameraManager::Instance();
	cameraManager = &cm;
}

CameraManager& CameraManager::Instance()
{
	static CameraManager cameraManager;
	return cameraManager;
}

CameraPtr CameraManager::activeCamera()
{
	return m_currentCamera;
}

void CameraManager::setActiveCamara(CameraPtr camera)
{
	m_currentCamera = camera;
}
