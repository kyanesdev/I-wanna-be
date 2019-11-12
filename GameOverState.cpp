#pragma once

#include<sstream>
#include "GameOverState.hpp"
#include "DEFINITIONS.hpp"
#include "GameState.hpp"

#include <iostream>

namespace Sonar
{
	GameOverState::GameOverState( GameDataRef data):_data(data)
	{
		
	}
	//Aca va a cargar la textura de fondo
	void GameOverState::Init()
	{
		_data->assets.LoadTexture("Game Over Background",GAME_OVER_BACKGROUND_FILEPATH);
		_background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
		
		_data->assets.LoadTexture("Game Over",GAME_OVER_BACKGROUND_FILEPATH);
		_gameOver.setTexture(this->_data->assets.GetTexture("Game Over"));
		
		_data->assets.LoadTexture("RetryButton",RETRY_BUTTON_FILEPATH);
		_retryButton.setTexture(this->_data->assets.GetTexture("RetryButton"));
		
		_data->assets.LoadTexture("Scores Frame",SCORES_FRAME_FILEPATH);
		_scoreContainer.setTexture(this->_data->assets.GetTexture("Scores Frame"));

		
		_scoreContainer.setPosition((_data -> window.getSize().x/2)  -	(_scoreContainer.getGlobalBounds().width/2),(_scoreContainer.getGlobalBounds().height/2));
		
		_gameOver.setPosition((_data -> window.getSize().x/2) -	(_gameOver.getGlobalBounds().width/2),(_scoreContainer.getPosition().y - (_gameOver.getGlobalBounds().height*1.2)));
		
		_retryButton.setPosition((_data -> window.getSize().x/2) -	(_retryButton.getGlobalBounds().width/2),_scoreContainer.getPosition().y + _scoreContainer.getGlobalBounds().height +_retryButton.getGlobalBounds().height*0.2);
	}
	
	
	void GameOverState::HandleInput()
	{
		sf::Event event;
		
		while(_data->window.pollEvent( event ))
		{
			if (sf::Event::Closed== event.type)
			{
				_data->window.close( );
			}
			
			if(_data->input.IsSpriteClicked(_retryButton,sf::Mouse::Left,_data->window)){
				
				_data->machine.AddState(StateRef(new GameState(_data) ),true);
			}
		}
	}
	void GameOverState::Update(float dt)
	{
	}
	
	void GameOverState::Draw( float dt ) 
	{
		
	
		_data->window.clear( );
		
		_data->window.draw( _background );
		
		_data->window.draw (_gameOver);
		
		_data->window.draw(_scoreContainer);
		
		_data-> window.draw(_retryButton);
		
		
		_data->window.display( );
	}
};
