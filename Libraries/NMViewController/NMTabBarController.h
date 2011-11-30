//
//  NMTabBarController.h
//  NMViewController
//
//  Created by Benjamin Broll on 10.11.10.
//  Copyright 2010 NEXT Munich. The App Agency. All rights reserved.
//

/*
 * The BSD License
 * http://www.opensource.org/licenses/bsd-license.php
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the name of NEXT Munich GmbH nor the names of its contributors may
 *   be used to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#import <UIKit/UIKit.h>

#import "NMTabBar.h"
#import "NMViewController.h"


@protocol NMTabBarControllerDelegate;



@interface NMTabBarController : NMViewController <NMTabBarDelegate> {

	// View
	UIView* viewControllerContainer;
	UIView *tabBarContainer;
	
	// State
	id<NMTabBarControllerDelegate> delegate;
	NSMutableArray* viewControllers;
	NSUInteger selectedIndex;
	// - the tab bar view
	NMTabBar *tabBar;
	
}

@property (nonatomic, retain) IBOutlet UIView *viewControllerContainer;
@property (nonatomic, retain) IBOutlet UIView *tabBarContainer;

@property (nonatomic, assign) id<NMTabBarControllerDelegate> delegate;
@property (nonatomic, copy) NSArray* viewControllers;
@property (nonatomic, assign) NSUInteger selectedIndex;
@property (nonatomic, assign) UIViewController* selectedViewController;
// currently, the tab has to be able to fill the whole width of the screen
// the tab bar's height is used as is
@property (nonatomic, retain) NMTabBar *tabBar;

@end


@protocol NMTabBarControllerDelegate <NSObject>

@optional

// only called when the user changes tabs. not called when tabBarController.selectedIndex
// is reassigned
- (void)tabBarController:(NMTabBarController*)vc willSelectIndex:(NSUInteger)tab;
- (void)tabBarController:(NMTabBarController*)vc didSelectIndex:(NSUInteger)tab;
- (void)tabBarController:(NMTabBarController*)vc popToRoot:(NSUInteger)tab;

@end
