#include<iostream>
#include<string>
#include<fstream>
#include<SDL2/SDL.h>

using namespace std;

void G_ErrorLog(string Operation,ostream Stream){
	
	Stream<<Operation<<": "<<SDL_GetError()<<endl;
	
}

int main(int argc,char** args){
	
	if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
		G_ErrorLog("SDL_Init()",cout);
		return 3;
	}
	
	
	const int G_WINDOWWIDTH = 640;
	const int G_WINDOWHEIGHT = 480; 
	
	
	
	SDL_Window* Window=SDL_CreateWindow(
		"random program",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		G_WINDOWWIDTH,
		G_WINDOWHEIGHT,
		SDL_WINDOW_SHOWN
   									);
	if(Window==NULL){
		G_ErrorLog("SDL_CreateWindow()",cout);
		SDL_Quit();
		return 1;
	}
	
	
	
	SDL_Renderer* Renderer=SDL_CreateRenderer(
		Window,
		-1,
		SDL_RENDERER_ACCELERATED
	);
	if(Renderer==NULL){
		G_ErrorLog("SDL_CreateRenderer",cout);
		SDL_DestroyWindow(Window);
		SDL_Quit();
	}
	
	
	SDL_Event Event;
	while(true){
		if(!SDL_PollEvent(&Event)){
			SDL_Delay(10);
			continue;
		}
		if(Event.type==SDL_QUIT){
			break;
		}
	}
	return 0;
	
}
