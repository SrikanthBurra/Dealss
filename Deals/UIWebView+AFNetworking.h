
#import <Foundation/Foundation.h>

#import <Availability.h>

#if defined(__IPHONE_OS_VERSION_MIN_REQUIRED)

#import <UIKit/UIKit.h>

@class AFHTTPRequestSerializer, AFHTTPResponseSerializer;
@protocol AFURLRequestSerialization, AFURLResponseSerialization;

/**
 This category adds methods to the UIKit framework's `UIWebView` class. The methods in this category provide increased control over the request cycle, including progress monitoring and success / failure handling.
 
 @discussion When using these category methods, make sure to assign `delegate` for the web view, which implements `–webView:shouldStartLoadWithRequest:navigationType:` appropriately. This allows for tapped links to be loaded through AFNetworking, and can ensure that `canGoBack` & `canGoForward` update their values correctly.
 */
@interface UIWebView (AFNetworking)

/**
 The request serializer used to serialize requests made with the `-loadRequest:...` category methods. By default, this is an instance of `AFHTTPRequestSerializer`.
 */
@property (nonatomic, strong) AFHTTPRequestSerializer <AFURLRequestSerialization> * requestSerializer;

/**
 The response serializer used to serialize responses made with the `-loadRequest:...` category methods. By default, this is an instance of `AFHTTPResponseSerializer`.
 */
@property (nonatomic, strong) AFHTTPResponseSerializer <AFURLResponseSerialization> * responseSerializer;

/**
 Asynchronously loads the specified request.
 
 @param request A URL request identifying the location of the content to load. This must not be `nil`.
 @param progress A block object to be called when an undetermined number of bytes have been downloaded from the server. This block has no return value and takes three arguments: the number of bytes read since the last time the download progress block was called, the total bytes read, and the total bytes expected to be read during the request, as initially determined by the expected content size of the `NSHTTPURLResponse` object. This block may be called multiple times, and will execute on the main thread.
 @param success A block object to be executed when the request finishes loading successfully. This block returns the HTML string to be loaded by the web view, and takes two arguments: the response, and the response string.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes a single argument: the error that occurred.
 */
- (void)loadRequest:(NSURLRequest *)request
           progress:(void (^)(NSUInteger bytesWritten, long long totalBytesWritten, long long totalBytesExpectedToWrite))progress
            success:(NSString * (^)(NSHTTPURLResponse *response, NSString *HTML))success
            failure:(void (^)(NSError *error))failure;

/**
 Asynchronously loads the data associated with a particular request with a specified MIME type and text encoding.

 @param request A URL request identifying the location of the content to load. This must not be `nil`.
 @param MIMEType The MIME type of the content. Defaults to the content type of the response if not specified.
 @param textEncodingName The IANA encoding name, as in `utf-8` or `utf-16`. Defaults to the response text encoding if not specified.
 @param progress A block object to be called when an undetermined number of bytes have been downloaded from the server. This block has no return value and takes three arguments: the number of bytes read since the last time the download progress block was called, the total bytes read, and the total bytes expected to be read during the request, as initially determined by the expected content size of the `NSHTTPURLResponse` object. This block may be called multiple times, and will execute on the main thread.
 @param success A block object to be executed when the request finishes loading successfully. This block returns the data to be loaded by the web view and takes two arguments: the response, and the downloaded data.
 @param failure A block object to be executed when the request operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes a single argument: the error that occurred.
 */
- (void)loadRequest:(NSURLRequest *)request
           MIMEType:(NSString *)MIMEType
   textEncodingName:(NSString *)textEncodingName
           progress:(void (^)(NSUInteger bytesWritten, long long totalBytesWritten, long long totalBytesExpectedToWrite))progress
            success:(NSData * (^)(NSHTTPURLResponse *response, NSData *data))success
            failure:(void (^)(NSError *error))failure;

@end

#endif
