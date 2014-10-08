#include "SDL.h"
#include "SDL_image.h"
#include <string>
#include <map>
#ifndef _TEXTUREMANAGER_H_
#define _TEXTUREMANAGER_H_

class TextureManager
{
public:

//string is in ordinary string not in string.h

bool load (std::string fileName,std::string id,SDL_Renderer *pRenderer);
void draw(std::string id, int x, int y,int width,int height,SDL_Renderer* pRenderer,SDL_RendererFlip flip=SDL_FLIP_NONE);
void drawFrame(std::string id, int x, int y,int width,int height,int currentRow,int currentFrame,SDL_Renderer* pRenderer,SDL_RendererFlip flip=SDL_FLIP_NONE);
static TextureManager* Instance();

private:
	TextureManager(){};
	
	static TextureManager *s_pInstance;
	std::map<std::string,SDL_Texture*> m_textureMap;


};


#endif
