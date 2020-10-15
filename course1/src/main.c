#include "memory.h"
#include "platform.h"
#include "course1.h"

int main(void) {
 
#ifdef COURSE1

	course1();
#endif 
/*This way we can have a simple main() function that can switch which course deliverable we wish to call by specifying the -DCOURSE1 compile time switch.*/
  return 0;
}
