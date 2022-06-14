#include<iostream>
using namespace std;

const int ROWS = 9;
const int COL = 9;
const int NUM_OF_QUADRANTS = 9;

enum quadrants {
	TOP_LEFT, TOP_CENTER, TOP_RIGHT,
	MID_LEFT, MID_CENTER, MID_RIGHT,
	BOT_LEFT, BOT_CENTER, BOT_RIGHT
};

enum rows {
	ROW1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7, ROW8, ROW9
};

enum cols {
	COL1, COL2, COL3, COL4, COL5, COL6, COL7, COL8, COL9
};

void cross_hatch_row(int row_index, bool cross_hatch_board[9][9]) {
	for (int i = 0; i < 9; i++) {
		cross_hatch_board[row_index][i] = true;
	}
}

void cross_hatch_col(int col_index, bool cross_hatch_board[9][9]) {
	for (int i = 0; i < 9; i++) {
		cross_hatch_board[i][col_index] = true;
	}
}

void fill_in_filled_squares(int sudokuPuzzle[9][9], bool crossHatch[9][9]) {
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (sudokuPuzzle[i][j] != 0)
			{
				crossHatch[i][j] = true;
			}
		}
	}
}

bool is_number_in_quadrant(int num, int game_board[9][9], int quadrant) {
	if (quadrant == TOP_LEFT)
	{
		for (int i = ROW1; i <= ROW3; i++)
		{
			for (int j = COL1; j <= COL3; j++)
			{
				if (game_board[i][j] == num)
					return true;
			}
		}
	}
	else if (quadrant == TOP_CENTER)
	{
		for (int i = ROW1; i <= ROW3; i++)
		{
			for (int j = COL4; j <= COL6; j++)
			{
				if (game_board[i][j] == num)
					return true;
			}
		}
	}
	else if (quadrant == TOP_RIGHT)
	{
		for (int i = ROW1; i <= ROW3; i++)
		{
			for (int j = COL7; j <= COL9; j++)
			{
				if (game_board[i][j] == num)
					return true;
			}
		}
	}
	else if (quadrant == MID_LEFT)
	{
		for (int i = ROW4; i <= ROW6; i++)
		{
			for (int j = COL1; j <= COL3; j++)
			{
				if (game_board[i][j] == num)
					return true;
			}
		}
	}
	else if (quadrant == MID_CENTER)
	{
		for (int i = ROW4; i <= ROW6; i++)
		{
			for (int j = COL4; j <= COL6; j++)
			{
				if (game_board[i][j] == num)
					return true;
			}
		}
	}
	else if (quadrant == MID_RIGHT)
	{
		for (int i = ROW4; i <= ROW6; i++)
		{
			for (int j = COL7; j <= COL9; j++)
			{
				if (game_board[i][j] == num)
					return true;
			}
		}
	}
	else if (quadrant == BOT_LEFT)
	{
		for (int i = ROW7; i <= ROW9; i++)
		{
			for (int j = COL1; j <= COL3; j++)
			{
				if (game_board[i][j] == num)
					return true;
			}
		}
	}

	else if (quadrant == BOT_CENTER)
	{
		for (int i = ROW7; i <= ROW9; i++)
		{
			for (int j = COL4; j <= COL6; j++)
			{
				if (game_board[i][j] == num)
					return true;
			}
		}
	}
	else if (quadrant == BOT_RIGHT)
	{
		for (int i = ROW7; i <= ROW9; i++)
		{
			for (int j = COL7; j <= COL9; j++)
			{
				if (game_board[i][j] == num)
					return true;
			}
		}
	}
	return false;
}

bool is_number_in_row(int num, int row, int sudokuPuzzle[9][9]) {
	for (int j = 0; j < COL; j++)
	{
		if (sudokuPuzzle[row][j] == num)
			return true;
	}
	return false;
}

