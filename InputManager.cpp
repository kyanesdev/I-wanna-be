#include "InputManager.hpp"

namespace Sonar {
	
	bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
	{
		
		if (sf::Mouse::isButtonPressed (button))
		{
			//getGlobalBounds obtiene los limites del objeto.
			sf::IntRect playButton(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);
			
			//verifica si la posicion del mouse al hacer click se encuentra sobre el objeto (playButton).
			if ( playButton.contains (sf::Mouse::getPosition(window)))
			{
				return true;
			}
		}
		
	return false;		
			
	}

//Vector2i define dos coordenadas enteras (posición del cursor en la ventana)
	sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow &window){
		return sf::Mouse::getPosition(window);
	}
	
}
