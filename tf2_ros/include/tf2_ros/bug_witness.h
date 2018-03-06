namespace bug_witness {

  void validate (char ** argv, ...);

} 

// Redefine ROS_FATAL to intercept the problem
#undef ROS_FATAL
#define ROS_FATAL(...) {\
  bug_witness::validate(argv, __VA_ARGS__);\
  ROS_LOG(::ros::console::levels::Fatal, ROSCONSOLE_DEFAULT_NAME, __VA_ARGS__); \
}
