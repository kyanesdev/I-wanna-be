#pragma once

#include <memory>
#include <stack>

namespace sonar{
	
	typedef std::unique_ptr<Estado> Estadoref;
	
	class Estadofuncionamiento
	{
	public:
		
		Estadofuncionamiento( ){ }
		~Estadofuncionamiento( ){ }
		
		void AgregaEstado(Estadoref newEstado, bool EsReemplazado = true)
		void RemoverEstado ( );
		void ProcesoCambioEstado( );
		
		Estadoref &GetActivarEstado( ); 
	};
}
