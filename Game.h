#include "GameObject.h"
#include "Player.h"
#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"


#ifndef _GAME_
#define _GAME_


class Game
{
	public:
	Game();
	~Game();
	
	bool init(const char* title,int xpos,int ypos,int width,int height,bool FULLCREEN=false);
	void render();
	void update();
	void handleEvents();
	void clean();
	
	bool running() { return m_bRunning;}
	
	private:
		SDL_Window* m_pWindow;
		SDL_Renderer* m_pRenderer;
		bool m_bRunning;
		int m_currentFrame;
		
		GameObject m_go;
		Player m_player;
		
		//TextureManager m_textureManager;
		
//		SDL_Texture* m_pTexture;
//		SDL_Rect m_sourceRectangle;
//		SDL_Rect m_destinationRectangle;
		
		
		

	
};

#endif 
