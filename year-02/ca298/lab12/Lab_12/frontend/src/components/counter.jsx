import { useState } from "react"

function CounterComponent(){

    const [myVar, setMyVar] = useState(0);

    function handleClick(){
        setMyVar(myVar + 1);
    }

    return(
        <div>
            <p>{myVar}</p>
            
            <button onClick={handleClick}>
                Clikc me
            </button>
        </div>
    )
}

export default CounterComponent;