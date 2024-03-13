import java.util.*;

class Value implements Comparable<Value>{
	final Integer value;
	private static boolean SORT_LOWER=true;


	Value(Integer value){
		this.value = value;
	}

	public Integer getValue(){
		return this.value;
	}

	public static boolean isSortedLower(){
		return SORT_LOWER;
	}

	public static void setSortLower(){
		SORT_LOWER = true;
	}


	public static boolean isSortedHigher(){
		return !(SORT_LOWER);
	}

	public static void setSortHigher(){
		SORT_LOWER = false;
	}	


	public int compareTo(Value other){
		int flag=1;
		if(Value.isSortedHigher()){ flag=-1;}
		return flag * this.getValue().compareTo(other.getValue());
	}

	public String toString(){
		return this.value.toString();
	}
}

class PreferLowerValues implements Comparator<Value>{
	public int compare(Value one, Value two){
		return one.getValue().compareTo(two.getValue());
	}
}

class PreferHigherValues implements Comparator<Value>{
	public int compare(Value one, Value two){
		return -(one.getValue().compareTo(two.getValue()));
	}
}

class MyFancyDataStructure{
	public static void main(String[] args) {
		System.out.println("ao");
		List<Value> list = Arrays.asList(
		new Value(1), new Value(50), new Value(-1),
		new Value(3), new Value(11), new Value(4)
		);

		Value.setSortLower();
		Collections.sort(list);
		System.out.println(list);

		Value.setSortHigher();
		Collections.sort(list);
		System.out.println(list);

		list.sort(new PreferLowerValues());
		System.out.println(list);

		list.sort(new PreferHigherValues());
		System.out.println(list);

	}
}
