# SmailBox - Sigfox powered mailbox

## Description
Tired of checking your mailbox every day? Upgrade it to the next level and get push notifications every time you have got a mail.

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

![Sigfox callback](https://cloud.githubusercontent.com/assets/9611327/16817305/80c1707a-4942-11e6-87d0-3fc3f9815a33.png)

### Wiring
![fritzing diagram](https://cloud.githubusercontent.com/assets/9611327/16817309/8779244e-4942-11e6-9e4e-41f5b9b87b8f.png)
