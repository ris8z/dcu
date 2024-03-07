import java.util.Scanner;

enum Color{
	Empty{
		public String toString(){
			return " ";
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

	Player(String name, Color color){
		this.name = name;
		this.color = color;
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

	public boolean checkwin(){
		int row, col;
		int count = 0;
		boolean first, validRow, validCol;

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
					return true;
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
					return true;
				}
			}
		}

		//check if there is a win in the diagonal /

		for(int i = 0; i < this.col + this.row - 1; i++){
			first = true;
			for(int j = 0; j < this.row; j++){
				row = 0 + j;
				col = 0 + i - j;
				validRow = (0 <= row && row < this.row);
				validCol = (0 <= col && col < this.col);
				if(validRow && validCol){
					if(this.grid[row][col] == Color.Empty){continue;}
					
					if(first){ count = 1; first = false; continue;}

					if(this.grid[row][col] != this.grid[row - 1][col + 1]){
						count = 1;
						continue;
					}

					count += 1;
					if(count == this.key){
						return true;
					}
				}
			}
		}

		//check if there is a win the diangoal \
		for(int i = 0; i < this.col + this.row - 1; i++){
			first = true;
			for(int j = 0; j < this.row; j++){
				row = 0 + j;
				col = this.col - 1 - i + j;
				validRow = (0 <= row && row < this.row);
				validCol = (0 <= col && col < this.col);
				if(validRow && validCol){
					if(this.grid[row][col] == Color.Empty){continue;}
					
					if(first){ count = 1; first = false; continue;}

					if(this.grid[row][col] != this.grid[row - 1][col - 1]){
						count = 1;
						continue;
					}

					count += 1;
					if(count == this.key){
						return true;
					}
				}
			}
		}

		
		return false;
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

class Game{
	private Grid grid;
	private Player[] players;

	Game(Grid grid, Player p1, Player p2){
		this.grid = grid;
		this.players = new Player[]{p1, p2};
	}

	public void play(){
		int idx = 0;
		Player current_player;
		Scanner cmd = new Scanner(System.in);
		int inputCol;


		while(true){
			System.out.println(this.grid);

			current_player = this.players[idx % 2];
			System.out.println("Insert a move for player("+ current_player.getName() +") :");
			inputCol = cmd.nextInt();

			this.grid.makeMove(inputCol - 1, current_player.getColor());

			if(this.grid.checkwin()){
				System.out.println(this.grid);
				System.out.println("Player "+current_player.getName()+" Won");
				break;
			}
			idx += 1;
		}
	}
}

class forza4{
	public static void main(String[] args) {
		var mygrid = new Grid(6, 7, 4);
		var p1 = new Player("peppe", Color.Red);
		var p2 = new Player("sab", Color.Yellow);
		var game = new Game(mygrid, p1, p2);
		game.play();
	}
}