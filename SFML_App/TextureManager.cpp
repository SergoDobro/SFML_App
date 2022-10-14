#include "TextureManager.h"
Texture* TextureManager::main_text = NULL;

void TextureManager::LoadTexture() {
	  TextureManager::main_text = new Texture();
	if (!(*TextureManager::main_text).loadFromFile("gun_division.png"))
	{
		// error...
	}
}
Texture TextureManager::GetTexture() {
	return *TextureManager::main_text;
}