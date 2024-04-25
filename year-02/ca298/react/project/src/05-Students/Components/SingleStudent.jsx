
import { useState } from "react";
import { useEffect } from "react";
import ModulesByCohorts from "../../04-Modules/Components/ModulesByCohort";


function SingleStudent({StudentID}){
    const [student, setStudent] = useState(null);
    const [error, setError] = useState("");
    const [ready, setReady] = useState(false);
    const [grades, setGrades] = useState(null);
    const [gradeflag, setgradeflag] = useState(false);

    useEffect(()=>{
        const url = `http://127.0.0.1:8000/api/student/${StudentID}/`
        const urlGrade = `http://127.0.0.1:8000/api/grade/?student=${StudentID}`;
        setError("");
        setgradeflag(false);
        setReady(false);

        fetch(url)
        .then(response => {
            if(!response.ok){
                setError("Student not Found");
            }
            return response.json();
        })
        .then(data => {
            setStudent(data);
            setReady(true);
        })
        .catch(e => console.log(e));

        
        fetch(urlGrade)
        .then(response => response.json())
        .then(data => {
            setGrades(data);
            setgradeflag(true);
        })
        .catch(e => console.log(e));

    },[StudentID]);


    const displayCohortCode = () =>{
        const tokens = (student.cohort).split("/");
        const result = tokens[tokens.length - 2];
        return result;
    }

    const displayGrades = () =>{
        const list = grades.map((e) => {
            const tokens = e.module.split("/");
            const moudleName = tokens[tokens.length - 2];
            return (<div> {moudleName} CA:{e.ca_mark} Exam:{e.exam_mark}</div>);
        });
        return list;
    }

    if(error){
        return (<div className="error">{error}</div>);
    }

    if(ready && gradeflag){
    return(
        <div className="inList">
            <h3>Main Datails:</h3>
            <p>Name: {student.first_name} {student.last_name}</p>
            <p>Email: {student.email}</p>
            <p>Cohort: <button> {displayCohortCode()} </button> </p>
            <ModulesByCohorts overrideID={displayCohortCode()}/>
            <h3>Grades:</h3>    
            {displayGrades()}
        </div>
    );
    }

    return (<p>Loading</p>);
}

export default SingleStudent;