# WebSocket
C++ WebSocket library for QT Creator - for internal project EuleHakenBot mainly

## Use it yourself
You can build the library by cloning this repo, opening the `WebSocket.pro` file (from top directory)
with QT Creator, selecting `WebSocket` by right-clicking on it, and hitting `Build "WebSocket"`.
Then, you can include the outcoming `.lib` file into your project.

You can also add this the WebSocket library as a submodule, which is prefered from my side.
This is possible by doing this:
* Open the directory you want to place the repo/library into (For example: `lib/`)
* Run this in your terminal:
    ```bash
        git submodules init
        git submodules add https://github.com/EuleHaken/WebSocket.git
    ```
* Create a file named, e.g. `WebSocket.pri` inside your `lib/` folder
    * That file should contain this code (you can change the `WEBSOCKET_NAMESPACE` to whatever you want):
        ```
        DEFINES += WEBSOCKET_NAMESPACE=EuleHaken
        include(../libs/WebSocket/WebSocket/WebSocket.pri)
        ```
* Now, open up the `YOUR_PROJECT.pro` file
* Add this somewhere in that file: `include(libs/WebSocket.pri)`

**If you have any issues or questions, you can create an issue here at any time**
