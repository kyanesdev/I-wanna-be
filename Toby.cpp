#include "Toby.hpp"

namespace Sonar
{
	Toby::Toby(GameDataRef data) : _data (data)
	{
		_animationIterator=0;
		_animationFrames.push_back(_data->assets.GetTexture("Toby 1"));
		_animationFrames.push_back(_data->assets.GetTexture("Toby 2"));
		_animationFrames.push_back(_data->assets.GetTexture("Toby 3"));
		
		_tobySprite.setTexture(_data->assets.GetTexture("Toby 1"));
		
		_tobySprite.setPosition((_data->window.getSize().x / 4) - (_tobySprite.getGlobalBounds().width / 2), (_data->window.getSize().y / 2) - (_tobySprite.getGlobalBounds().height / 2));
		
		_tobyState=TOBY_STATE_STILL;
	}
	
	void Toby::Draw()
	{
		_data->window.draw(_tobySprite);
	}
	
	void Toby::Animate(float dt)
	{
		if( _clock.getElapsedTime().asSeconds() > TOBY_ANIMATION_DURATION / _animationFrames.size())
		{
			if(_animationIterator < _animationFrames.size() - 1)
			{
				_animationIterator++;
			}
			else
			{
				_animationIterator = 0;
			}
			
			_tobySprite.setTexture(_animationFrames.at(_animationIterator));
			
			_clock.restart();
		}	
		
	}
	
	void Toby::Update (float dt){
		
		if(TOBY_STATE_FALLING == _tobyState){
		//cae gracias a la gravedad establecida	
		_tobySprite.move(0,GRAVITY*dt);
			
		}
		
		else if (TOBY_STATE_FLYING == _tobyState){
		//sube gracias a la velocidad de vuelo establecida
			_tobySprite.move(0,-FLYING_SPEED*dt);
		}
		//hace que cuando pase el tiempo de vuelo al hacer un tap, toby comience a caer.
		if (_movementClock.getElapsedTime().asSeconds()>FLYING_DURATION){
			_movementClock.restart();
			_tobyState= TOBY_STATE_FALLING;
		}
		
	}
	
	//cada vez que se hace un tap el reloj vuelve a 0 y toby vuela durante el tiempo definido
	void Toby::Tap(){
		
		_movementClock.restart();
		_tobyState= TOBY_STATE_FLYING;
		
	}
	const sf::Sprite &Toby::GetSprite() const
	{
		return _tobySprite;
	};
	
}
