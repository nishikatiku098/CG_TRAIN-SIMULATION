# CG_TRAIN-SIMULATION

This project is all about modelling with features of OpenGL .The starting point is a small virtual space that consists of a grassy plain and a simple parallel railway track running on it. It also consists of a clear sky. The train consists of an engine attached to two bogies and electric wires are attached to the train for power supply. Engines as well as the bogies contains wheels rotating as well as translating in forward direction. The train runs in two environments upon press of a key. Upon pressing ‘s’ or ‘S’, it starts raining and upon pressing ‘t’ or ‘T’ the rain stops.

For each of the component present in the virtual space, a function has been written which consists of the drawing code. Each object is defined using the coordinate system that makes modelling convenient. Sky, grass, railway track, engine and bogies are drawn by using GL_QUADS primitive one or more number of times. Rain is drawn by using GL_POINTS primitive. Some more elements are added to the engine to make it look closer to a real world engine by using a user-defined function which contains the drawing code, for example of a semicircle in order to make it look a little curved. Wheels are drawn using a user-defined function which contains code for drawing a circle. Parallel slant lines are drawn on the railway track using GL_LINES primitive to draw a single line and is repeated over and over again using loops to create a set of parallel slant lines.

After the static object is drawn, the next step is giving linear motion to the train over a straight track. And in this way the simulation is done.

The IDE used is Microsoft Visual Studio 2017.
