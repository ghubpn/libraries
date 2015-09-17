//Using SDL, SDL_image, standard IO, math, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>

//Local declarations
#include "Data.cpp"

//Screen dimension constants
const int SCREEN_WIDTH  = 1200;
const int SCREEN_HEIGHT = 500;

//Plot dimension constants
const int PLOT_WIDTH  = 480;
const int PLOT_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image as texture
SDL_Texture* loadTexture( std::string path );

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "Least Squares Regression", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Nothing to load
	return success;
}

void close()
{
	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				}

				//Clear screen
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

				//Render dark grey filled quad (background)
				SDL_Rect background = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
				SDL_SetRenderDrawColor( gRenderer, 0x1F, 0x1F, 0x1F, 0xFF );		
				SDL_RenderFillRect( gRenderer, &background );
				
				//Render black filled quad (background)
				SDL_Rect fillRect = { 10, 10, PLOT_WIDTH, PLOT_HEIGHT };
				SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF );		
				SDL_RenderFillRect( gRenderer, &fillRect );

				//Render green outlined quad
				SDL_Rect outlineRect = { 10, 10, PLOT_WIDTH, PLOT_HEIGHT };
				SDL_SetRenderDrawColor( gRenderer, 0x00, 0xFF, 0x00, 0xFF );		
				SDL_RenderDrawRect( gRenderer, &outlineRect );
				
				
				//Draw vertical lines of yellow dots
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0x00, 0xFF );
				for( int i = 1; i < n; ++i) {
					for( int j = 20; j < PLOT_HEIGHT; j += 4 )
					{
						SDL_RenderDrawPoint( gRenderer, 20 + i * (PLOT_WIDTH-20) / n, j );
					}
				}
				
				//Draw horizontal lines of yellow dots
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0x00, 0xFF );
				for( int i = 1; i < n; ++i) {
					for( int j = 20; j < PLOT_WIDTH; j += 4 )
					{
						SDL_RenderDrawPoint( gRenderer, j, i * PLOT_HEIGHT / n );
					}
				}
				
				//Draw green regression line
				SDL_SetRenderDrawColor( gRenderer, 0x00, 0xFF, 0x00, 0xFF );		
				SDL_RenderDrawLine( gRenderer,
									16 + (xData[0] * PLOT_WIDTH / n), 
									(SCREEN_HEIGHT / 2) + (yData[0] * PLOT_HEIGHT / -20), 
									PLOT_WIDTH, 
									(SCREEN_HEIGHT / 2 ) + (yData[4] * PLOT_HEIGHT / -20 ));

				
				//Draw red data points
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xBB );
				SDL_Rect datum = { 10, 10, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT - 20 };
				for( int i = 0; i < n; ++i )
				{
					datum = {
							14 + (xData[i] * PLOT_WIDTH / n) - 4*i,
							(PLOT_HEIGHT / 2 ) + (yData[i] * PLOT_HEIGHT / -20),
							6, 6
							};
					SDL_RenderFillRect( gRenderer, &datum );
				}

				//Update screen
				SDL_RenderPresent( gRenderer );
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}