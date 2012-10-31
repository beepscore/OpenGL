by Steve Baker, Beepscore LLC

# Purpose:
Record notes for Ch 7.

# References:
Book, Buck, Learning OpenGL ES for iOS  
Ch 7 Loading and Using Models pages 159-182  
<http://www.cosmicthump.com/learning-opengl-es-information/>

<http://en.wikipedia.org/wiki/Comparison_of_3D_computer_graphics_software>

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
- exports as .modelplist
- models must be within a few meters of the coordinate system origin to be visible.

## Reading modelplist Files
Figure 7.3 pg 167 shows structure  

## The OpenGLES_Ch7_1 Example
### Back Face Culling

## Advanced Models
### Skeletal Animation
#### OpenGLES_Ch7_2
Figure 7.6 Each vertex in UtilityMesh can reference 4 joint matrices in UtilityArmatureBaseEffect  

### Skinning
#### OpenGLES_Ch7_3
### Inverse Kinematics and Physics Simulation 
#### Bullet Physics
Works with Blender and SketchUp, exports COLLADA.

## Summary

