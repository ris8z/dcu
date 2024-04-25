import React, { useState, useEffect } from "react";

function NewGrade({ StudentObj }) {
  const [modules, setModules] = useState([]);
  const [selectedM, setSelectedM] = useState("");
  const [ready, setReady] = useState(false);
  const [ca_mark, setCa_mark] = useState("");
  const [exam_mark, setExam_mark] = useState("");
  const [myDict, setMyDict] = useState({});
  const [feedbackMessage, setFeedbackMessage] = useState(""); // Aggiunto per fornire feedback all'utente

  useEffect(() => {
    if (StudentObj == null) {
      return;
    }

    const arr = StudentObj.cohort.split("/");
    const CohortsID = arr[arr.length - 2];
    const url = `http://127.0.0.1:8000/api/module/?delivered_to=${CohortsID}`;

    fetch(url)
      .then(response => response.json())
      .then(data => {
        setModules(data);
        setReady(true);
      })
      .catch(e => {
        console.log(e);
        setFeedbackMessage("Error while loading modules."); // Fornisce feedback in caso di errore
      });

    const url2 = `http://127.0.0.1:8000/api/grade/?student=${StudentObj.student_id}`;
    fetch(url2)
      .then(response => response.json())
      .then(data => {
        data.forEach(e => {
          const arr = e.module.split("/");
          const ModuleID = arr[arr.length - 2];
          addKeyValue(ModuleID, e.id);
        });
      })
      .catch(e => {
        console.log(e);
        setFeedbackMessage("Error while loding grades."); // Fornisce feedback in caso di errore
      });
  }, [StudentObj]); // Assicurati che StudentObj sia incluso come dipendenza se il suo valore iniziale può cambiare

  const addKeyValue = (newKey, newValue) => {
    setMyDict(prevDict => ({
      ...prevDict,
      [newKey]: newValue,
    }));
  };

  async function Handle(event) {
    event.preventDefault();
    const new_grade = {
      "module": `http://127.0.0.1:8000/api/module/${selectedM}/`,
      "ca_mark": ca_mark,
      "exam_mark": exam_mark,
      "cohort": StudentObj.cohort,
      "student": `http://127.0.0.1:8000/api/student/${StudentObj.student_id}/`,
    };

    const url = !(selectedM in myDict)
      ? "http://127.0.0.1:8000/api/grade/"
      : `http://127.0.0.1:8000/api/grade/${myDict[selectedM]}/`;

    const method = !(selectedM in myDict) ? "POST" : "PUT";

    try {
      const response = await fetch(url, {
        method: method,
        headers: {
          "Content-Type": "application/json",
        },
        body: JSON.stringify(new_grade),
      });

      if (!response.ok) {
        throw new Error("La richiesta non è andata a buon fine");
      }

      const data = await response.json();
      console.log(data);
      setFeedbackMessage(method === "POST" ? "Valutazione aggiunta con successo." : "Valutazione aggiornata con successo."); // Fornisce feedback in base all'operazione eseguita
    } catch (error) {
      console.error("Errore di fetch: ", error);
      setFeedbackMessage("Errore durante l'aggiunta o l'aggiornamento della valutazione."); // Fornisce feedback in caso di errore
    }
  }

  if (!ready) {
    return <>Loading ...</>;
  }
  return (
    <div className="inForm">
        <form onSubmit={Handle}>
          <div>
            <label>Now Pick a Module and the grade, then click on COMPLETE</label><br></br>
            <select value={selectedM} onChange={e => setSelectedM(e.target.value)} required>
              <option value="">Pick a Module</option>
              {modules.map(d => (
                <option key={d.code} value={d.code}>{d.code}</option>
              ))}
            </select>
          </div>


          <div>
            <input type="number" value={ca_mark} onChange={e => setCa_mark(e.target.value)} placeholder="CA" min="1" max="100" required />
          </div>

          <div>
            <input type="number" value={exam_mark} onChange={e => setExam_mark(e.target.value)} placeholder="Exam" min="1" max="100" required />
          </div>

          <button type="submit">COMPLETE</button>
        </form>
        {feedbackMessage && <p>{feedbackMessage}</p>} {/* Visualizza il messaggio di feedback */}
    </div>
  );
}

export default NewGrade;