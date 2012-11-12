by Steve Baker, Beepscore LLC

# Purpose:
Record notes for Ch 8.

# References:
Book, Buck, Learning OpenGL ES for iOS  
Ch 8 Special Effects p 183-216  
<http://www.cosmicthump.com/learning-op1engl-es-information/>  

---

# Results: 

These techniques use 2D images to fool the eye, simpler than using 3D geometry  

- Skybox
- Particles
- Billboards

## Ch8 Code Examples

| Example        | Description                                                                 |
| -------------- | ----------------------                                                      |
| OpenGLES_Ch8_1 | uses GLKSkyboxEffect                                                        |
| OpenGLES_Ch8_2 | uses AGLKSkyboxEffect to show approximate implementation of GLKSkyboxEffect |
| OpenGLES_Ch8_3 |                                                                             |
| OpenGLES_Ch8_4 |                                                                             |

## Skybox
Put the 3D geometry, and usually the camera, inside a box.  
A 6 sided box adds only 12 triangles.   
Texture the box inner faces.  
In an outdoor scene, the texture may be images of the sky.  
Texture map with cube map.  
Make box cubical to avoid texture distortion.  
Distortion may become noticeable if camera gets too close to a cube edge.  

    self.textureInfo = [GLKTextureLoader cubeMapWithContentsOfFile:path  
                                         options:nil  
                                         error:&error];  

- Texture is sampled in a direction from viewer to the sides of an enclosing cube.   

### Environment map (aka Reflection map)
- Similar to a skybox, textures a reflective surface such as water. 
- Texture is sampled in a direction from surface of reflective object to the sides of an enclosing cube.   

## Deep Dive: How Does GLKSkyboxEffect Work?  

### Vertex Shader
### Fragment Shader

### Tying OpenGL ES 2.0 Shading Language Programs to Your Code
Methods reused by each of the custom Shading Language examples in this book:  

    - (BOOL)loadShaders;  
    - (BOOL)compileShader:(GLuint *)shader type:(GLenum)type file:(NSString *)file;  
    - (BOOL)linkProgram:(GLuint)prog;  
    - (BOOL)validateProgram:(GLuint)prog;  


## Particles

## Billboards

## Summary

