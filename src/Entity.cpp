#include "Entity.h"

#include "Physics/PhysEngine.h"
#include "RenderEngine.h"

#include "States.h"
#include "SDL.h"

#include <iostream>

static PhysicInfo defaultPhysicInfo = {Rect_t(0, 16, 0, 16)};


Entity_Base::Entity_Base(int x /*= 0*/, int y /* = 0*/)
	:m_body(new Physics_Rigid(defaultPhysicInfo, x, y)),
	m_id(ID_counter++)
{
	if (!m_body)
		throw;

	m_body->setEntityID(m_id);

	m_maxForwardSpeed = 100;
	m_maxBackwardSpeed = -10;
	m_maxDriveForce = 150000;
}




void Entity_Base::updateFriction()
{
	//lateral linear velocity
	float maxLateralImpulse = 25.f;
	b2Vec2 impulse = m_body->mass() * - m_body->lateralVelocity();
	if ( impulse.Length() > maxLateralImpulse )
		impulse *= maxLateralImpulse / impulse.Length();
	 m_body->applyLinearImpulse(impulse);

	//angular velocity
	 m_body->applyAngularImpulse( 0.1f * m_body->inertia() * - m_body->angularVelocity());

	//forward linear velocity

	//std::cout << "forward velocity: x = " << currentForwardNormal.x << " y = " << currentForwardNormal.y << "\n";

	//forward linear velocity
	b2Vec2 currentForwardNormal = m_body->forwardVelocity();
	float currentForwardSpeed = currentForwardNormal.Normalize();
	float dragForceMagnitude = -2 * currentForwardSpeed;
	m_body->applyForce( dragForceMagnitude * currentForwardNormal);

	//std::cout << m_body->GetWorldCenter().x << " " << m_body->GetWorldCenter().y << "\n";
}

b2Vec2 Entity_Base::center()
{
	b2Vec2 center = m_body->worldCenter();
	return center;
}

float Entity_Base::angle()
{
	return m_body->angle();
}

Rect_t Entity_Base::bounds()
{
	return m_body->bounds();
}

Entity_Base::~Entity_Base()
{

}

void Entity_Base::update(float deltaTime)
{
	updateFriction();	
}

SDL_Rect Rect2SDL_Rect(Rect_t rect)
{
	SDL_Rect sdl_rect = {rect.x1, rect.y1, rect.x2 - rect.x1, rect.y2 - rect.y1};
	return sdl_rect;
}

double Radian2Degree(double degree)
{
	return degree * 180.0 / M_PI;
}

void Entity_Base::draw()
{
	Texture text_;
	text_.SetRenderer(RenderEngine::Instance().m_pRenderer);
	text_.loadImage("E:\\Projects\\PanzerShok\\resource\\tank1.png");

	Rect_t size = bounds();
	SDL_Rect origin = Rect2SDL_Rect(size);

	b2Vec2 center_ = center();
	SDL_Rect dest = {center_.x - size.x2 / 2, center_.y - size.y2 / 2, size.x2, size.y2};


	SDL_Surface *s = SDL_CreateRGBSurface(0, size.x2, size.y2, 32, 0, 0, 0, 0);
	SDL_FillRect(s, NULL, SDL_MapRGB(s->format, 255, 0, 0));



	SDL_Texture* text = SDL_CreateTextureFromSurface(RenderEngine::Instance().m_pRenderer, s);

	if(RenderEngine::Instance().m_game->camera())
		dest = RenderEngine::Instance().m_game->camera()->world2camera(dest);

	SDL_RenderCopyEx(RenderEngine::Instance().m_pRenderer, text_.textureHandle(), &text_.rect()/*origin*/, &dest, Radian2Degree(angle()) + 180, NULL, SDL_FLIP_NONE);

	SDL_DestroyTexture(text);
	SDL_FreeSurface(s);
}

int Entity_Base::id()
{
	return m_id;
}

int Entity_Base::ID_counter = 0;
