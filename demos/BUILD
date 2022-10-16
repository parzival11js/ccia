cc_library(
  name = "threadsafe_stack",
  srcs = [],
  hdrs = ["threadsafe_stack.h",],
  deps = [],
  #linkopts = ["-lpthread"],
)

cc_binary(
  name = "threadsafe_stack_test",
  srcs = ["threadsafe_stack_test.cc"],
  deps = [":threadsafe_stack",],
  linkopts = ["-lpthread"],
)