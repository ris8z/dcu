import { useEffect } from 'react';
import { useState } from 'react';

function Book({id}){

    const [book, setBook] = useState({})
    
    const [isLoaded, setIsLoaded] = useState(false);

    const url = "http://127.0.0.1:8000/api/book/" + id;

    useEffect(()=>{
        console.log("start fetch");

        fetch(url)
        .then(data=>data.json())
        .then(json=>{
            console.log(json);
            setBook(json);
            setIsLoaded(true);
        })

        console.log("ending fetch guarda qua");
        console.log(book);
    }, []);


    if(isLoaded){
        return(
            <div>
                <h1>Book with ID: {id}</h1>
                <p>title: {book.title}</p>
                <p>author:{book.author}</p>
                <p>year:  {book.year}</p>
            </div>
        )
    }else{
        return(
            <img src="galaxyLoading.gif"/>
        )
    }
}

export default Book;