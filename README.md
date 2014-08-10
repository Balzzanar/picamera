Pi Camera
========

### Application to operate the camera of the raspberry pi.

###### Arguments
* **-loop** If set the application will lopp indef with a 7sec wait after each command. 
* **-p [path]** The path to where the media shall be saved, where **[path]** is the root path.
* **-l [sec]** The lengths of the video in seconds, where **[sec]** is the seconds.
* **-a [action]** The Action the application shall conduct, where **[action]** is 'img' or 'vid'.

###### Example
``` bash
wCamera -loop -p /media/usb/images/ -l 10 -a vid
```
