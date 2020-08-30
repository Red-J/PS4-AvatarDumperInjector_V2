# PS4-AvatarDumperInjector_V2
Avatar Dumper and injector payload for Ps4 v2

This version of payload will work on 4.55 (untested),4.74(untested),5.05(working) or 6.72(working).

You must use a bin loader to use it at the moment

The payload will check if an USB key is connected and contain "Avatar_Inject" folder.               

Files needed in Avatar_Inject folder:avatar.png,avatar64.dds,avatar128.dds,avatar260.dds,avatar440.dds                                                            

Change since v1:                                                                                                                     
-The payload loop to wait your usb key                                                                                                          
-The USB port is detected dynamicly                                                                                                                  
-Avatar_Inject content will be copy to connected user dynamicly                                                                                            
-An avatar backup will be done on usb key before the copy process                                                                                                    


When the copy is done, you must change user or reboot the ps4 to view the change.                                                            
This code is inspired by history_blocker from stooged
Code is compiled with Stooged payload sdk
It can be ported easily on Scene collective sdk but have issue with this sdk on my OS.

Greets:Stooged for history blocker and a lot of code who inspired me, Al-Azif for his help ,Team eversion for universal fw things, DefaultDNB and all people who work really on ps4 scene and don't just talk ! 
You know who your are;)

Red-J
