by Steve Baker, Beepscore LLC

# Purpose:
Record notes for Ch3_3.

# References:
Book, Buck, Learning OpenGL ES for iOS  
The OpenGLES_Ch3_3 Example pg 76 - 77.  
Opacity, Blending, and Multi-Texturing pg 77 - 78.  
<http://www.cosmicthump.com/learning-opengl-es-information/>

beepscore fork of xcoders/OpenGL  
<https://github.com/beepscore/OpenGL/network>


# Results: 

## Purpose of Example 3_3:
Map image to a texture.  
Show one triangle with blue checker texture.  

| UI Control            | What it controls        | How it controls               |
| --------------------- | ----------------------- | -------------------------     |
| Linear Filter switch  | texture sampling        | GL_LINEAR or GL_NEAREST       |
| Animation switch      | vertex buffer positions | update method                 |
| Slider                | texture coordinates     |                               |
| Repeat Texture switch | texture 1x or repeating | GL_REPEAT or GL_CLAMP_TO_EDGE |

## AGLKVertexAttribArrayBuffer class
new method -reinitWithAttribStride: numberOfVertices: data:  

## OpenGLES_Ch3_3ViewController.m defines category (AGLKAdditions) on class GLKEffectPropertyTexture
- adds method
     - (void)aglkSetParameter:(GLenum)parameterID value:(GLint)value;
- Uses unconventional name prefix aglk to reduce chance of name collision if Apple adds methods to GLKEffectPropertyTexture

## Opacity, Blending, and Multi-Texturing
- GL_RGBA texture format, Alpha specifies opacity of each texel.
    - 0 transparent
    - 1 opaque

- glEnable(GL_BLEND) enables blending
- Most common usage of alpha transparency
    - glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)

## Animation

### GLKViewController subclass method "update"

From Apple GLKViewController Class Reference:
As an alternative to implementing a glkViewControllerUpdate: method in a delegate, your subclass can provide an update method instead. The method must have the following signature:

- (void)update;

GLKit automatically calls update every frame.

#### Don't call super update
As an experiment, I tried calling [super update];  
Xcode gave error, said "no visible @interface for GLKViewController
declares the selector 'update'".

## Lighting
Ch 4 will discuss lighting. 

## My Changes
- In OpenGLES_Ch3_3ViewController changed deprecated viewDidUnload to dealloc.
- Moved method header comments from implementation .m to interface .h

