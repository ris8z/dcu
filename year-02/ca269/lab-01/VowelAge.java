import java.util.Scanner;

public class VowelAge {

    public static void main(String[] args){
        int age;
        String string_age;
        String name;
        int vowels = 0;

        Scanner input = new Scanner(System.in);
        name = input.nextLine();
        age = input.nextInt();

        for(char c : name.toCharArray()) {
            switch(Character.toLowerCase(c)){
                case 'a':
                    vowels += 1;
                    break;
                case 'e':
                    vowels += 1;
                    break;
                case 'i':
                    vowels += 1;
                    break;
                case 'o':
                    vowels += 1;
                    break;
                case 'u':
                    vowels += 1;
                    break;
            }
        }


        if(age >= 18){
            string_age = "an adult";
        }else{
            string_age = "a minor";
        }

        System.out.print("Hello " + name);
        System.out.print(", you have " + vowels);
        System.out.println(" vowels, and you are " + string_age);
    }

}
