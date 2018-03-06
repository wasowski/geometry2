#!/bin/sh

echo Starting: $*
$*
exit_status=$?
if [ ${exit_status} -eq 1 ]; then
  # sleep so that the dummy test can complete safely and kill us
  sleep 20s
fi
exit ${exit_status}
