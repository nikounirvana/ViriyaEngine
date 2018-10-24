#pragma once

#include "IRuntimeModule.hpp"
#include "Allocator.hpp"
#include <new>

namespace My{
	class MemoryManager : Implements IRuntimeModule
	{
	public:
		template<typename T, typename... Arguments>
		T* New(Arguments... parameters)
		{
			return new(Allocate(sizeof(T))) T(patameters...);
		}

		template<typename T>
		void Delete(T* p)
		{
			reinterpret_cast<T*>(p)->~T();
			Free(p, sizeof(T));
		}
	public:
		virtual ~MemoryManager(){}

		virtual int		Initialize();
		virtual void 	Finalize();
		virtual void 	Tick();

		void* 	Allocate(size_t size);
		void 	Free(void* p, size_t size);
	private:
		static size_t* 		m_pBlockSizeLookup;
		static Allocator*	m_pAllocators;

		static Allocator*	LookUpAllocator(size_t size);
	};
}
