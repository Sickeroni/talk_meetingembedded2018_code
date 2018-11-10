#!/bin/bash

#openocd -f "interface/jlink.cfg" -c "transport select swd" -f "target/klx.cfg"
openocd -f "interface/jlink.cfg" -c "transport select swd" -f "target/k60.cfg" -c "adapter_khz 5000"
