by Steve Baker, Beepscore LLC

# Purpose:
Record notes for Ch 9 Optimization.

# References:
Book, Buck, Learning OpenGL ES for iOS  
Ch 9 Optimization p 217-236  
<http://www.cosmicthump.com/learning-op1engl-es-information/>  

Glassboard: Xcoders Learning OpenGL ES  
Hal Mueller and Pam DeBriere comments 2-16 October 2012 about OpenGL ES Performance Detective.

Where is "OpenGL ES Performance Detective"  
question by Erik Buck answer by Hal Muller  
You must log into Apple developer forums.  
<https://devforums.apple.com/message/739655>  

Scene Graph  
<http://en.wikipedia.org/wiki/Scene_graph>  

Use Double Buffering to Avoid Resource Conflicts  
<https://developer.apple.com/library/ios/#documentation/3DDrawing/Conceptual/OpenGLES_ProgrammingGuide/OpenGLESApplicationDesign/OpenGLESApplicationDesign.html>  

---

# Results: 

Optimization strategies, in typical order of decreasing benefit:  

- Render As Little as Possible
    - Frustrum-Based Culling
    - Simplify
- Minimize Buffer Copying
- Minimize State Changes

Can optimize for speed, or minimum power usage to increase battery life.   

Optimizing can introduce bugs or make code harder to read and maintain.  
Measure performance and only optimize where necessary.  

## Code Examples

| Example        | Description                                                     |
| -------------- | ----------------------                                          |
| OpenGLES_Ch9_1 | Uses frustrum culling to process only some of the 81 spaceships |

## Render As Little as Possible

- Back face culling. Don't render back sides of triangles
- Frustrum-based culling. Don't render objects outside of the viewing frustrum.  

### Frustrum-Based Culling
Example struct AGLKFrustum defines a frustrum.  

> "... the frustum data structure stores the same information encoded in
projection and modelview matrices. The frustum data structure is just an
alternative representation convenient for testing whether or not
geometry intersects the frustum. Equivalent projection and modelview
matrices can be extracted from an initialized frustum."


| Function                               | What it does                                                      | Similar to                  |
| --------                               | ------------                                                      | ----------                  |
| AGLKFrustumMakeFrustumWithParameters() | returns an initialized AGLKFrustum data structure                 | GLKMatrix4MakePerspective() |
| AGLKFrustumMakePerspective()           | extracts a projection matrix from a frustum                       | GLKMatrix4MakePerspective() |
| AGLKFrustumSetPositionAndDirection()   | updates a frustum’s point of view                                 | GLKMatrix4MakeLookAt()      |
| AGLKFrustumComparePoint()              | calculates the vector-from-eye position to the point being tested |                             |
| AGLKFrustumCompareSphere()             | test whether a sphere intersects with a viewing frustum           |                             |

#### Scene Graph Assisted Culling
Scene graph - hierarchical organization of geometric objects using a tree data structure.  
Test parent node. If it's outside frustrum, don't render it or any of its children.  

### Simplify
- Use Special Effects such as billboards
- Reduce number of vertices in meshes
- Use smaller textures
- Multi-texture rather than multi-pass render
- Avoid multi-texturing
- Avoid lighting calculations: use fewer lights, bake lighting into textures  

> "Culling and simplifying almost always provide the best return on your
time spent optimizing. No amount of improved efficiency when rendering
objects will save as much time as simply rendering fewer objects. No
amount of optimization to lighting effects will save as much time as not
computing lighting at all."


## Don't Guess: Profile  

### Temporarily comment out drawing code
> Comment out all the application’s drawing code and measure the resulting
“update rate.” ... if the application doesn’t even call the commented drawing code at the desired rate, no amount of optimization to drawing will solve the problem.

### Capture and analyze a frame / OpenGL ES Performance Detective
Buck's book is out of date here.  
In Xcode 4.4.1 you could open Developer Tools / OpenGL ES Performance Detective.  

In Xcode 4.5.2 you:
Connect device to Mac.  
Run application.  
In left column select Debug Navigator. It shows frames per second (FPS).  
Show the debug area (command - shift - y).  
In debug bar, select camera icon to "Capture OpenGL ES frame".  
After several seconds, the Debug Navigator shows info.  
Also after capturing frame in left column Issue Navigator shows OpenGL issues.  

### Instruments
Connect device to Mac.  
From Xcode choose Scheme with the iOS device, choose Profile to run Instruments.  
When an iOS device is connected, Instruments will show:  

- CPU / Time Profiler  
- OpenGL ES Analysis   
- OpenGL ES Driver 

## Minimize Buffer Copying
- If possible use GL_STATIC_DRAW and don't modify or read the buffer from the CPU.  
- If CPU needs to access buffer, use double buffers and swap them via glBindBuffer().  


## Minimize State Changes
These functions change the context. Avoid calling them more times than necessary:  

- glBindBuffer()
- glVertexAttribPointer()
- glEnable()
- glDisable()
- glEnableVertexAttribArray() and variants  

> Because vertex array objects are non-standard, avoid them unless profiling indicates that context state changes involving vertex array attribute buffers represent a significant bottleneck.

Proposed addition to OpenGL standard glBindVertexArrayOES() can restore entire state with one call.  

## Summary
Draw less.  
 
> Remember that iOS devices have relatively small screens. Small textures and simple geometry often provide adequate visual quality. Don’t make geometric models so complex that triangles end up smaller than a single pixel onscreen. Users will never see the detail.

