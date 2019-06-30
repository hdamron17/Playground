/* Copyright 2019 Hunter Damron */
/* Inspiration from http://lazyfoo.net/tutorials/SDL/index.php */

#include "SDLPlayground/Graphics.h"

using std::cerr;
using std::endl;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

Graphics::~Graphics() {
  SDL_DestroyWindow(window_);
  SDL_Quit();
}

bool Graphics::init() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    cerr << "SDL could not initialize. SDL Error: " << SDL_GetError() << endl;
    return false;
  }

  window_ = SDL_CreateWindow("SDL Playground", SDL_WINDOWPOS_UNDEFINED,
                             SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                             SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

  if (window_ == nullptr) {
    cerr << "Window could not be created. SDL Error: " << SDL_GetError() << endl;
    return false;
  }

  screenSurface_ = SDL_GetWindowSurface(window_);

  if(IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
    cerr << "SDL_image could not initialize. SDL_image Error: " << IMG_GetError() << endl;
    return false;
  }

  if (!this->loadMedia()) {
    cerr << "Could not load media." << endl;
    return false;
  }

  return true;
}

void Graphics::cls() {
  SDL_FillRect(screenSurface_, NULL, SDL_MapRGB(screenSurface_->format, 0xFF, 0xFF, 0xFF));
  SDL_UpdateWindowSurface(window_);
}

bool Graphics::loadMedia() {
  return true;
}
