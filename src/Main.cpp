/* Copyright 2019 Hunter Damron */

#include "SDLPlayground/Graphics.h"

int main(int argc, char* argv[]) {
  Graphics g;
  if (!g.init())
    return -1;
  g.cls();
  SDL_Delay(5000);  // TODO(HD) remove
}
