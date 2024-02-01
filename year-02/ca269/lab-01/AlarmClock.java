import java.util.Scanner;

public class AlarmClock {

    public static void main(String[] args) {

    Scanner input = new Scanner(System.in);

    int clock_time;
    int last_time = 0;
    int current_time;
    int false_allarms = 0;

    clock_time = input.nextInt() * 60 + input.nextInt();

    while(last_time < clock_time){
        current_time = input.nextInt() * 60 + input.nextInt();

        if(current_time <= last_time){
            continue;
        }

        last_time = current_time;

        if(current_time < clock_time){
            false_allarms += 1;
        }
    }

    System.out.println("false alarms: " + false_allarms);
    }
}
