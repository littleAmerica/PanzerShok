#include "EventListener.h"


EventListener::EventListener() {
}

EventListener::~EventListener() {
	//Do nothing
}

void EventListener::OnEvent(SDL_Event* event) {
	switch(event->type) {
		//case SDL_ACTIVEEVENT: {
		//	switch(Event->active.state) {
		//	case SDL_APPMOUSEFOCUS: {
		//		if ( Event->active.gain )    OnMouseFocus();
		//		else                OnMouseBlur();

		//		break;
		//							}
		//	case SDL_APPINPUTFOCUS: {
		//		if ( Event->active.gain )    OnInputFocus();
		//		else                OnInputBlur();

		//		break;
		//							}
		//	case SDL_APPACTIVE:    {
		//		if ( Event->active.gain )    OnRestore();
		//		else                OnMinimize();

		//		break;
		//						   }
		//	}
		//	break;
		//					  }

	case SDL_KEYDOWN: {
		OnKeyDown(event->key.keysym.sym, event->key.keysym.mod);
		break;
					  }

	case SDL_KEYUP: {
		OnKeyUp(event->key.keysym.sym, event->key.keysym.mod);
		break;
				}

	case SDL_MOUSEMOTION: {
		OnMouseMove(event->motion.x, event->motion.y, event->motion.xrel, event->motion.yrel, 
			(event->motion.state& SDL_BUTTON(SDL_BUTTON_LEFT)) !=0,
			(event->motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT))!=0,
			(event->motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE)) !=0);
		break;
						  }

	case SDL_MOUSEBUTTONDOWN: {
		switch(event->button.button) {
		case SDL_BUTTON_LEFT: {
			OnLButtonDown(event->button.x, event->button.y);
			break;
						  		}
		case SDL_BUTTON_RIGHT: {
			OnRButtonDown(event->button.x, event->button.y);
			break;
						  		}
		case SDL_BUTTON_MIDDLE: {
			OnMButtonDown(event->button.x, event->button.y);
			break;
						  		}
		}
		break;
						  		}

						  //case SDL_MOUSEBUTTONUP:    {
						  //	switch(Event->button.button) {
						  //	case SDL_BUTTON_LEFT: {
						  //		OnLButtonUp(Event->button.x,Event->button.y);
						  //		break;
						  //						  }
						  //	case SDL_BUTTON_RIGHT: {
						  //		OnRButtonUp(Event->button.x,Event->button.y);
						  //		break;
						  //						   }
						  //	case SDL_BUTTON_MIDDLE: {
						  //		OnMButtonUp(Event->button.x,Event->button.y);
						  //		break;
						  //							}
						  //	}
						  //	break;
						  //						   }

						  //case SDL_JOYAXISMOTION: {
						  //	OnJoyAxis(Event->jaxis.which,Event->jaxis.axis,Event->jaxis.value);
						  //	break;
						  //						}

						  //case SDL_JOYBALLMOTION: {
						  //	OnJoyBall(Event->jball.which,Event->jball.ball,Event->jball.xrel,Event->jball.yrel);
						  //	break;
						  //						}

						  //case SDL_JOYHATMOTION: {
						  //	OnJoyHat(Event->jhat.which,Event->jhat.hat,Event->jhat.value);
						  //	break;
						  //					   }
						  //case SDL_JOYBUTTONDOWN: {
						  //	OnJoyButtonDown(Event->jbutton.which,Event->jbutton.button);
						  //	break;
						  //						}

						  //case SDL_JOYBUTTONUP: {
						  //	OnJoyButtonUp(Event->jbutton.which,Event->jbutton.button);
						  //	break;
						  //					  }

	case SDL_QUIT: {
		OnExit();
		break;
				   }

				   //case SDL_SYSWMEVENT: {
				   //	//Ignore
				   //	break;
				   //					 }

				   //case SDL_VIDEORESIZE: {
				   //	OnResize(Event->resize.w,Event->resize.h);
				   //	break;
				   //					  }

				   //case SDL_VIDEOEXPOSE: {
				   //	OnExpose();
				   //	break;
				   //					  }

	default: {
		//		OnUser(Event->user.type,Event->user.code,Event->user.data1,Event->user.data2);
		break;
			 }
	}
}

void EventListener::OnInputFocus() {
	//Pure virtual, do nothing
}

void EventListener::OnInputBlur() {
	//Pure virtual, do nothing
}

void EventListener::OnKeyDown(SDL_Keycode sym, Uint16 mod) {
	//Pure virtual, do nothing
}

void EventListener::OnKeyUp(SDL_Keycode sym, Uint16 mod) {
	//Pure virtual, do nothing
}

void EventListener::OnMouseFocus() {
	//Pure virtual, do nothing
}

void EventListener::OnMouseBlur() {
	//Pure virtual, do nothing
}

void EventListener::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle) 
{
	//Pure virtual, do nothing
}

void EventListener::OnMouseWheel(bool Up, bool Down) {
	//Pure virtual, do nothing
}

void EventListener::OnLButtonDown(int mX, int mY) {
	//Pure virtual, do nothing
}

void EventListener::OnLButtonUp(int mX, int mY) {
	//Pure virtual, do nothing
}

void EventListener::OnRButtonDown(int mX, int mY) {
	//Pure virtual, do nothing
}

void EventListener::OnRButtonUp(int mX, int mY) {
	//Pure virtual, do nothing
}

void EventListener::OnMButtonDown(int mX, int mY) {
	//Pure virtual, do nothing
}

void EventListener::OnMButtonUp(int mX, int mY) {
	//Pure virtual, do nothing
}

void EventListener::OnJoyAxis(Uint8 which,Uint8 axis,Sint16 value) {
	//Pure virtual, do nothing
}

void EventListener::OnJoyButtonDown(Uint8 which,Uint8 button) {
	//Pure virtual, do nothing
}

void EventListener::OnJoyButtonUp(Uint8 which,Uint8 button) {
	//Pure virtual, do nothing
}

void EventListener::OnJoyHat(Uint8 which,Uint8 hat,Uint8 value) {
	//Pure virtual, do nothing
}

void EventListener::OnJoyBall(Uint8 which,Uint8 ball,Sint16 xrel,Sint16 yrel) {
	//Pure virtual, do nothing
}

void EventListener::OnMinimize() {
	//Pure virtual, do nothing
}

void EventListener::OnRestore() {
	//Pure virtual, do nothing
}

void EventListener::OnResize(int w,int h) {
	//Pure virtual, do nothing
}

void EventListener::OnExpose() {
	//Pure virtual, do nothing
}

void EventListener::OnExit() {
	//Pure virtual, do nothing
}

void EventListener::OnUser(Uint8 type, int code, void* data1, void* data2) {
	//Pure virtual, do nothing
}