      
#include <sys/stat.h>
#include <sys/times.h>
//#include "usart.h"
#include "stm32f4xx.h"

// extern "C" int _write(int file, char *ptr, int len) {
//   (void) file;
//   (void) ptr;
//   (void) len;
// for (int i=0; i<len; ++i)
// {
//   while (!(USART2->SR & USART_SR_TXE));
//   USART2->DR = ptr[i];
// }
  
//   return len;
// }

USART_TypeDef* activeUSART = USART2; // Default to USART2

// Function to set the active USART
void setActiveUSART(USART_TypeDef* usartBase) {
    activeUSART = usartBase;
}

extern "C" int _write(int file, char *ptr, int len) {
    (void) file;
    for (int i = 0; i < len; ++i) {
        while (!(activeUSART->SR & USART_SR_TXE)); 
        activeUSART->DR = ptr[i];                 // Transmit the byte
    }
    return len;
}

extern "C" int _fstat(int fd, struct stat *st) {
  (void) fd, (void) st;
  return -1;
}

extern "C" void *_sbrk(int incr) {
  extern char _end;
  static unsigned char *heap = NULL;
  unsigned char *prev_heap;
  if (heap == NULL) heap = (unsigned char *) &_end;
  prev_heap = heap;
  heap += incr;
  return prev_heap;
}

extern "C" int _read(int fd, char *ptr, int len) {
  (void) fd, (void) ptr, (void) len;
  return -1;
}

extern "C" int _close(int file) { return -1; }
extern "C" int _isatty(int file) { return -1; }
extern "C" int _lseek(int file, int ptr, int dir) { return 0; }
extern "C" int _getpid(int file) { return -1; }
extern "C" int _kill(int pid, int sig) { return -1; }
    