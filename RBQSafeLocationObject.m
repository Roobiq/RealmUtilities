//
//  RBQSafeLocationObject.m
//  QuadTree
//
//  Created by Adam Fish on 1/21/15.
//  Copyright (c) 2015 Roobiq. All rights reserved.
//

#import "RBQSafeLocationObject.h"

@implementation RBQSafeLocationObject

+ (instancetype)safeLocationObjectWithObject:(RLMObject *)object
                                  coordinate:(CLLocationCoordinate2D)coordinate
{
    RBQSafeLocationObject *safeLocationObject = [self safeObjectFromObject:object];
    safeLocationObject->_coordinate = coordinate;
    
    return safeLocationObject;
}

@end
