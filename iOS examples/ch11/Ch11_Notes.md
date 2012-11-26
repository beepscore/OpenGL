by Steve Baker, Beepscore LLC

# Purpose:
Record notes for Ch 11 Math Cheat Sheet.  

# References:
Book, Buck, Learning OpenGL ES for iOS  
Ch 11 Math Cheat Sheet  p 277-302  
<http://www.cosmicthump.com/learning-op1engl-es-information/>  

Transformation Matrix / Wikipedia   
<https://en.wikipedia.org/wiki/Transformation_matrix>

> Linear transformations are not the only ones that can be represented by matrices. Some transformations that are non-linear on a n-dimensional Euclidean space Rn, can be represented as linear transformations on the n+1-dimensional space Rn+1. These include both affine transformations (such as translation) and projective transformations. For this reason, 4x4 transformation matrices are widely used in 3D computer graphics


Transformation Matrix  
Has an interactive Java applet for 2D transformation using a 3x3 matrix.  
3D transformation using a 4x4 matrix.  No applet / doesn't work?  
<http://mathforum.org/mathimages/index.php/Transformation_Matrix>

> Affine transformations are represented by transformation matrices that are one higher dimension than the regular transformations.  

Computer Graphics 2012 by Wolfgang Huerst  
<https://www.youtube.com/playlist?list=PLDFA8FCF0017504DE>  

Computer Graphics 2012, Lect. 5(1) - Linear and Affine Transformations  
37 minutes homogeneous coordinates

Computer Graphics 2012, Lect. 7(1) - Perspective Projection  
<https://www.youtube.com/watch?v=Xt-AkLPC3Iw>  

The purpose of Model View Projection Matrix  
<http://stackoverflow.com/questions/5550620/the-purpose-of-model-view-projection-matrix>  

> The model, view and projection matrices are three separate matrices. Model maps from an object's local coordinate space into world space, view from world space to camera space, projection from camera to screen.
... OpenGL... never separates the model and view matrices — keeping them as a single modelview matrix stack. 

---

# Results: 

## Overview
- Computer graphics uses linear algebra to manipulate vectors and matrices.  
- Point at location X,Y,Z
- Vector - 3D vector is sum of X,Y,Z component vectors.  

## Decoding a Matrix
- Any 3D coordinate system can be encoded with 16 values.
- In memory, the values are stored consecutively.  
- The values may be organized in a 4x4 matrix

## Identity matrix

| component   | x axis | y axis | z axis |     |
| ----------- | ------ | ------ | ------ | --- |
| x component | 1.0    | 0.0    | 0.0    | 0.0 |
| y component | 0.0    | 1.0    | 0.0    | 0.0 |
| z component | 0.0    | 0.0    | 1.0    | 0.0 |
| axis origin | 0.0    | 0.0    | 0.0    | 1.0 |

Translation affects 4th row axis origin x,y,z.
Rotation and scale affect axis vectors.
Perspective affects 4th column.

### modelviewProjectionMatrix
The modelviewProjectionMatrix can be represented as the product of two
matrices:  

    modelviewProjectionMatrix = modelviewMatrix * projectionMatrix 

## Quaternions

## Surviving Graphics Math

### The Modelview Matrix
- defines the coordinate system used to describe the position and orientation of objects within a scene.  
- The modelview matrix defines the position and orientation of the viewing frustum.  

### Projection Matrix
- defines either an orthographic or a perspective projection  

## Summary

### Matrices
- encode coordinate systems
- define the shape, position, and orientation of viewing frustums  

### Quaternions
- encode rotation about any vector  
- avoid "gimbal lock" problem possible with Euler rotation  

