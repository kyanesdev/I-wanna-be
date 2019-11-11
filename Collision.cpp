#include "Collision.hpp"

namespace Sonar
{
	Collision::Collision( )
	{
		
	}
	//Esta funcion comprueba la colision del personaje en un rango
	bool Collision::CheckSpriteCollision( sf::Sprite sprite1 ){
		sf::Rect<float> rect1 = sprite1.getGlobalBounds( );
		sf::Rect<float> rect2(0,745,600,1);
		sf::Rect<float> rect3(0,0,600,1);
		
		if( rect1.intersects ( rect2 ) || rect1.intersects ( rect3 )  )
		{
			return true;
		}
		else
		{
			return false;
		}
	};
	
	
	
	
	
	bool Collision::CheckPipeCollision ( sf::Sprite sprite1, sf::Sprite sprite2 )
	{
	sf::Rect<float> rect1 = sprite1.getGlobalBounds( );
	sf::Rect<float> rect2 = sprite2.getGlobalBounds( );
	
	
	if( rect1.intersects ( rect2 ) )
	{
		return true;
	}
	else
	{
		return false;
	}
	
};
	
	
	
};
