import { useState } from "react";
import { useEffect } from "react";
import { useParams } from "react-router-dom"
import { useNavigate} from "react-router-dom"

function ModulesByCohorts({overrideID = null}){

    const parms = useParams();

    const CohortsID = overrideID != null ? overrideID : parms.CohortsID;
    const [modules, setModules] = useState(null);
    const [ready, setReady] = useState(false);
    const [error, setError] = useState("");
    const navigate = useNavigate();

    useEffect(()=>{
        const url = `http://127.0.0.1:8000/api/module/?delivered_to=${CohortsID.toUpperCase()}`
        fetch(url)
        .then(response => {
            if(!response.ok){
                setError("Not found sorry");
            }
            return response.json();
        })
        .then(data => {
            console.log(data);
            setModules(data);
            setReady(true);
        })
        .catch(e => console.log(e));
        
    }, [CohortsID]);

    if(!ready){
        return(<><p>Loading ...</p></>);
    }

    if(error){
        return(<><p>{error}</p></>);
    }

    const display = () =>{
        const list = modules.map(m => (
            <button onClick={()=>navigate(`/modules/${m.code}`)}>{m.full_name}</button>
        ))
        return list;
    }

    return (
        <>
            <h3>{CohortsID.toUpperCase()} Modules:</h3>
            {display()}
        </>
    );
}

export default ModulesByCohorts;