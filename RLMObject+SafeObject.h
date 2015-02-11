//
//  RLMObject+SafeObject.h
//  RealmUtilities
//
//  Created by Christopher Vermilion on 2/11/15.
//  Copyright (c) 2015 Roobiq. All rights reserved.
//

#import "RLMObject.h"

@class RBQSafeRealmObject;

@interface RLMObject (SafeObject)

/**
 *  Create a RBQSafeRealmObject from a RLMObject
 *
 *  @return RBQSafeRealmObject which is a thread-safe representation of the original RLMObject
 */
- (RBQSafeRealmObject *)rbq_safeObject;

/**
 *  Create a RLMObject from a RBQSafeRealmObject
 *
 *  Returns nil if the safe object's className doesn't match ours.
 *
 *  @param safeObject RBQSafeRealmObject instance
 *
 *  @return RLMObject of appropriate subtype
 */
+ (instancetype)rbq_objectFromSafeObject:(RBQSafeRealmObject *)safeObject;

/**
 *  Create a RLMObject in a specific Realm from a RBQSafeRealmObject
 *
 *  Returns nil if the safe object's className doesn't match ours.
 *
 *  @param realm      Realm in which the returned RLMObject is persisted
 *  @param safeObject RBQSafeRealmObject to convert into RLMObject
 *
 *  @return RLMObject of appropriate subtype
 */
+ (instancetype)rbq_objectInRealm:(RLMRealm *)realm
                   fromSafeObject:(RBQSafeRealmObject *)safeObject;

@end
