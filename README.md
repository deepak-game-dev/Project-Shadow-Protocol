# Project Shadow Protocol

A C++ gameplay prototype built to explore core gameplay engineering concepts, including player movement, enemy AI, collision detection, combat, and mission interactions.

## Overview

Project Shadow Protocol is a console-based gameplay prototype developed in C++ using Visual Studio. It demonstrates how different gameplay systems work together in a simple mission-based scenario.

## Features

- **Player System:** Health and combat functionality.
- **Enemy AI:** State-based behavior with idle, chase, investigate, and attack states.
- **Movement System:** Acceleration, velocity, and movement based on delta time.
- **Collision Detection:** Axis-aligned bounding box (AABB) collision checks and movement resolution.
- **Input System:** Keyboard input handling.
- **Interaction System:** Collectible-object interaction and mission progression.
- **Mission System:** Collect a research drive and reach the extraction area.
- **Game Loop:** Updates gameplay systems using delta time.

## Technologies

- C++
- Visual Studio
- Windows API for keyboard input

## How to Run

1. Clone or download this repository.
2. Open the solution file in Visual Studio.
3. Select a suitable Windows build configuration.
4. Build the solution.
5. Run the compiled application.

## Controls

- **W / A / S / D:** Move
- **F:** Attack
- **E:** Interact with the research drive or extraction point
- **ESC:** Exit the game loop

## Project Purpose

This project is part of my journey toward becoming a Gameplay Programmer. It helps me practise C++, gameplay architecture, AI state machines, collision handling, and the integration of multiple gameplay systems.

## Author

Deepak K

- GitHub: https://github.com/deepak-game-dev

## Future Improvements

- Add a graphical game environment.
- Improve combat targeting and attack-range validation.
- Enhance enemy navigation and obstacle avoidance.
- Add more gameplay scenarios and mission objectives.
