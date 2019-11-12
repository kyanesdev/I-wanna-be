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
		
		const std::vector<sf::Sprite> &GetSprites () const;
		
		void SpawnScoringPipe( );
		
		void MovePipes(float dt);
		
		void RandomisePipeOffset();
		
		
		std::vector<sf::Sprite> &GetScoringSprites ( );
		
	private:
		GameDataRef _data;
		std::vector<sf::Sprite> pipeSprites;
		std::vector<sf::Sprite> scoringPipes;
		
		
		
		int _pipeSpawnYOffset;
	};
}
