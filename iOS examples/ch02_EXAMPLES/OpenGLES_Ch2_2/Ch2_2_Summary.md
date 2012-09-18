// by Steve Baker, Beepscore LLC

#Purpose:
Summarize Ch2_2.

#References:
Book, Buck, Learning OpenGL ES for iOS  
Deep Dive: How Does GLKView Work? pages 42 = 51.  
<http://www.cosmicthump.com/learning-opengl-es-information/>

overriding getter name  
<https://developer.apple.com/library/mac/#documentation/Cocoa/Conceptual/ObjectiveC/Chapters/ocProperties.html>

beepscore fork of xcoders/OpenGL  
<https://github.com/beepscore/OpenGL/network>


#Results:
"OpenGLES_Ch2_2 is identical to OpenGLES_Ch2_1 except that AGLKView and
AGLKViewController are used instead of GLKit classes to show what the
GLKit classes do behind the scenes."

AGLKView is the author's partial reimplementation of Apple's GLKView.
AGLKView is a teaching aid, we can see its implementation.
AGLKView isn't used again. The rest of the book uses GLKView and you
should too.

##AGLKView 

- subclasses UIView
- property delegate 
    - adopts AGLKViewDelegate protocol  
    - must implement glkView:drawInRect:
- designated initializer initWithFrame:context: sets some layer properties.
- uses CAEAGLayer, which can share pixel color storage with an OpenGL
frame buffer
- property EAGLContext

- overrides setContext:
 
    - "Changing the view’s context invalidates any previously created buffers and requires creation and configuration of new buffers."  
    - Setter configures a frame buffer and a pixel color render buffer for use with the view’s Core Animation layer. 

- implements dealloc
   - if EAGLContext currentContext was self's context, sets currentContext to nil.
   - sets context nil to free memory


##AGLKViewController 

- subclasses UIViewController
- property preferredFramesPerSecond
- readonly property framesPerSecond
- property paused, specifies getter name isPaused
- ivar CADisplayLink timer periodically redraws the view


##Changes - S Baker 

- In AGLKView use dictionary literals. 
    - @{ kEAGLDrawablePropertyRetainedBacking : [NSNumber numberWithBool:NO],
       kEAGLDrawablePropertyColorFormat : kEAGLColorFormatRGBA8 }
    - Note inside a dictionary replacing value [NSNumber numberWithBool:NO] with @NO didn't work.

- In AGLKView.m setContext: second occurrence of context = aContext is unnecessary. Delete it.
- In AGLKViewController comment fix typo change Thi to This.
- In AGLKViewController reformat, re-indent.
