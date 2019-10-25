//Created by Kele

#include "personaje.h"

int altura=10; 

personaje::personaje(Texture *tex,int x, int y) {
	sflappy.setTexture(*tex);
	ancho = tex->getSize().x;
	alto = tex->getSize().y;
	
	this->y = y;
	
	velY = 0;
}
void personaje::subir() {
	
	altura+= -5;
	altura+= -10;
	altura+= -20;
	
	
}

void personaje::caer() {
	altura+= 10;
	
}

void personaje::dibujar(RenderWindow *w) {
	
	sflappy.setPosition(100, altura);
	w->draw(sflappy);
}

