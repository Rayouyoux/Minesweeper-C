typedef struct GridSlot {
	int x;
	int y;
	int isBomb; // False
	int isRevealed;
	int bombs;
} GridSlot;

void DisplaySlot(GridSlot grid);