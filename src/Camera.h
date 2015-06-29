#ifndef __CAMERA__
#define __CAMERA__

#include "SDL.h"
#include "Types.h"

#include <memory>

class Camera
{
public:
	Camera(int screenWidth, int screenHeight);
	SDL_Rect apply(SDL_Rect rect);

	void setCameraRect(SDL_Rect rect);
	void setCameraCenter(SDL_Point point);
	void setCameraFactor(float x, float y);

	Point_t zoomFactor();
	float zoomFactorX();
	float zoomFactorY();
	
private:

	int			m_screenWidth;
	int			m_screenHeight;

	SDL_Point	m_cameraTopLeftCorner; // top left camera rect corner in absolute coordinates

	float		m_zoomFactorX, m_zoomFactorY; // zoom factor of camera, is equal to screenSize / cameraSize 
};

typedef std::shared_ptr<Camera> CameraPtr;

#endif //__CAMERA__