#include <SDL2/SDL.h>

#include <list>
#include <vector>

#include "module_1.hpp"
#include "module_2.hpp"

int main() {
  module_1();
  module_2();

  // Test stuff.
  std::list<int> l = {1, 2, 3, 4, 5, 6};
  std::vector<int> v = {7, 8, 9, 10, 11, 12};

  // Test prints.
  print_list(&l);
  print_vector(&v);

  // Test binary search.
  bool found;
  found = binary_search(&v, 22);
  std::cout << found << std::endl;

  // SDL2 project name connect the dots.
  // SDL Init stuff.
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window *window = nullptr;
  SDL_Renderer *renderer = nullptr;
  SDL_CreateWindowAndRenderer(2000, 2000, 0, &window, &renderer);
  SDL_Event event;

  // A single point to update every frame.
  SDL_Point current;
  std::vector<SDL_Point> vector_of_points;

  // The type of connection we want.
  int type = 0;

  // Main loop.
  while (true) {
    // Events.
    while (SDL_PollEvent(&event)) {
      // Handle closing the window.
      if (event.type == SDL_QUIT) {
        SDL_Quit();
        exit(0);
      }
      // Store the current location of the mouse if we click on the mouse.
      if (event.type == SDL_MOUSEBUTTONDOWN) {
        int x, y;
        auto button = SDL_GetMouseState(&x, &y);

        if (event.button.button == SDL_BUTTON_LEFT) {
          vector_of_points.emplace_back(SDL_Point{x, y});
        }
      }
      // Get the current mouse location per frame.
      if (event.type == SDL_MOUSEMOTION) {
        SDL_GetMouseState(&current.x, &current.y);
      }
      // If the c key is clicked, we are going to clear the container.
      if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_c) {
        vector_of_points.clear();
      }
      // If key m is clicked, all previous points connect to new point.
      if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_m) {
        type = 0;
      }
      // If key m is clicked, last point connect to new point.
      if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_l) {
        type = 1;
      }
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // SDL_RenderDrawLines(renderer, vector_of_points.data(),
    //                     vector_of_points.size());

    if (type == 0) {
      for (auto point : vector_of_points) {
        for (auto point2 : vector_of_points) {
          SDL_RenderDrawLine(renderer, point.x, point.y, point2.x, point2.y);
        }
      }
    }
    if (type == 1) {
      SDL_RenderDrawLines(renderer, vector_of_points.data(),
                          vector_of_points.size());
    }
    // Present the drawing.
    SDL_RenderPresent(renderer);
    SDL_Delay(150);
  }

  return 0;
}
