#pragma once
#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace Sonar
{
	class Bird
	{
	public:
		
		Bird(GameDataRef data);
		
		void Draw();
		
	private:
		
		GameDataRef _data;
		
		sf::Sprite _birdSprite;
		
		
	};
}
