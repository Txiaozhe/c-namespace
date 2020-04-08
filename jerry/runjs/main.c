#include "jerryscript.h"

int main()
{
  const jerry_char_t scripts[] = "var str = 'hello world!'";
  bool ret_value = jerry_run_simple (scripts, sizeof (scripts) - 1, JERRY_INIT_EMPTY);
  return (ret_value ? 0 : 1);
}
