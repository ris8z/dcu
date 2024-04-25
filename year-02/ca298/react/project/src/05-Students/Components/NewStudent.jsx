
import { useEffect, useState } from "react";


function NewStudent(){
    
    const [cohorts, setCohorts] = useState(null);
    const [ready, setReady] = useState(false);
    const [selectedC, setSelectedC] = useState("");

    const [fname, setFname] = useState("");
    const [lname, setLname] = useState(""); 
    const [output, setOuput] = useState("");

    //prefetch all the cohorts
    useEffect(() => {
        fetch("http://127.0.0.1:8000/api/cohort/")
        .then(response => response.json())
        .then(data => {
            console.log(data);
            setCohorts(data);
            setReady(true);
        })
        .catch(e => console.log(e));

    }, []);

    /**
    cohort: "http://127.0.0.1:8000/api/cohort/COMBUS2/"
    first_name: "Homer"
    last_name: "Quarles"
     */
    async function HandleSubmit(event){
        event.preventDefault();
        setOuput("");
        const new_student = {
            "cohort": `http://127.0.0.1:8000/api/cohort/${selectedC}/`,
            "first_name": fname,
            "last_name": lname,
        }
        const url = "http://127.0.0.1:8000/api/student/";
        const sendData  = {
            method: "POST",
            headers: {
                "Content-Type": "application/json",
            },
            body: JSON.stringify(new_student)
        }
        
        try{
            const response = await fetch(url, sendData);

            if(!response.ok)//our request failed
            {
                const errorData = await response.json();
                console.log(errorData);
            }
            else //our request did not fail
            {
                const data = await response.json();
                //console.log(data);
                setOuput(data.student_id)
            }
        }catch(error){
            console.log(error);
        }
    }

    if(ready){
    return (
        <div className="inForm">
            <form onSubmit={HandleSubmit}>
                <div><input type="text" value={fname} onChange={e => setFname(e.target.value)} placeholder="First name" required /></div>

                <div><input type="text" value={lname} onChange={e => setLname(e.target.value)} placeholder="Last name" required /></div>

                <div>
                    <select value={selectedC} onChange={(e) => setSelectedC(e.target.value)} required>
                    <option value="">Pick a Cohort</option>
                        {cohorts.map(d => (
                            <option key={d.id} value={d.id}> {d.id}</option>
                        ))}
                    </select>
                </div>

                <button type="submit">Add Student</button>
                {output && <div><p>New Student ID:{output}</p></div>}
            </form>
        </div>
    );
    }

    return (<>Loading ...</>);
}

export default NewStudent;