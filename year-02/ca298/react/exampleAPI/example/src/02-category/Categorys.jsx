import { useEffect, useState } from "react";

const BASE_URL = "http://127.0.0.1:8000/api";

//  {
//     "shortcode": "tops",
//     "display_name": "Tops"
//   },

function Categorys(){

    const [error, setError] = useState("");
    const [isLoading, setIsLoading] = useState(false);
    const [categorys, setCategorys] = useState([]);
    
    useEffect(() =>{
        const FetchCategorys = async () => {
            setIsLoading(true);
            try{
                const response = await fetch(`${BASE_URL}/category`);
                const categorys = await response.json();
                setCategorys(categorys);
            }
            catch(error){
                setError(error.toString());
            }
            finally{
                setIsLoading(false);
            }
        }

        FetchCategorys();
    },[]);

    if(isLoading){
        return(<div>Loading ...</div>)
    }

    if(error){
        return(<div>Something went wrong! Plis try again</div>)
    }

    return(
    <div className="categorys">
        <h1>Category List</h1>
        <ul>
            {
                categorys.map((c) => {
                    return <li>{c.shortcode} {c.display_name}</li>
                })
            }
        </ul>
    </div>
    )
}

export default Categorys;