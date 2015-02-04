//
//  RBQSafeLocationObject.h
//  QuadTree
//
//  Created by Adam Fish on 1/21/15.
//  Copyright (c) 2015 Roobiq. All rights reserved.
//

#import "RBQSafeRealmObject.h"
#import <MapKit/MapKit.h>

/**
 *  Subclass of RBQSafeRealmObject that adds location information
 */
@interface RBQSafeLocationObject : RBQSafeRealmObject

/**
 *  Coordinate of the object
 */
@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;

/**
 *  Transient property to hold the current distance from a seach point.
 */
@property (nonatomic, assign) CLLocationDistance currentDistance;

/**
 *  Constructor method to create safe object from RLMObject with a coordinate value
 *
 *  @param object     original RLMObject
 *  @param coordinate coordinate value for the RLMObject
 *
 *  @return instance of RBQSafeLocationObject
 */
+ (instancetype)safeLocationObjectWithObject:(RLMObject *)object
                                  coordinate:(CLLocationCoordinate2D)coordinate;

@end
