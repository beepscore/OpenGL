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

## Purpose of example 3_3:
Maps image to a texture.  
Shows one triangle with blue checker texture.  
User can change:  

| UI Control            | What it controls        | How it controls           |
| --------------------- | ----------------------- | ------------------------- |
| Linear Filter switch  | texture sampling        | GL_LINEAR or GL_NEAREST   |
| Animation switch      | vertex buffer positions | update called every frame |
| Slider                | texture map offset      | glTexParameteri()         |
| Repeat Texture switch | turn on or off          |                           |

## AGLKVertexAttribArrayBuffer class
new method -reinitWithAttribStride:numberOfVertices: data:  

## OpenGLES_Ch3_3ViewController.m defines category (AGLKAdditions) on class GLKEffectPropertyTexture
- adds method
     - (void)aglkSetParameter:(GLenum)parameterID value:(GLint)value;
- Uses unconventional name prefix aglk to reduce chance of name collision if Apple adds methods to GLKEffectPropertyTexture

## Opacity, Blending, and Multi-Texturing
Use the GL_RGBA texture format containing Alpha components to specify the opacity of each texel.
Ch 4 will discuss lighting. 

- glEnable(GL_BLEND) enables blending
- Most common usage of alpha transparency
    - glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)
- Alpha = 0 transparent
- Alpha = 1 opaque

## My Changes
- In OpenGLES_Ch3_3ViewController changed deprecated viewDidUnload to dealloc.
- Moved method header comments from implementation .m to interface .h

