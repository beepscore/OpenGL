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

---

# Results: 


## Code Examples

| Example        | Description                                                     |
| -------------- | ----------------------                                          |
| OpenGLES_Ch9_1 | Uses frustrum culling to process only some of the 81 spaceships |

## Render As Little as Possible

### Frustrum-Based Culling

### Simplify


## Don't Guess: Profile  

### OpenGL ES Performance Detective
Buck's book is out of date here.  
In Xcode 4.4.1 you could open Developer Tools / OpenGL ES Performance Detective.  

In Xcode 4.5.2 you can do several analyses:

- Capture and analyze a frame
- Run Instruments OpenGL ES Analysis.  

#### Capture and analyze a frame
Connect device to Mac.  
Run application, show the debug area.  
In debug bar, select camera icon to "Capture OpenGL ES frame".  
Then in left column Debug Navigator select captured frame to see info.  

#### OpenGL ES Analysis
Connect device to Mac.  
From Xcode choose Scheme with the iOS device, choose Profile to run Instruments.  
When an iOS device is connected, Instruments will show iOS Graphics Instruments such as
Core Animation, OpenGL ES Driver and OpenGL ES Analysis.   
Choose OpenGL ES Analysis.  

## Minimize Buffer Copying

## Minimize State Changes

## Summary

