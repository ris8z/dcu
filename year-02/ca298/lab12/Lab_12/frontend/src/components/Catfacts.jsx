import { useState } from "react";
import { useEffect } from "react";

function CatFactsComponent(){
    
    const [facts, setFacts] = useState([
        "Cats are cool",
        "Cats are nice",
    ]);

    const [isLoaded, setIsLoaded] = useState(false);

    useEffect(()=>{
        
        fetch("https://cat-fact.herokuapp.com/facts")
        .then(response=>response.json())
        .then(data=>{ 
            //e.text is the field of the e object that we want to dispay
            setFacts(data.map(e=>e.text));// get the array of text out and set it as our state
            setIsLoaded(true);
        })
        .catch(err=>console.log(err));

    }, []);
    
    const displayFacts = () =>{
        const list = facts.map(
            elem=><li>{elem}</li>
        );
        return list;
    };

    if(isLoaded)
    {
        return(
            <ul>
                { displayFacts()}
            </ul>
        )
    }else{
        return(
            <img src="galaxyLoading.gif"/>
        )
    }
}

export default CatFactsComponent;