
#import <Foundation/Foundation.h>

#import <Availability.h>

#if defined(__IPHONE_OS_VERSION_MIN_REQUIRED)

#import <UIKit/UIKit.h>

@class AFURLConnectionOperation;

/**
 This category adds methods to the UIKit framework's `UIProgressView` class. The methods in this category provide support for binding the progress to the upload and download progress of a session task or request operation.
 */
@interface UIProgressView (AFNetworking)

///------------------------------------
/// @name Setting Session Task Progress
///------------------------------------

/**
 Binds the progress to the upload progress of the specified session task.
 
 @param task The session task.
 @param animated `YES` if the change should be animated, `NO` if the change should happen immediately.
 */
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= 70000
- (void)setProgressWithUploadProgressOfTask:(NSURLSessionUploadTask *)task
                                   animated:(BOOL)animated;
#endif

/**
 Binds the progress to the download progress of the specified session task.

 @param task The session task.
 @param animated `YES` if the change should be animated, `NO` if the change should happen immediately.
 */
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= 70000
- (void)setProgressWithDownloadProgressOfTask:(NSURLSessionDownloadTask *)task
                                     animated:(BOOL)animated;
#endif

///------------------------------------
/// @name Setting Session Task Progress
///------------------------------------

/**
 Binds the progress to the upload progress of the specified request operation.

 @param operation The request operation.
 @param animated `YES` if the change should be animated, `NO` if the change should happen immediately.
 */
- (void)setProgressWithUploadProgressOfOperation:(AFURLConnectionOperation *)operation
                                        animated:(BOOL)animated;

/**
 Binds the progress to the download progress of the specified request operation.

 @param operation The request operation.
 @param animated `YES` if the change should be animated, `NO` if the change should happen immediately.
 */
- (void)setProgressWithDownloadProgressOfOperation:(AFURLConnectionOperation *)operation
                                          animated:(BOOL)animated;

@end

#endif
