// Rapsberry Pi: I2C in C - Versione 0.61 - Luglio 2013
// Copyright (c) 2013, Vincenzo Villa (http://www.vincenzov.net)
// Creative Commons | Attribuzione-Condividi allo stesso modo 3.0 Unported.
// Creative Commons | Attribution-Share Alike 3.0 Unported
// http://www.vincenzov.net/tutorial/elettronica-di-base/RaspberryPi/i2c-c.htm

// Compile:  gcc check_I2C.c -std=c99 -o check_I2C
// Run as user with R&W right on /dev/i2c-* (NOT ROOT!)
// vv@vvrpi ~ $ ./check_I2C 
// Check whether some i2c functionality are present

#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>

#define I2C_ADDR 0x4B				// Device adress

#define LM92_TEMP 0                             // Temperature register (see data sheet)
#define LM92_RES 0.0625                         // Resolution (see data sheet)

static const char *device = "/dev/i2c-1";	// I2C bus

static void exit_on_error (const char *s)	// Exit and print error code
{ 	perror(s);
  	abort();
} 

int main(int argc, char *argv[])
{
	int fd;
	
	int32_t functionality;

        
        printf("Rapsberry Pi: I2C in C - Versione 0.61 - Luglio 2013\n");
        printf("Copyright (c) 2013, Vincenzo Villa (http://www.vincenzov.net)\n");
        printf("Creative Commons | Attribuzione-Condividi allo stesso modo 3.0 Unported.\n");
        printf("Creative Commons | Attribution-Share Alike 3.0 Unported\n");
        printf("http://www.vincenzov.net/tutorial/elettronica-di-base/RaspberryPi/i2c-c.htm\n\n");                                       

       	// Open I2C device
       	if ((fd = open(device, O_RDWR)) < 0) exit_on_error ("Can't open I2C device");

        if (ioctl(fd, I2C_FUNCS, &functionality) < 0)  exit_on_error ("Can't use I2C_FUNCS ioctl");
        
        printf("Raw data from driver (I2C_FUNCS): 0x%.8X\n", functionality);        
        
        printf("\nI2C_FUNC_I2C ");
        if ( I2C_FUNC_I2C & functionality) printf("\t\t\t\tOK");      

        printf("\nI2C_FUNC_10BIT_ADDR ");
        if ( I2C_FUNC_10BIT_ADDR & functionality)  printf("\t\t\tOK");
                                                                                                        
        printf("\nI2C_FUNC_PROTOCOL_MANGLING ");                 
        if ( I2C_FUNC_PROTOCOL_MANGLING & functionality) printf("\tOK");                   

//        printf("\nI2C_FUNC_NOSTART ");
//        if ( I2C_FUNC_NOSTART & functionality) printf("\tOK");
                
        printf("\nI2C_FUNC_SMBUS_QUICK ");
        if ( I2C_FUNC_SMBUS_QUICK & functionality) printf("\t\t\tOK");
                
        printf("\nI2C_FUNC_SMBUS_READ_BYTE ");
        if ( I2C_FUNC_SMBUS_READ_BYTE & functionality) printf("\t\tOK");
                
        printf("\nI2C_FUNC_SMBUS_WRITE_BYTE ");
        if ( I2C_FUNC_SMBUS_WRITE_BYTE & functionality) printf("\t\tOK");
                                                               
        printf("\nI2C_FUNC_SMBUS_READ_BYTE_DATA ");
        if ( I2C_FUNC_SMBUS_READ_BYTE_DATA & functionality) printf("\t\tOK");
                
        printf("\nI2C_FUNC_SMBUS_WRITE_BYTE_DATA ");
        if ( I2C_FUNC_SMBUS_WRITE_BYTE_DATA & functionality) printf("\t\tOK");
                
        printf("\nI2C_FUNC_SMBUS_READ_WORD_DATA ");
        if ( I2C_FUNC_SMBUS_READ_WORD_DATA & functionality) printf("\t\tOK");

        printf("\nI2C_FUNC_SMBUS_WRITE_WORD_DATA ");
        if ( I2C_FUNC_SMBUS_WRITE_WORD_DATA & functionality) printf("\t\tOK");

        printf("\nI2C_FUNC_SMBUS_PROC_CALL ");  
        if ( I2C_FUNC_SMBUS_PROC_CALL & functionality) printf("\t\tOK"); 
                
        printf("\nI2C_FUNC_SMBUS_READ_BLOCK_DATA ");  
        if ( I2C_FUNC_SMBUS_READ_BLOCK_DATA & functionality) printf("\t\tOK");                                                                                                                 

        printf("\nI2C_FUNC_SMBUS_WRITE_BLOCK_DATA ");  
        if ( I2C_FUNC_SMBUS_WRITE_BLOCK_DATA & functionality) printf("\tOK");                                                
 
        printf("\nI2C_FUNC_SMBUS_READ_I2C_BLOCK ");  
        if ( I2C_FUNC_SMBUS_READ_I2C_BLOCK & functionality) printf("\t\tOK"); 
 
        printf("\nI2C_FUNC_SMBUS_WRITE_I2C_BLOCK ");  
        if ( I2C_FUNC_SMBUS_WRITE_I2C_BLOCK & functionality) printf("\t\tOK");         
        
        printf("\n\n");

        if (ioctl( fd, I2C_PEC, 1) < 0) printf("Failed to enable PEC\n");
        else printf("PEC enabled\n\n"); 

        //data = i2c_smbus_read_byte_data ( fd , 0x0a );

        close(fd);

	return (0);
}