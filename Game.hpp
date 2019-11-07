#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "AssetManager.hpp"
#include "StateMachine.hpp"
#include "InputManager.hpp"


namespace Sonar
{
	//GameData seran los datos accesibles a traves de todas las clases, tendra
	//todo lo implementado previamente
	struct GameData
	{
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
	};
	
	//Esta sera la referencia por el cual accederemos a lo anterior
	typedef std::shared_ptr<GameData> GameDataRef;
	
	
	class Game
	{
		public:
		//Aqui declaramos el ancho y el largo de la pantalla junto con el nombre
		//del juego
		Game(int width, int height, std::string title);
		
		private:
		//Basicamente esto seria los frames por segundo
		const float dt = 1.0f / 60.0f;
		sf::Clock _clock;
		GameDataRef _data = std::make_shared<GameData>();
		
		//Esto hace que corra nuestro juego
		void Run();
		
	};
	
	
	
}








