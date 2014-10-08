#include "Game.h"
#include "TextureManager.h"
bool Game::init(const char* title,int xpos,int ypos,int width,int height,bool FULLSCREEN)
{
	int flags=0;
	if(FULLSCREEN==true) flags=SDL_WINDOW_FULLSCREEN;
	if(SDL_Init(SDL_INIT_EVERYTHING)==0)
	{
		m_pWindow=SDL_CreateWindow(title,xpos,ypos,width,height,SDL_WINDOW_SHOWN|flags);
		if(m_pWindow!=0)
		{
			m_pRenderer=SDL_CreateRenderer(m_pWindow,-1,0);
			if(m_pRenderer!=0)
			{
			SDL_SetRenderDrawColor(m_pRenderer,155,255,255,110);
			}
			else
			return false;
		}
		else
		return false;
	}
	else
	return false;
	
	m_bRunning=true;
	
	TextureManager::Instance()->load("assets/emo.png","animate",m_pRenderer);
	
	m_go.load(100,100,200,261,"animate");
	m_player.load(300,300,200,261,"animate");
	
	

	return true;
}
void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	//Clear renderer with set color -> SDL_SetRenderDrawColor(renderer*p,r,g,b,a);
	/*
	SDL_RenderCopyEx(m_pRenderer,m_pTexture,&m_sourceRectangle,&m_destinationRectangle,0,0,SDL_FLIP_HORIZONTAL);
	
	TextureManager::Instance()->draw("animate",0,0,200,261,m_pRenderer);
	for(int i=0;i<100;++i)
	{
		TextureManager::Instance()->drawFrame("animate",100*i,100,200,261,1,m_currentFrame,m_pRenderer);
	}
	TextureManager::Instance()->drawFrame("animate",100,100,200,261,1,m_currentFrame,m_pRenderer);
	*/
	m_go.draw(m_pRenderer);
	m_player.draw(m_pRenderer);
	
	SDL_SetRenderDrawColor(m_pRenderer,255,0,0,255);
	SDL_RenderPresent(m_pRenderer);
	//Show changes
	
}
void Game::clean()
{
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}
Game::Game()
{
	
}
Game::~Game()
{
}
void Game::handleEvents()
{
	SDL_Event event;
	if(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT : m_bRunning=false;break;
			default: break;
		}
	}
	
}
void Game::update()
{
	//m_currentFrame=int(((SDL_GetTicks()/100)%5));
	m_go.update();
	m_player.update();
	
}


