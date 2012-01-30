//
//  HTTPRouteMapping.h
//  iVocabulary
//
//  Created by Christian Beer on 12.12.11.
//  Copyright (c) 2011 Christian Beer. All rights reserved.
//

#import "CocoaHTTPServer/CocoaHTTPServer.h"

#import "WebSocketRouteDefinition.h"

typedef NSObject<HTTPResponse>* (^HTTPRequestHandler)(HTTPConnection* connection, NSString *method, NSString *path, NSDictionary *pathParameters, NSDictionary *requestParameters);
@class HTTPRouteDefinition;


@interface HTTPRouteMapping : NSObject

@property (strong, nonatomic, readonly) NSMutableArray      *routes;
@property (strong, nonatomic, readonly) NSMutableArray      *webSocketRoutes;

@property (nonatomic, copy)     HTTPRequestHandler  defaultHandler;

+ (HTTPRouteMapping*) sharedInstance;

- (HTTPRouteDefinition*) routeDefinitionForMethod:(NSString*)method path:(NSString *)path;
- (WebSocketRouteDefinition*) webSocketRouteDefinitionForPath:(NSString *)path;

- (void) addHandlerForMethod:(NSString*)method withPath:(NSString*)path handler:(HTTPRequestHandler)handler;
- (void) addHandlerForGetWithPath:(NSString*)path handler:(HTTPRequestHandler)handler;
- (void) addHandlerForPostWithPath:(NSString*)path handler:(HTTPRequestHandler)handler;
- (void) addHandlerForPutWithPath:(NSString*)path handler:(HTTPRequestHandler)handler;
- (void) addHandlerForDeleteWithPath:(NSString*)path handler:(HTTPRequestHandler)handler;

- (WebSocketRouteDefinition*) addWebSocketHandlerForPath:(NSString*)path receivedMessageHandler:(WebSocketDidReceiveMessageHandler)handler;

@end
