#include "GameObject.h"

#ifndef _PLAYER_H_
#define _PLAYER_H_
class Player:public GameObject
{
	public:
		
		void load(int x,int y,int width,int height,std::string textureID);
		void draw(SDL_Renderer* pRenderer);
		void update();
		void clean();
};
#endif
