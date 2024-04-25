import { useState } from "react";
import { useEffect } from "react";
import { useNavigate } from 'react-router-dom';

function AllCohorts(){
    const [cohorts, setCohorts] = useState(null);
    const [isLoaded, setIsLoadead] = useState(false);
    const navigate = useNavigate();

    useEffect(()=>{
        async function fetchData(){
            try
            {
                const url = "http://127.0.0.1:8000/api/cohort/";
                const response = await fetch(url);

                if(!response.ok){
                    throw new Error("error while fetching");
                }

                const data = await response.json();

                console.log(data);
                setCohorts(data);
                setIsLoadead(true);
            }
            catch(error)
            {
                console.log(error);
            }
        }

        fetchData();
    }, []);

    const display = () => {
        const list = cohorts.map(
            (element) => <button onClick={()=>{navigate(`/cohorts/${element.id}`)}}>{element.id}</button>
        );
        return list;
    }


    if(isLoaded){
        return (
            <div className="inList">
            {display()}
            </div>
        );
    }
    else{
        return(<p>Loading ...</p>);
    }
}

export default AllCohorts;