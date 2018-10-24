#pragma once
#include "IRuntimeModule.hpp"

namespace My{
	class GraphicsManager : Implements IRuntimeModule
	{
		public:
			virtual ~GraphicsManager(){}
			virtual int Initialize();
			virtual void Finalize();
			virtual void Tick();
	};
}
