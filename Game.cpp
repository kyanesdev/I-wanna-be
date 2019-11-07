#include "Game.hpp"

namespace Sonar
{
	//Esto sera la funcion implementada de ancho, largo y titulo
	Game::Game(int width , int height, std::string title)
	{
		_data->window.create(sf::VideoMode (width, height), title , sf::Style::Close | sf::Style::Titlebar);
		
		
		//Lo corre al juego
		this->Run();
		
	}
	
	
	void Game::Run()
	{
		float newTime, frameTime, interpolation;
		
		//Sera la cantidad de tiempo que tiene desde que comenzo el reloj
		float currentTime = this->_clock.getElapsedTime().asSeconds();
		
		float acumulator = 0.0f;
		
		//Esta funcion hara que se mientras se ejecute la ventana 
		while(this->_data->window.isOpen())
		{
			this->_data->machine.ProcessStateChanges();
			//Aca establezco el tiempo para que se mantengan en una cantidad de frames continua
			newTime = this->_clock.getElapsedTime().asSeconds();
			
			frameTime = newTime - currentTime;
			
			//Limito los frames
			if(frameTime > 0.25f)
			{
				frameTime = 0.25f;
				
			}
			
			currentTime= newTime;
			acumulator += frameTime;
			
			while(acumulator >= dt)
			{
				
				this->_data->machine.GetActivateState()->HandleInput();
				this->_data->machine.GetActivateState()->Update(dt);
				
				acumulator -= dt;
				
				
			}
			
			interpolation = acumulator / dt;
			this->_data->machine.GetActivateState()->Draw(interpolation);
			
			
		}
	}
}









