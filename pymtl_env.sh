# Environment sourcing for PyMTL
source venv/pymtl3/bin/activate

PYMTL_VERILATOR_INCLUDE_DIR=$(which verilator | sed 's#bin/verilator#include#g')

alias noenv="deactivate"