#include "vsync.h"
#include "display_control.h"
#include "keys.h"
#include "etchASketch.h"

u16 _key_current=0, _key_previous=0;

int main(void) {
	DISPLAY_CONTROL = DISPLAY_MODE3 | DISPLAY_LAYER_BG2 | DISPLAY_LAYER_OBJ;

	EtchASketchState state = getDefaultEtchASketchState();

	while (1) {
		vsync();
		poll_keys();

		etchASketchFrame(&state);
	}
}
