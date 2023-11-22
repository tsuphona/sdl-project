#include <SDL2/SDL.h>

#include <cmath>
#include <complex>
#include <numeric>

int is_in_set(std::complex<double> c) {
  std::complex<double> z(0, 0);
  for (int i = 0; i < 250; i++) {
    z = std::pow(z, 2) + c;

    if (std::norm(z) > 10) {
      return i;
    }
  }
  return 0;
}

int main(int argc, char* argv[]) {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window* window = nullptr;
  SDL_Renderer* renderer = nullptr;
  SDL_CreateWindowAndRenderer(1500, 1500, 0, &window, &renderer);
  SDL_RenderSetScale(renderer, 1.5, 1.5);

  for (double x = 0.0; x < 1.0; x += 0.001) {
    for (double y = 0.0; y < 1.0; y += 0.001) {
      double point_x = std::lerp(-2.0, 2.0, x);
      double point_y = std::lerp(-2.0, 2.0, y);
      int iters = is_in_set(std::complex<double>(point_x, point_y));

      double m = 1000;
      if (iters == 0) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawPointF(renderer, x * m, y * m);
      } else {
        SDL_SetRenderDrawColor(renderer, 12 * iters % 255, 13 * iters % 255,
                               14 * iters % 255, 255);
        SDL_RenderDrawPointF(renderer, x * m, y * m);
      }
    }
  }

  SDL_RenderPresent(renderer);
  SDL_Delay(10000);

  return 0;
}