bool is_number_in_column(int num, int col, int sudokuPuzzle[9][9]) {
	for (int i = 0; i < COL; i++)
	{
		if (sudokuPuzzle[i][col] == num)
			return true;
	}
	return false;
}

bool one_square_in_row(int row, bool crossHatch[9][9]){
	int counter = 0;
	for (int j = 0; j < COL; j++)
	{
		if (crossHatch[row][j] == false)
			counter++;
	}
	if (counter == 1)
		return true;
	else
		return false;
}

bool one_square_in_column(int col, bool crossHatch[9][9]) {
	int counter = 0;
	for (int i = 0; i < ROWS; i++)
	{
		if (crossHatch[i][col] == false)
			counter++;
	}
	if (counter == 1)
		return true;
	else
		return false;
}

bool one_square_in_quadrant(int quadrant, bool crossHatch[9][9]) {
	int counter = 0;
	if (quadrant == TOP_LEFT)
	{
		for (int i = ROW1; i <= ROW3; i++)
		{
			for (int j = COL1; j <= COL3; j++)
			{
				if (crossHatch[i][j] == false)
					counter++;
			}
		}
	}
	else if (quadrant == TOP_CENTER)
	{
		for (int i = ROW1; i <= ROW3; i++)
		{
			for (int j = COL4; j <= COL6; j++)
			{
				if (crossHatch[i][j] == false)
					counter++;
			}
		}
	}
	else if (quadrant == TOP_RIGHT)
	{
		for (int i = ROW1; i <= ROW3; i++)
		{
			for (int j = COL7; j <= COL9; j++)
			{
				if (crossHatch[i][j] == false)
					counter++;
			}
		}
	}
	else if (quadrant == MID_LEFT)
	{
		for (int i = ROW4; i <= ROW6; i++)
		{
			for (int j = COL1; j <= COL3; j++)
			{
				if (crossHatch[i][j] == false)
					counter++;
			}
		}
	}
	else if (quadrant == MID_CENTER)
	{
		for (int i = ROW4; i <= ROW6; i++)
		{
			for (int j = COL4; j <= COL6; j++)
			{
				if (crossHatch[i][j] == false)
					counter++;
			}
		}
	}
	else if (quadrant == MID_RIGHT)
	{
		for (int i = ROW4; i <= ROW6; i++)
		{
			for (int j = COL7; j <= COL9; j++)
			{
				if (crossHatch[i][j] == false)
					counter++;
			}
		}
	}
	else if (quadrant == BOT_LEFT)
	{
		for (int i = ROW7; i <= ROW9; i++)
		{
			for (int j = COL1; j <= COL3; j++)
			{
				if (crossHatch[i][j] == false)
					counter++;
			}
		}
	}

	else if (quadrant == BOT_CENTER)
	{
		for (int i = ROW7; i <= ROW9; i++)
		{
			for (int j = COL4; j <= COL6; j++)
			{
				if (crossHatch[i][j] == false)
					counter++;
			}
		}
	}
	else if (quadrant == BOT_RIGHT)
	{
		for (int i = ROW7; i <= ROW9; i++)
		{
			for (int j = COL7; j <= COL9; j++)
			{
				if (crossHatch[i][j] == false)
					counter++;
			}
		}
	}
	else
		cout << "error";
	if (counter == 1)
		return true;
	else
		return false;
}

