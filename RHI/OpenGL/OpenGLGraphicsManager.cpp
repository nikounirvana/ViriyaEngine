#include <stdio.h>
#include "glad/glad.h"
#include "OpenGLGraphicsManager.hpp"

using namespace My;

extern struct gladGLversionStruct GLVersion;

int My::OpenGLGraphicsManager::Initialize()
{
	int result;

	result = gladLoadGL();
	if(!result){
		printf("opengl load failed!\n");
		result = -1;
	}else{
		result = 0;
		printf("OpenGl version %d.%d loaded\n", GLVersion.major, GLVersion.minor);
		if(GLAD_GL_VERSION_3_0){
			glClearDepth(1.0f);

			glEnable(GL_DEPTH_TEST);

			// set the polygon winding to front face
			glFrontFace(GL_CW);

			// enable back face culling.
			glEnable(GL_CULL_FACE);
			glCullFace(GL_BACK);
		}
	}

	return result;
}

void My::OpenGLGraphicsManager::Finalize()
{
}

void My::OpenGLGraphicsManager::Tick()
{
}
