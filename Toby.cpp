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
}
