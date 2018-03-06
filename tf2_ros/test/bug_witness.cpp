#include <cstdio>
#include "ros/ros.h"

namespace bug_witness {

  void validate (char ** argv, ...)
  {
    // Only works for this file at this time (three arguments in both call sites)
    va_list valist;
    #pragma GCC diagnostic ignored "-Wvarargs"
    va_start(valist, 3); 
    // Skip the format string
    va_arg(valist, const char *);
    const char * s1 = va_arg(valist, const char *);
    const char * s2 = va_arg(valist, const char *);

    // The only case in which ROS_FATAL is called in this file:
    ROS_ASSERT_MSG (strcmp (s1,s2) == 0, "I expected '%s' and '%s' be the same", s1, s2);
    // Never fails as rostest adds parameters:
    ROS_ASSERT (s2 != NULL); 
    // luckily works in both cases, once we asserted the above:
    ROS_ASSERT (strcmp (s2,argv[8]) == 0); 

    va_end(valist);
  }

}
