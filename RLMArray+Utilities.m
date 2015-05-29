//
//  RLMArray+Utilities.m
//  RBQFetchedResultsControllerExample
//
//  Created by AsanoYuki on 2015/05/29.
//  Copyright (c) 2015年 Roobiq. All rights reserved.
//

#import "RLMArray+Utilities.h"
#import "RLMObject.h"

@implementation RLMArray (Utilities)

- (BOOL)containsObject:(RLMObject *)anObject
{
    for (RLMObject *containedObject in self) {
        if ([containedObject isEqualToObject:anObject]) {
            return YES;
        }
    }
    return NO;
}

@end
