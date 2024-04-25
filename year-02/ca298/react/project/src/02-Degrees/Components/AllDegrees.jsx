import { useState } from "react";
import { useEffect } from "react";
import { useNavigate } from 'react-router-dom';

function AllDegrees(){
    
    const [degrees, setDegrees] = useState(null);
    const [isLoaded, setIsLoaded] = useState(false);
    const navigate = useNavigate();

    useEffect(()=>{
        async function fetchData(){
            try
            {
                const response = await fetch("http://127.0.0.1:8000/api/degree/");

                if(!response.ok){
                    throw new Error("Could not fetch the data");
                }

                const data = await response.json();
   
                setDegrees(data);
                setIsLoaded(true);
            }
            catch(error)
            {
                console.log(error);
            }
        }

        fetchData();

    }, []);

    const display = () =>{
        /*const list = degrees.map(
            e => <li><a href={`/degrees/${e.shortcode}`}>{e.full_name}</a></li>
        );*/

        const list = degrees.map(
            e => <button className="main" onClick={()=>navigate(`/degrees/${e.shortcode}`)}> {e.full_name} </button>
        )
        return list;
    }

    if(isLoaded){
        return(
            <div className="inList">
            {display()}
            </div>
        );
    }
    else{
        return(
            <p> Loading ... </p>
        );
    }
}

export default AllDegrees;