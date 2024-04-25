
import { useState } from "react";
import NewGrade from "../Components/NewGrade";

function PutGradePage(){
    const [id, setId] = useState("");
    const [falg, setFlag] = useState(false);
    const [error, setError] = useState("");
    const [student, setStudent] = useState(null);

    const handlesubmit = (event) =>{ //just check if the student exist
        event.preventDefault();
        setError("");
        setFlag(false);

        fetch(`http://127.0.0.1:8000/api/student/${id}`)
        .then(response => {
            if(response.ok){
                setFlag(true);
            }else{
                setError("This Student does not exist");
                throw new Error("student not found")
            }
            return response.json()
        })
        .then(data => {
            setStudent(data)
            console.log(data);
        })
        .catch(e => console.log(e))
    }



    return(
        <div className="outForm">
        <h3>Select a grade for a student and his module</h3>
        <form onSubmit={handlesubmit}>
            <div> <label>Insert first the Student ID</label></div>
            <div> <input type="text" value={id} onChange={e=>setId(e.target.value)} placeholder="Student ID" required /></div>
            <button type="submit"> submit </button>
        </form>
        {error && <p>these student do not exist</p>}
        {falg && <NewGrade StudentObj={student}/>}
        </div>

    );
}

export default PutGradePage;