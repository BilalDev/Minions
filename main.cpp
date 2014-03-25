#include "headers.h"
#include "EngineCore.h"
#include "Game.h"

int main(int argc, char** argv)
{
	SDL_Surface* screen = NULL;
	SDL_Event event;
	bool play = true;
	EngineCore& engine = Singleton<EngineCore>::getInstance();
	Game game;
	int mousex, mousey = 0;
	SDL_Surface *cursor = IMG_Load("resources/cursor.png");
	SDL_Rect positionCursor;

	if (!engine.init())
		exit(EXIT_FAILURE);

	if ((screen = SDL_SetVideoMode(engine.getWidth(), engine.getHeight(), 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN)) == NULL)
	{
		fprintf(stderr, "Erreur lors de l'initialisation de la fenêtre %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_WM_SetCaption("Minions Avengers", NULL);
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
	SDL_ShowCursor(0);

	
	while (play)
	{
		// INPUT PLAYER
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				play = false;
				break;
			case SDL_MOUSEMOTION:
				positionCursor.x = mousex = event.motion.x;
				positionCursor.y = mousey = event.motion.y;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					play = false;
					break;
				default:break;
				}
				break;
			default: break;
			}
		}
		

		// LOGIC
		game.move_board(mousex, mousey);


		// RENDER
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
		game.display_board(screen);
		SDL_BlitSurface(cursor, NULL, screen, &positionCursor);
		SDL_Flip(screen);
	}

	SDL_Quit();

	return (EXIT_SUCCESS);
}