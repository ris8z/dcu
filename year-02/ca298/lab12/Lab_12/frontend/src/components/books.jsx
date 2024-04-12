import { useState } from 'react'
import { useEffect } from 'react'

function BooksComponent(){

    const [Books, setBooks] = useState({});

    const [isLoaded, setIsLoaded] = useState(false);

    useEffect(()=>{
        console.log("Started fetch");

        fetch("http://127.0.0.1:8000/api/book/")
        .then(data=>
            data.json()
        ).then(json=>{
            console.log(json);
            setBooks(json);
            setIsLoaded(true);
        })

        console.log("ending fetch");
        console.log(Books);
    }, []);


    const displayBooks = () =>{
        const list = Books.map(
            elem=><li>{elem.title}, {elem.author}, {elem.year}</li>
        );
        return list;
    }

    
    if(isLoaded)
    {
        return(
            <div>
                <h1>List of Books</h1>
                <ul>
                    { displayBooks() }
                </ul>
            </div>
        )
    }
    else
    {
        return(
            <img src="galaxyLoading.gif"/>
        )
    }
}

export default BooksComponent;