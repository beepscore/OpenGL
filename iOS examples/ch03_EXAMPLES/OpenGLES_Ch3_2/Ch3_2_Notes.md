by Steve Baker, Beepscore LLC

#Purpose:
Record notes for Ch3_2.

#References:
Book, Buck, Learning OpenGL ES for iOS  
Deep Dive: How Does GLKTextureLoader Work? pages 69 - 75.  
<http://www.cosmicthump.com/learning-opengl-es-information/>

beepscore fork of xcoders/OpenGL  
<https://github.com/beepscore/OpenGL/network>


#Results: 

##Purpose of example 3_2:
OpenGLES_Ch3_2 is similar to OpenGLES_Ch3_1 except that it uses
AGLKTextureLoader instead of Apple's GLKTextureLoader.

##AGLKTextureLoader versus GLKTextureLoader

###AGLKTextureLoader 
- author's partial reimplementation of Apple's GLKTextureLoader.  
- teaching aid, don't use it in production code.
- declares one method +textureWithCGImage:options:error:

###GLKTextureLoader:
- can load textures synchronously or asynchronously
- can generate MIP maps
- can load 1D, 2D, and 3D texture buffers

##How to use a texture buffer

| Step                                                    | OpenGL function |
| ------------------------------------------------------- | --------------- |
| Prepare image for use as a texture:                     |                 |
| - resize image dimensions to power of 2, perhaps square |                 |
| Generate buffer identifier                              | glGenTextures() |
| Bind buffer into current context                        | glBindTexture() |
| Initialize texture buffer with image                    | glTexImage2D()  |


##glTexImage2D()
- One of the most complex functions in OpenGL ES
- copies image pixel color data into the bound texture buffer
 
| Argument             |                                        |
| -------------------- | -------------------------------------- |
| GLenum target        | GL_TEXTURE_2D for 2D textures          |
| Glint level          | MIP map detail level, 0 for no MIP map |
| Glint internalFormat | for iOS, GL_RGB or GL_RGBA             |
| GLsizei width        | image width, power of 2                |
| GLsizei height       | image height, power of 2               |
| Glint border         | border around texels, 0 for OpenGL ES  |
| GLenum format        | set equal to internalFormat argument   |
| GLenum type          | bit encoding, e.g. GL_UNSIGNED_BYTE    |
| const GLvoid *data   | pointer to image's pixel color data    |


##CoreGraphics cgImage Y Axis Direction
- Mac OS X is y up, same as OpenGL
- iOS is y down

##AGLKTextureLoader.m defines category (AGLKTextureLoader) on class AGLKTextureInfo
- A category can add methods to an existing class.
- (AGLKTextureLoader) category adds method -initWithName:target:width:height: to AGLKTextureInfo
- location in AGLKTextureLoader.m file and name AGLKTextureLoader signal it is for use within the AGLKTextureLoader class.

##My Changes
In OpenGLES_Ch3_2ViewController changed deprecated viewDidUnload to dealloc.

