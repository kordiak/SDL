
#include <string>
#include "SDL.h"
//#include "SDL_image.h"
#include "TextureManager.h"

#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

class GameObject
{
	public:
		void load(int x,int y,int width,int height,std::string textureID);
		void draw(SDL_Renderer* pRenderer);
		void update();
		void clean();
	protected:
		
		std::string m_textureID;
		int m_currentFrame;
		int m_currentRow;
		
		int m_x;
		int m_y;
		
		int m_width;
		int m_height;
			
};

#endif
