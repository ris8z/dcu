interface MyList<Thing>{
	void add(Thing t);
	void add(Thing t, int pos);
	Thing remove();
	Thing remove(int pos);
	void clear();
	int size();
	int contains(Thing t);
}

class MyArrayList <Thing> {
	private Thing[] array = (Thing[])new Object[100];
	private int size = 0;

	public void add(Thing t){
		this.array[size] = t;
		size++;
	}

	public void add(Thing t, int pos){
		if(!(0 <= pos && pos <= size)){
			return;
		}

		int i = size;
		while(i != pos){
			this.array[i] = this.array[i - 1];
			i--;
		}
		this.array[i] = t;
		size++; 
	}

	Thing remove(){
		if(!(size > 0)){
			return null;
		}
		Thing result = this.array[size - 1];
		size--;
		return result;
	}

	Thing remove(int pos){
		if(!(0 <= pos && pos <= size - 1)){
			return null;
		}

		Thing result = this.array[pos];

		int i = pos;
		while(i != size - 1){
			this.array[i] = this.array[i + 1];
			i++;
		}

		size--;
		return result;
	}

	public void clear(){
		this.size = 0;
	}

	public int size(){
		return this.size;
	}

	public String toString(){
		String output = "[";
		for(int i = 0; i<this.size; i++){
			output += this.array[i] + ",";
		}
		return output + "]";
	}

	public int contains(Thing t){
		int i = 0;
		while(i < this.size && this.array[i] != t){
			i++;
		}

		if(i < this.size){
			return i;
		}
		return -1;
	}

	public static void main(String[] args) {
		MyArrayList<Integer> numList = new MyArrayList<>();
		for(int i=0; i<10; i++) { numList.add(i); }
		System.out.println(numList);
		// output: [0,1,2,3,4,5,6,7,8,9,]
		numList.add(125, 5);
		System.out.println(numList);
		// output: [0,1,2,3,4,125,5,6,7,8,9,]
		System.out.println(numList.remove() == 9);
		// output: 9
		System.out.println(numList);
		// output: [0,1,2,3,4,125,5,6,7,8,]
		System.out.println(numList.remove(5) == 125);
		// output: 125
		System.out.println(numList);
		// output: [0,1,2,3,4,5,6,7,8,]
		System.out.println(numList.size() == 9);
		// output: 9

		System.out.println(numList.contains(6) == 6);
		// output: 6
		System.out.println(numList.contains(125) == -1);
		// output: -1

		numList.clear();
		System.out.println(numList);
		// output: []
	}
}