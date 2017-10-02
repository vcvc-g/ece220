/*
 * countLiveNeighbor
 * Inputs:
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * row: the row of the cell that needs to count alive neighbors.
 * col: the col of the cell that needs to count alive neighbors.
 * Output:
 * return the number of alive neighbors. There are at most eight neighbors.
 * Pay attention for the edge and corner cells, they have less neighbors.
 */
int countLiveNeighbor(int* board, int boardRowSize, int boardColSize, int row, int col)
{
	int alive_n = 0;

/*
INTRO
This code has three functions, which are coountLiveNeighbor updateboard and alivestable.
The first function count how many alive neighbors a cell have I used a double for loop to go
through the eight neighbors and using a count varible to record how many alive neighbors an cell'
has.
The second function is update the board we first set a temp arry the same size of the board
and checkthe alive neighbors to determine a cell is live or die and copy the value in the temp array
and finally to copy the temp array to the board array to update
The third function checks if the alive cells stay the same for next step. We creat a temp array first
to hold the old board and call the function updateboard to update and compare every single element in
two arrays to check if it's the same or not.
*/

int countLiveNeighbor(int* board, int boardRowSize, int boardColSize, int row, int col){
	int live = 0;
    for(int i = row-1; i <= row + 1; i++){
        for(int j = col-1; j <= col + 1; j++){
        	if(i < 0 || j < 0 || i >= boardRowSize || j >= boardColSize)//check number of live cells in 3x3 square
        		continue;;																								// if its i or j <0, continue
        	if(board[i * boardColSize + j] == 1)
            	live++;

        }
    }
		if (board[row*boardColSize+col]==1){ //mins itself
			live--;
		}
	return live;                      // return number of live cells around it
}
/*
 * Update the game board to the next step.
 * Input:
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * Output: board is updated with new values for next step.
 */
void updateBoard(int* board, int boardRowSize, int boardColSize) 
{
	int up_board[boardRowSize*boardColSize];
	int live_num;

    int live_num;
    int n_board[boardRowSize*boardColSize];             // create a new intermediate board
    for (int i = 0; i < boardRowSize; i++){
    	for(int j = 0; j < boardColSize; j++){
    		live_num = countLiveNeighbor(board,boardRowSize,boardColSize,i,j);
            if(board[i*boardColSize+j] == 1){
            	if(live_num == 2 || live_num == 3){      // apply conditions
            		n_board[i*boardColSize+j] = 1;
            	}
            	else{
            		n_board[i*boardColSize+j] = 0;
            	}
            }
            else{
            	if(live_num == 3){
            		n_board[i*boardColSize+j] = 1;
            	}
            	else{
            		n_board[i*boardColSize+j] = 0;
            	}
            }
    	}
    }
    for(int k = 0; k < boardRowSize*boardColSize; k++)
    {
    	board[k] = n_board[k];                          //update input board through deep copy
    }


}

/*
 * aliveStable
 * Checks if the alive cells stay the same for next step
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * Output: return 1 if the alive cells for next step is exactly the same with
 * current step or there is no alive cells at all.
 * return 0 if the alive cells change for the next step.
 */


int aliveStable(int* board, int boardRowSize, int boardColSize){

int all = boardColSize*boardRowSize;
int compareboard[all];
for(int i = 0; i < all; i++){
	compareboard[i] = board[i];              //copy board to a temp board before update it
}
updateBoard(compareboard,boardRowSize,boardColSize);

for(int j = 0; j < all; j++){
	if(compareboard[j] != board[j])         //compare old and new
		return 0;
}

return 1;
}
