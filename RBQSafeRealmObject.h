//
//  RBQSafeRealmObject.h
//  RealmUtilities
//
//  Created by Adam Fish on 1/4/15.
//  Copyright (c) 2015 Roobiq. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Realm/Realm.h>

/**
 *  An RBQSafeRealmObject acts as a thread-safe representation of a RLMObject.
 
 @warning RBQSafeRealmObjects can only be created from RLMObjects that contain a primary key. Attempting to create a RBQSafeRealmObject without a primary key will result in an exception.
 */
@interface RBQSafeRealmObject : NSObject <NSCopying>

/**
 *  Original RLMObject's class name
 */
@property (nonatomic, readonly) NSString *className;

/**
 *  Original RLMObject's primary key value
 */
@property (nonatomic, readonly) id primaryKeyValue;

/**
 *  Original RLMObject's primary key property
 */
@property (nonatomic, readonly) RLMPropertyType primaryKeyType;

/**
 *  The Realm in which this object is persisted
 */
@property (nonatomic, readonly) RLMRealm *realm;

/**
 *  Constructor method to create an instance of RBQSafeRealmObject
 *
 *  @param className       class name for the original RLMObject
 *  @param primaryKeyValue primary key value for the original RLMObject
 *  @param primaryKeyType  primary key type for the original RLMObject
 *  @param realm           Realm in which the original RLMObject is persisted
 *
 *  @return A new instance of RBQSafeRealmObject
 */
- (id)initWithClassName:(NSString *)className
        primaryKeyValue:(id)primaryKeyValue
         primaryKeyType:(RLMPropertyType)primaryKeyType
                  realm:(RLMRealm *)realm;

/**
 *  Create a RBQSafeObject from a RLMObject
 *
 *  @param object The RLMObject to transform into RBQSafeObject
 *
 *  @return RBQSafeObject which is a thread-safe
 */
+ (instancetype)safeObjectFromObject:(RLMObject *)object;

/**
 *  Create a RLMObject from a RBQSafeObject
 *
 *  @param safeObject RBQSafeRealmObject instance
 *
 *  @return RLMObject (not thread-safe)
 */
+ (RLMObject *)objectfromSafeObject:(RBQSafeRealmObject *)safeObject;

/**
 *  Create a RLMObject in a specific Realm from a RBQSafeObject
 *
 *  @param realm      Realm in whcih the returned RLMObject is persisted
 *  @param safeObject RBQSafeRealm object to convert into RLMObject
 *
 *  @return Converted RLMObject
 */
+ (RLMObject *)objectInRealm:(RLMRealm *)realm
              fromSafeObject:(RBQSafeRealmObject *)safeObject;

/**
 *  Quickly convert a RBQSafeRealm object into its RLMObject
 *
 *  @return RLMObject
 */
- (RLMObject *)RLMObject;

/**
 *  Equality test for RBQSafeObject
 *
 *  @param object RBQSafeRealmObject to compare
 *
 *  @return YES if both objects contain the same primary key
 */
- (BOOL)isEqualToObject:(RBQSafeRealmObject *)object;

@end
