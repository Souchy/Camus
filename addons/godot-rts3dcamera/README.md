# Godot RTS 3D Camera

This is a couple of scripts for controlling a configurable 3D Camera for RTS games.
![example](/images/example.gif)

It includes:

* Size configurable edge pushing camera movement
* Smooth stopping
* Free look rotation
* Zooming
* Sensibility configuration
* Key configuration
* Mobile support with:
  * Swipe to move
  * Pinch to zoom
  * Free look rotation


## Installation

1. Add CharacterCamera.gd and CameraInput.gd into your project.
1. Connect all the signals in CameraInput.gd you need to the homologues functions in CameraController.gd:
![signals](/images/signals.png)
1. Add an action in Project->Project Settings->Input Map called "ToggleCameraAction" and bind any key you want.
## Usage

In the included example project you can:
### On desktop:
* Move the camera placing the cursor on the edge or near them depending on the current configured edge size.
* Hold mouse middle button and move the cursor around to rotate the camera view.
* Use the mouse wheel to zoom in and out.

### On mobile:
* Swipe to move the camera.
* Press to the toggle button in the bottom left to toggle camera mode.
* While in rotation mode, slide your finger on the screen to rotate the camera view.
* Pinch to zoom.

### Change action toggle key
You can change the action toggle hotkey in Project->Project Settings->Input Map
![signals](/images/config_rotation_key.gif)

## License
[MIT](https://choosealicense.com/licenses/mit/)