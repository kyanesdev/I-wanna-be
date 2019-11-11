#include "Collision.hpp"

namespace Sonar{
	Collision::Collision( ){
		
	}
	bool Collision::CheckSpriteCollision( sf::Sprite sprite1 ){
		sf::Rect<float> rect1 = sprite1.getGlobalBounds( );
		sf::Rect<float> rect2(0,0,600,780);
		
		if( rect1.intersects ( rect2 ) ){
			return true;
		}
		else{
			return false;
		}
	};
};
