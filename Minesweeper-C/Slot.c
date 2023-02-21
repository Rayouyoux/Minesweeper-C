#include <stdio.h>
#include "Slot.h"

void DisplaySlot(GridSlot slot) {
	printf("\nSlot at pos(x: %d, y: %d) - isBomb: %d - contains: %d nearby bombs - isRevealed: %d\n", slot.x, slot.y, slot.isBomb, slot.bombs, slot.isRevealed);
}