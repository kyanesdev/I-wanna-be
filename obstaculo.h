#ifndef OBSTACULOS_H
#define OBSTACULOS_H

#include <SFML/Graphics.hpp>


using namespace sf;



class obstaculo{
	
private:
	int x;
	int y;
	int velx;
	int ancho;
	int alto;
	Sprite sobstaculo;
	Texture tobstaculo;
	
	
public:
	obstaculo(int x, int y);
	
	void dibujar(RenderWindow *w);
	
	void desplazarse();
	
	
};




#endif
