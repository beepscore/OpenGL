by Steve Baker, Beepscore LLC

# Purpose:
Record notes for Ch 8 Special Effects.

# References:
Book, Buck, Learning OpenGL ES for iOS  
Ch 8 Special Effects p 183-216  
<http://www.cosmicthump.com/learning-op1engl-es-information/>  

OpenGL ES 2.0 Programming Guide by Munshi, Ginsburg, Shreiner  
<http://www.pearsonhighered.com/educator/product/OpenGL-ES-20-Programming-Guide/9780321502797.page>

OpenGL ES 2.0 API Quick Reference Card  
<http://www.khronos.org/opengles/sdk/docs/reference_cards/OpenGL-ES-2_0-Reference-card.pdf>

---

# Results: 

These techniques use 2D images to fool the eye, simpler than using 3D geometry.  

| Effect     | What it does                                                    |
| ------     | --------------------------------------------------------------  |
| Skybox     | Encloses scene in a cube with textures facing in                |
| Particles  | Simulates explosions, moving water or smoke                     |
| Billboards | Textured surface rotates to stay perpendicular to point of view |


## Code Examples

| Example        | Description                                                          |
| -------------- | ----------------------                                               |
| OpenGLES_Ch8_1 | skybox uses GLKSkyboxEffect, boat in environment with water and sky  |
| OpenGLES_Ch8_2 | like example 8_1 but uses AGLKSkyboxEffect                           |
| OpenGLES_Ch8_3 | particles, looks like tennis balls shot from a ball throwing machine |
| OpenGLES_Ch8_4 | billboards, trees, can choose cylindrical or spherical               |

## Skybox
Put the 3D geometry and camera inside a box.  
A 6 sided box adds only 12 triangles.   
Texture the box inner faces.  
In an outdoor scene, the texture may be images of the sky.  
Texture map with cube map.  
Make box cubical to avoid texture distortion.  
Distortion may become noticeable if camera gets too close to a cube edge.  

    self.textureInfo = [GLKTextureLoader cubeMapWithContentsOfFile:path  
                                         options:nil  
                                         error:&error];  

Texture is sampled in a direction from viewer to the sides of an enclosing cube.   

### Environment map (aka Reflection map)
- Similar to a skybox, textures a reflective surface such as water. 
- Texture is sampled in a direction from surface of reflective object to the sides of an enclosing cube.   

## Deep Dive: How Does GLKSkyboxEffect Work?  
Example OpenGLES_Ch8_2 is similar to OpenGLES_Ch8_1 but uses AGLKSkyboxEffect to show approximate implementation of GLKSkyboxEffect.  

To orient triangle front faces inward, list vertices in correct order.
See Ch 7 Loading and Using Models / Back Face Culling.  

### Shaders
Shaders are relatively low level.  
GLKit reduces need to write your own shaders, but you can write your own and may need to.  
Write shaders in OpenGL ES 2.0 Shading Language.  

Shaders always include two subprograms:  

- Vertex Shader
- Fragment Shader

#### Vertex Shader
File name extension .vsh  
Runs once per vertex processed in scene.  
Sets gl_Position  

#### Fragment Shader
File name extension .fsh  
Fragments don't have a one-to-one correspondence with vertex shader positions.  
Rasterizing is a rendering step that converts geometric shape to colored pixels in the frame buffer.  

#### Tying OpenGL ES 2.0 Shading Language Programs to Your Code
Methods reused by each of the custom Shading Language examples in this book:  

    - (BOOL)loadShaders;  
    - (BOOL)compileShader:(GLuint *)shader type:(GLenum)type file:(NSString *)file;  
    - (BOOL)linkProgram:(GLuint)prog;  
    - (BOOL)validateProgram:(GLuint)prog;  


## Particles
A colored or textured geometrical object, defined by a single 3D position.  

### Point sprites
- remain oriented parallel to the viewing frustrum near and far planes. 
- Similar to billboards, but render more efficiently. 
- GL_POINTS mode
- Requires a custom Shading Language program to control size.

Example OpenGLES_Ch8_3 defines class AGLKPointParticleEffect which wraps a custom Shading Language program to control particle size.  

## Billboards

| Type           | Orientation                                                   |
| -------------- | ------------------------------------------------------------  |
| Planar         | orients to face the viewer                                    |
| Cylindrical    | orients to face the viewer but stays aligned with "up" vector |
| Spherical      | stays aligned to frustrum's near plane                        |


## Summary
Special effects look good and require less GPU processing than other 3D objects.  

They have limitations:

- Skybox and billboard may appear distorted from some viewpoints
- Point sprite particles aren't sorted by depth and so may render incorrectly.  

