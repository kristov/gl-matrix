# gl-matrix C

A C port of gl-matrix.js:

  https://github.com/toji/gl-matrix

Similar to:

  https://github.com/coreh/gl-matrix.c

But with some important differences:

1. There are no memory allocations
2. Everything operates on pointers passed
3. Everything is floats
4. Modifications are done to the first argument

If you want to produce a new object after performing some operation, first copy that object outside this library (maybe memcpy it) then pass it as arg 1.

The library is very unsafe in that all pointers must be pre-initialized/allocated to the correct size before calling functions. It will blindly set values without checking for NULL pointers and can not check for overflow.
