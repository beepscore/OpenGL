by Steve Baker, Beepscore LLC

# Purpose:
Record notes for Ch5.

# References:
Book, Buck, Learning OpenGL ES for iOS  
Ch 5 Lighting pg 107 - 133.  
<http://www.cosmicthump.com/learning-opengl-es-information/>

# Results: 

## Depth Render Buffer - aka Z buffer
>"Almost every OpenGL ES application uses a depth buffer because  
>almost every OpenGL ES application uses coordinate system
transformations to change the rendering point of view."  

Default is off. To turn in on:  

    view.drawableDepthFormat = GLKViewDrawableDepthFormat16;
or  

    view.drawableDepthFormat = GLKViewDrawableDepthFormat24;

Choosing too few bits of depth format can cause Z-fighting.

To clear both the color buffer and depth buffer in one command,
use bitwise OR:  

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)


## OpenGLES_Ch5_1
Sphere appears stretched vertically.  
This example's model was made in Blender, exported as .obj file.  
Custom Perl script converted .obj to C code sphere.h that can be compiled directly. Not typical practice but easier for now.  
In practice most models will be stored in a graphics file format such as Collada .dae.

Often using a single buffer with interleaved vertex components speeds memory access.  
Ch5_1 uses multiple vertex attribute array buffers. This is easiest for use with sphere.h.


## OpenGLES_Ch5_2
Uses a transformation so sphere appears spherical.
In glkView:drawInRect:  

    // Scale the Y coordinate based on the aspect ratio of the
    // view's Layer which matches the screen aspect ratio for
    // this example 
    const GLfloat  aspectRatio = (GLfloat)view.drawableWidth / (GLfloat)view.drawableHeight; 
 
    self.baseEffect.transform.projectionMatrix = 
       GLKMatrix4MakeScale(1.0f, aspectRatio, 1.0f);

Scaling can stretch unit vectors so they aren't unit length.
To maintain correct lighting, rescale normal vectors to unit length.  

## Deep Dive
>"Example OpenGLES_Ch5_3 ... explores how GLKView works by
replicating its depth buffer functionality."  
 
## Transformations

### Four basic transformations
- translation
- rotation
- scaling
- perspective

Any number of basic transformations in any order can be captured and stored in a ... 4 by 4 matrix of floating-point values.  


#### Rotation
In radians. (pi radians / 180 degrees).  

    GLKMathDegreesToRadians()

    GLKMatrix4MakeRotation(GLKMathDegreesToRadians(30.0), 1.0, 0.0, 0.0);

#### Scaling
Scaling by a negative number flips axis direction.

#### Order matters
Ch5_4 UI has controls to apply multiple transformations.  

#### Open GL ES 1.1 had 3 matrix stacks
- projection matrix - define coordinate system for the scene
- modelview matrix - define coordinate system for an object
- texture matrix

#### GLKit modelviewProjection matrix
Concantenates modelview matrix with projection matrix.

##### Texture matrix
Currently not in GLKit, though Apple may add it.
The author wrote AGLKTextureTransformBaseEffect.

##### Ch5_5
-  texture matrix  
-  GLKMatrixStack stores 4x4 matrices on a stack  

### Transformation Cookbook

### Perspective and the Viewing Frustum
Units get progressively shorter away from the origin.  
Makes objects appear smaller as they get farther away.  

