by Steve Baker, Beepscore LLC

# Purpose:
Record notes for Ch 10 Terrain and Picking.

# References:
Book, Buck, Learning OpenGL ES for iOS  
Ch 10 Terrain and Picking p 237-276  
<http://www.cosmicthump.com/learning-op1engl-es-information/>  

USGS Digital Elevation Model (DEM) data  
<http://earthexplorer.usgs.gov>

Global Multi-resolution Terrain Elevation Data 2010 (GMTED2010)  
<http://eros.usgs.gov/#/Find_Data/Products_and_Data_Available/GMTED2010>  

ROAM - Real-Time Optimally Adapting Mesh  
<http://www.gamasutra.com/view/feature/3188/realtime_dynamic_level_of_detail_.php>  

---

# Results: 
Several types of 3D graphics show large data sets, e.g.

- terrain
- medical imaging
- molecular modeling

Partition large data sets into subsets for access by the GPU.  

Picking determines which object the user selected.   


## Code Examples

| Example         | Description                                         |
| --------------- | ----------------------                              |
| TerrainEditor   | Mac OS X, generates terrain model                   |
| OpenGLES_Ch10_1 | Terrain with false color for picking                |
| OpenGLES_Ch10_2 | like 10_1, but optimizes via frustrum-based culling |

## Terrain Implementation

### Height Map
Terrain mesh is rectangular grid in X,Z plane.  
File supplies Y elevation (altitude).  

#### TerrainEditor.app
Run app on Mac OS X.  
Imports grayscale image such as heightMap.tga to be used as height map.  
Imports texture image such as Sahara.jpg and applies it to terrain.  
File/Save As exports Core Data terrain model as binary, sqlite, or xml.  
Using Core Data database allows app to reference model entities as Objective-C objects.  
In Finder double clicking .binary or .sqlite opens TerrainEditor.app.

##### TEDocument
Sets constant TEMetersPerUnit = 10.0 (10.0 meter/pixel)  
Sets constant TEHeightScaleFactor = 35.0  
Sets path to height map file heightMap.tga  
In example data, height map image is 300x300 pixels.  
So horizontal scale is 10 meter/pixel * 300 pixel/side = 3,000 meter/side   
Instantiates TEHightMap.  
Imports texture image and applies it to terrain.  
Contains light info.  

##### TEHeightMap

###### loadFromPath:
Input image pixel brightness ranges from 0-255 == 1 byte / gray pixel.  

###### heightAtXPos:yPos:
Rescales height.  

---

#### OpenGLES_Ch10_1 
iOS app.  Imports Core Data terrain model file trail.binary.  
File was exported from TerrainEditor.app.  

ch10_EXAMPLES.app generates Objective-C object TETerrain and TETerrainTile sub-objects.   

---

##### Aside: Terrain data file location
In Xcode project navigator, file is in group Supporting Files.  
File Inspector shows file isn't in directory ch10_EXAMPLES, but in sibling directory "Resources".

After building app, app bundle is OpenGLES_Ch10_1.app.  
For simulator, app may be located at:  

    ~/Library/Application Support/iPhoneSimulator/6.0/Applications/<long string here>/OpenGLES_Ch10_1.app  
In Finder, show package contents. Directory OpenGLES_Ch10_1.app contains:  

- trail.binary (11.8 Mb)
- OpenGLES_Ch10_1.momd (16 kb).  

---

#### OpenGLES_Ch10_1AppDelegate

##### didFinishLaunchingWithOptions:
Makes Core Data request to managedObjectContext, response sets self.terrain  

---

##### Aside: Core Data stack

###### managedObjectContext
Connects itself to use persistentStoreCoordinator

###### persistentStoreCoordinator
Initializes itself with managedObjectModel  
Adds binary store "trail.binary"  

###### managedObjectModel
Returns mainBundle "OpenGLES_Ch10_1.momd"  

##### applicationsDocumentDirectory seems not to get called.

---

### Terrain Tiles
In this chapter the height map image has 300*300 == 90,000 pixels.
Each pixel maps to an X,Y,Z position in the terrain rectangular mesh.
Each rectangle is composed of two triangles, so the terrain mesh contains 180,000 triangles.  
Open GL ES glDrawElements() can't draw this many elements at one time.  
So the app partitions TETerrain into smaller TETerrainTile objects.  

App uses Core Data to automatically generate model files, and adds to
model behavior by defining categories on the model classes.  This way,
if during development you ask Core Data to regenerate model files, it
won't disturb the categories.  

| Core Data generated model | Category                 |
| ------------------------- | ------------------------ |
| TETerrain                 | TETerrain+viewAdditions  |
| TETerrain                 | TETerrain+modelAdditions |

### Terrain Effect

#### lightAndWeightsTextureInfo
- A texture created by a custom OpenGL ES shader
- Can blend four weighted detail textures
- Can incorporate pre-calculated baked-in lighting

---

## Adding Models

### UtilityMesh
#### - prepareToPick

### UtilityModel
#### doesRequireLighting
NO - model texture has baked in lighting  

### Model Placement
#### TEModelPlacement
- name
- position
- angle of rotation about Y axis

### Model Effect
Shader statements "if" and "discard" can slow GPU execution.  

## OpenGL ES Camera
- A camera is a familiar and intuitive way to control scene point of view.  
- Class UtilityCamera  
- UtilityOpenGLCameraDelegate  

## Picking
- When app senses a touch, UtilityPickTerrainEffect renders a false color image.  
- As part of rendering, foreground objects occlude background objects.
- Image is stored in a pixel color render buffer as a Frame Buffer Object (FBO).  
- FBO is square, power of two, 512 by 512.  
- This FBO isn't displayed on screen.  
- Terrain X is encoded into fragment Red color channel.  
- Terrain Z is encoded into fragment Green color channel.  
- Model index from (0 - 255) is encoded into fragment Blue color channel. (see pg 265)  

### -terrainInfoForProjectionPosition:
- argument provides screen coordinate. 
- Method reads pixel color at tapped screen coordinate to determine which terrain position was picked  
- returns info with terrain 3D coordinates
- returns modelIndex if a model (e.g. a house, a tree) was picked
- false-color picking is relatively simple but requires CPU to wait for GPU to render before it can read FBO  

### Alternative Picking Approaches
- Geometric approaches avoid rendering false-color image.  
- Add software complexity, might run faster than color based picking if view shows few objects.  
- Ray casting 
    - draws imaginary ray from touch point on near clipping plane to far clipping plane
    - returns closest object that ray intersects, if any
- Bullet 3D Game Multiphysics
    - If your app already uses 3D collision detection, you can pick by checking if
a cast ray "collides" with a 3D object. This doesn't add much incremental complexity or speed penalty.  

## Optimizing
OpenGLES_Ch10_2 doubles frame rate relative to OpenGLES_Ch10_1.   
uses frustrum based culling  
Simplifies distant tiles, renders as triangle fans instead of triangle strips.  

### Other Potential Optimizations
Many optimization strategies may or may not increase frame rate, depending upon the particular 3D scene, system hardware and balance between CPU, GPU, and memory.  

#### ROAM - Real-Time Optimally Adapting Mesh

#### Texture sampling within a vertex shader program
Currently no iOS device can do this.  

## Summary
- Dividing one terrain into tiles reduce large terrain data set into pieces small enough for glDrawElements()
- Dividing one terrain into tile objects enables culling of off screen tiles.  
- Color based picking is simple and fast, but ray casting may work better in some applications.  
