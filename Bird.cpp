#include "Bird.hpp"

namespace Sonar
{
	Bird::Bird(GameDataRef data) : _data (data)
	{
		_birdSprite.setTexture(_data->assets.GetTexture("Bird 1"));
	}
	
	void Bird::Draw()
	{
		_data->window.draw(_birdSprite);
	}
}
