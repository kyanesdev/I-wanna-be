#pragma oncee

namespace Sonar{
	
	class State{
		
	public:
		virtual void Init( )=0;
		
		virtual void HandleInput( )=0;
		
		virtual void Update(int dt)=0;
		
		virtual void Draw( float dt )=0;
		
		virtual void Pause( ) { }
		
		virtual void Resume ( ) { }
	};
	
	
	
	
}
