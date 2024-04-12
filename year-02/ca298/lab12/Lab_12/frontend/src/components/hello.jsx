function HelloComponent(){
    //components are rendered two times only god knows why
    //in fact this log spawn two times in the console when reload is cliccked
    console.log("test");
    
    const name = "Peppe";
    const greetings = ["how are you",
        "how's it going?",
        "where were you when the westfold fell",
        "did you put your name in the gobelt of fire",
        "this is the way",
        "I was there the day Horus slew the Emperor",
    ];

    const sayHello = () =>{
        let randomGreeting = greetings[Math.floor(Math.random() * greetings.length)];
        return `Hello ${name}, ${randomGreeting}`;
    }
    return (
        <div>
            <h1>{sayHello(1,2)}</h1>
        </div>
    )
}

export default HelloComponent;