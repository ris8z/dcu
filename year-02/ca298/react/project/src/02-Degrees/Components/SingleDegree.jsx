import { useState } from "react";
import { useEffect } from "react";
import { useParams } from 'react-router-dom';
import { useNavigate } from "react-router-dom";

function SingeDegree(){
    const { DegreeCode } = useParams(); //Estrae il codice del degree dal url

    const [degree, setDegree] = useState(null);
    const [isDegreeLoaded, setIsDegreeLoaded] = useState(false);

    const [cohorts, setCohorts] = useState(null);
    const [isCohortsLoaded, setIsCohortsLoaded] = useState(false);
    const navigate = useNavigate();

    useEffect(()=>{
        async function fetchDegree(){
            try
            {
                const response = await fetch(`http://127.0.0.1:8000/api/degree/${DegreeCode}/`);

                if(!response.ok){
                    
                    throw new Error("Could not fetch the data degree");
                }

                const data = await response.json();
   
                setDegree(data);
                setIsDegreeLoaded(true);
                //console.log(data);
            }
            catch(error)
            {
                console.log(error);
            }
        }

        async function fetchCohorts(){
            try
            {
                const response = await fetch(`http://127.0.0.1:8000/api/cohort/?degree=${DegreeCode}`);
                
                if(!response.ok){
                    throw new Error("Could not fetch the data cohorts");
                }

                const data = await response.json();
                setCohorts(data);
                setIsCohortsLoaded(true);
                //console.log(data);

            }
            catch(error)
            {
                console.log(error);
            }
        }


        fetchDegree();
        fetchCohorts();

    }, [DegreeCode]);

    const displayCohorts = () => {
        const list = cohorts.map(
            e => <button onClick={()=>navigate(`/modules/cohort/${e.id}`)}>{e.id}</button>
        )
        return list;
    }

    if(isDegreeLoaded && isCohortsLoaded){
        return(
            <div className="inList">
            <h2>{degree.full_name} ({degree.shortcode})</h2>
            <h4>Cohorts:</h4>
                {displayCohorts()}
            </div>
        );
    }
    else{
        return(
            <p> Loading ... data for {DegreeCode}</p>
        );
    }
}

export default SingeDegree;