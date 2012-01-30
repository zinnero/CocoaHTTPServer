//
//  HTTPRouteDefinition.h
//  iVocabulary
//
//  Created by Christian Beer on 29.12.11.
//  Copyright (c) 2011 Christian Beer. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "RouteDefinition.h"
#import "HTTPRouteMapping.h"

@interface HTTPRouteDefinition : RouteDefinition

@property (copy, nonatomic, readonly) NSString            *method;
@property (copy, nonatomic, readonly) HTTPRequestHandler  handler;


- (id) initWithMethod:(NSString*)method path:(NSString*)path error:(NSError**)outError handler:(HTTPRequestHandler)handler;

@end