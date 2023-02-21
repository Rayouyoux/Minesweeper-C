#include <stdio.h>
#include <stdlib.h>
#include "Helpers.h"
#include "Slot.h"

#define GRID_SIZE 10
#define SQUARED_SIZE GRID_SIZE * GRID_SIZE

// Declare Main Functions
void InitGrid(GridSlot* grid);
int GetArrayPosition(i, j);
GridSlot* GetValue(int x, int y, GridSlot* grid); // Besoin de retourner l'adresse avec * ?
void SetValue(GridSlot newValue, int x, int y, GridSlot* grid);
void DisplayGrid(GridSlot* grid);

int main() {
	GridSlot oGrid[SQUARED_SIZE];
	InitGrid(oGrid);
	// Place bombs
	// Determiner les bombes

	DisplayGrid(oGrid);

	return 0;
}

/// <summary>
/// Return a newly created grid based on the GRID_SIZE
/// </summary>
/// <returns></returns>
void InitGrid(GridSlot* grid) {
	for (unsigned int i = 0; i < GRID_SIZE; i++)
	{
		for (unsigned int j = 0; j < GRID_SIZE; j++)
		{
			GridSlot oValue;
			oValue.x = i;
			oValue.y = j;
			oValue.isBomb = 0;
			oValue.isRevealed = 1;
			oValue.bombs = 0;
			SetValue(oValue, i, j, grid);
		}
	}
}

/// <summary>
/// Return the one-dimensional position from a two-dimensional coordinates grid
/// </summary>
/// <param name="i"></param>
/// <param name="j"></param>
/// <returns></returns>
int GetArrayPosition(int i, int j) {
	return i * GRID_SIZE + j;
}

/// <summary>
/// Return the value at the position x and y in the given grid
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="grid"></param>
/// <returns></returns>
GridSlot* GetValue(int x, int y, GridSlot* grid) {
	int pos = GetArrayPosition(x, y);
	return &grid[pos];
}

/// <summary>
/// Set the given newValue at the x and y coordinates of the given grid
/// </summary>
/// <param name="newValue"></param>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="grid"></param>
void SetValue(GridSlot newValue, int x, int y, GridSlot* grid) {
	int pos = GetArrayPosition(x, y);
	grid[pos] = newValue;
}

/// <summary>
/// Display the formated grid
/// </summary>
/// <param name="grid"></param>
void DisplayGrid(GridSlot* grid) {
	printf("\n");
	Repeat('  ', 4);
	Repeat('|', 1);
	Repeat(' ', 1);
	int iStartingAscii = 65;
	for (unsigned int k = 0; k < GRID_SIZE; k++) {
		printf("%c  ", iStartingAscii + k);
	}
	printf("\n");
	Repeat('-', 4);
	Repeat('+', 1);
	Repeat('-', GRID_SIZE * 3 - 1);
	printf("\n");

	for (unsigned int i = 0; i < GRID_SIZE; i++)
	{

		printf(i+1 > 9 ? " %d |" : " %d  |", i+1);
		for (unsigned int j = 0; j < GRID_SIZE; j++)
		{
			GridSlot* oValue = GetValue(i, j, grid);
			printf(" %c ", oValue->isBomb ? 'B' : '.');
		}
		printf("\n");
	}
}

void Dig(int x, int y, GridSlot* grid) {
	GridSlot* oSlot = GetValue(x, y, grid);
	if (oSlot->bombs == 0) {
		RecursiveReveal(oSlot, grid);
	} else {
		oSlot->isRevealed = 1;
	}
	if (oSlot->isBomb)
		Loose();
}

void RecursiveReveal(GridSlot* slot, GridSlot* grid) {
	slot->isRevealed = 1;
	GridSlot result[8];
	int n = GetAdjacentSlots(slot->x, slot->y, grid, result);
	for (int i = 0; i < n; i++) {
		GridSlot* slot = &result[i];
		if (slot->bombs == 0 && slot->isBomb == 0) {
			slot->isRevealed = 1;
			RecursiveReveal(slot, grid);
		}
	}
}

int GetAdjacentSlots(int x, int y, GridSlot* grid, GridSlot** outResult) {

}

void Loose() {
	printf("You lost!");
}