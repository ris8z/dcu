import java.io.Reader;
import java.io.FileReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.Writer;
import java.io.FileWriter;
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import org.apache.commons.csv.CSVFormat;
import org.apache.commons.csv.CSVRecord;
import com.google.gson.Gson;

class StarWarsCharacter{
	String name = "";
    String height = "";
    String mass = "";
    String hairColor = "";
    String skinColor = "";
    String eyeColor = "";
    String birthYear = "";
    String gender = "";
    String homeworld = "";
    String species = "";

	StarWarsCharacter() {}

	void setName(String name){
		this.name = name;
	}

	void setHeight(String height){
		this.height = height;
	}

	void setMass(String mass){
		this.mass = mass;
	}

	void setHairColor(String hairColor){
		this.hairColor = hairColor;
	}

	void setSkinColor(String skinColor){
		this.skinColor = skinColor;
	}

	void setEyeColor(String eyeColor){
		this.eyeColor = eyeColor;
	}

	void setBirthYear(String birthYear){
		this.birthYear = birthYear;
	}

	void setGender(String gender){
		this.gender = gender;
	}

	void setHomeWorld(String homeworld){
		this.homeworld = homeworld;
	}

	void setSpecies(String species){
		this.species = species;
	}

	public String toString(){
		String output = "(";
		output += this.name + ", ";
		output += this.height + ", ";
		output += this.mass + ", ";
		output += this.hairColor + ", ";
		output += this.skinColor + ", ";
		output += this.eyeColor + ", ";
		output += this.birthYear + ", ";
		output += this.gender + ", ";
		output += this.homeworld + ", ";
		output += this.species + ")";
		return output;
	}
}

public class JarJarBinks{
	public static void main(String[] args){
		
		try
		{
			Reader in = new FileReader("characters.csv");
			CSVFormat CSVparser = CSVFormat.Builder.create().setHeader().build();
			Iterable<CSVRecord> records = CSVparser.parse(in);
			List<StarWarsCharacter> characterList = new ArrayList<>();

			for(CSVRecord record: records)
			{
				StarWarsCharacter c = new StarWarsCharacter();
				c.setName(record.get("name"));
				c.setHeight(record.get("height"));
				c.setMass(record.get("mass"));
				c.setHairColor(record.get("hair_color"));
				c.setSkinColor(record.get("skin_color"));
				c.setEyeColor(record.get("eye_color"));
				c.setBirthYear(record.get("birth_year"));
				c.setGender(record.get("gender"));
				c.setHomeWorld(record.get("homeworld"));
				c.setSpecies(record.get("species"));
				characterList.add(c);	
			}

			
			// System.out.println(gson.toJson(characterList.get(0)));
			// for(StarWarsCharacter c1: characterList)
			// {
			// 	System.out.println(c1);
			// }
			//System.out.println(gson.toJson(characterList.get(0)));
			//System.out.println(gson.toJson(characterList.get(characterList.size() - 1)));

			Writer out = new FileWriter("characters.json");
			Gson gson = new Gson();
			gson.toJson(characterList, out);
			out.close();

		}
		catch(FileNotFoundException e)
		{
			System.out.println("Error with open file");
		}
		catch(IOException e)
		{
			System.out.println("Error with io");
		}
	
	}
}