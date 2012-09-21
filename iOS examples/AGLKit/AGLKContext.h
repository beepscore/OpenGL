//
//  GLKContext.h
//
//

#import <GLKit/GLKit.h>

@interface AGLKContext : EAGLContext

// clear (background) RGBA color.
// The clear color is undefined until it is set.
@property (nonatomic, assign, readwrite) GLKVector4 clearColor;

// This method instructs OpenGL ES to set all data in the
// current Context's Render Buffer(s) identified by mask to
// colors (values) specified via -setClearColor: and/or
// OpenGL ES functions for each Render Buffer type.
- (void)clear:(GLbitfield)mask;

- (void)enable:(GLenum)capability;

- (void)disable:(GLenum)capability;

- (void)setBlendSourceFunction:(GLenum)sfactor
           destinationFunction:(GLenum)dfactor;

@end
