enum Color{
	Empty{
		public String toString(){
			return "E";
		}
	},
	Red{
		public String toString(){
			return "R";
		}
	},
	Yellow{
		public String toString(){
			return "Y";
		}
	};
}

class Player{
	private String name;
	private Color color;
	private int score;

	Player(String name, Color color){
		this.name = name;
		this.color = color;
		this.score = 0;
	}

	public String getName(){
		return this.name;
	}

	public Color getColor(){
		return this.color;
	}

	public String toString(){
		return "(" + this.name + "," + this.color + ")";
	}
}

class Grid{
	private int row;
	private int col;
	private int key;
	private Color[][] grid;

	Grid(int row, int col, int key){
		this.row = row;
		this.col = col;
		this.key = key;
		this.grid = new Color[row][col];
		System.out.println("teset");
		this.setUpGrid();
	}

	private void setUpGrid(){
		for(int i = 0; i < this.row; i++){
			for(int j = 0; j < this.col; j++){
				this.grid[i][j] = Color.Empty;
			}
		}
	}

	public boolean makeMove(int col, Color color){
		int row = 0;
		while(row < this.row && this.grid[row][col] == color.Empty){
			row += 1;
		}
		if(0 <= row - 1 && row - 1 < this.row){
			this.grid[row - 1][col] = color;
			return true;
		}else{
			return false;
		}
	}

	public Color checkwin(){
		int row, col;
		int count = 0;

		//check is there is a win in the rows
		for(row = 0; row < this.row; row++){
			for(col = 0; col < this.col; col++){
				if(this.grid[row][col] == Color.Empty){ continue;}

				if(col == 0){ count = 1; continue;}

				if(this.grid[row][col] != this.grid[row][col - 1]){ 
					count = 1;
					continue;
				}

				count += 1;
				if(count == this.key){
					return this.grid[row][col];
				}
			}
		}

		//check if there is a win in the cols
		for(col = 0; col < this.col; col++){
			for(row = 0; row < this.row; row++){
				if(this.grid[row][col] == Color.Empty){ continue;}

				if(row == 0){ count = 1; continue;}

				if(this.grid[row][col] != this.grid[row - 1][col]){
					count = 1;
					continue;
				}

				count += 1;
				if(count == this.key){
					return this.grid[row][col];
				}
			}
		}

		//check if there is a win in the diagonal \
		// for(int diagonal = 0; diangonal < this.row + this.col - 1; i++){
		// }
		return null;
	}

	public String toString(){
		String result = "";
		result += "/-----------\\\n";
		for(int i = 0; i < row; i++){
			result += "|";
			for(int j = 0; j < row; j++){
				result += this.grid[i][j] + "|";
			}
			result += "\n";
		}
		result += "\\-----------/\n";
		return result;
	}
}

class Game{}

class forza4{
	public static void main(String[] args) {
		System.out.println("hello");
		var mygrid = new Grid(6, 7, 4);
		System.out.println(mygrid);
		mygrid.makeMove(2, Color.Red);
		mygrid.makeMove(2, Color.Red);
		mygrid.makeMove(2, Color.Red);
		mygrid.makeMove(3, Color.Yellow);
		mygrid.makeMove(3, Color.Yellow);
		mygrid.makeMove(3, Color.Yellow);
		mygrid.makeMove(3, Color.Yellow);
		System.out.println(mygrid);
		System.out.println(mygrid.checkwin());


	}
}