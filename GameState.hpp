#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Pipe.hpp"
#include "Toby.hpp"

#include "Collision.hpp"


namespace Sonar
{
	class GameState : public State 
	{
	public:
		GameState(GameDataRef data);
		
		void Init();
		
		void HandleInput();
		void Update (float dt);
		void Draw(float dt);
	private:
		GameDataRef _data;
		
		sf::Sprite _background;
		
		Pipe *pipe;
		Toby *toby;
		Collision collision;
		
		sf::Clock clock;
		int _gameState; //crea otra variable para que no colisione con el definicions .cpp
		
	};
};
