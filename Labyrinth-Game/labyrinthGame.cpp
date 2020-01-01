#include <SFML/Graphics.hpp>

using namespace sf;

int main(int argc, const char * argv[]) {
    
    VideoMode desktop = VideoMode::getDesktopMode();
    
    //Create a video mode object
    VideoMode vm(1680, 1048, desktop.bitsPerPixel);
    
    //Create and open a window for the game
    RenderWindow window(vm, "Labyrinth Game", Style::Fullscreen);

    return 0;
}
