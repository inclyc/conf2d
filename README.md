# Introduction

[简体中文](./README_zh.md)

There are various configuration files in the system, some configuration files allow you to split into a directory, usually in the form of `xxx.conf.d`. However, some files do not support this notation. This program listens for file system changes and starts a scheduled task in another thread to synchronize the contents of the folder with the files.

# How to use

````
Usage: conf2d [OPTION...]

   -d, --dir=DIR Target directory to watch
   -f, --file=FILE Target file to watch
   -?, --help Give this help list
       --usage Give a short usage message

Mandatory or optional arguments to long options are also mandatory or optional
for any corresponding short options.
````

# Features

* Update files every once in a while

* Automatically update when the target folder is modified (inotify implementation)
