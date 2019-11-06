#pragma once
#include <SFML/Graphics.hpp>

namespace Game {
	
	class InputManager{
		
	public:
		InputManager (){}
		~InputManager (){}
		
		bool IsSpriteClicked (sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
	
	
	//vector2i define dos coordenadas enteras (posición del cursor en la ventana)
	sf::Vector2i GetMousePosition(sf::RenderWindow &window);
	};
}
