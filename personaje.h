#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <SFML/Graphics.hpp>


using namespace sf;



class personaje{
	
private:
	int x;
	int y;
	int velY;
	int ancho;
	int alto;
	Sprite sflappy;
	
	
public:
	personaje(Texture *tex , int x, int y);
	
	void subir();
	
	void dibujar(RenderWindow *w);
	
	void caer();
	
	
	
	
};
#endif //PERSONAJE_H
