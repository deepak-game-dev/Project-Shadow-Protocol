# Project Shadow Protocol

**A C++ Gameplay Engineering Prototype**

Project Shadow Protocol is a console-based C++ gameplay prototype developed in Visual Studio to explore core gameplay engineering concepts, including player movement, enemy AI, collision detection, combat, and mission progression.

The project demonstrates how multiple gameplay systems interact within a mission-based scenario, with a focus on gameplay architecture, reusable systems, and real-time game-loop processing.

## Overview

In Project Shadow Protocol, the player navigates a mission environment, encounters enemy AI, engages in combat, and interacts with mission objectives to complete the extraction sequence.

The project focuses on implementing gameplay mechanics and understanding how individual systems communicate to create a functional gameplay experience.

## Gameplay Features

- **Player System:** Manages player health and combat-related functionality.
- **Enemy AI System:** Implements state-based enemy behavior, including idle, chase, investigate, and attack states.
- **Movement System:** Uses acceleration, velocity, and delta time to process player movement.
- **Collision Detection:** Implements Axis-Aligned Bounding Box (AABB) collision checks and movement resolution.
- **Input System:** Handles keyboard input for player controls and gameplay interactions.
- **Combat System:** Supports player attacks and combat-related gameplay logic.
- **Interaction System:** Enables interaction with collectible objects and mission objectives.
- **Mission System:** Requires the player to collect a research drive and reach the extraction area.
- **Game Loop:** Updates gameplay systems using delta time to support time-based movement and gameplay processing.

## Technical Implementation

### Gameplay Architecture

The project separates gameplay responsibilities into distinct systems, helping demonstrate how player behavior, enemy AI, movement, collision, combat, and mission progression work together.

### Enemy AI and State Machines

Enemy behavior is organized around distinct AI states:

- **Idle:** The enemy waits or remains inactive.
- **Chase:** The enemy pursues the player.
- **Investigate:** The enemy investigates a previously detected player location.
- **Attack:** The enemy engages the player when appropriate.

State-based behavior helps organize AI decision-making and makes enemy logic easier to extend and maintain.

### Movement and Collision

The movement system uses acceleration, velocity, and delta time to calculate movement over time.

AABB collision checks and movement resolution help detect and handle collisions between gameplay entities.

### Mission Progression

The mission objective connects the interaction and mission systems. The player must collect a research drive and reach the extraction area to complete the mission.

## Technologies Used

- **Language:** C++
- **IDE:** Microsoft Visual Studio
- **Platform:** Windows
- **Input Handling:** Windows API
- **Core Concepts:** Object-Oriented Programming, Gameplay Architecture, State Machines, Collision Detection, Delta Time, and Game Loops

## Controls

| Key | Action |
|---|---|
| W / A / S / D | Move |
| F | Attack |
| E | Interact with the research drive or extraction point |
| ESC | Exit the game loop |

## How to Run

1. Clone or download the repository.
2. Open the solution file in Microsoft Visual Studio.
3. Select a suitable Windows build configuration.
4. Build the solution.
5. Run the compiled application.

## Project Goals

Project Shadow Protocol is part of my journey toward becoming an AAA Gameplay Programmer.

The project provides practical experience with:

- Writing gameplay logic in C++.
- Designing and organizing gameplay systems.
- Implementing state-based enemy AI.
- Understanding movement, collision detection, and combat.
- Integrating multiple systems into a functional gameplay loop.
- Managing mission objectives and progression.
- Building a foundation for more advanced gameplay engineering projects.

## Demo Video

▶️ [Watch Project Shadow Protocol — C++ Gameplay Programming Demo](https://youtu.be/ktnt_XhmTiI)

## Portfolio

🌐 **[Visit My Game Development Portfolio](https://deepak-game-dev.github.io/)**

Explore my gameplay programming projects, demonstrations, and development work.



## Future Improvements

- Introduce a graphical game environment.
- Improve combat targeting and attack-range validation.
- Enhance enemy navigation and obstacle avoidance.
- Expand enemy AI behaviors and decision-making.
- Add additional gameplay scenarios and mission objectives.
- Explore integration with a full game engine.

## Author

**Deepak K**

GitHub: [https://github.com/deepak-game-dev](https://github.com/deepak-game-dev)

---

*Project Shadow Protocol — Building gameplay systems through C++ and practical game engineering.*
