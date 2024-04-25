
import SingleStudent from "../Components/SingleStudent";
import { useState } from "react";

function SingleStudentPage(){
    const [id, setId] = useState("");
    const [submittedId, setSubmittedId] = useState(null);

    const HandleSubmit = (e) =>{
        e.preventDefault();
        setSubmittedId(id);
    }

    return(
        <div className="outForm" id="tooManyOut">
           
            <form onSubmit={HandleSubmit}>
                 <h3> Search for a Student by id:</h3>
                <div>
                    <input type="text" value={id} onChange={e => setId(e.target.value)} placeholder="ID Student" required />
                </div>
                    <button type="submit">Search Student</button>
            </form>
            {submittedId && <SingleStudent StudentID={submittedId}/>}
        </div>
    );

}

export default SingleStudentPage;