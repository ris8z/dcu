class diagonal{
	public void dig_trbl(int[][] matrix, int row, int col){
		int n = row + col - 1;
		int currRow, currCol;
		boolean validRow, validCol, first;

		for(int i = 0; i < n; i++){
			first = true;
			for(int j = 0; j < row; j++){
				currRow = 0 + j;
				currCol = col - 1 - i + j;
				validRow = 0 <= currRow && currRow < row;
				validCol = 0 <= currCol && currCol < col;
				if(validRow && validCol){
					if(first){
						System.out.print("first:");
						first = false;
					}
					System.out.print("(" + matrix[currRow][currCol] + "),");
				}
			}
			System.out.println("\n");
		}
	}

	public void dig_tlbr(int[][] matrix, int row, int col){
		int n = row + col - 1;
		int currRow, currCol;
		boolean validRow, validCol, first;

		for(int i = 0; i < n; i++){
			first = true;
			for(int j = 0; j < row; j++){
				currRow = 0 + j;
				currCol = 0 + i - j;
				validRow = (0 <= currRow && currRow < row);
				validCol = (0 <= currCol && currCol < col);
				if(validRow && validCol){
					if(first){
						first = false;
						System.out.print("first: ");
					}
					System.out.print("("+matrix[currRow][currCol]+")");
				}	
			}
			System.out.println("\n");
		}
	}



	public static void main(String[] args) {
		int[][] matrix = {
			{1,2,3,10},
			{4,5,6,11},
			{7,8,9,12},
		};
		var a = new diagonal();
		a.dig_trbl(matrix, 3, 4);
		a.dig_tlbr(matrix, 3, 4);
	}
}