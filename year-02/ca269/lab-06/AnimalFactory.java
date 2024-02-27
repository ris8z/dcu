import java.util.*;

interface SafetyRegulation{
	public int getMaxItemsPermitted();
}

abstract class Item implements SafetyRegulation{
}

class Duck extends Item{
	private int max_istances = 5;

	public int getMaxItemsPermitted(){
		return max_istances;
	}
}

class Swan extends Item{
	private int max_istances = 2;

	public int getMaxItemsPermitted(){
		return max_istances;
	}
}

class Flamingo extends Item{
	private int max_istances = 3;

	public int getMaxItemsPermitted(){
		return max_istances;
	}
}

class Dog extends Item{
	private int max_istances = 20;

	public int getMaxItemsPermitted(){
		return max_istances;
	}
}

class Cat extends Item{
	private int max_istances = 20;

	public int getMaxItemsPermitted(){
		return max_istances;
	}
}

class AnimalFactory <Thing extends Item & SafetyRegulation> {
	private int unitsProduced;

	AnimalFactory(){
		unitsProduced = 0;
	}

	public Thing continueProduction(Thing T){
		if(!(T instanceof SafetyRegulation)){
			return null;
		}

		if(!(this.getCount() < ((SafetyRegulation)T).getMaxItemsPermitted() )) {
			return null;
		}

		this.unitsProduced++;

		return T;
	}

	public int getCount(){
		return unitsProduced;
	}

    public static void main(String[] args){
    	// main() for testing:
		AnimalFactory<Duck> AF_D = new AnimalFactory<>();
		while(AF_D.continueProduction(new Duck()) != null);
		System.out.println("Total Ducks produced: " + AF_D.getCount());

		AnimalFactory<Swan> AF_S = new AnimalFactory<>();
		while(AF_S.continueProduction(new Swan()) != null);
		System.out.println("Total Swans produced: " + AF_S.getCount());

		AnimalFactory<Flamingo> AF_F = new AnimalFactory<>();
		while(AF_F.continueProduction(new Flamingo()) != null);
		System.out.println("Total Flamingos produced: " + AF_F.getCount());

		AnimalFactory<Dog> AF_G = new AnimalFactory<>();
		while(AF_G.continueProduction(new Dog()) != null);
		System.out.println("Total Dogs produced: " + AF_G.getCount());

		AnimalFactory<Cat> AF_C = new AnimalFactory<>();
		while(AF_C.continueProduction(new Cat()) != null);
		System.out.println("Total Cats produced: " + AF_C.getCount());

		// which produces the output
		// Total Ducks produced: 5
		// Total Swans produced: 2
		// Total Flamingos produced: 3
		// Total Dogs produced: 20
		// Total Cats produced: 20

    }
}
