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
| TerrainEditor   | Mac OS X, generates terrain models                  |
| OpenGLES_Ch10_1 | Terrain with false color for picking                |
| OpenGLES_Ch10_2 | like 10_1, but optimizes via frustrum-based culling |

## Terrain Implementation

### Height Map
Terrain mesh is rectangular grid in X,Z plane.  
File supplies Y elevation (altitude).  

#### TerrainEditor.app
Imports grayscale image to be used as height map.
Exports Core Data terrain model.  
Mac OS X app. Uses Core Data.  

##### TEDocument
Sets constant TEMetersPerUnit = 10.0 (10.0 meter/pixel)  
Sets constant TEHeightScaleFactor = 35.0  
Sets path to height map file heightMap.tga  
In example data, height map image is 300x300 pixels.  
So horizontal scale is 10 meter/pixel * 300 pixel/side = 3,000 meter/side   
Instantiates TEHightMap.  
Imports texture image such as Sahara.jpg and applies it to terrain.  
Contains light info.  

##### TEHeightMap

###### loadFromPath:
Input image pixel brightness ranges from 0-255 == 1 byte / gray pixel.  

###### heightAtXPos:yPos:
Rescales height.  

---

#### OpenGLES_Ch10_1 
iOS app.  Imports Core Data model.  
Generates Objective-C object TETerrain.  

App bundle is OpenGLES_Ch10_1.app.  
For simulator, app may be located at:  

    ~/Library/Application Support/iPhoneSimulator/6.0/Applications/<long string here>/OpenGLES_Ch10_1.app  

In Finder, show package contents. Directory OpenGLES_Ch10_1.app contains:  

- trail.binary (11.8 Mb)
- OpenGLES_Ch10_1.momd (16 kb).  

#### OpenGLES_Ch10_1AppDelegate

##### didFinishLaunchingWithOptions:
Makes Core Data request to managedObjectContext, response sets self.terrain  

##### Core Data stack

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
TETerrain is partitioned into TETerrainTile objects.  

### Terrain Effect

---

## Adding Models

### Model Placement

### Model Effect


## OpenGL ES Camera

## Picking

### Alternative Picking Approaches


## Optimizing

### Other Potential Optimizations

#### ROAM - Real-Time Optimally Adapting Mesh


## Summary

