#include<iostream>
#include<string>
#include<fstream>
#include<SDL2/SDL.h>

using namespace std;

void G_ErrorLog(string Operation,ostream& Stream){
	
	Stream<<Operation<<": "<<SDL_GetError()<<endl;
	
}

void G_RenderCubePBP(SDL_Renderer* Renderer){//render cube point by point
	Uint8 Red;
	Uint8 Blue;
	Uint8 Green;
	Uint8 Alfa;
	SDL_GetRenderDrawColor(Renderer,&Red,&Green,&Blue,&Alfa);
	SDL_SetRenderDrawColor(Renderer,100,100,100,255);
	for(int j=0;j<200;j++){
		for(int i=0;i<200;i++){	
			SDL_RenderDrawPoint(
				Renderer,
				i,
				j
			);
			SDL_RenderPresent(Renderer);
		}
	}
	SDL_SetRenderDrawColor(Renderer,Red,Green,Blue,Alfa);
}

void G_RenderCubeAPT(SDL_Renderer* Renderer){//render cube all points together
	Uint8 Red;
	Uint8 Blue;
	Uint8 Green;
	Uint8 Alfa;
	SDL_GetRenderDrawColor(Renderer,&Red,&Green,&Blue,&Alfa);
	SDL_SetRenderDrawColor(Renderer,100,100,100,255);
	for(int j=0;j<200;j++){
		for(int i=0;i<200;i++){	
			SDL_RenderDrawPoint(
				Renderer,
				i,
				j
			);
		}
	}
	SDL_RenderPresent(Renderer);
	SDL_SetRenderDrawColor(Renderer,Red,Green,Blue,Alfa);
}


int main(int argc,char** args){
	//setup
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
	
	
	string InputText="";
	
	
	
	//event handler
	SDL_Event Event;
	while(true){
		if(!SDL_PollEvent(&Event)){
			SDL_Delay(10);
			continue;
		}
		if(Event.type==SDL_QUIT){
			break;
		}
		if(Event.type==SDL_TEXTINPUT){
			InputText.append(Event.text.text);
			continue;
		}
	}
	cout<<InputText<<endl;
	return 0;
	
}
