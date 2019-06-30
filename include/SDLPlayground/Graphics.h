/* Copyright 2019 Hunter Damron */

#ifndef SDLPLAYGROUND_GRAPHICS_H_
#define SDLPLAYGROUND_GRAPHICS_H_

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Graphics {
 public:
  Graphics(void)
  : window_(nullptr),
    screenSurface_(nullptr) {}
  virtual ~Graphics(void);

  bool init(void);
  void cls(void);
  bool loadMedia(void);
 private:
  SDL_Window* window_;
  SDL_Surface* screenSurface_;
};

#endif /* SDLPLAYGROUND_GRAPHICS_H_ */
