#FIRMWARE TEST # 1
![Instructions](https://github.com/kbickham/Coding-Challenges-and-Tests/blob/master/Embedded%20C%20and%20C%2B%2B/Timed%20Problems/Firmware%20Test%201/firmwaretest1.PNG)


This is a copy of a firmware I have completed for an entity that I will not reveal.
I do not have access to the code I actually submitted, as  I was too thoughtless to log on here and upload it
before I left the testing location. I have recreated the code as best I could.

Problems with this solution:

1.) I did not enumerate the states on the k4 button state machine (runs sequence on the 3 leds) 
2.) I did not modularize the code very well. I very much like the philosophy of using a front end/control function to set flags,
  and then having a seperate function that is dedicated to enacting output. This has proben robust and stable for me in the past.
3.) Unused variables in the structs I have defined for the buttons and leds

I will return to this problem at some point and attempt to write a better more efficient solution.


