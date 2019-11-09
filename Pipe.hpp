#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>
#include "DEFINITIONS.hpp"
namespace Sonar
{
	class Pipe
	{
	public:
		Pipe(GameDataRef data);
	
		void DrawPipes();
		
		void SpawnBottomPipe();
		
		void SpawnTopPipe();
		
		void SpawnInvisiblePipe();
		
		void MovePipes(float dt);
		
		void RandomisePipeOffset();
		
	private:
		GameDataRef _data;
		std::vector<sf::Sprite> pipeSprites;
		
		
		int _pipeSpawnYOffset;
	};
}
