#include<sstream>
#include "GameState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace Sonar
{
	GameState::GameState( GameDataRef data):_data(data)
	{
		
	}
	//Aca va a cargar la textura de fondo
	void GameState::Init()
	{
		_data->assets.LoadTexture("Game Background",GAME_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Pipe",PIPE_UP_FILEPATH);
		_data->assets.LoadTexture("Pipe",PIPE_DOWN_FILEPATH);
		
		pipe = new Pipe(_data);
		
		_background.setTexture(this->_data->assets.GetTexture("Game Background"));
	}
	void GameState::HandleInput()
	{
		sf::Event event;
		
		while(_data->window.pollEvent( event ))
		{
			if (sf::Event::Closed== event.type)
			{
				_data->window.close( );
			}
			
			if(_data->input.IsSpriteClicked(_background, sf::Mouse::Left, _data->window))
			{
				pipe->SpawnInvisiblePipe();
				pipe->SpawnBottomPipe();
				pipe->SpawnTopPipe();
			}
		}
	}
	void GameState::Update(float dt)
	{
		pipe->MovePipes(dt);
	}
	void GameState::Draw( float dt ) 
	{
		_data->window.clear( );
		
		_data->window.draw( _background );
		pipe->DrawPipes();
		_data->window.display( );
	}
};
