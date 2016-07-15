# SmailBox - Sigfox powered mailbox

## Description
Tired of checking your mailbox every day? Upgrade it to the next level and get push notifications every time you have got a mail.

This is very simple demo, planed improvements:
- Optimize power consumption
- Send notification when someone open the mailbox and you don't need to check it
- Use NFC on SmartEverything to identify who collects the mails (wife, son, daughter, dog:) - NFC tag on keyring
- Add Sketch for Akeru or other boards 
- Ideally create small Arduino based hw prototype to be build in into mailbox for years:)

## Getting the parts
- 1 SmartEverything board (http://www.smarteverything.it)
- 1 Snap action switch (but you can use reed switch, tilt sensor, optical gate - depends on construction of your mailbox)
- 1 100 Ω resistor


### PushOver
- Login/Sign up to http://pusover.net
- Create new app - https://pushover.net/apps/build and write/copy app TOKEN somewhere you will need it in the next step
- Setup push over url by following scheme and replace %TOKEN% and %USER% with your own values (USER key can be found in the dashboard https://pushover.net/dashboard)
```
https://api.pushover.net/1/messages.json?token=%TOKEN%&user=%USER%&message='You've got mail snr: {snr}'
```
For more options/parameters check https://pushover.net/api

### Sigfox
-  Login into Sigfox [Backend](https://backend.sigfox.com)
-  Configure callback to POST URL with pushover url from the previous step
(open [List of devices](https://backend.sigfox.com/devicetype/list click o) click on device name and in the left menu, select Callbacks)

![Sigfox callback](https://cloud.githubusercontent.com/assets/9611327/16817305/80c1707a-4942-11e6-87d0-3fc3f9815a33.png)

### Wiring
Its really simple, just snap action switch and the pull down resistor
![fritzing diagram](https://cloud.githubusercontent.com/assets/9611327/16817309/8779244e-4942-11e6-9e4e-41f5b9b87b8f.png)

### Apps
- Download PushOver app and try it
![Pushover app](https://cloud.githubusercontent.com/assets/9611327/16881819/3b48a92a-4abc-11e6-9999-676b986881a8.png)
