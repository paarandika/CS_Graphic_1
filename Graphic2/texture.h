#pragma once
#include<glut.h>
#include "imageloader.h"


class Texture
{
public:
	Texture();
	~Texture();
	static GLuint loadTexture(Image* image);
};

