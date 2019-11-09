#pragma once
#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"
#include <vector>

namespace Sonar
{
	class Toby
	{
	public:
		
		Toby(GameDataRef data);
		
		void Draw();
		
		void Animate(float dt);
		
		void Update(float dt);
		
		void Tap();
		
		
	private:
		
		GameDataRef _data;
		
		sf::Sprite _tobySprite;
		std::vector<sf::Texture> _animationFrames;
		
		unsigned int _animationIterator;
		
		sf::Clock _clock;
		sf::Clock _movementClock;
		
		int _tobyState;
		
	};
}
