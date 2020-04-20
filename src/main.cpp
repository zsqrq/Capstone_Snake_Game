#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "Score.h"

int main() {

    std::cout << "Enter Your Name Please: ";
    std::string name;
    std::cin >> name;
    constexpr std::size_t kFramesPerSecond{60};
    constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
    constexpr std::size_t kScreenWidth{800};
    constexpr std::size_t kScreenHeight{800};
    constexpr std::size_t kGridWidth{32};
    constexpr std::size_t kGridHeight{32};

    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    Controller controller;
    Game game(kGridWidth, kGridHeight);
    game.Run(controller, renderer, kMsPerFrame);
    std::cout << "Game has terminated successfully!\n";
    std::cout << "Score: " << game.GetScore() << "\n";
    std::cout << "Size: " << game.GetSize() << "\n";

    int score = game.GetScore();
    int size = game.GetSize();
    //Write to log file
    Score().WriteToResFile(name, score, size);
    //Kill the renderer
    renderer.~Renderer();
    return 0;
}