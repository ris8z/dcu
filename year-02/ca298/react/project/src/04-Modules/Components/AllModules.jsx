import { useState } from "react";
import { useEffect } from "react";
import { useNavigate} from "react-router-dom"

function AllModules(){

    const [modules, setModules] = useState(null);
    const [ready, setReady] = useState(false);
    const navigate = useNavigate();

    useEffect(()=>{
        const url = "http://127.0.0.1:8000/api/module/";
        
        fetch(url)
        .then(response => response.json())
        .then((data) =>{
            console.log(data);
            setModules(data);
            setReady(true);
        })
        .catch(e => console.log(e));

    }, []);

    const display = () =>{
        const list = modules.map(e => (<button onClick={()=>navigate(`/modules/${e.code}`)}>{e.code}</button>)); 
        return list;
    }

    if(!ready){
        return(<p>Loading ...</p>);
    }

    return(
        <div className="inList">
            {display()}
        </div>
    );
}

export default AllModules;