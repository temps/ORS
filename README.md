# Oil Rig Simulator Prototype

This repository contains a minimal C++ prototype for the Oil Rig Simulator game described in the accompanying UML documentation.

## Building

Ensure you have a C++17 compiler. To build the demo executable, run:

```bash
make
```

This will produce an executable named `ors`.

## Running

Execute the program after building:

```bash
./ors
```

The demo now simulates several in-game days. It demonstrates hiring staff, paying daily wages, executing multi-day contracts that yield revenue and reputation, producing oil each day and updating the market price.

## Unreal Engine Project

A basic Unreal Engine project is provided for further development. To open it, ensure Unreal Engine 5 is installed and run:

```bash
"<path_to_unreal>/UE5Editor" OilRigSimulator.uproject
```

The core game code resides in `Source/OilRigSimulator`. Build files like `OilRigSimulator.Build.cs` are included to compile the module within Unreal.
