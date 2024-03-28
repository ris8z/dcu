

class NoCakeFoundException extends Exception{
	NoCakeFoundException(){
		super();
	}

	NoCakeFoundException(String Message){
		super(Message);
	}

	public String toString(){
		return "The Cake is a Lie!";
	}
}


class Cake{
	public void getCake() throws NoCakeFoundException{
		throw new NoCakeFoundException();
	}

	public void eatCake(){
		try
		{
			getCake();
		}
		catch(NoCakeFoundException e)
		{
			System.out.println(e);
		}
	}
}


class mock{
	public static void main(String[] args) {
		new Cake().eatCake();

		return;
	}

}