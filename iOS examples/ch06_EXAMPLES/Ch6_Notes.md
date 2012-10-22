by Steve Baker, Beepscore LLC

# Purpose:
Record notes for Ch6.

# References:
Book, Buck, Learning OpenGL ES for iOS  
Ch 6 Animation pg 133 - 158.  
<http://www.cosmicthump.com/learning-opengl-es-information/>

Quaternion  
<http://en.wikipedia.org/wiki/Quaternion>

# Results: 

## Ch6 Code Examples

| Example        | Description                                                 | Animates |
| -------------- | ----------------------------------------------------------- | -------- |
| OpenGLES_Ch6_1 | bumper car ride                                             | location |
| OpenGLES_Ch6_2 | sinuously rippling (undulating) plane                       |          |
| OpenGLES_Ch6_3 | adds 2 colored moving spotlights                            |          |
| OpenGLES_Ch6_4 | adds plane texture with tranparent areas                    |          |
| OpenGLES_Ch6_5 | plane texture is animated movie. Optional turn on ripple.   | texture  |


## Methods for implementing animation

| Class                     | Method                    |
| ------------------------- | ------------------------- |
| GLKViewController         | -update                   |
| GLKView                   | -drawInRect               |
| GLKViewDelegate           | -glkView:drawInRect       |

GLKViewController properties. Units are seconds.

- timeSinceLastUpdate
- timeSinceLastDraw
- timeSinceLastResume
- timeSinceFirstResume

GLKViewController

| Method                    | Action                           |
| ------------------------- | -------------------------------- |
| paused                    | pauses updates                   |
| framesDisplayed           | count since application launched |

Core Animation swaps the front frame buffer and back frame buffer during hardware display refresh.

## OpenGLES_Ch6_1 Motion Within a Scene page 134-139
Simulates bumper car ride.  
Each car has its own local coordinate system and is at origin {0,0,0}.  
App doesn't change vertex position or vertex normals.  

### GLKMatrix4MakeLookAt()
- calculates transformation matrix representing a point of view.
- first 3 arguments {x,y,z} user eye position 
- second 3 arguments {x,y,z} point user is looking at
- third 3 arguments [x,y,z] "up" direction vector
- returns a modelView matrix

GLKQuaternion avoids gimbal lock.

First person Point of View (POV) moves with the car.  
Third person point of view is stationary outside car rink.  
App uses low pass filter to gradually change point of view.

## Animating Vertex Data


## Animating Colors and Lights

## Animating Textures

## Summary

