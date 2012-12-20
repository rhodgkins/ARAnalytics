//
//  ARAnalytics.h
//  Art.sy
//
//  Created by orta therox on 18/12/2012.
//  Copyright (c) 2012 Art.sy. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation
//  files (the "Software"), to deal in the Software without
//  restriction, including without limitation the rights to use,
//  copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following
//  conditions:
//
//  The above copyright notice and this permission notice shall be
//  included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
//  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
//  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.


#import <Foundation/Foundation.h>

@interface ARAnalytics : NSObject <UINavigationControllerDelegate>

/// Setup methods for each individual Analytics type
+ (void)setupTestFlightWithTeamToken:(NSString *)token;
+ (void)setupCrashlyticsWithAPIKey:(NSString *)key;
+ (void)setupMixpanelWithToken:(NSString *)token;
+ (void)setupFlurryWithAPIKey:(NSString *)key;
+ (void)setupGoogleAnalyticsWithID:(NSString *)id;

/// Set a per user property
+ (void)identifyUserwithID:(NSString *)id andEmailAddress:(NSString *)email;
+ (void)addUserProperty:(NSString *)property toValue:(NSString *)value;

/// Submit user events
+ (void)event:(NSString *)event;
+ (void)event:(NSString *)event withProperties:(NSDictionary *)properties;

+ (void)monitorNavigationViewController:(UINavigationController *)controller;

// Submit errors
+ (void)error:(NSString *)string, ...;

@end

// Whilst we cannot include the Crashlytics library
// we can stub out the implementation with methods we want
// so that it will link with the real framework later on ./

@interface Crashlytics : NSObject
+ (Crashlytics *)startWithAPIKey:(NSString *)apiKey;
+ (void)setUserIdentifier:(NSString *)identifier;
+ (void)setUserName:(NSString *)name;
+ (void)setObjectValue:(id)value forKey:(NSString *)key;
@end