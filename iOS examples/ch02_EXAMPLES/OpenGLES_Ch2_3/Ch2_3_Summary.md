by Steve Baker, Beepscore LLC

#Purpose:
Summarize Ch2_3.

#References:
Book, Buck, Learning OpenGL ES for iOS  
Deep Dive: How Does GLKView Work? pages 51- 57.  
<http://www.cosmicthump.com/learning-opengl-es-information/>

beepscore fork of xcoders/OpenGL  
<https://github.com/beepscore/OpenGL/network>


#Results:
"There are no direct OpenGL ES function calls in OpenGLES_Ch2_3ViewController."  

Uses AGLKVertexAttribArrayBuffer and AGLKContext Objective C methods to
wrap OpenGL functions.

##AGLKVertexAttribArrayBuffer 
    + (void)drawPreparedArraysWithMode:(GLenum)mode
       startVertexIndex:(GLint)first
       numberOfVertices:(GLsizei)count;
    
    - (id)initWithAttribStride:(GLsizeiptr)stride
       numberOfVertices:(GLsizei)count
       bytes:(const GLvoid *)dataPtr
       usage:(GLenum)usage;
    
    - (void)prepareToDrawWithAttrib:(GLuint)index
       numberOfCoordinates:(GLint)count
       attribOffset:(GLsizeiptr)offset
       shouldEnable:(BOOL)shouldEnable;
    
    - (void)drawArrayWithMode:(GLenum)mode
       startVertexIndex:(GLint)first
       numberOfVertices:(GLsizei)count;
       
    - (void)reinitWithAttribStride:(GLsizeiptr)stride
       numberOfVertices:(GLsizei)count
       bytes:(const GLvoid *)dataPtr;


##AGLKContext 
    - (void)clear:(GLbitfield)mask;

    - (void)enable:(GLenum)capability;

    - (void)disable:(GLenum)capability;

    - (void)setBlendSourceFunction:(GLenum)sfactor 
       destinationFunction:(GLenum)dfactor;


##Changes
As an experiment, in OpenGLES_Ch2_3ViewController viewDidLoad set  

    self.preferredFramesPerSecond = 300;

and ran Performance Detective.

