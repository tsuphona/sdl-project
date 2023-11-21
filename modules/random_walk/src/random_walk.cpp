#include <SDL2/SDL.h>

#include <random>
#include <vector>

int main(int argc, char* argv[]) {
  SDL_Window* window = nullptr;
  SDL_Renderer* renderer = nullptr;
  SDL_CreateWindowAndRenderer(50 * 20, 50 * 20, 0, &window, &renderer);
  SDL_RenderSetScale(renderer, 20, 20);

  int x = 25;
  int y = 25;

  std::random_device dev;
  std::uniform_int_distribution<uint8_t> nd(0, 4);

  while (true) {
    uint8_t dir = nd(dev);

    switch (dir) {
      case 0:
        x -= 1;
        y -= 1;
        break;
      case 1:
        x += 1;
        y -= 1;
        break;
      case 2:
        x += 1;
        y += 1;
        break;
      case 3:
        x -= 1;
        y += 1;
        break;
    }

    SDL_SetRenderDrawColor(renderer, static_cast<uint8_t>(60 * dir % 255),
                           static_cast<uint8_t>(60 * dir % 255),
                           static_cast<uint8_t>(60 * dir % 255), 255);
    SDL_RenderDrawPoint(renderer, x, y);
    SDL_RenderPresent(renderer);

    if (x > 50 || x < 0 || y > 50 || y < 0) {
      x = 25;
      y = 25;
    }

    SDL_Delay(50);
  }
  return 0;
}
