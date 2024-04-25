import { useState } from "react";
import { useNavigate } from 'react-router-dom';

function NewDegree(){
    const [fullname, setFullName] = useState("");
    const [shortcode, setShortCode] = useState("");
    const [error, setError] = useState("");
    const navigate = useNavigate();
    
    async function HandleSubmit(event)
    {
        event.preventDefault();//prevent the form to empty itself on subit
        const NewDegree = {full_name: fullname, shortcode: shortcode};

        try
        {
            const url = "http://127.0.0.1:8000/api/degree/";
            const mySendRequest = {
                method: 'POST',
                headers: {
                'Content-Type': 'application/json',
                },
                body: JSON.stringify(NewDegree),
            }
            const response = await fetch(url, mySendRequest);

            if(!response.ok)//our request failed
            {
                const errorData = await response.json();
                if(response.status === 400 || response.status === 409)// 400 and 409 are code for bad req
                {
                    setError(errorData.shortcode);
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
                navigate("/degrees");
            }
        }
        catch(error)
        {
            console.log(error);
        }
    }

    return(
        <div className="inForm">
        {error && <div className="error">{error}</div>}
        <form onSubmit={HandleSubmit}>
            <div>
                <input 
                    id="full_name"
                    type="text"
                    value={fullname}
                    onChange={(event) => setFullName(event.target.value)}
                    placeholder="Full Name"
                    required
                />
            </div>

            <div>
                <input
                    id="short_code"
                    type="text"
                    value={shortcode}
                    onChange={(event) => setShortCode(event.target.value)}
                    placeholder="Short Code"
                    required
                />
            </div>

            <button type="submit"> Create a New Degree</button>
        </form>
        </div>
    );
}

export default NewDegree;