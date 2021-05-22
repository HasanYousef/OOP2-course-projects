#pragma once

#include "Textures.h"

//---------------------------------------------
Textures& Textures::instance() {
	static Textures inst;
	return inst;
}

//---------------------------------------------
sf::Texture* Textures::get_texture(PipeType textureIndex, bool rec) const {
	return m_textures[textureIndex + rec];//if recieve water we add 1
	                                     //to choose the white texture
}

//---------------------------------------------
Textures::Textures() {
	// initing the textures object in the array member
	for (int i = 0; i < NUM_OF_TYPES; i++)
		m_textures[i] = new sf::Texture;
	// not finish
}