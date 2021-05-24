#pragma once

#include "Textures.h"

//---------------------------------------------
Textures& Textures::instance() {
	static Textures inst;
	return inst;
}

//---------------------------------------------
sf::Texture* Textures::get_texture(PipeType textureIndex, bool rec) const {
	return rec ? m_turnedOnPipesTextures[textureIndex] : m_turnedOffPipesTextures[textureIndex];
}

//---------------------------------------------
Textures::Textures() {
	// initing the textures object in the array member
	for (int i = 0; i < NUM_OF_TYPES; i++) {
		m_turnedOffPipesTextures[i] = new sf::Texture;
		m_turnedOnPipesTextures[i] = new sf::Texture;
	}
	// load the textures from the files
	(*m_turnedOffPipesTextures[PipeType::Receiver]).loadFromFile("ReceiverOff.png");
	(*m_turnedOnPipesTextures[PipeType::Receiver]).loadFromFile("ReceiverOn.png");

	(*m_turnedOffPipesTextures[PipeType::Pumper]).loadFromFile("PumperOff.png");
	(*m_turnedOnPipesTextures[PipeType::Pumper]).loadFromFile("PumperOn.png");	// no need of this in this game

	(*m_turnedOffPipesTextures[PipeType::TwoSides]).loadFromFile("TwoSidesOff.png");
	(*m_turnedOnPipesTextures[PipeType::TwoSides]).loadFromFile("TwoSidesOn.png");

	(*m_turnedOffPipesTextures[PipeType::Corner]).loadFromFile("CornerOff.png");
	(*m_turnedOnPipesTextures[PipeType::Corner]).loadFromFile("CornerOn.png");

	(*m_turnedOffPipesTextures[PipeType::ThreeSides]).loadFromFile("ThreeSidesOff.png");
	(*m_turnedOnPipesTextures[PipeType::ThreeSides]).loadFromFile("ThreeSidesOn.png");

	(*m_turnedOffPipesTextures[PipeType::FourSides]).loadFromFile("FourSidesOff.png");
	(*m_turnedOnPipesTextures[PipeType::FourSides]).loadFromFile("FourSidesOn.png");
}
