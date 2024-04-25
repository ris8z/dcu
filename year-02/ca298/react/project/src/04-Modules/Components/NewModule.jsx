import { useState } from "react";
import { useEffect } from "react";
import { useNavigate } from "react-router-dom"

/*
example:

const obj = {
    code: "CA106"
    full_name: "something"
    ca_split: 100
    delivered_to: ["http://127.0.0.1:8000/api/cohort/COMBUS1/", 
    "http://127.0.0.1:8000/api/cohort/COMSCI1/"]
}
*/
function NewModule(){

    const navigate = useNavigate();
    const [cohorts, setChorts] = useState([]);
    const [selectedC, setSelectC] = useState([])
    const [ready, setReady] = useState(false);
    const [error, setError] = useState("");

    const [code, setCode] = useState(null);
    const [fullName, setFullName] = useState(null);
    const [caSplit, setCaSplit] = useState("");


    //we load all the possible cohorts at the mount of the page
    useEffect(()=>{
        fetch("http://127.0.0.1:8000/api/cohort/")
        .then(response => response.json())
        .then(data => {setChorts(data);setReady(true);})
        .catch(e => console.log(e));
    }, []);


    async function HandleSubmit (event){
        event.preventDefault();
        const new_module = {
            "code": code.toUpperCase(),
            "full_name": fullName,
            "ca_split": parseInt(caSplit, 10),
            "delivered_to": selectedC.map(e => `http://127.0.0.1:8000/api/cohort/${e}/`),
        };
        const url = "http://127.0.0.1:8000/api/module/";
        const sendData  = {
            method: "POST",
            headers: {
                "Content-Type": "application/json",
            },
            body: JSON.stringify(new_module),
        }

        try{
            const response = await fetch(url, sendData);
            if(!response.ok){
                //faild
                const errorResponse = await response.json();
                setError(errorResponse.code || "Undefined error");
            }else{
                //did not fail
                navigate("/modules");
            }
        }catch(e){
            console.log(e);
        }

    }


    if(!ready){
        return(<p>Loading ...</p>);
    }


    return(
        <>
            <div className="inForm">
                {error && <div className="error">{error}</div>}
                <form onSubmit={HandleSubmit}>

                    <div><input type="text" value={code} onChange={e => setCode(e.target.value)} placeholder="Code" required /></div>

                    <div><input type="text" value={fullName} onChange={e => setFullName(e.target.value)} placeholder="Full name" required /></div>

                    <div><input type="number" value={caSplit} onChange={e => setCaSplit(e.target.value)} placeholder="CA split" 
                    min="1"
                    max="100"
                    required/></div>

                    <div>
                        <select multiple={true} value={selectedC} onChange={e => setSelectC(Array.from(e.target.selectedOptions, o => o.value))} >
                                {cohorts.map(c => (<option key={c.id} value={c.id}>{c.id}</option>))}
                        </select>
                    </div>

                    <div>Hold control to choose multiple Cohorts</div>
                    <button type="submit">add Module</button>
                    
                </form>
            </div>
        </>
    );
}

export default NewModule;