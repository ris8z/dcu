import { useState } from "react";
import { useEffect } from "react";
import { useParams } from 'react-router-dom';

function SingleCohorts(){
    const {CohortsID} = useParams();

    const [cohort, setCohort] = useState(null);
    const [isCohortLoaded, setIsCohortLoaded] = useState(false);

    const [students, setStudents] = useState(null);
    const [isStudentsLoaded, setIsStudentLoaded] = useState(false);

    useEffect(()=>{
        async function fetchCohort(){
            try{
                const url = `http://127.0.0.1:8000/api/cohort/${CohortsID.toUpperCase()}/`;
                const response = await fetch(url);

                if(!response.ok){
                    throw new Error("Could not fetch data cohort");
                }
                
                const data = await response.json();

                //console.log(data);
                setCohort(data)
                setIsCohortLoaded(true);
                
            }catch(error){
                console.log(error);
            }
        }

        async function fetchStudents(){
            try{
                const url = `http://127.0.0.1:8000/api/student/?cohort=${CohortsID.toUpperCase()}`;
                const response = await fetch(url);

                if(!response.ok){
                    throw new Error("Could not fetch data cohort");
                }
                
                const data = await response.json();

                console.log(data);
                setStudents(data);
                setIsStudentLoaded(true);
                
            }catch(error){
                console.log(error);
            }
        }

        fetchCohort();
        fetchStudents();

    }, [CohortsID]);

    const display = () =>{
        const list = students.map(
            (el)=> <button>{el.email}</button>
        );
        return list;
    }

    if(isCohortLoaded && isStudentsLoaded){
        return(
            <div className="inList">
                <h2>{cohort.name} ({cohort.id})</h2>
                <h4> Students: </h4>
                {display()}
            </div>
        );
    }
    else{
        return(
            <p> Loading ... data for {CohortsID}</p>
        );
    }
}

export default SingleCohorts;