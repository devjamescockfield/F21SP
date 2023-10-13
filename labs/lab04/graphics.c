#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

// The size of the display, in pixels
#define WIDTH 800
#define HEIGHT 600

// Die with an error message
void die(const char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, SDL_GetError());
    exit(1);
}

// The rendering function, called once per frame
void render(uint32_t *pixels)
{
    // FIXME: Implement something more interesting here!
}

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        die("SDL init failed");
    atexit(SDL_Quit);

    SDL_Window *window;
    window = SDL_CreateWindow("Graphics Exercise",
                              0, 50, WIDTH, HEIGHT, 0);
    if (window == NULL)
        die("SDL_CreateWindow failed");

    SDL_Renderer *renderer;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
        die("SDL_CreateRenderer failed");

    SDL_Texture *texture;
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_XRGB8888,
                                SDL_TEXTUREACCESS_STREAMING,
                                WIDTH, HEIGHT);
    if (texture == NULL)
        die("SDL_CreateTexture failed");

    Uint32 *pixels = calloc(WIDTH * HEIGHT, 4);
    if (pixels == NULL)
        die("malloc failed");

    bool is_fullscreen = false;
    while (true)
    {
        // Call the rendering function
        render((uint32_t *)pixels);

        // Copy pixels into the texture
        SDL_UpdateTexture(texture, NULL, pixels, WIDTH * 4);

        // Draw the texture to the window
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);

        // Update display and (hopefully) wait for vsync
        SDL_RenderPresent(renderer);

        // Process input events
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // Quit if the window is closed or Esc is pressed
            if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
            {
                exit(0);
            }
            // Toggle fullscreen if F is pressed
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_f)
            {
                is_fullscreen = !is_fullscreen;
                SDL_SetWindowFullscreen(window,
                                        is_fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
            }
        }
    }
}
