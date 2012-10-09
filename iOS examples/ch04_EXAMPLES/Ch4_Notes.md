by Steve Baker, Beepscore LLC

# Purpose:
Record notes for Ch4.

# References:
Book, Buck, Learning OpenGL ES for iOS  
Ch 4 Lighting pg 87 - 106.  
<http://www.cosmicthump.com/learning-opengl-es-information/>

beepscore fork of xcoders/OpenGL  
<https://github.com/beepscore/OpenGL/network>

Cross product
<http://en.wikipedia.org/wiki/Cross_product>
<http://mathworld.wolfram.com/CrossProduct.html>

Dot product
<http://en.wikipedia.org/wiki/Dot_product>

# Results: 

## Types of light
- Ambient light
    - direction independent
    - lights all triangles equally
- Diffuse light
    - directional
- Specular light
    - directional
    - shiny highlights
    - reflects light

## Lighting support

### Open GL ES 1.x 

- supports lights directly.

### Open GL ES 2.0  

- doesn't support lights directly.
- uses custom OpenGL Shading Language programs (shaders)

### GLKit GLKBaseEffect class
- for Open GL ES 2.0
- mimics Open GL ES 1.x lights
- automatically generates shaders for lights
- supports up to 3 lights named light0, light1, and light2

    #### Lights
    - each light has a position, an ambient color, a diffuse color, and a specular color
    - color is GLKVector4, rgba, each component 0-1.0f
    - ambient color default is opaque black 0,0,0,1
    - specular color default is opaque white 1,1,1,1
    - Each light can be separately enabled or disabled
    - Positional light sources can be configured as spot lights that shed light in a cone
    - constantColor property is only applicable when rendering flat unlit objects.
    - If any light is enabled, base effect constant color and vertex colors are ignored.
    - Best to minimize number of light sources, use zero or one only.
    - Can reduce need for lights by "baking" static lighting into textures before run time.

---

## Vector operations

### Normalize
- unit vector parallel to vectorA  
- GLKVector3Normalize(GLKVector3 vectorA)

### Cross product

- vector normal to surface
- right hand rule
- A x B = |vectorA| * |vectorB| * sin(theta) * unit vector perpendicular to A and B
- Determinant of matrix i,j,k / B.x B.y B.z / B.x B.y B.z /
- (A.y * B.z - A.z * B.y) i + (A.z * B.x - A.x * B.z) j + (A.x * B.y - A.y * B.x) k  
- GLKVector3 GLKVector3CrossProduct( GLKVector3 vectorA, GLKVector3 vectorB)

### Dot product

- scalar
- A * B = |vectorA| * component of B along A
- A * B = |vectorA| * |vectorB| * cos(theta)
- (A.x * B.x) + (A.y * B.y) + (A.z * B.z)

### Dot product of normalized cross product

- indicates how parallel light is to a surface
- indicates how much diffuse and specular light coming 
  from a given direction will illuminate a surface pointing in another direction.

### Normals pg 94-96
- "If all three vertices of a triangle are given the same normal vector,
called a face normal, the lighting simulation makes the triangle appear flat."
- "If the normal vector of each vertex is an average of the normal
vectors for all triangles that include the vertex, the lighting
simulation creates the illusion that the triangles are slightly curved"
- "most applications pre-calculate the normal vectors or load the normal
vectors from a data file along with vertex position information"  

---

## Materials
OpenGL ES supports different types of materials  
 
- computationally taxing for current mobile hardware
- "vast majority" of mobile apps should use default material values
- use textures to control object appearance.

---

## Example 4_1 pg 97-103

- Shows how to enable and configure lighting.  
- If you turn on "show normals", each vertex shows 3 face normals that will be
averaged to calculate vertex normal.

- SceneVector3UnitNormal(const GLKVector3 vectorA, const GLKVector3 vectorB)  
returns unit normal vector perpendicular to surface formed by vectorA and vectorB.

---

## Textures
### Bake Lighting into Textures pg 104 - 105
With embedded GPUs, textures almost always produce higher quality rendered results than OpenGL ES materials.
### Example 4_2
Uses texture map with baked lighting.

## Fragment Operations pg 105 - 106
- Calculate lighting for each fragment (texel) instead of for each vertex
- Requires each fragment to have a normal, stored in a normal map texture (bump map)
- Computationally expensive
- "Per-fragment lighting techniques are possible with all hardware that
runs iOS and will become more common as memory, processor, and tools
support improve."

