# TrafficJam Application
The TrafficJam application is a graphical user interface (GUI) program built using the Qt framework. It simulates a traffic scene with cars represented in a 3D environment. Users can interact with the simulation by moving and selecting cars.

# Overview
The TrafficJam class encapsulates the main functionalities of the application, including:

+ Constructor: Initializes the TrafficJam instance.
+ Destructor: Cleans up resources when the TrafficJam instance is destroyed.
+ setupUi(): Sets up the user interface (UI) elements.
+ readOBJ(): Reads the OBJ file of a car.
+ sceneStatic(): Renders the static scene of cars.
+ UpperMove(): Moves the selected car in the upward direction.
+ DownMove(): Moves the selected car in the downward direction.
+ LeftMove(): Moves the selected car to the left.
+ RightMove(): Moves the selected car to the right.
+ selectCar(): Allows the user to select a specific car from the dropdown menu.
+ stop(): Stops the game.
# User Interface
The UI components include:
+ OpenGLWindow: Renders the 3D scene.
+ Start, Top, Down, Stop, Select buttons: Control the simulation and car movements.
+ Dropdown menu: Allows the user to select a specific car.
### Methods
+ addVerticesColor()
Adds vertices along with colors to mVertices and mColors for rendering in OpenGLWindow.
+ addVertices()
Adds vertices to mVertices for rendering in OpenGLWindow.
+ bbox_creator()
Creates bounding boxes for cars.
+ readTxt()
Reads a text file.
+ isMovable()
Checks if the selected car is movable.
+ isMovableAroundBoundaryY()
Checks if the selected car is movable around the Y-axis boundary.
+ isMovableAroundBoundaryX()
Checks if the selected car is movable around the X-axis boundary.
### Usage
To use the TrafficJam application:
Instantiate a TrafficJam object.<br>
Call the setupUi() method to set up the UI.<br>
Interact with the simulation using the provided buttons and dropdown menu.<br>
