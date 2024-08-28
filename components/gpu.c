#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../slstatus.h"
#include "../util.h"

const char *gpu_temp(const char *unused) {

  int temp;
  const char *result;
  const char *cmd =
      "nvidia-smi --query-gpu=temperature.gpu --format=csv,noheader";

  result = run_command(cmd);
  temp = atoi(result);
  return bprintf("%ju", temp);
}
