//
//  ViewController.h
//  OpenGLES_Ch3_3
//

#import <GLKit/GLKit.h>

@class AGLKVertexAttribArrayBuffer;


@interface OpenGLES_Ch3_3ViewController : GLKViewController

@property (strong, nonatomic) GLKBaseEffect *baseEffect;
@property (strong, nonatomic) AGLKVertexAttribArrayBuffer *vertexBuffer;
@property (nonatomic) BOOL shouldUseLinearFilter;
@property (nonatomic) BOOL shouldAnimate;
@property (nonatomic) BOOL shouldRepeatTexture;
@property (nonatomic) GLfloat sCoordinateOffset;

// This method is called by a user interface object configured
// in Xcode and updates the value of the sCoordinateOffset
// property to demonstrate how texture coordinates affect
// texture mapping to geometry
- (IBAction)takeSCoordinateOffsetFrom:(UISlider *)sender;

// This method is called by a user interface object configured
// in Xcode and updates the value of the shouldRepeatTexture 
// property to demonstrate how textures are clamped or repeated
// when mapped to geometry with texture coordinates outside the
// range 0.0 to 1.0.
- (IBAction)takeShouldRepeatTextureFrom:(UISwitch *)sender;

// This method is called by a user interface object configured
// in Xcode and updates the value of the shouldAnimate 
// property to demonstrate how texture coordinates affect
// texture mapping and visual distortion as geometry changes.
- (IBAction)takeShouldAnimateFrom:(UISwitch *)sender;

// This method is called by a user interface object configured
// in Xcode and updates the value.
- (IBAction)takeShouldUseLinearFilterFrom:(UISwitch *)sender;

@end
