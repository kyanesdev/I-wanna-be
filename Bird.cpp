#include "Bird.hpp"

namespace Sonar
{
	Bird::Bird(GameDataRef data) : _data (data)
	{
		_animationIterator=0;
		_animationFrames.push_back(_data->assets.GetTexture("Bird 1"));
		_animationFrames.push_back(_data->assets.GetTexture("Bird 2"));
		_animationFrames.push_back(_data->assets.GetTexture("Bird 3"));
		
		_birdSprite.setTexture(_data->assets.GetTexture("Bird 1"));
	}
	
	void Bird::Draw()
	{
		_data->window.draw(_birdSprite);
	}
	
	void Bird::Animate(float dt)
	{
		if( _clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / _animationFrames.size())
		{
			if(_animationIterator < _animationFrames.size() - 1)
			{
				_animationIterator++;
			}
			else
			{
				_animationIterator = 0;
			}
			
			_birdSprite.setTexture(_animationFrames.at(_animationIterator));
			
			_clock.restart();
		}	
		
	}
}
