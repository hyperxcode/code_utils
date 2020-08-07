//
//  AppDelegate.m
//  TestOcDylib
//
//  Created by Sw007 on 2020/8/7.
//  Copyright © 2020 hyperxcode. All rights reserved.
//

#import "AppDelegate.h"
#import "dlfcn.h"

@interface AppDelegate ()

typedef int (*fnAdd)(int a, int b);
@property (weak) IBOutlet NSWindow *window;
@end

@interface OcDylib : NSObject
- (int) oc_add:(int) a withB : (int) b;
@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    // Insert code here to initialize your application
}


- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)sender {
    
    NSLog(@"-------close");
    return YES;
}

- (IBAction)OcCall:(id)sender {
    
    NSLog(@"oc call");
    void* handle = dlopen("libOcDylib.dylib", RTLD_LAZY);
    if (!handle) {
        NSAlert *alert = [[NSAlert alloc] init];
        [alert setInformativeText:@"OcDylib.dylib null"];
        [alert runModal];
        return;
    }
    
    Class roos = NSClassFromString(@"OcDylib");
    if (!roos) {
        dlclose(handle);
        
        NSAlert *alert = [[NSAlert alloc] init];
        [alert setInformativeText:@"NSClassFromString null"];
        [alert runModal];
        return;
    }
    
    id obj = [[roos alloc] init];
    int result = [(OcDylib*)obj oc_add: 5 withB: 8];
    
    dlclose(handle);
    
    NSAlert *alert = [[NSAlert alloc] init];
    [alert setInformativeText:[NSString stringWithFormat:@"%d", result]];
    [alert runModal];
    
}

- (IBAction)CppCall:(id)sender {
    NSLog(@"cpp call");
    void* handle = dlopen("libOcDylib.dylib", RTLD_LAZY);
    if (!handle) {
        NSAlert *alert = [[NSAlert alloc] init];
        [alert setInformativeText:@"OcDylib.dylib null"];
        [alert runModal];
        return;
    }
    
    fnAdd add = (fnAdd)dlsym(handle, "add");
    if(!add){
        dlclose(handle);
        
        NSAlert *alert = [[NSAlert alloc] init];
        [alert setInformativeText:@"function null"];
        [alert runModal];
        return;
    }
    
    int result = add(1, 5);
    dlclose(handle);
    
    NSAlert *alert = [[NSAlert alloc] init];
    [alert setInformativeText:[NSString stringWithFormat:@"%d", result]];
    [alert runModal];
}
@end
