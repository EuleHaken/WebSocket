# WebSocket
C++ WebSocket for QT Creator - for internal project EuleHakenBot mainly

## Use it yourself
You have multiple choices in how you want to use the library

1. Build it yourself
    * You can build the library, and then use the `.lib` and/or the `.dll` files
   
2. Copy the repo and use as internal library
    * Copy the repo
    * Place it inside your projects dir/libs folder, for example
    
3. Use git submodules
    * Open the directory you want to place the repo/library into (For example: `libs/`)
    * Run this in your terminal/cmd:
    ```
        git submodules init
        git submodules add https://github.com/EuleHaken/WebSocket.git
    ```
    * Optionally, you can create a file, named, e.g. `WebSocket.pri` inside your `libs/` folder
    * Now, open up your `YOUR_PROJECT.pro` file
    * Add this somewhere: `include(libs/WebSocket.pri)`
    * In that `.pri` file, you can define your wanted namespace
    * Example: (put this in your `libs/WebSocket.pri` file) `DEFINES += WEBSOCKET_NAMESPACE YOUR_WANTED_NAMESPACE`
