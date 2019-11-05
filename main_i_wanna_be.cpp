#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>


#include "personaje.h"
#include "obstaculo.h"




using namespace sf;



int main() {
	
	
	
	Texture tpersonaje;

	
	int resx, resy, y=10;
	
	resx=800;
	
	resy=400;
	
	RenderWindow w(VideoMode(640, 480), "i wanna be");
	
	
	Texture tground;
	tground.loadFromFile("ground.png");
	Sprite sground;
	sground.setTexture(tground);
	sground.setPosition(0,320);
	
	
	
	w.setFramerateLimit(20);
	
	
	
	tpersonaje.loadFromFile("flappy.png");
	personaje player(&tpersonaje, 640 / 2, 480 / 2);
	
	
	
	obstaculo pilar(640 / 2, 480 / 2);
	
	
	
	
	
	int cooldown=0, conta;
	bool upApretado = false;
	while (w.isOpen()) {
	
		
		
		Event e;
		while (w.pollEvent(e)) {
			if (e.type == Event::Closed)
				w.close();

		}
		
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			if(upApretado==false){
				
				upApretado=true;
				
				if(e.key.code == sf::Keyboard::Up && cooldown==0)
					cooldown=5;
				
			}
			if(cooldown>0){
				
			player.subir();
			}
			
			
			
		}else
				upApretado=false;
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			//player.bajar();
		}
		
		w.clear(Color(176, 200, 255 , 255));
		
		std::cout<<cooldown<<std::endl;
		
		if(cooldown>0){
			cooldown--;
		}
		
		pilar.dibujar(&w);
		w.draw(sground);
		player.dibujar(&w);
		
		player.caer();
		
		
		
		
		w.display();

		
		}
	
	
		
	
	
	return EXIT_SUCCESS;
}

