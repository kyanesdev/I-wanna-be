#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>

#include "pressEnter.h"
#include "personaje.h"
using namespace sf;

//hello

int main() {
	
	Texture tpersonaje;
	
	RenderWindow w(VideoMode(640, 480), "i wanna be");
	system("color ");
	
	/*
	Sprite spressEnter;
	
	tpressEnter.loadFromFile("pressEnter1.png");
	spressEnter.setTexture(tpressEnter);
	spressEnter.setPosition(50, 50);
	*/
	
	tpersonaje.loadFromFile("flappy.png");
	personaje player(&tpersonaje, 640 / 2, 480 / 2);
	
	
	while (w.isOpen()) {
		Event e;
		while (w.pollEvent(e)) {
			if (e.type == Event::Closed)
				w.close();
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			player.subir();
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			player.bajar();
		}
		
		w.clear(Color(255, 255, 255, 255));
		player.dibujar(&w);
		
		}
		
		w.display();
		
	
	
	
	return 0;
}

