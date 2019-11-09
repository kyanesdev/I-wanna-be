#include "Pipe.hpp"
#include<iostream>
namespace Sonar
{
	Pipe::Pipe(GameDataRef data) : _data (data)
	{
		
		_pipeSpawnYOffset=0;
	}
	
	
	void Pipe::SpawnBottomPipe()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Pipe"));
		
		sprite.setPosition(_data->window.getSize().x , _data->window.getSize().y - sprite.getGlobalBounds().height-_pipeSpawnYOffset+390);
			
		pipeSprites.push_back(sprite);
	}
	
	void Pipe::SpawnTopPipe()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Pipe"));
		
		sprite.setPosition(_data->window.getSize().x , -_pipeSpawnYOffset);
			
			pipeSprites.push_back(sprite);
	}
	void Pipe::SpawnInvisiblePipe()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Pipe"));
		
		sprite.setPosition(_data->window.getSize().x , _data->window.getSize().y - sprite.getGlobalBounds().height );
			
			sprite.setColor(sf::Color(0,0,0,0));
			
			pipeSprites.push_back(sprite);
		
		
	}
	void Pipe::MovePipes(float dt)
	{
		for(unsigned short int i = 0 ; i < pipeSprites.size(); i++)
		{
			//para que los obstaculos desaparezcan al salir de la pantalla.
			if(pipeSprites.at(i).getPosition().x < 0 - pipeSprites.at(i).getGlobalBounds().width){
				
				pipeSprites.erase(pipeSprites.begin()+i);
				
			}
			else{
				
				float movement = PIPE_MOVEMENT_SPEED * dt;
			
				pipeSprites.at(i).move(-movement, 0);
			}
	}
	}
	 
	void Pipe::DrawPipes()
	{
		for(unsigned short int i = 0 ; i < pipeSprites.size(); i++)
		{
			
			_data->window.draw(pipeSprites.at(i));
		}
	}
	
	void Pipe::RandomisePipeOffset(){
		
		_pipeSpawnYOffset=rand()%+400;
		std::cout<<_pipeSpawnYOffset;
	}
	}
