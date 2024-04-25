import { useState } from "react";
import { useEffect } from "react";
import { useNavigate } from 'react-router-dom';

function NewCohort(){
    const navigate = useNavigate();
    const [error, setError] = useState("");

    const [id, setId] = useState("");
    const [year, setYear] = useState("");

    const [selectedDegree, setSD] = useState("");
    const [degrees, setDegrees] = useState([]);
    const [ready, setReady] = useState(false);

    //we load the degrees at mount so []
    useEffect(()=>{
        fetch("http://127.0.0.1:8000/api/degree/")
        .then(response => response.json())
        .then((data) => {
            console.log(data);
            setDegrees(data);
            setReady(true);
        })
        .catch(error => console.log(error));
    },[]);

    
    
    if(!ready){
        return(<p>Loading ...</p>);
    }


    async function HandleSubmit (event){
        event.preventDefault();
        const newCohort = {
            "id" : id.toUpperCase(),
            "year": year,
            "degree": `http://127.0.0.1:8000/api/degree/${selectedDegree}/`
        }
        const url = "http://127.0.0.1:8000/api/cohort/";
        const sendData  = {
            method: "POST",
            headers: {
                "Content-Type": "application/json",
            },
            body: JSON.stringify(newCohort)
        }
        
        try{
            const response = await fetch(url, sendData);

            if(!response.ok)//our request failed
            {
                const errorData = await response.json();
                if(response.status === 400 || response.status === 409)// 400 and 409 are code for bad req
                {
                    setError(`${errorData.id || ""}`)
                }
                else
                {
                    setError("Unkown Error Sorry");
                }
            }
            else //our request did not fail
            {
                const data = await response.json();
                console.log(data);
                navigate("/cohorts");
            }

        }catch(error){
            console.log(error);
        }
    }

    return (
        <div className="inForm">
        {error && <div className="error">{error}</div>}
        <form onSubmit={HandleSubmit}>
            <div>
                <input
                    type = "text"
                    value = {id}
                    onChange={(e) => setId(e.target.value)}
                    placeholder="id"
                    required
                />
            </div>

            <div>
                <input
                    type="number"
                    value={year}
                    onChange={(e) => setYear(e.target.value)}
                    placeholder="year"
                    min="1"
                    max="4"
                    require
                />
            </div>

            <div>
                <select
                    value={selectedDegree}
                    onChange={(e) => setSD(e.target.value)}
                    required
                >
                    <option value="">Pick a Degree</option>
                        {degrees.map(d => (
                            <option 
                                key={d.shortcode}
                                value={d.shortcode}
                            >
                                {d.full_name}
                            </option>
                        ))}
                </select>
            </div>

            <button type="submit">Add Cohort</button>
        </form>
        </div>
    );
}

export default NewCohort;