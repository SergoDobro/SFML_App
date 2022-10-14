#include <SFML/Graphics.hpp>  
#include "Selectable.cpp"
using namespace sf;
static class TextureManager {
public:
	static Texture* main_text;
	static void LoadTexture();
	static Texture GetTexture();
};