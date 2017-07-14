# MalDuino Password Grabber
Arduino sketch to program a MalDuino bad USB (lite) to download a password grabber* and send the results via email

Please read the [Arduino Project](#arduino-project) section to see how to setup your MalDuino bad USB password grabber

> *: designed to work with [NirSoft](https://nirsoft.net) password recovery tools

## Sources
The inspiration is a Rubber Ducky payload to grab passwords and send them via email but prepared for [NirSoft.net](https://nirsoft.net) tools

https://github.com/hak5darren/USB-Rubber-Ducky/wiki/Payload---download-mimikatz%2C-grab-passwords-and-email-them-via-gmail

## RubberDucky script
The file `rubber_ducky_script.txt` contains the RubberDucky script used to generate the Arduino project using the [MalDuino converter](https://malduino.com/converter)

> The generated project though, __contains two errors when generating the CTRL+A and CTRL+S combinations__ so the final project was edited to fix it.
> 
> To solve it, we used the A and S keystrokes defined in [USB HID](https://www.usb.org/developers/hidpage/Hut1_12v2.pdf) manual after the rubberducky script was transformed, adding 0x88 (136) to each keycode according to the `Keyboard::press` function design in [`lite/Keyboard.cpp`](lite/Keyboard.cpp#L253-L257)

## Arduino project
In order to control your MalDuino, the Arduino project called [`lite.ino`](lite/lite.ino) inside `lite` folder can be used to setup your MalDuino bad USB

### Project parameters
It's very important to __setup the project parameters__ in the file [`lite\Params.h`](lite/Params.h) for a succesful execution

#### Which applications to use
In order to grab passwords, we tested the project with [nirsoft.net](https://nirsoft.net) [WebBrowserPassView](https://nirsoft.net/utils/web_browser_password.html) but it may work with other NirSoft's applications as they all work the same way
