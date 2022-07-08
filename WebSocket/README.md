# WebSocket
C++ WebSocket for QT Creator - for internal project EuleHakenBot mainly

## Use it yourself
Recommended way:
* Open the directory you want to place the repo/library into (For example: `libs/`)
* Run this in your terminal/cmd:
    ```
        git submodules init
        git submodules add https://github.com/EuleHaken/WebSocket.git
    ```
* Create a file named, e.g. `WebSocket.pri` inside your `libs/` folder
    * That file should contain this code (you can change the `WEBSOCKET_NAMESPACE` to whatever you want):
        ```
        DEFINES += WEBSOCKET_NAMESPACE=EuleHaken
        include(../libs/WebSocket/WebSocket.pri)
        ```
* Now, open up your `YOUR_PROJECT.pro` file
* Add this somewhere: `include(libs/WebSocket.pri)`

**If you have any issues or questions, you can create an issue here at any time**
