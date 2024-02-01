import java.time.LocalDate;
import java.time.Period;


enum State {
    TODO, BEGN, HALT, WAIT, DONE;
}

class Task {
    String title=null;
    String description;
    LocalDate scheduled;
    LocalDate deadline;
    State state = State.TODO;


    Task(String title, State state) {
        this.title = title;
        setState(state);
    }
    Task(String title, State state, LocalDate scheduled) {
        this(title, state);
        setScheduled(scheduled);
    }
    Task(String title, State state, String description, LocalDate scheduled, LocalDate deadline) {
        this(title, state);
        setDescription(description);
        setScheduled(scheduled);
        setDeadline(deadline);
     }


    public void setTitle(String title){
        this.title = title;
    }
    public void setDescription(String description){
        this.description = description;
    }
    public void setScheduled(LocalDate scheduled){
        this.scheduled = scheduled;
    }
    public void setDeadline(LocalDate deadline){
        this.deadline = deadline;
    }
    public void setState(State state){
        this.state = state;
    }


    public String getTitle(){
        return this.title;
    }
    public String getDescription(){
        return this.description;
    }
    public LocalDate getScheduled(){
        return this.scheduled;
    }
    public LocalDate getDeadline(){
        return this.deadline;
    }
    public State getState(){
        return this.state;
    }


    public String toString() {
        String message = this.title + " (" + this.state + ")";
        if (scheduled != null) {
            message += " scheduled: " + scheduled;
        }
        if (deadline != null) {
            message += " deadline: " + deadline;
        }
        return message;
    }

    public static void main(String[] args){
        //test a simple Task object works correctly
        Task t1 = new Task("T1", State.TODO);
        LocalDate now = LocalDate.now();
        LocalDate.now();
        System.out.println(t1);

        // test repeated task
        Task s1 = new RepeatedTask("S1", State.TODO);
        System.out.println(s1);
        s1.setState(State.DONE);
        System.out.println(s1);

        // Check Chores work correctly on DONE -> repeat
        // note s2 is Task but object is type Chore
        Task s2 = new Chore("S2", State.TODO, LocalDate.now(), LocalDate.now().plus(Period.ofDays(7)));
        System.out.println(s2);
        s2.setState(State.DONE);
        // verify the scheduled date has moved by +7
        System.out.println(s2);

        //sheared tasks
        Task t2 = new SharedTask("T2", "Alice");
        System.out.println(t2);

        //dependecy taks
        Task t3 = new Dependency("T3", State.TODO, t1);
        System.out.println(t3);
        t3.setState(State.DONE);
        System.out.println(t3); //should be still TODO
        t1.setState(State.DONE);
        t3.setState(State.DONE);
        System.out.println(t3); //should be DONE
    }
}

class RepeatedTask extends Task{
    RepeatedTask(String title, State state){
        super(title, state);
    }

    @Override
    public void setState(State state){
        if(state == State.DONE) {
            this.state = State.TODO;
        }else{
            this.state = state;
        }
    }
}         


class Chore extends RepeatedTask {
    LocalDate repeat;

    Chore(String title, State state, LocalDate scheduled, LocalDate repeat) {
        super(title, state);
        setScheduled(scheduled);
        setRepeat(repeat);
    }

    public LocalDate getRepeat() {
        return this.repeat;
    }

    public void setRepeat(LocalDate repeat) {
        this.repeat = repeat;
    }

    @Override
    public void setState(State state) {
        // set the istance state from RepeatedTask, so it's going to be always TODO
        super.setState(state);
        //here we are checking the var from the argument non the var this.state, but state
        if (state == State.DONE) {
            // scheduled = repeat
            // but first set repeat to +7 days
            LocalDate repeat_new = repeat.plus(Period.ofDays(7));
            setScheduled(repeat);
            setRepeat(repeat_new);
        }
    }
}

 class SharedTask extends Task {
    String name;

    SharedTask(String title, String name) {
        // state always starts with WAIT
        super(title, State.WAIT);
        this.name = name;
    }

    @Override
    public String toString() {
        return super.toString() + " shared with: " + name;
    }
}

class Dependency extends Task {
    Task task_dependency;

    Dependency(String title, State state, Task task_dependency) {
        super(title, state);
        this.task_dependency = task_dependency;
    }

    @Override
    public String toString() {
        return super.toString() + " dependent on: " + task_dependency.toString();
    }

    @Override
    public void setState(State state) {
    if (state == State.DONE && !(task_dependency.state == State.DONE)) {
        return;
    }
    this.state = state;
    }
}
