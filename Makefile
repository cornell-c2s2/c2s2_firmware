# Makefile to install dependencies for testing our Caravel board

# Use the same subshell for venv altering
.ONESHELL:

BREW_VERSION := $(shell brew --version 2> /dev/null)
VERILATOR_VERSION := $(shell verilator --version 2> /dev/null | cut -d " " -f2)
VENV_PYTHON := $(PWD)/venv/pymtl3/bin/python3

#---------------------------------
# Homebrew Installation
#---------------------------------

brew:
	@echo "[INFO] Finding Homebrew..."
ifdef BREW_VERSION
	@echo "[INFO] - Homebrew found!"
else
	@echo "[INFO] - Homebrew not found: Installing Homebrew"
	@/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
endif

#---------------------------------
# Python3 Installation
#---------------------------------



#---------------------------------
# Verilator Installation
#---------------------------------

verilator: brew
	@echo "[INFO] Finding Verilator..."
ifdef VERILATOR_VERSION
ifeq ($(VERILATOR_VERSION),4.036)
	@echo "[INFO] - Verilator 4.036 found!"
else
	@echo "[INFO] - Verilator found, but not version 4.036"
	@echo "[INFO]   Pymtl currently requires version 4.036. Please uninstall verilator and try again"
	@exit 1
endif
endif

ifndef VERILATOR_VERSION
	@echo "[INFO] - Verilator not found; Installing Verilator 4.036..."

# Here, we can now install Verilator using Homebrew
# Homebrew's default version is too advanced, so we're going to have to get the old Ruby file ourselves
	@curl https://raw.githubusercontent.com/Homebrew/homebrew-core/86447d2239a9ebc4d98607fd4ae5b034d3349c02/Formula/verilator.rb > verilator.rb

# Remove the "bottle do" code - it's no longer used by Homebrew - see https://github.com/orgs/Homebrew/discussions/2429
	@sed -i '' '7,11d' verilator.rb

# Now we can use the Ruby file to install it with Homebrew
	@brew install verilator.rb
	@rm verilator.rb
	@echo "[INFO] - Verilator 4.036 Installed!"
endif

#---------------------------------
# Build our Virtual Environment
#---------------------------------

.build_venv:
	@echo "[INFO] Building Python Virtual Environment in venv/pymtl3..."
	@mkdir -p venv
	@python3 -m venv venv/pymtl3
	@echo " - Virtual Environment Build!"

venv:
	@echo "[INFO] Building Python Virtual Environment in venv/pymtl3..."
	@mkdir -p venv
	@python3 -m venv venv/pymtl3
	@echo " - Virtual Environment Build!"

# Install PyMTL3
	@echo "Installing PyMTL3 in Virtual Environment.."
	@$(VENV_PYTHON) -m pip install pymtl3
	@echo "[INFO] - PyMTL3 Installed"

# Install Graphviz
	@echo "Installing Graphviz in Virtual Environment..."
	@$(VENV_PYTHON) -m pip install graphviz
	@echo "[INFO] - Graphviz Installed"
	
# Install FTDI
	@echo "Installing PyFTDI in Virtual Environment..."
	@$(VENV_PYTHON) -m pip install pyftdi
	@echo "[INFO] - PyFTDI Installed"
	