void enter_number_quad(int num, int quadrant, bool crossHatch[9][9], int sudokuPuzzle[9][9]) {
	if (quadrant == TOP_LEFT)
	{
		for (int i = ROW1; i <= ROW3; i++)
		{
			for (int j = COL1; j <= COL3; j++)
			{
				if (crossHatch[i][j] == false)
					sudokuPuzzle[i][j] = num;
			}
		}
	}
	else if (quadrant == TOP_CENTER)
	{
		for (int i = ROW1; i <= ROW3; i++)
		{
			for (int j = COL4; j <= COL6; j++)
			{
				if (crossHatch[i][j] == false)
					sudokuPuzzle[i][j] = num;
			}
		}
	}
	else if (quadrant == TOP_RIGHT)
	{
		for (int i = ROW1; i <= ROW3; i++)
		{
			for (int j = COL7; j <= COL9; j++)
			{
				if (crossHatch[i][j] == false)
					sudokuPuzzle[i][j] = num;
			}
		}
	}
	else if (quadrant == MID_LEFT)
	{
		for (int i = ROW4; i <= ROW6; i++)
		{
			for (int j = COL1; j <= COL3; j++)
			{
				if (crossHatch[i][j] == false)
					sudokuPuzzle[i][j] = num;
			}
		}
	}
	else if (quadrant == MID_CENTER)
	{
		for (int i = ROW4; i <= ROW6; i++)
		{
			for (int j = COL4; j <= COL6; j++)
			{
				if (crossHatch[i][j] == false)
					sudokuPuzzle[i][j] = num;
			}
		}
	}
	else if (quadrant == MID_RIGHT)
	{
		for (int i = ROW4; i <= ROW6; i++)
		{
			for (int j = COL7; j <= COL9; j++)
			{
				if (crossHatch[i][j] == false)
					sudokuPuzzle[i][j] = num;
			}
		}
	}
	else if (quadrant == BOT_LEFT)
	{
		for (int i = ROW7; i <= ROW9; i++)
		{
			for (int j = COL1; j <= COL3; j++)
			{
				if (crossHatch[i][j] == false)
					sudokuPuzzle[i][j] = num;
			}
		}
	}

	else if (quadrant == BOT_CENTER)
	{
		for (int i = ROW7; i <= ROW9; i++)
		{
			for (int j = COL4; j <= COL6; j++)
			{
				if (crossHatch[i][j] == false)
					sudokuPuzzle[i][j] = num;
			}
		}
	}
	else if (quadrant == BOT_RIGHT)
	{
		for (int i = ROW7; i <= ROW9; i++)
		{
			for (int j = COL7; j <= COL9; j++)
			{
				if (crossHatch[i][j] == false)
					sudokuPuzzle[i][j] = num;
			}
		}
	}
	else
		cout << "error";
}

void enter_number_row(int num, int row, bool crossHatch[9][9], int sudokuPuzzle[9][9]) {
	for (int j = COL1; j < COL; j++)
	{
		if (crossHatch[row][j] == false)
			sudokuPuzzle[row][j] = num;
	}
}

void enter_number_col(int num, int col, bool crossHatch[9][9], int sudokuPuzzle[9][9]) {
	for (int i = ROW1; i < ROWS; i++)
	{
		if (crossHatch[i][col] == false)
			sudokuPuzzle[i][col] = num;
	}
}


void display_board(int game[9][9]) {
	int new_row = 0;
	int counter = 0;
	int row_underscore = 0;
	for (int i = 0; i < 9; i++) {
		for (int x = 0; x < 9; x++) {
			cout << game[i][x] << " ";
			new_row++;
			counter++;
			if (new_row == 9) {
				cout << endl;
				new_row = 0;
				counter = 0;
				row_underscore++;
				if (row_underscore == 3) {
					cout << "*******|********|******";
					cout << endl;
					row_underscore = 0;
				}
			}
			else if (counter == 3) {
				cout << " " << "|" << " ";
				counter = 0;
			}
			else {
				continue;
			}
		}
		
	}
}

void display_board(bool board[9][9]) {
	int new_row = 0;
	for (int i = 0; i < 9; i++) {
		for (int x = 0; x < 9; x++) {
			cout << board[i][x] << " ";
			new_row++;
			if (new_row == 9) {
				cout << endl;
				new_row = 0;
			}
			else {
				continue;
			}
		}

	}
}

