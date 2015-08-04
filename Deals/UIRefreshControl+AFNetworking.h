#import <Foundation/Foundation.h>

#import <Availability.h>

#if defined(__IPHONE_OS_VERSION_MIN_REQUIRED)

#import <UIKit/UIKit.h>

@class AFURLConnectionOperation;

/**
 This category adds methods to the UIKit framework's `UIRefreshControl` class. The methods in this category provide support for automatically begining and ending refreshing depending on the loading state of a request operation or session task.
 */
@interface UIRefreshControl (AFNetworking)

///-----------------------------------
/// @name Refreshing for Session Tasks
///-----------------------------------

/**
 Binds the refreshing state to the state of the specified task.
 
 @param task The task. If `nil`, automatic updating from any previously specified operation will be diabled.
 */
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= 70000
- (void)setRefreshingWithStateOfTask:(NSURLSessionTask *)task;
#endif

///----------------------------------------
/// @name Refreshing for Request Operations
///----------------------------------------

/**
 Binds the refreshing state to the execution state of the specified operation.

 @param operation The operation. If `nil`, automatic updating from any previously specified operation will be disabled.
 */
- (void)setRefreshingWithStateOfOperation:(AFURLConnectionOperation *)operation;

@end

#endif
