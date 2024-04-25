import { useState } from "react";

const BASE_URL = "http://127.0.0.1:8000/api"

// {
//   "shortcode": "strin",
//   "display_name": "string"
// }

function New_Category(){
    const [error, setError] = useState("");
    const [shortcode, setShortcode] = useState("");
    const [display_name, setDisplay_name] = useState("");

    const HandleSubmit = async (event) =>{
        event.preventDefault();
        const new_obj = {
            "shortcode": shortcode,
            "display_name": display_name,
        }
        const sendData = {
            method: "POST",
            headers: { "Content-Type": "application/json", },
            body: JSON.stringify(new_obj),
        }

        setError("");
        try{
            const response = await fetch(`${BASE_URL}/category/`, sendData);
            const responseData = await response.json();
            if(!response.ok){
                throw new Error(`Server responded with ${response.status}: ${responseData.shortcode}`)
            }
            console.log(responseData);
        }catch(error){
            setError(error.toString());
        }
    }


    return(
        <div>
            {error && <div> {error} </div>}
            <form onSubmit={HandleSubmit}>
                <div>
                    <input type="text" value={shortcode} 
                    onChange={e => setShortcode(e.target.value)}
                    placeholder="shortcode" required/>
                </div>

                <div>
                    <input type="text" value={display_name} 
                    onChange={e => setDisplay_name(e.target.value)}
                    placeholder="display name" required/>
                </div>

                <button type="submit">Add category</button>
            </form>
        </div>
    )
}

export default New_Category;