# Input the serial port using an environment variable.
SELECTED_SERIAL_PORT=$(if $(SERIAL_PORT), $(SERIAL_PORT),notset)
SELECTED_PROJECT:=.

FQBN=esp32:esp32:esp32cam

default: build

init: config board 

config:
	@cd $(SELECTED_PROJECT) \
		&& arduino-cli config add board_manager.additional_urls https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

board:
	@cd $(SELECTED_PROJECT) \
		&& arduino-cli core update-index \
		&& arduino-cli core install esp32:
build:
	@cd $(SELECTED_PROJECT) \
		&& arduino-cli compile --build-path gen --profile esp32cam --build-property build.extra_flags="-DESP32 -Og -DCONFIG_COMPILER_CXX_EXCEPTIONS=y"  .

upload: build
	@cd $(SELECTED_PROJECT) \
		&& arduino-cli upload --build-path gen --profile esp32cam

monitor:
	@cd $(SELECTED_PROJECT) \
		&& arduino-cli monitor --profile esp32cam

usb:
	@cd $(SELECTED_PROJECT) \
		&& arduino-cli board list \
		&& ioreg -p IOUSB

