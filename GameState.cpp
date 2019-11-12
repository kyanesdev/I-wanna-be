#include<sstream>
#include "GameState.hpp"
#include "DEFINITIONS.hpp"
#include "GameOverState.hpp"

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
		_data->assets.LoadTexture("Toby 1",TOBY_FRAME_1_FILEPATH);
		_data->assets.LoadTexture("Toby 2",TOBY_FRAME_2_FILEPATH);
		_data->assets.LoadTexture("Toby 3",TOBY_FRAME_3_FILEPATH);
		_data->assets.LoadTexture("Scoring Pipe",SCORING_PIPE_FILEPATH);
		_data->assets.LoadFont("FlappyFont.ttf",FLAPPY_FONT_FILEPATH);
		
		
		pipe = new Pipe(_data);
		toby = new Toby(_data);
		hud = new HUD ( _data);
		
		_background.setTexture(this->_data->assets.GetTexture("Game Background"));
		
		_score=0;
		hud->UpdateScore( _score );
		
		_gameState = GameStates::eReady; 
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
				if(GameStates::eGameOver != _gameState){
					_gameState=GameStates::ePlaying;
					toby->Tap( );
				}
				
			
			}
		}
	}
	void GameState::Update(float dt)
	{
		if(GameStates::eGameOver != _gameState)
		{
			toby->Animate(dt);
			
		}
		if(GameStates::ePlaying == _gameState)
		{
			pipe->MovePipes(dt);
			
			if(clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY){
			
				pipe->RandomisePipeOffset();
				
				
				pipe->SpawnBottomPipe();
				pipe->SpawnTopPipe();
				pipe->SpawnScoringPipe();
				
				clock.restart();
			
				
			}
			
			
			toby->Update(dt);
			
			std::vector<sf::Sprite> pipeSprites = pipe->GetSprites ();
			
			
			
			for(int i=0; i < pipeSprites.size(); i++)
			{
				if(collision.CheckPipeCollision(toby->GetSprite(), pipeSprites.at(i)))
				{
					_gameState = GameStates::eGameOver;
				}
			}
			
			
			
			if(GameStates::ePlaying == _gameState){
				std::vector<sf::Sprite> &scoringSprites = pipe->GetScoringSprites ( );
				for(int i=0;i<scoringSprites.size();i++){
					
					if(collision.CheckPipeCollision(toby->GetSprite( ),scoringSprites.at(i))){
						
						_score++;
						
						hud->UpdateScore( _score );
						
						scoringSprites.erase( scoringSprites.begin()+i);
						
					}
				}
			}
			
			
			
			for(int i=0;i<780;i++)
			{
				if(collision.CheckSpriteCollision(toby->GetSprite())){
					_gameState = GameStates::eGameOver;
					
				}
			}
			
			
	    }	
	if(GameStates::eGameOver == _gameState){
			_data->machine.AddState(StateRef(new GameOverState(_data)), true);
			
	}
	}

	
	void GameState::Draw( float dt ) 
	{
		_data->window.clear( );
		
		_data->window.draw( _background );
		pipe->DrawPipes();
		toby->Draw();
		hud->Draw();
		
		_data->window.display( );
	}
}
