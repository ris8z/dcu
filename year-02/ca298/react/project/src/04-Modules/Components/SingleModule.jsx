import { useEffect } from "react";
import { useState } from "react";
import { useParams } from "react-router-dom"

function SingleModule(){
    const {ModuleCode} = useParams();
    const [module, setModule] = useState(null);
    const [ready, setReady] = useState(false);
    const [error, setError] = useState("");

    useEffect(()=>{
        const url = `http://127.0.0.1:8000/api/module/${ModuleCode.toUpperCase()}/`
        fetch(url)
        .then(response => {
            if( !response.ok ){
                setError("Sorry Module not found");                
            }
            return response.json();
        })
        .then((data) => {
            //console.log(data);
            setModule(data);
            setReady(true);
        })
        .catch(e => console.log(e));

    }, [ModuleCode]);


    const display = () =>{
        const tokens = module.delivered_to[0].split("/");
        return tokens[tokens.length - 2];
    }

    if(!ready){
        return(<>Loading ... {ModuleCode}</>);
    }


    if(error){
        return(<> <h1>{error}</h1> </>);
    }

    return(
        <>
        <h3>{module.full_name} ({module.code}) {display()}</h3>
        </>
    );
}

export default SingleModule;