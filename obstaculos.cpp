#include "obstaculo.h"


int posicionx_obs=100; 
int altura_obs=100;

obstaculo::obstaculo(int x, int y) {
	tobstaculo.loadFromFile("cactus.png");
	sobstaculo.setTexture(tobstaculo);
}

void obstaculo::desplazarse() {
	
	posicionx_obs+=-8;
	
	
}

void obstaculo::dibujar(RenderWindow *w) {
	sobstaculo.setPosition(100, altura_obs);
	w->draw(this->sobstaculo);
	}
	

