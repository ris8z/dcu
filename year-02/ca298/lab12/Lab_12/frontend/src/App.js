import logo from './logo.svg';
import './App.css';
import HeadingComponent from './components/heading';
import HelloComponent from './components/hello';
import ButtonCompoent from './components/button';
import CounterComponent from './components/counter';
import CatFactsComponent from './components/Catfacts';
import BooksComponent from './components/books';
import Book from './components/book';

function App() {
  return (
    <div className="App">
      <header className="App-header">
        <HeadingComponent name="John" age={10}/>
        <HelloComponent />
        <ButtonCompoent />
        <CounterComponent />
        <CatFactsComponent />
        <BooksComponent />
        <Book id={2} />
        <img src={logo} className="App-logo" alt="logo" />
        <p>
          Edit <code>src/App.js</code> and save to reload.
        </p>
        <a
          className="App-link"
          href="https://reactjs.org"
          target="_blank"
          rel="noopener noreferrer"
        >
          Learn React
        </a>
      </header>
    </div>
  );
}

export default App;
