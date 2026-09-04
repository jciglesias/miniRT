# miniRT

A lightweight 3D ray-tracing project built in C, designed to render simple scenes from configuration files and explore the fundamentals of computer graphics.

## Overview

miniRT is a project focused on real-time and offline rendering techniques, with a scene parser, camera model, geometric primitives, and lighting calculations. It reads a .rt scene description, builds the corresponding 3D environment, and renders a final image using ray-casting and shading logic.

This project demonstrates core graphics concepts such as:

- geometric intersection math
- camera-to-world transformations
- light and shadow handling
- scene parsing and validation
- image generation for both display and exported output

## Features

- Parses scene files in .rt format
- Supports multiple basic 3D objects, including spheres, planes, cylinders, squares, and triangles
- Includes camera and lighting configuration
- Implements shading and visibility calculations for rendered objects
- Renders directly in a window with support for interactive viewing adjustments
- Exports rendered frames as BMP files
- Built with a custom C library and miniLibX integration

## Project Structure

- src/: rendering, parsing, validation, and event logic
- Includes/: project headers and shared declarations
- libft/: custom utility library
- minilibx-linux/: windowing and image handling
- scenes/: example configuration files for testing and demonstration

## Build

From the project root:

```bash
make
```

This compiles the project and produces the miniRT executable.

## Run

Open a scene file:

```bash
./miniRT scenes/subject.rt
```

Render and save a BMP output:

```bash
./miniRT scenes/basic_shapes/sphere_origin.rt --save
```

## Example Scenes

The repository includes sample files for a range of setups, including:

- basic geometry tests
- lighting and brightness variations
- camera and transformation examples
- multi-object compositions

## Notes

This project was developed as a graphics-focused implementation exercise and emphasizes clean scene parsing, mathematical rendering logic, and image generation from a custom scene description format.

## License

This project is intended for educational and portfolio use.
