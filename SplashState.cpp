
#include<sstream>
#include "SplashState.hpp"
#include "DEFINICIONS.h"

#include <iostream>

namespace Sonar
{
	SplashState::SplashState( GameDataRef data):_data(data)
	{
		
	}
	
	void SplashState::Init()
	{
		_data->assets.LoadTexture("Splash State Background",SPLASH_SCENE_BACKGROUND_FILEPATH);
		
		_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
	}
	void SplashState::handleInput()
	{
		sf::Event event;
		
		while( _data->window.pollEvent( event )){
			if (sf::Event::Closed== event.type){
				_data->window.close( );
			}
		}
	}
	void SplashState::Update(float dt)
	{
		if (_clock.getElapsedTime( ).asSeconds( )> SPLASH_STATE_SHOW_TIME )
		{
			std::cout <<"Go to main Menu" << std::endl;
		}
	}
	void SplashState::Draw( float dt ) 
	{
		_data->window.clear( );
		
		_data->window.draw( _background );
		
		_data->window.display( );
	}
};
