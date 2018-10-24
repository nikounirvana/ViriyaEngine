add_executable(MyGameEngineOpenGL 
    WindowsApplication.cpp 
    OpenGLApplication.cpp
    ${PROJECT_SOURCE_DIR}/External/GL/src/glad_wgl.c
    )
target_link_libraries(MyGameEngineOpenGL Common OpenGLRHI opengl32)
target_include_directories(MyGameEngineOpenGL PRIVATE "${PROJECT_SOURCE_DIR}/External/GL/include")
