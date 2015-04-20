//
//  RLMObject+Utilities.m
//  RealmUtilities 
//
//  Created by Adam Fish on 1/9/15.
//  Copyright (c) 2015 Roobiq. All rights reserved.
//

#import "RLMObject+Utilities.h"

#import <Realm/Realm.h>
#import <Realm/RLMObjectSchema.h>
#import <Realm/RLMProperty.h>

@implementation RLMObject (Utilities)

+ (id)primaryKeyValueForObject:(RLMObject *)object
{
    if (!object) {
        return nil;
    }
    
    RLMProperty *primaryKeyProperty = object.objectSchema.primaryKeyProperty;
    
    if (primaryKeyProperty) {
        id value = nil;
        
        value = [object valueForKey:primaryKeyProperty.name];
        
        if (!value) {
            @throw [NSException exceptionWithName:@"RBQException"
                                           reason:@"Primary key is nil"
                                         userInfo:nil];
        }
        
        return value;
    }
    
    @throw [NSException exceptionWithName:@"RBQException"
                                   reason:@"Object does not have a primary key"
                                 userInfo:nil];
}

+ (NSString *)classNameForObject:(RLMObject *)object
{
    // Returns the class name in code (i.e. "TestObject" not "RLMAccessor_V0_TestObject")
    NSString *className = [[object class] className];
    
    Class objcClass = NSClassFromString(className);
    
    // If we have Obj-C class return the name
    if (objcClass) {
        return className;
    }
    
    /*
     *  Create the Swift class name (i.e. "AppName.ClassName")
     *
     *  https://developer.apple.com/library/ios/documentation/Swift/Conceptual/BuildingCocoaApps/WritingSwiftClassesWithObjective-CBehavior.html#//apple_ref/doc/uid/TP40014216-CH5-XID_68
     */
    NSString *appName = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleName"];
    
    NSString *swiftClassName = [NSString stringWithFormat:@"%@.%@",appName,className];
    
    return swiftClassName;
}

@end
