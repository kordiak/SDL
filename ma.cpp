//#include <SDL.h>
#include "SDL.h"
#include "SDL_image.h"
#include "Game.h"
#include <iostream>

//	#ifdef __cplusplus
  //	extern "C"
  	//#endif
  bool right;
  
  int main(int argc, char *argv[])
  {
  	Game * game=new Game();
  	//Game gra;
   	right=game->init("Test",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,false);
   	game->render();
   	
   	
   	
  	if(right==false) return -1;
  	
  	while(game->running())
	{
		game->render();
		SDL_Delay(10);
		game->update();
		game->handleEvents();
	}  	
  	game->clean();
 	return 0; 
  }


