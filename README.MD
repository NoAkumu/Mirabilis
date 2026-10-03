# Mirabilis Engine
> A proprietary, in-house style game engine built for a future game of mine

## Overview

Mirabilis is a game engine designed around an editor-driven workflow and a component-based architecture, inspired by the structure and workflow of modern engines such as Unity

This engine is more focused to working with RPG games that don't need advanced Physics or Ragdolling

This project was made using SFML 3, but i plan on changing it to pure OpenGL (or Vulkan) on the future

The project is primarily intended for personal development, experimentation, and studying game engine architecture.

## Features
At the moment the engine has:
* Component-based architecture
* Object system
* Rendering system
* Input system
* Basic Physics system (Not planning this to be a Physics engine)

> Features listed above may be incomplete or still under development.

## Architecture

The engine follows an architecture centered around **Objects and Components**.

The goal is to keep the engine modular while providing a workflow where game logic is built by combining reusable components.

## Project Status

This project is currently **in development**.

APIs, systems, and internal architecture may change significantly as development continues.

## Building

### Requirements

* [SFML 3](https://github.com/SFML/SFML)
* [TinyXML2](https://github.com/leethomason/tinyxml2)

### Build
If you want to only build the game without running it run
```shell
make && make clean
```

### Run
To build and run the game just run
```shell
make && make run
```
Or build it first then run
```shell
./game.out
```

## Usage

It isn't usable to create real games at the moment, it's just the base of the engine

## Roadmap

* [x] Core engine
* [x] Component system
* [x] Rendering
    - [ ] Changing rendering system to only OpenGL without SFML
* [x] Basic Physics
* [x] Input
* [x] Camera Component
* [x] Window management
* [ ] Scene management
* [ ] Audio
* [ ] Editor
* [ ] Asset pipeline
* [ ] Scripting
* [ ] Documentation

## License

This project is proprietary software.

The source code is available for archival, educational, and personal study purposes only.

See [LICENSE](LICENSE) for the full license.