# OpenGLWindow Class
The OpenGLWindow class is a Qt widget that extends QOpenGLWidget and provides an OpenGL-based rendering environment. This class is designed for visualizing 3D scenes and handling user interactions such as zooming and mouse movement.

# Overview
The OpenGLWindow class encapsulates the following functionalities:

+ Constructor: Initializes the OpenGLWindow instance with a specified background color and parent widget.
+ Destructor: Cleans up resources when the OpenGLWindow instance is destroyed.
+ setVectorOfLines(): Sets the vector of lines for rendering.
+ setColorOfLines(): Sets the color of lines for rendering.
+ updateData(): Updates the data, including vertices and colors, for rendering.
+ paintGL(): Overrides the default paintGL method to handle OpenGL rendering.
+ initializeGL(): Overrides the default initializeGL method to perform OpenGL initialization.
+ shaderWatcher(): Monitors shader files for changes and reloads them.
+ mouseMoveEvent(): Handles mouse move events for interaction.
+ zoomIn(): Zooms in on the scene.
+ zoomOut(): Zooms out from the scene.
+ wheelEvent(): Handles wheel events for zooming.
+ readShader(): Reads a shader from a file.
# Usage
To use the OpenGLWindow class:

Instantiate an OpenGLWindow object, providing the background color and parent widget.<br>
Use the provided methods (setVectorOfLines(), setColorOfLines(), updateData()) to set up or update the data for rendering.<br>
Interact with the scene using mouse events and zoom functionalities.<br>