void wipe_board(bool board[9][9]) {
	for (int i = 0; i < 9; i++) { // row_index
		for (int x = 0; x < 9; x++) { // col_index
			board[i][x] = false;
		}
	}
}

void cross_hatching(int search_term, int game_board[9][9], bool cross_hatch_board[9][9]) {
	//search row by row
	for (int i = 0; i < 9; i++) { // row_index
		for (int x = 0; x < 9; x++) { // col_index
			if (game_board[i][x] == search_term) {
				cross_hatch_row(i, cross_hatch_board);
				cross_hatch_col(x, cross_hatch_board);
			}
		}
	}

}

bool game_loop(int game_board[9][9]) { // determines wether or not the game is finished 
	int counter = 0;
	for (int i = 0; i < 9; i++) {
		for (int x = 0; x < 9; x++) {
			if (game_board[i][x] == 0) {
				counter++;
			}
			else {}
		}
	}
	if (counter == 0) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	//declarations
	int user_board[9][9] = {
		{5,3,4,0,7,0,9,1,2},
		{6,0,0,1,9,5,0,0,8},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,4},
		{2,8,7,4,1,9,0,0,5},
		{3,4,5,0,8,0,0,7,9} };

	//int user_board[9][9] = {
//	{5, 0, 4, 6, 0, 8, 9, 0, 2},
//	{0, 7, 0, 1, 0, 5, 0, 4, 0},
//	{1, 0, 8, 0, 4, 0, 5, 0, 7},
//	{0, 5, 0, 7, 0, 1, 0, 2, 0},
//	{4, 0, 6, 0, 5, 0, 7, 0, 1},
//	{0, 1, 0, 9, 0, 4, 0, 5, 0},
//	{9, 0, 1, 0, 3, 0, 2, 0, 4},
//	{0, 8, 0, 4, 0, 9, 0, 3, 0},
//	{3, 0, 5, 0, 8, 0, 1, 0, 9}
//};

	bool cross_hatching_board[9][9] = { {false} };
	bool loop = false;

	while (game_loop(user_board) == false) { //While the puzzle is not solved
		for (int i = 1; i <= 9; i++) //For numbers 1 to 9
		{
			bool loop = true;
			while (loop == true)
			{
				loop = false;

				//cross hatch number
				wipe_board(cross_hatching_board);
				fill_in_filled_squares(user_board, cross_hatching_board);
				cross_hatching(i, user_board, cross_hatching_board);

				//FOR QUADRANTS
				for (int threeByThree = TOP_LEFT; threeByThree < BOT_RIGHT; threeByThree++) //for all quadrants
				{
					if (is_number_in_quadrant(i, user_board, threeByThree) == false) //If number is not in quadrant
					{
						if (one_square_in_quadrant(threeByThree, cross_hatching_board) == true) //if there is one square available in quadrant w/ cross hatch
						{
							enter_number_quad(i, threeByThree, cross_hatching_board, user_board); //Enter the remaining number
							loop = true;
							continue;
						}
					}
				}

				//FOR ROWS
				for (int row = 0; row < ROWS; row++) //for all rows
				{
					if (is_number_in_row(i, row, user_board) == false) //If number is not in row
					{
						if (one_square_in_row(row, cross_hatching_board) == true) //if there is one square available in row w/ cross hatch
						{
							enter_number_row(i, row, cross_hatching_board, user_board); //Enter the remaining number
							loop = true;
							continue;
						}
					}
				}

				//FOR COLUMNS
				for (int col = 0; col < COL; col++) //for all columns
				{
					if (is_number_in_column(i, col, user_board) == false) //If number is not in column
					{
						if (one_square_in_column(col, cross_hatching_board) == true) //if there is one square available in column w/ cross hatch
						{
							enter_number_col(i, col, cross_hatching_board, user_board); //Enter the remaining number
							loop = true;
							continue;
						}
					}
				}
			}
		}
	}


	
	cout << endl;
	display_board(user_board);
	return 0;
}
