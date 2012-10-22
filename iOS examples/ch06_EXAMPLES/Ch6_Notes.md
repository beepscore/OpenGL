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
Sphere appears stretched vertically.  
Ch5_1 uses multiple vertex attribute array buffers. This is easiest for use with sphere.h.


## Animating Colors and Lights
Uses a transformation so sphere appears spherical.

## Animating Textures

## Summary

