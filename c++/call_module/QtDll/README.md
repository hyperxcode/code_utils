# QtDll

* This is a Qt Demo Call Dll with windows,linux,mac.
* there have two projects,the simplest dll project and the caller project.
* we can use qt function to call dll or the platform raw way to call dll




# Record
there have some tools for different platform.

> windows
* [Dependency Walker](http://www.dependencywalker.com/)
* [Dependencies](https://github.com/lucasg/Dependencies.git)


> linux

> mac

* nm
``` bash
nm dylib
```

* otool
``` bash
otool -l xx.dylib
```

* ar
``` bash
ar -v -t xx.a
```

* lipo
``` bash
lipo -info xxx.framework/xxx
```