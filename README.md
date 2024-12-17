# Simple Ray Tracer

This ray tracer is based on Peter Shirley's [Ray Tracing in One Weekend Series][https://raytracing.github.io/]

## Structure
* **/build/**: All the compiled versions of the executables so far
* **/image_outputs/**: All the produced .ppm images, since they are text based a image viewing software with support for .ppm files is necessary. Each image corresponds to the executable fot he same name

## Files
* **main.cpp**: The main function to be compiled. It is used to set up the camera viewport arguments and to set up the world by creating hittables within the world
* **common.h**: A header file to contain common constants and utility functions
* **interval.h**: A header file to define intervals between a minimum value and a maximum value
* **camera.h**: A class to set up the viewport
* **vec3.h**: A class to describe 3 dimensional vectors, along with common vector operations (dot product, cross product, etc). Also aliased as point3
* **ray.h**: A class to describe a ray with origin and destination points
* **hittable.h**: A class to describe 'hittables'. Anything that exists in the world and can be hit by a ray
* **hittable_list.h**: A class to have a vector of hittables
* **sphere.h**: A class to describe a simple sphere hittable
* **material.h**: A class to describe the material a hittable is made of. Currently deals with only reflection of rays.
