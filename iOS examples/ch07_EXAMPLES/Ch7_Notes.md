by Steve Baker, Beepscore LLC

# Purpose:
Record notes for Ch 7.

# References:
Book, Buck, Learning OpenGL ES for iOS  
Ch 7 Loading and Using Models pages 159-182  
<http://www.cosmicthump.com/learning-opengl-es-information/>

<http://en.wikipedia.org/wiki/Comparison_of_3D_computer_graphics_software>

Blender  
<http://www.blender.org>  

SketchUp from Trimble (formerly Google)  
<http://www.sketchup.com>

Bullet Physics  
<http://bulletphysics.org/wordpress/>  

---

# Results: 

## Ch7 Code Examples

| Example        | Description            |
| -------------- | ---------------------- |
| OpenGLES_Ch7_1 | bumper car             |
| OpenGLES_Ch7_2 | rotate armature joints |
| OpenGLES_Ch7_3 | bones deform skin      |

## Load data at runtime, but minimize delay
- store data in a way that requires minimal processing while loading
- delay loading until data is needed
- load asynchronously

## Modelling Tools and File Formats
Vertex mesh defines model shape.

### Popular 3D Modeling Tools
- 3ds Max
- Maya
- Blender
- SketchUp

### 3D file formats
| Format         | Information stored                                          |
| -------------- | ------------------------------                              |
| .obj Wavefront | geometry, not animation                                     |
| .dae COLLADA   | geometry, materials, textures, lights, animations, and more |

### Asset Pipeline
- Create model, store as COLLADA file.
- Merge model meshes into one big mesh, store in easily parseable file.


#### ColladaViewer.app
- parses .dae xml file into model.
- exports as binary .modelplist file.  
- models must be within a few meters of the coordinate system origin to be visible.
- On Mac can use Apple Scene Kit Document Viewer instead  
  <https://developer.apple.com/library/mac/#samplecode/SceneKitDocumentViewer/Introduction/Intro.html>  
  <https://developer.apple.com/library/mac/#documentation/3DDrawing/Conceptual/SceneKit_PG/Introduction/Introduction.html>  

## Reading modelplist Files
- Figure 7.3 pg 167 shows structure  
- Root is NSDictionary  

## The OpenGLES_Ch7_1 Example
OpenGLES_Ch7_1ViewController reads file ch07_EXAMPLES/Resources/bumper.modelplist  
To improve memory efficiency, all of the vertex geometry is combined into one mesh.  
Each object uses a subset of the mesh.
Model file contains an axis aligned bounding box. Can use for collision detection.  

### Back Face Culling
- discards triangles that face away from the viewer  
- avoids Z fighting by only rendering one side.  

## Advanced Models
### Skeletal Animation
- big optimization. 
>Sending new orientations for relatively few armature
joints to the GPU is faster than recalculating and sending every vertex
position in a mesh.

#### OpenGLES_Ch7_2
Figure 7.6 Each vertex in UtilityMesh can reference 4 joint matrices in UtilityArmatureBaseEffect  

### Skinning
#### OpenGLES_Ch7_3
In UtilityModel+skinning.m can experiment with joint weights e.g.  

    GLKVector4 jointWeights = {
      // 1.0f / MAX(joint0.distanceSquared, 0.001),
      // 1.0f / MAX(joint1.distanceSquared, 0.001),
      // 1.0f / MAX(joint2.distanceSquared, 0.001),
      // 1.0f / MAX(joint3.distanceSquared, 0.001)};
      1.0f,
      32.0f,
      1.0f,
      1.0f 
    };


### Inverse Kinematics and Physics Simulation 
#### Bullet Physics
Works with Blender and SketchUp, exports COLLADA.

## Summary
>Model armatures, skeletal animation, and skinning use the GPU to deform
meshes at runtime. Updating a relatively small number of joint matrices
avoids the need to update large amounts of vertex data and repeatedly
resend that data to the GPU.  

