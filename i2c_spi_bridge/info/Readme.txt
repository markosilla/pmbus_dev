

Custom built kernel module, except some changes in spi-sc18is602

Use ../dev.sh to build/develop

Use ../flash_sem/flash_sem_file.sh for flashing

Hi Sten,

I have attached the 2 patch we have made on the spi bridge driver, which is located at drivers/spi/spi-sc18is602.c in kernel source tree
Depending on which version of the kernel you have this may apply smooth or not.
If you have any issues applying it or building the module please ask, we try to help you
/Gabor
On 05/09/2016 04:05 PM, Miro Ranilovic wrote:
If all the changes are done purely to spi-sc18is602.c (as far as I remember, they are), sure. Just patch and rebuild that one as a kernel module. We *want* the same /CS handling on the PI, since the PI is going to be using the same bridge. This does not affect the PI itself, since it doesn't use these. Regarding the bind-unbind, this is used so the driver does not need the standard early resource allocation, so rebuilding PI low level inits and DTB is not needed, just the module plus the bind-unbind sysfs calls areshould be enough.
 
    Miro
 
From: Gábor Tóth 
Sent: Monday, May 09, 2016 3:50 PM
To: Miro Ranilovic; Sten Leima
Cc: Marko Silla
Subject: Re: I2C SPI bridge
 
hehe, I told Sten that you may point back at me :)
I remember one thing that we made in the bridge driver to handle the chip select properly (I mean according to how we implemented the hardware)
And there was a hell lot of stuff you added to the mtd driver (bind/unbind/etc)
Can that be redone in a stock linux as well?
/gabor
On 05/09/2016 03:45 PM, Miro Ranilovic wrote:
Sure. Gabor has the code. You just have to build it as a kernel module. I don't remember there being a lot of hardcoded things in the driver, but some tinkering may be required.
 
    Miro
 
From: Sten Leima 
Sent: Monday, May 09, 2016 3:03 PM
To: Miro Ranilovic
Cc: Marko Silla; Gábor Tóth
Subject: I2C SPI bridge
 
Hi Miro,
 
I’m one of the production test developers for Athena storage boards and I have a problme with which I hope you can help.
In the SEM board fixture we will not have a SIM reference, instead we use a Raspberry Pi for all I2C and PMB actions and we would like to use it also for reprogram SEM flash through the I2C-SPI bridge.
It would be really cool if we could reuse the solution you developed for SIM, but just execute it on a Rpi. Can you help?
 
Regards,
Sten
