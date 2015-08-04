
#import <Foundation/Foundation.h>

#import <Availability.h>

#if defined(__IPHONE_OS_VERSION_MIN_REQUIRED)

#import <UIKit/UIKit.h>

@class AFURLConnectionOperation;

/**
 This category adds methods to the UIKit framework's `UIAlertView` class. The methods in this category provide support for automatically showing an alert if a session task or request operation finishes with an error. Alert title and message are filled from the corresponding `localizedDescription` & `localizedRecoverySuggestion` or `localizedFailureReason` of the error.
 */
@interface UIAlertView (AFNetworking)

///-------------------------------------
/// @name Showing Alert for Session Task
///-------------------------------------

/**
 Shows an alert view with the error of the specified session task, if any.
 
 @param task The session task.
 @param delegate The alert view delegate.
 */
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= 70000
+ (void)showAlertViewForTaskWithErrorOnCompletion:(NSURLSessionTask *)task
                                         delegate:(id)delegate;
#endif

/**
 Shows an alert view with the error of the specified session task, if any, with a custom cancel button title and other button titles.
 
 @param task The session task.
 @param delegate The alert view delegate.
 @param cancelButtonTitle The title of the cancel button or nil if there is no cancel button. Using this argument is equivalent to setting the cancel button index to the value returned by invoking addButtonWithTitle: specifying this title.
 @param otherButtonTitles The title of another button. Using this argument is equivalent to invoking addButtonWithTitle: with this title to add more buttons. Too many buttons can cause the alert view to scroll. For guidelines on the best ways to use an alert in an app, see "Temporary Views". Titles of additional buttons to add to the receiver, terminated with `nil`.
 */
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= 70000
+ (void)showAlertViewForTaskWithErrorOnCompletion:(NSURLSessionTask *)task
                                         delegate:(id)delegate
                                cancelButtonTitle:(NSString *)cancelButtonTitle
                                otherButtonTitles:(NSString *)otherButtonTitles, ... NS_REQUIRES_NIL_TERMINATION;
#endif

///------------------------------------------
/// @name Showing Alert for Request Operation
///------------------------------------------

/**
 Shows an alert view with the error of the specified request operation, if any.

 @param operation The request operation.
 @param delegate The alert view delegate.
 */
+ (void)showAlertViewForRequestOperationWithErrorOnCompletion:(AFURLConnectionOperation *)operation
                                                     delegate:(id)delegate;

/**
 Shows an alert view with the error of the specified request operation, if any, with a custom cancel button title and other button titles.

 @param operation The request operation.
 @param delegate The alert view delegate.
 @param cancelButtonTitle The title of the cancel button or nil if there is no cancel button. Using this argument is equivalent to setting the cancel button index to the value returned by invoking addButtonWithTitle: specifying this title.
 @param otherButtonTitles The title of another button. Using this argument is equivalent to invoking addButtonWithTitle: with this title to add more buttons. Too many buttons can cause the alert view to scroll. For guidelines on the best ways to use an alert in an app, see "Temporary Views". Titles of additional buttons to add to the receiver, terminated with `nil`.
 */
+ (void)showAlertViewForRequestOperationWithErrorOnCompletion:(AFURLConnectionOperation *)operation
                                                     delegate:(id)delegate
                                            cancelButtonTitle:(NSString *)cancelButtonTitle
                                            otherButtonTitles:(NSString *)otherButtonTitles, ... NS_REQUIRES_NIL_TERMINATION;

@end

#endif
