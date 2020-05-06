    #include <stdio.h>   /* Standard input/output definitions */    
    #include <string.h>  /* String function definitions */    
    #include <unistd.h>  /* UNIX standard function definitions */    
    #include <fcntl.h>   /* File control definitions */    
    #include <errno.h>   /* Error number definitions */    
    #include <termios.h> /* POSIX terminal control definitions */    
    
    /*     * 'open_port()' − Open serial port 1.     *     
    * Returns the file descriptor on success or −1 on error.     */    
   
   int fd; /* File descriptor for the port */
   unsigned char bufptr;
   int reader;
   int n;
   int m;
   
   int open_port(void)    
   {            
     //fd = open("/dev/bus/usb/003/006", O_RDONLY | O_NOCTTY | O_NDELAY);
     //fd = open("/dev/ttyS0", O_RDWR | O_NOCTTY | O_NDELAY);
     fd = open("/dev/ttyAMA0", O_RDWR | O_NOCTTY | O_NDELAY);   
         
     if(fd == -1) 
     {       
       /*        * Could not open the port.        */        
       perror("open_port: Unable to open /dev/ttyAMA0 − ");      
     }      
     
    return (fd);    
  }

  int close_port(void)
  {
    close(fd);
    return (fd);
  }

  int write_port(void)
  {
    n = write(fd, "1", 1);
    if (n < 0)
    fputs("write() of 1 bytes failed!\n", stderr);

    return(fd);
  }

  int write0_port(void)
  {
    m = write(fd, "0", 1);
    if (m < 0)
    fputs("write() of 1 bytes failed!\n", stderr);
    return(fd);
  }

  int main()
  {
    struct termios options;
    /*
    * Get the current options for the port...
    */

    tcgetattr(fd, &options);

    /*
    * Set the baud rates to 115200...
    */
    cfsetispeed(&options, B115200);
    cfsetospeed(&options, B115200);

    /*
    * Enable the receiver and set local mode...
    */
    options.c_cflag |= (CLOCAL | CREAD);

    /*
    * Set to 8 data bits
    */
    options.c_cflag &= ~CSIZE; /* Mask the character size bits */
    options.c_cflag |= CS8;    /* Select 8 data bits */

    /*
    * Set to no parity
    */
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;

    /*
    * Set the new options for the port...
    */
    tcsetattr(fd, TCSANOW, &options);


    printf("Serial reader has started...\n\n");
    open_port();
    sleep(1);
    while(1)
    {
      //open_port();
      write_port();
      sleep(1);
      write0_port();
      //close_port();
    }
    close_port();

    return 0;
  }