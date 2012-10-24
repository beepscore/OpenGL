by Steve Baker, Beepscore LLC

# Purpose:
Record notes for Ch6.

# References:
Book, Buck, Learning OpenGL ES for iOS  
Ch 6 Animation page 133 - 158.  
<http://www.cosmicthump.com/learning-opengl-es-information/>

C arrays in Objective C  
<https://borkwarellc.wordpress.com/2007/09/06/its-still-just-c-arrays-and-pointers/>

Quaternion  
<http://en.wikipedia.org/wiki/Quaternion>

---

# Results: 

## Ch6 Code Examples

| Example        | Description                                           | Animates                  |
| -------------- | ----------------------------------------------------- | ------------------        |
| OpenGLES_Ch6_1 | bumper car ride                                       | location                  |
| OpenGLES_Ch6_2 | planar "flag" sinuously waving (undulating)           | vertex coordinates        |
| OpenGLES_Ch6_3 | adds 2 colored moving spotlights                      | spotlight angle           |
| OpenGLES_Ch6_4 | adds texture with tranparent areas, rotates texture   | texture coordinates       |
| OpenGLES_Ch6_5 | Texture is animated movie. Optionally turn on ripple. | texture atlas coordinates |


## Methods for implementing animation

| Class               | Method               |
| ------------------- | -------------------- |
| GLKViewController   | -update              |
| GLKView             | -drawInRect          |
| GLKViewDelegate     | -glkView:drawInRect  |

GLKViewController properties. Units are seconds.

- timeSinceLastUpdate
- timeSinceLastDraw
- timeSinceLastResume
- timeSinceFirstResume

GLKViewController

| Method             | Action                           |
| ------------------ | -------------------------------- |
| paused             | pauses updates                   |
| framesDisplayed    | count since application launched |

Core Animation swaps the front frame buffer and back frame buffer during hardware display refresh.

---

## OpenGLES_Ch6_1 Motion Within a Scene page 134-139
Simulates bumper car ride.  
Each car has its own local coordinate system and is at origin {0,0,0}.  
App doesn't change vertex position or vertex normals.  

### obj2opengl.pl
Perl script converts obj file to a .h file.    
In OpenGLES_Ch6_1 it created bumperCar.h.  

### bumperCar.h
Defines float array variables: bumperCarVerts[], bumperCarNormals[].  
The variables are compatible with OpenGL function glDrawArrays.  

### SceneCarModel.m
Imports bumperCar.h  
init creates a SceneMesh named carMesh, then creates a SceneCarModel.  

### SceneMesh  
Author's class manages vertex data and data transfer to GPU-controlled memory.  

#### initWithPositionCoords:...
Uses array variables like those defined in bumperCar.h to instantiate a SceneMesh.

    - (id)initWithPositionCoords:(const GLfloat *)somePositions
       normalCoords:(const GLfloat *)someNormals
       texCoords0:(const GLfloat *)someTexCoords0
       numberOfPositions:(size_t)countPositions
       indices:(const GLushort *)someIndices
       numberOfIndices:(size_t)countIndices;

##### Argument type for array
In Objective C methods usually use Cocoa NSArray. Type is pointer variable (NSArray *).  
initWithPositionCoords:... uses C arrays, not NSArrays. 
Variable type is pointer to <element type>, e.g.  GLFloat *.
Points to address of element 0.  

### GLKMatrix4MakeLookAt()
- calculates transformation matrix representing a point of view.
- first 3 arguments {x,y,z} user eye position 
- second 3 arguments {x,y,z} point user is looking at, must be different than eye position.
- third 3 arguments [x,y,z] "up" direction vector, can't be parallel to look direction.
- returns a transformation matrix

GLKQuaternion for rotation avoids gimbal lock.

First person Point of View (POV) moves with the car.  
Each frame, update method calls updatePointOfView.  
Third person point of view is stationary outside car rink.  
App uses low pass filter to gradually change point of view.

---

## Animating Vertex Data

### OpenGLES_Ch6_2 
Animates vertex data. This is not common, because it requires frequent memory copying.  
Usually faster to animate coordinate system changes instead.  

#### Triangle strip
Representation avoids repeating vertex information.  

#### Indexed vertices 
If multiple triangle strips are adajent, use indexed vertices instead.  
Indexed vertices list each vertex one time only, requires less memory than triangle strips. 

## Animating Colors and Lights
OpenGLES_Ch6_3 animates spotlight angles.  

OpenGLES_Ch6_4 texture image RadiusSelectionTool.png has transparent areas.
Animates transform texture coordinates to rotate texture.

## Animating Textures
OpenGLES_Ch6_5 uses texture atlas with many subimages RabbitTextureAtlas.png  
Transforms and scales texture coordinates S, T to increment through
subimages and show a "movie" on the textured object's surface.  

## Summary
>Almost all animations result from changing coordinate systems over time.

