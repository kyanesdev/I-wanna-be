#pragma oncee

namespace sonar{
	
	class estado{
		
	public:
		virtual void inicio( )=0;
		
		virtual void entrada( )=0;
		
		virtual void update( )=0;
		
		virtual void dibujar( float dj )=0;
		
		virtual void pausa( ) { }
		
		virtual void continuar ( ) { }
	};
	
	
	
	
}
